#include <LPC17xx.H>   
int main (void)  
{ 
LPC_GPIO4->FIODIR = 0x30000000 ;  
LPC_GPIO1->FIODIR&=~(0x0001C000); 
LPC_GPIO2->FIOSET =(1<<8);  
while(1) 
{ 
if (!(LPC_GPIO1->FIOPIN & (1<<14)))            
LPC_GPIO4->FIOPIN=0X10000000;                
if (!(LPC_GPIO1->FIOPIN &(1<<15)))             
LPC_GPIO4->FIOPIN=0X30000000;                
if (!( LPC_GPIO1->FIOPIN & (1<<16)))           
LPC_GPIO4->FIOPIN=0X20000000; 
}
 }
