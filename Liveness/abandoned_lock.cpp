#include <thread>
#include <mutex>
#include <iostream>

int cake_piece = 500;
// abandoned lock example
void philosopher(std::mutex &chopsticks){
    while (cake_piece > 0){
        std::scoped_lock lock(chopsticks);
        std::cout << "philosopher "<<std::this_thread::get_id() << " is eating\n";

        if(cake_piece){
            cake_piece--;
        }

        // if (cake_piece==20) break;
    }
    
}


int main(){
    std::mutex fork_1;

    std::thread me(philosopher, std::ref(fork_1));
    std::thread you(philosopher, std::ref(fork_1));


    me.join();
    you.join();

    std::cout << "The philosophers are done eating\n";

}