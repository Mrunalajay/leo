square wave
#include <LPC17xx.H>
 #define voltage 1024
 #define freq 120000
 int main (void)
 {
 uint32_t m;
 LPC_PINCON->PINSEL1 |= (1<<21);
 while(1)
 {
 LPC_DAC->DACR = (voltage/2 << 6);
 for(m = freq; m > 1; m--);
 LPC_DAC->DACR = (voltage << 6);
 for(m = freq; m > 1; m--);
 }
 }

triangle wave

 #include <LPC17xx.H>
 #define voltage 1024
 int main (void)
 {
 uint32_t i = 0;
 LPC_PINCON->PINSEL1 |= (1<<21);
 while(1)
 {
 for(i = 0; i < voltage; i++)
 LPC_DAC->DACR = (i << 6);
 for(i = voltage; i > 0; i--)
 LPC_DAC->DACR = (i << 6);
 }
 }
