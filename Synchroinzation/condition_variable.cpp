#include <thread>
#include <mutex>
#include <iostream>
#include <condition_variable>

int soup_servings = 10;
std::mutex slow_cooker_lid;
std::condition_variable soup_taken;

const int HUNGARY_PEOPLE = 5;

void hungary_person(int id){
    int put_lid_back = 0;
    while(soup_servings > 0){
        std::unique_lock<std::mutex> lid_lock(slow_cooker_lid);
        // if it is not turn to take soup 
        while ((id!=soup_servings%HUNGARY_PEOPLE) && (soup_servings>0)){
            put_lid_back++;
            soup_taken.wait(lid_lock); // releasing lock if not have turn. 
        }

        if(soup_servings > 0){
            soup_servings--;
            soup_taken.notify_all();        // notify_one will wake one out 4 and if it is not their turn it will stuck. 
        }
    }
    std::cout << "Person "<<id<< " put the lid back "<< put_lid_back <<" times" << std::endl;
}

int main(){
    std::array<std::thread, HUNGARY_PEOPLE> hungary_persons;
    for (int i=0; i < HUNGARY_PEOPLE;i++){
        hungary_persons[i] = std::thread(hungary_person, i);
    }
    for (auto &hp : hungary_persons){
        hp.join();
    }
}