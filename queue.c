#include "queue.h"


int orders[4][3]={
  {0,0,0},
  {0,0,0},
  {0,0,0},
  {0,0,0}
};

//Funksjoner:

//Given floor and buttontype, this function sets the following button to 1 in queue.
void add_to_queue(int floor, elev_button_type_t button){
  printf("Running add_to_queue");
  orders[floor][button]={1};
};    

//Sums the orders of the floor, returns 0 if no orders, 1 if else.
bool check_floor_orders(int floor){
  printf("Running check_floor_orders");
  return (orders[floor][0]+orders[floor][1]+orders[floor][2]);
};

//Clears floor orders
void clear_orders_at_floor(int floor){
  printf("Running clear_orders_at_floor");
  orders[floor]={0,0,0};
  printf("Done clear_orders_at_floor");
};

elev_motor_direction_t get_new_direction(){
  TILSTANDSMASKIN????
};
