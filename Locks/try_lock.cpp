#include <thread>
#include <iostream>
#include <mutex>


unsigned int items_on_notepad = 0;
std::mutex pencil;

void shopper(const std::string &name){
    int items_to_add = 0;

    while(items_on_notepad < 20){
        if (items_to_add && pencil.try_lock() ){
            // actually writing into list
            
            std::cout << "\n\n"<< name << " added "<<items_to_add <<" items in notepad\n\n";  

            items_on_notepad += items_to_add;
            items_to_add = 0;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            pencil.unlock();

        }else {
            // thinking..... what to buy. 
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            items_to_add++;
            std::cout << name << " found "<<items_to_add << " to buy\n";

        }
    }
}


int main(){
    std::thread t1(shopper, "me");
    std::thread t2(shopper, "you");

    t1.join();
    t2.join();
}


