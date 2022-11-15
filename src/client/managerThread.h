#ifndef __MANAGER_CLI_H__
#define __MANAGER_CLI_H__
#include <pthread.h>
#include <semaphore.h>

#ifdef DEBUG
#include <stdio.h>
#endif

#include "../util/queue.h"
void* manage(void* arguments);

#endif