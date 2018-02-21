#include "elev.h"
#include "io.h"

//FUNKSJONER FRA ELEV.C: 

//Door open or closed (1: open, 0: closed)
//void elev_set_door_open_lamp(int value);

//Stoplamp on or off (1:on, 0: off)
//void elev_set_stop_lamp(int value);

//Set buttonlight
//void elev_set_button_lamp(elev_button_type_t button, int floor, int value);

//Floor indicator
//void elev_set_floor_indicator(int floor);

//elev_button_type_t er en enum: BUTTON_CALL_UP=0, BUTTON_CALL_DOWN=1, BUTTON_COMMAND=2
int elev_get_button_signal(elev_button_type_t button, int floor);

void clear_lights_at_floor(floor){
  elev_set_button_lamp(BUTTON_CALL_DOWN, floor, 0);
  elev_set_button_lamp(BUTTON_CALL_UP, floor, 0);
  elev_set_button_lamp(BUTTON_COMMAND, floor, 0);
}
  //Implementeres vha trippel forløkke elev_set_button_lamp(a,b,0);

  


  
