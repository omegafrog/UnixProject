#include "senderClientThread.h"
extern int sendKey;
extern int id;

void *senderClient(void *arguments)
{
    Msg msg;

    while (1)
    {
        printf("[client%d]:", id);
        scanf("%s", msg.msg);
        msg.mtype = MSG_TO_SRV;
        int status = 0;

        if ((status = msgsnd(sendKey, &msg, sizeof(Msg), 0)) == 0)
        {
            #ifdef DEBUG
            printf("successful\n");
            #endif
        }
    }
}