#include"adc.h"
#include"LPC17xx.h"

void ADCinit(void)
{
LPC_SC->PCONP |=BV(PCONP_PCADC);

LPC_PINCON->PINSEL1 &= ~(BV(19) |BV(18)); //clear the pinsl bit of ADC2
LPC_PINCON->PINSEL1 |= BV(18); //setting pinsel for ADC

LPC_ADC->ADCR =((CLKDIV-1) << ADCR_CLKDIV) | BV(ADCR_CHN2);//USER manual
LPC_ADC->ADCR |= BV(ADCR_PDN);

}
uint32_t adc_read(void)
{
  uint32_t dr;
LPC_ADC ->ADCR |= BV(ADCR_START0);

do{

  dr=LPC_ADC->ADGDR;

  }while(!(dr & BV(ADGR_DONE)));

return((dr >> ADGR_RESULT) & RESULT_MASK);
}
