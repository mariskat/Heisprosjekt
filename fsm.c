#include "elev.h"
#include "fsm.h"
#include "queue.h"
#include "timer.h"

#include <stdio.h>

typedef enum{
	INITIALIZE,
	IDLE,
	MOVING,
	DOOROPEN,
	EMERGENCYSTOP,
	STOPBETWEENFLOORS
} state_t;

state_t currentstate = INITIALIZE;

