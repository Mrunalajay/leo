program 5 led blink
#include <lpc17xx.h>
 void delay()
 {
 int i,j;
 for(i=0;i<0x4000;i++)
 for(j=0;j<0x400;j++);
 } 
int main (void)
 {  
LPC_GPIO0->FIODIR = 0x0000FF0;            
LPC_GPIO0->FIOCLR = 0x0000FF0;          
while(1)
 {
 LPC_GPIO0->FIOSET = 0x0000FF0;  
delay();
 LPC_GPIO0->FIOCLR = 0x0000FF0;
 delay();
 }
 }
