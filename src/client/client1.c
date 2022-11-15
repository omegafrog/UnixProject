#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>

#include "../header/msgQueue.h"
#include "../header/msg.h"
#include "../util/queue.h"

#include "senderClientThread.h"
#include "printReceivedThread.h"
#include "getServerInputThread.h"
#include "managerThread.h"

Msg received;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
struct QueueDatum datum;
sem_t sem;
Queue q;
int receivedKey;
int sendKey;
int id;
pthread_t getServerThread;
pthread_t managerThread;
pthread_t senderThread;
pthread_t printReceivedThread;

void sig_handler(int signo){
    msgctl(receivedKey, IPC_RMID,NULL);
    msgctl(sendKey, IPC_RMID, NULL);
}

int main()
{


    sem_init(&sem, 0, 0);
    init(&q);
    receivedKey = msgget(MSG_SRV_CLI1_KEY, IPC_CREAT | 0660);
    sendKey = msgget(MSG_CLI1_SRV_KEY, IPC_CREAT | 0660);
    id = 1;

    pthread_create(&getServerThread, NULL, getServerInput, NULL);

    pthread_create(&managerThread, NULL, manage, NULL);

    pthread_create(&senderThread, NULL, senderClient, NULL);

    pthread_create(&printReceivedThread, NULL, printReceived, NULL);

    pthread_join(getServerThread, NULL);
    pthread_join(managerThread, NULL);
    pthread_join(senderThread, NULL);
    pthread_join(printReceivedThread, NULL);
    signal(SIGINT, sig_handler);
}