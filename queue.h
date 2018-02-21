#include "channels.h"
#include "elev.h"
#include "io.h"


#include <assert.h>
#include <stdlib.h>
#include <time.h>


//Variable: 
int orders[][];

//Funksjoner:

//elev_button_type_t er en enum: BUTTON_CALL_UP=0, BUTTON_CALL_DOWN=1, BUTTON_COMMAND=2
void queue_add_to(int floor,elev_button_type_t buttons);

bool queue_check_floor_orders(int floor);

void queue_clear_orders_at_floor( int floor);

void queue_clear_all_orders();

int queue_get_new_direction(int previous_direction, int previous_floor);

//Sets the motor direction of the elevator: elev_motor_direction_t is enum: DIRN_DOWN=-1, DIRN_STOP=0, DIRN_UP=1
int queue_stop(int floor, elev_button_type_t buttons);
