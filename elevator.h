#include "channels.h"
#include "elev.h"
#include "io.h"
#include "queue.h"

#include <assert.h>
#include <stdlib.h>

/*Included from elev.h:

Sets the motor direction of the elevator: elev_motor_direction_t is enum: DIRN_DOWN=-1, DIRN_STOP=0, DIRN_UP=1
void elev_set_motor_direction(elev_motor_direction_t dirn);

Get floor sensor signal: Not on floor = -1, On floor = 0-3 (ground fl.- top fl.)
int elev_get_floor_sensor_signal(void);
*/

//elev_button_type_t er en enum: BUTTON_CALL_UP=0, BUTTON_CALL_DOWN=1, BUTTON_COMMAND=2
int elev_get_button_signal(elev_button_type_t button, int floor);
