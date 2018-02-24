#include "elev.h"
#include "timer.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int last_stop_button;
int last_floor_visited = -9;

int main() {
	
    /* Initializing hardware. This will return an error if the initializing is not sucsessful. 
       If successful, the lift will start driving upwards.  */
	
    if (!elev_init()) 
    {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }

    printf("Press STOP button to stop elevator and exit program.\n");
    elev_set_motor_direction(DIRN_UP);
	


    /* CONTINOUS LOOP: The system will continously check if one of the following cases has occurred: 
    	Change direction at top/bottom floor
	Stop button is pushed
	Elevator order buttons are pushed
	Arrival@floor
	Timer is up (door closing) */
	
    while (1)
    	{
        	// Change direction when the elevator reaches top/bottom floor.
        	if (elev_get_floor_sensor_signal() == N_FLOORS - 1)
			elev_set_motor_direction(DIRN_DOWN);
        	else if (elev_get_floor_sensor_signal() == 0) 
           		elev_set_motor_direction(DIRN_UP);
        

        	/* Stop elevator: Check if the button is pushed(1) or released(0). If the state of the button has changed,
	    	   the code will run the fsm_event_stop_pressed() or fsm_event_stop_released() code accordingly
		   and put the elevator in idle state.  */
	    
        	int stopbtn = elev_get_stop_signal();
       		if(stopbtn != last_stop_button)
		{
           		if(stopbtn)
          			fsm_event_stop_pressed();
            		else 
                		fsm_event_stop_released();
            	}
        
        	last_stop_button = stopbtn;
          
        
        	/*Elevator order: With a double loop, all order buttons are continuously checked. If a button is pushed
		  fsm_event_order_button_pressed(buttontype, buttonfloor) will be run. The code will also check if the lift
		  is already at the ordered floor.  */
	    
        	int buttonfloor;
        	elev_button_type_t buttontype;
	    
       		for (buttonfloor = 0; buttonfloor < N_FLOORS; buttonfloor++){
        		for(buttontype = 0; buttontype < N_BUTTONS; buttontype++)
			{
            			
				int test = elev_get_button_signal(buttontype,buttonfloor);
            			if (test)
					{
            					fsm_event_order_button_pressed(buttontype, buttonfloor);
						if (buttonfloor == last_floor_visited)
							{fsm_event_arrived_at_floor(last_floor_visited);}
						
					}
        		}
       		}
        
	    
        	/* Arrived@Floor: Elev_get_floor_sensor_signal returns -1 while not at a floor. If the lift has arrived a floor,
	    	   it will return the floornumber (0-3).  */
	    
          	int floor = elev_get_floor_sensor_signal();
	    
           	if(floor != last_floor_visited  &&  floor != -1)       
			{fsm_event_arrived_at_floor(floor);}
           		
	    	last_floor_visited = floor;
	    
        
       		/* Door closing: This part of the code checks if the time is up, and closes the door if the time is up */
	    
		if (timer_isTimeOut())
			{fsm_event_door_closed();}
		
    	}
            
            
        }
   
    return 0;
}
