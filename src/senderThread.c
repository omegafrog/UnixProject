#include <senderThread.h>

void sender(void *arguments)
{
    struct ThreadArgs *args = (struct ThreadArgs *)arguments;
    pthread_mutex_t *mutex1 = args->mutex1;
    pthread_mutex_t *mutex2 = args->mutex2;
    sem_t *isReceived1 = args->isReceived1;
    sem_t *isReceived2 = args->isReceived2;

    ChatMsg *clientMsg1 = args->clientMsg1;
    ChatMsg *clientMsg2 = args->clientMsg2;

    ChatMsg buffer;

    int srv2Cli1 = msgget(MSG_SRV_CLI1_KEY, 0666);
    int srv2Cli2 = msgget(MSG_SRV_CLI2_kEY, 0666);
    int cli12Srv = msgget(MSG_CLI1_SRV_KEY, 0666);
    int cli22Srv = msgget(MSG_CLI2_SRV_KEY, 0666);

    for (;;)
    {
        int size = 0;
        if ((size = msgrcv(cli12Srv, &buffer, sizeof(ChatMsg), MSG_TO_SRV, 0)) > 0)
        {
            pthread_mutex_lock(mutex1);
            printf("Recieve msg from client1-size:%d\n", size);
            memcpy(clientMsg1, &buffer,sizeof(ChatMsg));
            sem_post(isReceived1);
            msgsnd(srv2Cli2, clientMsg1, sizeof(ChatMsg), MSG_TO_CLI);
            pthread_mutex_unlock(mutex1);
        }
        pthread_mutex_lock(mutex2);
        if ((size = msgrcv(cli22Srv, clientMsg2, sizeof(ChatMsg), MSG_TO_SRV, 0)) > 0)
        {
            printf("Recieve msg from client2-size:%d\n", size);
            sem_post(isReceived2);
            msgsnd(srv2Cli1, clientMsg2, sizeof(ChatMsg), MSG_TO_CLI);
        }
        pthread_mutex_unlock(mutex2);
    }
}