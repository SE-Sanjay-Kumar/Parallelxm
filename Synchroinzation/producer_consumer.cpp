#include <thread>
#include <queue>
#include <iostream>
#include <mutex>
#include <condition_variable>

class MQ {
    std::queue<int> mq;
    std::mutex queue_lock;
    std::condition_variable value_served; 
    public:
        void put_value(int i){
            std::unique_lock<std::mutex> lock(queue_lock);
            mq.push(i);
            lock.unlock();
            value_served.notify_one();
        }

        int take_value(){
            std::unique_lock<std::mutex> lock(queue_lock);
            while(mq.empty()){
                value_served.wait(lock);
            }
            int n = mq.front();
            mq.pop();
            lock.unlock();
            return n;
        }
};

MQ message_queue = MQ();

void message_producer(){
    for (int i=0;i<10000;i++){
        message_queue.put_value(i);
    }
    message_queue.put_value(-1);                // indicates no more values to put
    std::cout << " producer is done putting values\n";
}

void message_consumer(){
    int total_buffered_values = 0;
    while(true){
        int value = message_queue.take_value();
        if(value == -1){
            std::cout << " consumer has taken "<<total_buffered_values<< " values\n";
            message_queue.put_value(-1);        // putting value back so that other consumers indicated that queue has no more values to consume
            return;
        }else{
            total_buffered_values += value;
        }
    }
}


int main(){
    std::thread he (message_producer);
    std::thread she (message_consumer);
    std::thread it (message_consumer);

    he.join();
    she.join();
    it.join();
}