
#include <thread>
#include <chrono>
#include <mutex>
#include <iostream>
#include <condition_variable>

class Semaphore {
    unsigned long count;
    std::mutex m;
    std::condition_variable cv;
    public:
        Semaphore(unsigned long init_count){
            count = init_count;
        }
        void acquire(){
            std::unique_lock<std::mutex> lck(m);
            while(!count){
                cv.wait(lck);
            }
            count--;
        }
        void release(){
            std::unique_lock<std::mutex> lck(m);
            count++;
            lck.unlock();
            cv.notify_one();
        }
};

int CHARGER_PORTS = 4;
Semaphore charger(CHARGER_PORTS);

void cell_phone(int id){
    charger.acquire();
    std::cout << "Phone "<<id<< " is charging\n";
    srand(id);
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 2000 + 1000));
    std::cout << "Phone "<<id<< " is done charging\n";
    charger.release();
}

int main(){
    std::thread phones[10];
    for (int i=0;i<10;i++){
        phones[i] = std::thread(cell_phone, i);
    }
    for (int i=0;i<10;i++){
        phones[i].join();
    }

}
