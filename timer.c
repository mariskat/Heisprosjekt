

//Start timer
void 
timer_start(void)                               //Start timer if the door is open
{                          
    start_time = time(NULL); 
}

// Stop timer
void 
timer_stop(void)                                //Return -1 for failure
{
    start_time = -1;                             
}
  
// Check if time is up (3 sec)
bool 
timer_ timeIsUp(void)
{
  
  if (start_time==-1)                            //Return false if the door is closed
  {                           
       return false;
  }
  
  if (time(NULL) - start_time > 3)                //Is the difference between the time right now and the starttime more than 3 sec? 
  {              
        return true;
  } 
    else 
  {
         return false;
  }
}
