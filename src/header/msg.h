#ifndef __MSG_H__
#define __MSG_H__

#define MAX_MSG_QUEUE_SIZE 300
#define MAX_CONTENT_SIZE 300
#define MAX_USERNAME_SIZE 50
typedef struct Msg{
    long mtype;
    char msg[MAX_CONTENT_SIZE];
}Msg;

#endif