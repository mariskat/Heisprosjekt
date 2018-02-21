#include "channels.h"
#include "elev.h"
#include "io.h"


#include <assert.h>
#include <stdlib.h>



//Variable: 
int orders[][];

//Funksjoner:

//elev_button_type_t er en enum: BUTTON_CALL_UP=0, BUTTON_CALL_DOWN=1, BUTTON_COMMAND=2
void add_to_queue(int floor,elev_button_type_t buttons);

bool check_floor_orders();

void clear_orders_at_floor( int floor);

void clear_all_orders();

int get_new_direction(int previous_direction, int previous_floor);

//Sets the motor direction of the elevator: elev_motor_direction_t is enum: DIRN_DOWN=-1, DIRN_STOP=0, DIRN_UP=1
int stop_queue(int floor, elev_button_type_t buttons);


