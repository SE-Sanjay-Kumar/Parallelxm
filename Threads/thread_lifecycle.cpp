#include <thread>
#include <chrono>
#include <iostream>

void chef_t(){
    std::cout << "chef_t started & waiting for sausage to thaw....\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "chef_t is done cutting sausage. \n";
}

int main(){
    std::cout << "chef_main requests chef_t's help\n";
    std::thread t(chef_t);

    std::cout << t.joinable() << std::endl;

    std::cout << "chef_main continues cooking soup. \n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "chef_main patiently waiting for chef_t to finish and join ....\n";
    t.join();

    std::cout << t.joinable() << std::endl;



    std::cout << "chef_main and chef_t are both done!\n";
}