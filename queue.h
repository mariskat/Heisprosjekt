#include "channels.h"
#include "elev.h"
#include "io.h"


#include <assert.h>
#include <stdlib.h>

//FUNKSJONER FRA ELEV.C

/*

typedef enum tag_elev_lamp_type { 
    BUTTON_CALL_UP = 0,
    BUTTON_CALL_DOWN = 1,
    BUTTON_COMMAND = 2
} elev_button_type_t;

*/

//Variable: 
int orders[][];

//Funksjoner:
void add_to_queue(floor,type);
bool check_floor_orders();
void clear_orders_at_floor();
void clear_all_orders();
bool get_new_direction();
