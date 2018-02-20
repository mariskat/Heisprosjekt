#include "elev.h"
#include "light.h"
#include "buttons.h"
#include "elevator.h"
#include "timer.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    // Initialize hardware

    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }

    printf("Press STOP button to stop elevator and exit program.\n");

    elev_set_motor_direction(DIRN_UP);

    while (1) {
        // Change direction when we reach top/bottom floor
        if (elev_get_floor_sensor_signal() == N_FLOORS - 1) {
            elev_set_motor_direction(DIRN_DOWN);
        } else if (elev_get_floor_sensor_signal() == 0) {
            elev_set_motor_direction(DIRN_UP);
        }

        // Stop elevator and exit program if the stop button is pressed
        if (elev_get_stop_signal()) {
            elev_set_motor_direction(DIRN_STOP);
            break;
          
        
        //overordnet buttonsfunksjon
        
        //Arrived@Floor
            //
            int current_floor = elev_get_floor_sensor_signal(void);
            elev_set_floor_indicator(current_floor);
            if (check_floor_orders()){
                elev_set_motor_direction(DIRN_STOP);
                clear_orders_at_floor();
                elev_set_door_open_lamp(1);                 //Wait 3 seconds
                elev_set_motor_direction(queue.get_new_direction());  //Reevaluvates most efficient direction
            }
            
            
        }
    }

    return 0;
}
