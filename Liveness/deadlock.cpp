#include <thread>
#include <mutex>
#include <iostream>

int cake_piece = 500;

void philosopher(std::mutex &fork1, std::mutex &fork2){
    while (cake_piece > 0){
        std::scoped_lock lock(fork1, fork2);

        if(cake_piece){
            cake_piece--;
        }
    }
    
}


int main(){
    std::mutex fork_1, fork_2;

    std::thread me(philosopher, std::ref(fork_1), std::ref(fork_2));
    std::thread you(philosopher, std::ref(fork_2), std::ref(fork_1));


    me.join();
    you.join();

    std::cout << "The philosophers are done eating\n";

}