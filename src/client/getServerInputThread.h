#ifndef __SRV_INPUT_H__
#define __SRV_INPUT_H__

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "../header/msg.h"
#include "../header/msgQueue.h"
#include "../util/queue.h"

void *getServerInput(void* arguments);

#endif