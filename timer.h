#include "channels.h"
#include "elev.h"
#include "io.h"

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>


static 
  clock_t start_time = -1;                 //Static - da bevarer den verdien ute av scope. Døren er i utgangspunktet lukket: -1. 

//Using time() in seconds to set start_time
void 
timer_start(void);


//Failing start_time (=-1)
void 
timer_stop(void);


//Returns true if 3 seconds (or more) has passed. If not - or door is closed - returns false. 
bool 
timer_timeIsUp(void);

