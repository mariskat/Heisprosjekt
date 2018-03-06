

/* We define an enum named state_t for the different possible states for the lift. 
   Hereafter, we create a variable of this enum named current_state which will hold the current state of the lift
   through the whole system  */

typedef enum
{
	INITIALIZE,
	IDLE,
	MOVING,
	DOOROPEN,
	EMERGENCYSTOP,
	STOPBETWEENFLOORS
} state_t;

state_t current_state = INITIALIZE;
int currentFloor;
elev_motor_direction_t direction;



/* Arrived@floor: Given the current floor and the current state of the lift, this function will evaluvate which way the lift should
   drive. When the current state is INITIALIZE, the lift will stop at the first floor reached and change state to idle. If the lift arrives a floor while
   MOVING, the queue_should_stop() code will check if there are any orders at the floor in the right direction and stop accordingly. 
   If the the lift is already at the floor (DOOROPEN or IDLE) the door light will be set. */

void 
fsm_event_arrived_at_floor(int new_floor)
{
	currentFloor = new_floor;
	 
	switch(current_state)
	{
			
		case INITIALIZE:
			elev_set_motor_direction(DIRN_STOP);
			elev_set_floor_indicator(currentFloor);
			current_state = IDLE;
			break;

		case IDLE:		
		case DOOROPEN:
			elev_set_door_open_lamp(1);
			queue_clear_orders_at_floor(currentFloor);
			queue_clear_lights_at_floor(currentFloor);
			timer_start();                	
			break;

		case MOVING:
			elev_set_floor_indicator(currentFloor);

			if(queue_should_stop(currentFloor, direction))
			{
				elev_set_motor_direction(DIRN_STOP);
				elev_set_door_open_lamp(1);
				queue_clear_orders_at_floor(currentFloor);
				queue_clear_lights_at_floor(currentfloor);
				timer_start();
				current_state = DOOROPEN;
			}
			break;

		default:
			break;
	}
}



/* Order button is pushed: This function takes the button type and the floor of the button pushed as arguments. The order is added
   to the queue and the according lights are set. If the lift is in IDLE and the order is not for the current floor, the lift will 
   drive to floor immediatley and the state will changed to MOVING. Or else, the state will be changed to DOOROPEN and the door light
   will be set. If the lift is busy (MOVING or DOOR OPEN) it will only set the lights and add the order to the queue. If the lift is
   STOPBETWEENFLOORS, the order will be added to queue and evaluvate which direction the lift should drive.   */


void 
fsm_event_order_button_pressed(elev_button_type_t button, int floor)
{ 
	switch(current_state)
	{
        	case IDLE:

        	if (floor!=currentFloor)
		{
				queue_add_to_queue(button, floor);
				elev_set_button_lamp(button, floor, 1); 
				direction = queue_get_direction(previous_direction, currentFloor);
				elev_set_motor_direction(direction);
				previous_direction = direction;
				current_state = MOVING;
		}		
		else
		{
				elev_set_door_open_lamp(1);
				timer_start();
				current_state = DOOROPEN;
			
		} 
		break;
			
		case DOOROPEN:
		case MOVING:
			queue_add_orders(button, floor);
			elev_set_button_lamp(button, floor, 1);
			break;

		case STOPBETWEENFLOORS:
			queue_add_orders(button, floor);
			elev_set_button_lamp(button, floor, 1);

			if (floor==currentFloor)
			{	
				elev_set_motor_direction(-(previous_direction));
			}
			else 
			{	
				direction = queue_get_direction(previous_direction, currentFloor);
				elev_set_motor_direction(direction);
			}
			
			current_state = MOVING;
			break;

		default:
			break;
	}
	
	
/* Stop button is pressed: If the stop button is pushed, the lift will stop and the queue orders will be erased. If the lift is at
   a floor, the door will be open. The state will be changed to EMERGENCYSTOP. */	
	
void 
fsm_event_stop_pressed()
{ 
	switch(current_state)
	{
			
		case MOVING:
		case DOOROPEN:
		case STOPBETWEENFLOORS:
		case IDLE:
			elev_set_motor_direction(DIRN_STOP);
			queue_remove_all_orders();
			
			for(floorbtn = 0; floorbtn < N_FLOORS; floorbtn++){
				queue_clear_lights_at_floor(floorbtn);
			}
			
			elev_set_stop_lamp(1);

			if (elev_get_floor_sensor_signal() != -1)
				elev_set_door_open_lamp(1);

			current_state = EMERGENCYSTOP;
			break;

		default:
			break;
	}
}

/* Stop button is released: The stop button light will be turned off. If the lift is at a floor, the door wil stay open for another
   three seconds and the lift will be in IDLE. Or else, the lift will be set to STOPBETWEENFLOOR state*/
	
void 
fsm_event_stop_released()
{
	switch(current_state)
	{
		case EMERGENCYSTOP:
			elev_set_stop_lamp(0);

			if (elev_get_floor_sensor_signal() == -1)
			{
			current_state = STOPBETWEENFLOORS;
			}
			else 
			{
				elev_set_door_open_lamp(0);
				current_state = IDLE;
				timer_start();
			}
			break;

		default:
			break;
	}

/* When the state of the lift is DOOROPEN, this function will close the door and set the direction of the lift the same as the
   previous direction and set the state accordingly to IDLE or MOVING  */
	
void 
fsm_event_door_closed()
{
	switch(current_state)
	{
		case DOOROPEN:
			elev_set_door_open_lamp(0);
			direction = queue_get_direction(previous_direction, currentFloor);
			elev_set_motor_direction(direction);
			previous_direction = direction;

			if(direction!=DIRN_STOP)
			{
				current_state = MOVING;
			} 
			else 
			{
				current_state = IDLE;
			}		
			break;

		default:
			break;
	}		
}
	
