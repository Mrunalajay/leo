 #include "lpc17xx.h“
 void delay()
 {
 int i,j;
 for(i=0;i<0x2000;i++)
 for(j=0;j<0x200;j++);
 }
 int main (void)
 {      
LPC_PINCON->PINSEL7 = 0X02000000;
 LPC_GPIO0->FIODIR = 0X02000000; 
LPC_GPIO0->FIOCLR =0X02000000;
 while(1)
 {
 LPC_GPIO0->FIOSET =0X02000000;
 delay();
 LPC_GPIO0->FIOCLR =  0X02000000;
 delay();
 }
 }

 
