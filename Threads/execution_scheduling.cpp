#include <chrono>
#include <thread>
#include <iostream>

bool chopping = true;
void vegetable_chopper(const char* name) {
    unsigned int vegetable_count = 0;
    while(chopping){
        vegetable_count++;
    }
    std::cout << name <<" chopped "<<vegetable_count << " vegetables" << std::endl;
}

int main(){
    std::thread t1(vegetable_chopper, "t1");
    std::thread t2(vegetable_chopper, "t2");

    std::cout << "t1 and t2 are chopping vegetables ....\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    chopping = false;

    t1.join();
    t2.join();
}