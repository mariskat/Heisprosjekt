#include "elev.h"
#include "light.h"
#include "buttons.h"
#include "elevator.h"
#include "timer.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int last_stop_button;
int last_floor_visited = -9;

int main() {
    //  INITIALIZING HARDWARE
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }

    printf("Press STOP button to stop elevator and exit program.\n");

    elev_set_motor_direction(DIRN_UP);

    // CONTINOUS LOOP
    while (1) {
        // Change direction when we reach top/bottom floor
        if (elev_get_floor_sensor_signal() == N_FLOORS - 1) {
            elev_set_motor_direction(DIRN_DOWN);
        } else if (elev_get_floor_sensor_signal() == 0) {
            elev_set_motor_direction(DIRN_UP);
        }

        // Stop elevator and exit program if the stop button is pressed
        int stopbtn = elev_get_stop_signal();
        if(stopbtn != last_stop_button){
            if(stopbtn){
                fsm_event_stop_pressed();
            } else {
                fsm_event_stop_released();
            }
        }
        last_stop_button = stopbtn;
          
        
        //Elevator order
        int buttonfloor;
        int buttontype;
        for (buttonfloor = 0; buttonfloor < N_FLOORS; buttonfloor++){
        	for(buttontype = 0; buttontype < N_BUTTONS; buttontype++){
            	int test = elev_get_button_signal(buttontype,buttonfloor);
            	if (test){
            		fsm_event_order_button_pressed(buttontype, buttonfloor);
					if (buttonfloor == last_floor_visited){
						fsm_event_arrived_at_floor(last_floor_visited);
					}
				}
        	}
        }
        
        //Arrived@Floor
            int floor = elev_get_floor_sensor_signal();
            if(floor != last_floor_visited  &&  floor != -1){           //elev_get_floor_sensor_signal returns -1 while not at a floor
                fsm_event_arrived_at_floor(floor);
            }
            last_floor_visited = floor;
        
        
            }
            
            
        }
    }

    return 0;
}
