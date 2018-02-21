#include "queue.h"


int orders[4][3]={
  {0,0,0},
  {0,0,0},
  {0,0,0},
  {0,0,0}
};

//Funksjoner:

//Given floor and buttontype, this function sets the following button to 1 in queue.
void queue_add_to(int floor, elev_button_type_t button){
  orders[floor][button]={1};
};    

//Sums the orders of the floor, returns 0 if no orders, 1 if else.
bool queue_check_floor_orders(int floor){
  return (orders[floor][0]+orders[floor][1]+orders[floor][2]);
};

//Clears floor orders
void queue_clear_orders_at_floor(int floor){
  orders[floor]={0,0,0};
};

elev_motor_direction_t queue_get_new_direction(){
  TILSTANDSMASKIN????
};


void queue_clear_all_orders(){
 
  ;

int queue_stop(int floor, elev_button_type_t buttons);
