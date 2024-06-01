#include <thread>
#include <mutex>
#include <iostream>


unsigned int watch_count = 0;
unsigned int watch_protector = 0;

std::recursive_mutex shop_man;


void buy_watch_protector(){
    shop_man.lock();
    watch_protector++;
    shop_man.unlock();
}


void buy_watch(){
    shop_man.lock();
    watch_count++;
    buy_watch_protector();
    shop_man.unlock();
}

void shopper(){
    for (int i=0;i<100000;i++){
        buy_watch();
        buy_watch_protector();
    }
}



int main(){
    std::thread me(shopper);
    std::thread you(shopper);


    me.join();
    you.join();



    std::cout << "we should buy "<<watch_count <<" watches\n";
    std::cout << "we should buy "<<watch_protector <<" watch protectors\n";
    

}
