//Order-array
int orders[4][3]={
  {0,0,0},
  {0,0,0},
  {0,0,0},
  {0,0,0}
};

//Given floor and buttontype, this function sets the following button to 1 in queue.
void 
queue_add_to(int floor, elev_button_type_t button)
{
  orders[floor][button]={1};
};    

//Sums the orders of the floor, returns 0 if no orders, 1 if else.
bool 
queue_check_floor_orders(int floor)
{
  return (orders[floor][0]+orders[floor][1]+orders[floor][2]);
};

//Clears floor orders and lights
void 
queue_clear_orders_at_floor(int floor)
{
  orders[floor]={0,0,0};
};

void 
queue_clear_lights_at_floor(int floor)
{
  elev_set_button_lamp(BUTTON_COMMAND, floor, 0);
	
  if (i != 0)
  elev_set_button_lamp(BUTTON_CALL_DOWN, floor, 0);

  if (i != N_FLOORS - 1)
  elev_set_button_lamp(BUTTON_CALL_UP, floor, 0);
};

//Clear all previous orders
void 
queue_clear_all_orders()
{
 		for(int i=0;i<=3;i++){
      for(int j=0;j<=4;j++){
        orders [j][i] = 0;
      }
    };
	
	
//PRIORITIZING THE ORDERS:
 
/*DIRN_DOWN=-1, DIRN_STOP=0,DIRN_UP=1	
  BUTTON_CALL_UP=1, BUTTON_CALL_DOWN=-1, BUTTON_COMMAND=2 */
	
//Check if there is an up-button pressed above the current floor
bool 
queue_orders_upward(int currentFloor)
{	
	for (int floor=currentFloor;floor<=3;floor++)
	{
		for (int order=0;order<=3;order++)
		{
			if (orders [floor][order]==1)
			{
				return true;
			}
		}
	}
	return false;
}
		
//Check if there is a down-button pressed above the current floor
bool 
queue_orders_downward(int currentFloor)
{
		for (int floor=currentFloor;floor<=3;floor--)
		{
		for (int order=3;order>=0;order--)
		{
			if (orders [floor][order]== -1)
			{
				return true;
			}
		}
	}
	return false;
}

//Check if the elevator should stop in the current floor or continue
bool 
queue_elevator_should_stop(int currentFloor, elev_motor_direction_t dirn)
{	
	
    if (orders[currentFloor][BUTTON_COMMAND] == 1)		//Stop the elevator if a commandbutton is pressed in this floor
    	{		
		return true; 
    	}
    if (dirn == DIRN_UP)					//If the elevator is moving in upwards direction
    {					
        if (orders[currentFloor][BUTTON_CALL_UP] == 1)		//If an up-button is pressed in this floor, stop the elevator
	{		
            return true;
	}
        if (queue_orders_upward(currentFloor))			//Keep moving if an up-button is pressed below the floor
	{			
            return false;
    	}
    }
    if (dirn == DIRN_DOWN)					//If the elevator is moving in downwards direction
    {					
        if (orders[currentFloor][BUTTON_CALL_DOWN] == 1)	//If a down-button is pressed in this floor, stop the elevator
	{	
            return true;
	}
        if (queue_orders_downward(currentFloor))		//Keep moving if a down-button is pressed below the floor
	{		
            return false;
	}
    }

    return true;
}

	
//Considering the scenario of double-ordering
bool 
queue_double_order(elev_button_type_t button, int floor)
{
	if (orders[floor][button]==1)
	{
		return true;
	}
	return false;
}
	

elev_motor_direction_t 
queue_get_new_direction(int last_dirn, int floor)
{
	if (last_dirn == DIRN_DOWN)			//If the previous direction was downwards
	{						
		if(queue_orders_down(floor))
		{
			return DIRN_DOWN;
		}
	}
	if (last_dirn == DIRN_UP)
	{
		if (queue_orders_upward(floor)
		  {
			return DIRN_UP;
		   }
		}
	if (queue_orders_downward(floor))
	{
		return DIRN_DOWN;
	}
	if (queue_orders_upward(floor)
	{
		return DIRN_UP;
	}
	return DIRN_STOP;
 }
