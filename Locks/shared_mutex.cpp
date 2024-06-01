#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <array>
#include <shared_mutex>

using namespace std;

std::string WEEKDAYS[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int today = 0;
std::shared_mutex marker;


void read_calendar(const int id){
    for (int i=0;i<7;i++){
        marker.lock_shared();
        std::cout << "Reader "<<id<<" sees today "<<WEEKDAYS[today] << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(20));

        marker.unlock_shared(); 
    }
}

void write_to_calender(const int id){
    for (int i=0;i<7;i++){
        marker.lock();
        today = (today + 1) % 7;
        std::cout << "Writer "<<id<<" updates date to "<<WEEKDAYS[today] << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        marker.unlock();

    }
}

int main(){
    std::array<std::thread, 10> readers;
    
    for (unsigned int i=0;i<readers.size();i++){
        readers[i] = std::thread(read_calendar, i);
    }

    std::array<std::thread, 2> writers;
    for (unsigned int i=0;i<writers.size();i++){
        writers[i] = std::thread(write_to_calender, i);
    }


    for (unsigned i=0;i<readers.size();i++){
        readers[i].join();
    }

    for (unsigned i=0;i<writers.size();i++){
        writers[i].join();
    }

}