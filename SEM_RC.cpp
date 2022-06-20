#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>


long long int SALDO = 0;

using namespace std;

void increment(int arg)
{
    int i;
    for (i = 1; i <= 10000 ; i++)
    {
        SALDO = SALDO + 1;
        printf("incremento => <thread %d>: %lld\n", arg, SALDO);

    }
}


void decrement(int arg)
{
    int i;


    for (i = 1; i <= 10000 ; i++)
    
    {
        SALDO = SALDO - 1;
        printf("desc => <thread %d>: %lld\n", arg, SALDO);
    }
}




int main()
{   
    int n=22;
    std::vector<thread> threads(n);

    for (int i = 0; i < n; i+=2) {
        threads[i] = thread(increment, i + 1);
        threads[i+1] = thread(decrement, i + 2);
    }

    for (auto& th : threads) {
        th.join();
    }
        printf("O Saldo final %lld\n",SALDO);
    return 0;
}


