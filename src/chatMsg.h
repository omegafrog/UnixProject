#ifndef __CHAT_MSG_H__
#define __CHAT_MSG_H__

#define MAX_USERNAME_SIZE 20
#define MAX_CONTNET_SIZE 300

typedef struct ChatMsg{
    char sender[MAX_USERNAME_SIZE];
    char receiver[MAX_USERNAME_SIZE];
    char content[MAX_CONTNET_SIZE];
}ChatMsg;
#endif