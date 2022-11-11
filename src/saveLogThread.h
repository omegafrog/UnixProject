#ifndef __SAVE_LOG_H__
#define __SAVE_LOG_H__

#include <stdio.h>
#include <stdlib.h>
#include <msg.h>
#include <msgQueue.h>
#include <threadArgs.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>

void saveLog(void* arguments);


#endif