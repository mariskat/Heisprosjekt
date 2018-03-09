#include "channels.h"
#include "elev.h"
#include "io.h"

#include <assert.h>
#include <stdlib.h>
#include <time.h>


/*DIRN_DOWN=-1, DIRN_STOP=0,DIRN_UP=1	
  BUTTON_CALL_UP=1, BUTTON_CALL_DOWN=-1, BUTTON_COMMAND=2 */


//Sets the motor direction of the elevator: elev_motor_direction_t is enum: DIRN_DOWN=-1, DIRN_STOP=0, DIRN_UP=1
int 
queue_stop(int floor, elev_button_type_t buttons);

//Add orders to queue by setting the "order-placement" in the array to 1
void 
queue_add_to(int floor,elev_button_type_t buttons);

//Returns true if there is an order at the floor
bool 
queue_check_floor_orders(int floor);

//Clears the order in the current floor
void 
queue_clear_orders_at_floor( int floor);

//Clears the lights in the current floor
void 
queue_clear_lights_at_floor( int floor);

//Clears all the previous orders
void 
queue_clear_all_orders();

//Returns true if the elevator should stop in the current floor (prioritizing the orders)
bool 
queue_elevator_should_stop(int currentFloor, elev_button_type_t buttons);

//Returns true if there is an order below the current floor
bool 
queue_orders_downward(currentFloor);
  
//Returns true if there is an order above the current floor
bool 
queue_orders_upward(currentFloor);

//Considers the scenarion of double-ordering: Returns true if there already is an order at the floor
bool 
queue_double_order(elev_button_type_t button, int floor);

//Gets new direction
elev_motor_direction_t 
queue_get_new_direction(int last_dirn, int floor);
