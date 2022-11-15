#ifndef __PRINT_RCV_H__
#define __PRINT_RCV_H__

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>
#include "../header/msg.h"
#include "../header/msgQueue.h"
#include "../util/queue.h"

void *printReceived(void* arguments);

#endif