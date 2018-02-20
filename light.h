#include "channels.h"
#include "elev.h"
#include "io.h"
#include "timer.h"

#include <assert.h>
#include <stdlib.h>


//Funksjoner
void set_lights(floor,type);
void clear_lights_at_floor();
void door_open();
void door_close();
void set_floor_lights(floor);
void floor_indicator();
