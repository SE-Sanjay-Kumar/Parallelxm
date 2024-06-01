#include <thread>
#include <mutex>
#include <barrier>
#include <iostream>

unsigned int bags_of_chips = 1;

std::barrier my_barrier{ 10 };

std::mutex pencil;


void cpu_work(unsigned long work_units){
    unsigned long x = 0;
    for (unsigned long i=0;i<work_units*1000000;i++){
        x++;
    }
}

void a_shopper(){
    
    cpu_work(1);        // do a bit of work first
    my_barrier.wait(my_barrier.arrive());
    std::scoped_lock<std::mutex> lck(pencil);
    bags_of_chips *= 2;
    std::cout << "a shopper doubles bags of chips\n";

}

void b_shopper(){
    cpu_work(1);
    std::scoped_lock<std::mutex> lck(pencil);
    bags_of_chips += 3;
    std::cout << "b shopper added 3 bags of chips\n";

    my_barrier.arrive();
}

int main(){
    std::thread shoopers[10];
    for (int i=0;i<10;i+=2){
        shoopers[i] = std::thread(a_shopper);
        shoopers[i+1] = std::thread(b_shopper);
    }
    for (auto & s: shoopers){
        s.join();
    }
    std::cout << "we need to buy "<<bags_of_chips<<std::endl;
}