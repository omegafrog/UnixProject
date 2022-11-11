#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#include <senderThread.h>
#include <saveLogThread.h>

ChatMsg* clientMsg1=NULL;
ChatMsg* clientMsg2=NULL;
sem_t isReceived1;
sem_t isReceived2;
pthread_mutex_t mutex1= PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2= PTHREAD_MUTEX_INITIALIZER;


void sender(void *arguments);


int main(){
    sem_init(&isReceived1,0,0);
    sem_init(&isReceived2,0, 0);
    pthread_t senderThread;
    struct ThreadArgs args = {&mutex1,&mutex2, &isReceived1,&isReceived2, clientMsg1, clientMsg2};
    pthread_create(senderThread, NULL, sender, (void *)&args);
    pthread_t saveLogThread;
    pthread_create(saveLogThread, NULL, saveLog,(void *)&args);
        



    pthread_exit(NULL);
}



