#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

long long int SALDO = 0;
pthread_mutex_t aLock;


void increment(int *arg)
{
    int i;
    for (i = 1; i <= 1000 ; i++)
    {
        pthread_mutex_lock(&aLock); // Lock a mutex for a
        SALDO = SALDO + 1;
        printf("incremento => <thread %d>: %lld\n", *arg, SALDO);
        pthread_mutex_unlock(&aLock); // Unlock a mutex for a
    }
}


void decrement(int *arg)
{
    int i;


    for (i = 1; i <= 1000 ; i++)
    
    {
        pthread_mutex_lock(&aLock); // Lock a mutex for a
        SALDO = SALDO - 1;
        printf("desc => <thread %d>: %lld\n", *arg, SALDO);
        pthread_mutex_unlock(&aLock); // Unlock a mutex for a
    }
}




int main()
{   
    int quant =22;
    printf("Entre com pares de threads: ");
    scanf("%d", &quant);
     pthread_t *thread_group = malloc(sizeof(pthread_t) * quant);
    int i;
    SALDO = 0;


   for (int j=0; j< quant; j+=2){
        int temp = j+1;
        pthread_create(&thread_group[j], NULL, (void*)&increment, &temp);  // Create a new thread for threadFunc
        pthread_create(&thread_group[j+1], NULL, (void*)&decrement, &temp+1);  // Create a new thread for threadFunc
    }


    
    

    for (int i=0; i< quant; i++)
        pthread_join(thread_group[i], NULL);  // waiting to join thread "one" without status



    printf("%lld\n",SALDO);
    return 0;
}