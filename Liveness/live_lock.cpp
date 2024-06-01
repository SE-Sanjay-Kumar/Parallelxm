#include <thread>
#include <mutex>
#include <iostream>

int cake_piece = 10000;

void philosopher(std::mutex &fork1, std::mutex &fork2){
    while (cake_piece > 0){
        fork1.lock();

        if (!fork2.try_lock()){
            fork1.unlock();
            std::this_thread::yield();
            
        }else {
           if(cake_piece){
            cake_piece--;
            }

            fork2.unlock();
            fork1.unlock();
        }
        

        

    }
    
}


int main(){
    std::mutex fork_1, fork_2;

    std::thread me(philosopher, std::ref(fork_1), std::ref(fork_2));
    std::thread you(philosopher, std::ref(fork_2), std::ref(fork_1));
    std::thread he(philosopher, std::ref(fork_1), std::ref(fork_2));
    


    me.join();
    you.join();
    he.join();

    std::cout << "The philosophers are done eating\n";

}