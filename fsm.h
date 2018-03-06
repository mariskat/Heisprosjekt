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


/* Order button is pushed: This function takes the button type and the floor of the button pushed as arguments. The order is added
   to the queue and the according lights are set. If the lift is in IDLE and the order is not for the current floor, the lift will 
   drive to floor immediatley and the state will changed to MOVING. Or else, the state will be changed to DOOROPEN and the door light
   will be set. If the lift is busy (MOVING or DOOR OPEN) it will only set the lights and add the order to the queue. If the lift is
   STOPBETWEENFLOORS, the order will be added to queue and evaluvate which direction the lift should drive.   */

void 
fsm_event_order_button_pressed();


/* Arrived@floor: Given the current floor and the current state of the lift, this function will evaluvate which way the lift should
   drive. When the current state is INITIALIZE, the lift will stop at the first floor reached and change state to idle. If the lift arrives a floor while
   MOVING, the queue_should_stop() code will check if there are any orders at the floor in the right direction and stop accordingly. 
   If the the lift is already at the floor (DOOROPEN or IDLE) the door light will be set. */
void 
fsm_event_arrived_at_floor(int new_floor);


/* When the state of the lift is DOOROPEN, this function will close the door and set the direction of the lift the same as the
   previous direction and set the state accordingly to IDLE or MOVING  */
void 
fsm_event_door_closed();
