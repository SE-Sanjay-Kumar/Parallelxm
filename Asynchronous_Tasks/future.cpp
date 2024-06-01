#include <future>
#include <chrono>
#include <thread> 

int how_many_vegetables(){
    printf("he is counting vegetables ...\n");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 36;
}



int main(){ 
    printf("I asked how many vegetables in pantry \n");
    std::future<int> f =  std::async (std::launch::async, how_many_vegetables);
    printf("I am waiting for him to count vegetables\n");
    printf("Total vegetables in pantry are %d\n", f.get());
}