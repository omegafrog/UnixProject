#ifndef __MSG_H__
#define __MSG_H__

#include <chatMsg.h>

#define MAX_MSG_QUEUE_SIZE 300

typedef struct Msg{
    long mtype;
    ChatMsg msg;
}Msg;

#endif