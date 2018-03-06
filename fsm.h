#include "elev.h"
#include "queue.h"
#include "timer.h"

#include <stdio.h>

/* Stop button is pressed: If the stop button is pushed, the lift will stop and the queue orders will be erased. If the lift is at
   a floor, the door will be open. The state will be changed to EMERGENCYSTOP. */	
void 
fsm_event_stop_pressed();


/* Stop button is released: The stop button light will be turned off. If the lift is at a floor, the door wil stay open for another
   three seconds and the lift will be in IDLE. Or else, the lift will be set to STOPBETWEENFLOOR state*/
void 
fsm_event_stop_released();


/* Order button is pushed: Sets order and according lights. If in idle: drive to floor immediately (moving state). If not: dooropen state. 
   If busy: Set lights and add to order. If STOPBETWEENFLOORS: Add order to queue and evaluate best direction. */

void 
fsm_event_order_button_pressed();


/* Arrived@floor: Given the current floor and the current state of the lift, this function will evaluate which way the lift should
   drive. */
void 
fsm_event_arrived_at_floor(int new_floor);


/* When the state of the lift is DOOROPEN, this function will close the door and set the direction of the lift the same as the
   previous direction and set the state accordingly to IDLE or MOVING  */
void 
fsm_event_door_closed();
