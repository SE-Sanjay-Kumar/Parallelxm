#include <cstdio>
#include <future>

unsigned long long recursive_sum(unsigned int lo, unsigned int hi, unsigned int depth = 0){
    if (depth > std::thread::hardware_concurrency()){
        unsigned long long sum = 0;
        for (int i=lo; i<hi; i++){
            sum += i;
        }
        return sum;
    }else{
        auto mid = (lo + hi) / 2;
        auto left = std::async(std::launch::async, recursive_sum, lo, mid, depth+1);
        auto right = recursive_sum( mid, hi, depth+1);
        return left.get() + right;
    }
}

int main(){
    unsigned long long total = recursive_sum(0, 10000000000);
    printf("total : %lld\n", total);
}