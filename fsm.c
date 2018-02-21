#include "elev.h"
#include "fsm.h"
#include "queue.h"
#include "timer.h"

#include <stdio.h>

/*Included from elev.h:

Sets the motor direction of the elevator: elev_motor_direction_t is enum: DIRN_DOWN=-1, DIRN_STOP=0, DIRN_UP=1
void elev_set_motor_direction(elev_motor_direction_t dirn);

Get floor sensor signal: Not on floor = -1, On floor = 0-3 (ground fl.- top fl.)
int elev_get_floor_sensor_signal(void);
*/

typedef enum{
	INITIALIZE,
	IDLE,
	MOVING,
	DOOROPEN,
	EMERGENCYSTOP,
	STOPBETWEENFLOORS
} state_t;

state_t currentstate = INITIALIZE;

