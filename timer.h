#include "channels.h"
#include "elev.h"
#include "io.h"

#include <assert.h>
#include <stdlib.h>
#include <time.h>

//Variable: 
static clock_t start_time = -1;                 //Static - da bevarer den verdien ute av scope. Døren er i utgangspunktet lukket: -1. 

//Funksjoner:

void timer_start(void);

void timer_stop(void);

bool timer_timeIsUp(void);






#endif /*timer.h*/
