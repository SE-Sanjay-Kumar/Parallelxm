#include <thread>
#include <chrono>
#include <iostream>

void kitchen_cleaner(){
    while(true){
        std::cout << "garbage collector clearned the kitchen\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main(){
    std::thread garbage_collector(kitchen_cleaner);
    garbage_collector.detach();
    for (int i=0; i< 3 ; i++){
        std::cout << "chef_main cooking ....\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }
    std::cout << "chef_man is done!\n";
}