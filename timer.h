#include "channels.h"
#include "elev.h"
#include "io.h"

#include <assert.h>
#include <stdlib.h>

//Variable: 
int timer_ value;

//Funksjoner:
void timer_start();
void timer_stop();
bool timer_timeIsUp();
