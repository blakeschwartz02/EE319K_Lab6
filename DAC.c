// DAC.c
// This software configures DAC output
// Lab 6 requires a minimum of 4 bits for the DAC, but you could have 5 or 6 bits
// Runs on TM4C123
// Program written by: Chloe Tang, Blake Schwartz
// Date Created: 3/6/17 
// Last Modified: 1/17/21 
// Lab number: 6
// Hardware connections
#include "dac.h"   // TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data

// **************DAC_Init*********************
// Initialize 4-bit or 6-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void){
	// write this
	SYSCTL_RCGCGPIO_R |= 0x02; // Port B 
	
	__asm__ {
		NOP
		NOP
	}

	GPIO_PORTB_DIR_R |= 0x3F; // make PB5-0 outputs 
	GPIO_PORTB_DEN_R |= 0x3F; // make PB5-0 digital 
	
}
	
	
// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// or     6-bit data, 0 to 63
// Input=n is converted to n*3.3V/15
// or Input=n is converted to n*3.3V/63
// Output: none
void DAC_Out(uint8_t data){
	// write this
	data = GPIO_PORTB_DATA_R; 
	data = (data*3.3)/15; 
}
