#include <stdint.h>
#include "uart.h"
#include "gpio.h"

#define A 17
#define B 26

int main(){

	// Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons
	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;
	
	int led_matrix_on = 0;

	
	
	int sleep = 0;
	uart_init();
	while(1){
	

        if(!(GPIO->IN & (1<<A)))
        {   
            uart_send('A');     
        }
        
        if(!(GPIO->IN & (1<<B)))
        {
            uart_send('B');
        }
        
        
        if(uart_read() != '\0')
        {
            if(!led_matrix_on)
            {
            GPIO->OUTSET = (1 << 13);
			GPIO->OUTSET = (1 << 14);
			GPIO->OUTSET = (1 << 15);
			led_matrix_on=1;
			}
			else
			{
			GPIO->OUTCLR = (1 << 13);
			GPIO->OUTCLR = (1 << 14);
			GPIO->OUTCLR = (1 << 15);
			led_matrix_on=0;
			}
			
        }
       
        
		sleep = 10000;
		while(--sleep);
	}
	
	return 0;
}


//Regnet ut verdien under ved å trekke 0x520 fra 0x700, regne om til desimalverdi, og dele på 4
