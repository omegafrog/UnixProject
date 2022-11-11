#ifndef __THREAD_ARGS_H__
#define __THREAD_ARGS_H__

#include <msg.h>
#include <msgQueue.h>
struct ThreadArgs{
    pthread_mutex_t* mutex1;
    pthread_mutex_t* mutex2;
    sem_t* isReceived1;
    sem_t* isReceived2;
    ChatMsg* clientMsg1;
    ChatMsg* clientMsg2;
};

#endif