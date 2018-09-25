#ifndef __ADC_H
#define __ADC_H

#include "LPC17xx.h"

#define PCONP_PCADC 12      // setting PCON pn high

#define PCLK 18000000UL       // peri clock
#define CLKDIV 3            // prescalar 18MHz/3 = 6MHz
#define RESULT_MASK 0X0FFF

#define ADCR_CHN2  2      //select channel 2
#define ADCR_CLKDIV 8       // system clk divider
#define ADCR_BURST  16      //burst mode on if set
#define ADCR_PDN    21      //powerdown mode on if set
#define ADCR_START0 24      // start conversion
#define ADCR_START1 25      //
#define ADCR_START2 26      //

#define ADGR_RESULT   4     // starting bit of result
#define ADGR_OVERRUN  30    // over run bit
#define ADGR_DONE     31    // done flag bit

void ADCinit(void);
uint32_t adc_read(void);

#endif
