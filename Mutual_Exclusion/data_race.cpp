#include <thread>
#include <iostream>


unsigned int watch_count = 0;


void shopper(){
    for (int i=0;i<100000;i++){
        watch_count++;
    }
}



int main(){
    std::thread me(shopper);
    std::thread you(shopper);


    me.join();
    you.join();



    std::cout << "we should buy "<<watch_count <<" watches\n";
    

}
