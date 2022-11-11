#include <saveLogThread.h>

void saveLog(void *arguments)
{
    struct ThreadArgs *args = (struct ThreadArgs *)arguments;
    ChatMsg clientMsg1 = *(args->clientMsg1);
    ChatMsg clientMsg2 = *(args->clientMsg2);
    sem_t* isReceived1 = args->isReceived1;
    sem_t* isReceived2 = args->isReceived2;
    pthread_mutex_t *mutex1 = args->mutex1;
    pthread_mutex_t *mutex2 = args->mutex2;

    time_t tcurrent;
    char filename[50] = "chatlog";

    int fd = open( filename, O_RDWR|O_CREAT|O_APPEND, 0666);
    char log[400];
    int writed1, writed2= 0;
    sem_wait(isReceived1);
    if(writed1==0){
        tcurrent = time(NULL);
        char* timeString = ctime(&tcurrent);
        dprintf(fd, "[%s -> %s : %s] :%s\n", clientMsg1.sender, clientMsg1.receiver, timeString, clientMsg1.content);
        writed1=1;
        sem_post(isReceived1);
    }
    sem_wait(isReceived2);
    if(writed2==0){
        tcurrent = time(NULL);
        char* timeString = ctime(&tcurrent);
        dprintf(fd, "[%s -> %s : %s] : %s\n", clientMsg2.sender, clientMsg2.receiver, timeString, clientMsg2.content);
        writed2=1;
        sem_post(isReceived2);
    }
    
    

}