#include "channels.h"
#include "elev.h"
#include "io.h"
#include "queue.h"

#include <assert.h>
#include <stdlib.h>

 
//Variable
bool previous_dir;
bool previous_floor;
bool door_open;


//Funksjoner
int arrived_at_floor();
void motor_start();
void motor_stop();
void set_direction();
void get_current_dir();


//elev_button_type_t er en enum: BUTTON_CALL_UP=0, BUTTON_CALL_DOWN=1, BUTTON_COMMAND=2
int elev_get_button_signal(elev_button_type_t button, int floor);
