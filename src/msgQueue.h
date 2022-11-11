#ifndef __MSGQUEUE_H__
#define __MSGQUEUE_H__
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_QUEUE_CAPACITY 50
#define MSG_SRV_CLI1_KEY 60080
#define MSG_SRV_CLI2_kEY 60081
#define MSG_CLI1_SRV_KEY 60082
#define MSG_CLI2_SRV_KEY 60083


#define MSG_TO_SRV 1
#define MSG_TO_CLI 2

#endif