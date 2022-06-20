#include <thread>
#include <atomic>
#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;
struct AtomicCounter {
    std::atomic<int> value;

    AtomicCounter() : value(0) {}

    void increment(){
        for(int i=0;i<1000; i++){
            ++value;
             printf("<increment> %d\n", value.load());
        }
    }

    void decrement(){
        for(int i=0;i<1000; i++){
            --value;
             printf("<decrement> %d\n", value.load());
        }

    }

    int get(){
        return value.load();
    }
};




int main()
{   
    
    AtomicCounter counter;
    int n=22;
    std::vector<std::thread> threads;
    int temp =0;
    for(int i = 0; i < n; i++){
        
        if(i%2==0){
            threads.push_back(std::thread([&counter](){
                counter.decrement();
            }));
        }else{

            threads.push_back(std::thread([&counter](){
                counter.increment();
            }));


        }

    }

    for(auto& thread : threads){
        thread.join();
    }

    std::cout << "O Saldo final "<< counter.get() << std::endl;
    return 0;
}