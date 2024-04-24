#include <thread>
#include <chrono>
#include <iostream>
#include <unistd.h>

void cpu_waster(){
    std::cout << "CPU Waster process ID " << getpid() << std::endl;
    std::cout << "CPU Waster thread ID " << std::this_thread::get_id() << std::endl;
    while(true) continue;
}

int main(){
    std::cout << "CPU Waster process ID " << getpid() << std::endl;
    std::cout << "CPU Waster thread ID " << std::this_thread::get_id() << std::endl;   

    std::thread thread1(cpu_waster);
    std::thread thread2(cpu_waster);
    
    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}