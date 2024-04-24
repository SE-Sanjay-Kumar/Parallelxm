#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>


unsigned int watch_count = 0;
std::mutex pencil;


void shopper(){
    
    for (int i=0;i<10;i++){
        std::cout << "Shopper "<<std::this_thread::get_id() << " is thinking\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        pencil.lock();
        watch_count++;
        pencil.unlock();
    }
   
}



int main(){
    std::thread me(shopper);
    std::thread you(shopper);


    me.join();
    you.join();



    std::cout << "we should buy "<<watch_count <<" watches\n";
    

}
