//sanket ADC
#include<stdio.h>
#include "LPC17xx.h"
#include "lcd.h"
#include "adc.h"
#

int main()
{
	// variable declaration
	uint32_t x=0;
	char str[20];
		// function init
	SystemInit();
	LCDInit();
	ADCinit();

	enterdata(line1,"Hakuna MAtata!!");
	while (1)
	 {
		 x=adc_read();
		 sprintf(str,"value = %04lu",x);
		 enterdata(line2,str);
		 SW_DELAY_MS(500);
		/* code */
	}
}
