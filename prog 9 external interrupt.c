 PROGRAM:9 external interupt
 #include <lpc17xx.h>
 P2.27
 P1.28
 unsigned char data7[] = {0x88,0xeb,0x4c,0x49,0x2b,0x19,0x18,0xcb, 
0x8,0x9,0xa,0x38,0x9C,0x68,0x1c,0x1e};
 void intrupt_init()
 {
 LPC_PINCON->PINSEL4 = (1<<20);
 LPC_SC->EXTINT = (1<<0) ;
 LPC_SC->EXTMODE = (1<<0) ;
 LPC_SC->EXTPOLAR = (1<<0);
 }
 void EINT0_IRQHandler(void)
 {
 if (!(LPC_GPIO1->FIOPIN & (1<<14)))
 LPC_SC->EXTINT = (1<<0);
 }
 int main()
 {
 unsigned int i,j;
 unsigned int count=0;
 intrupt_init();
 LPC_SC->EXTINT = (1<<0);
 NVIC_EnableIRQ(EINT0_IRQn);
 LPC_GPIO2->FIODIR = 0x000000FF;
 LPC_GPIO1->FIODIR = 0x3C000000;
 LPC_GPIO1->FIOSET=(1<<29);
 LPC_GPIO1->FIODIR&=~(0x00008000);
 Disp1
 (D9)
 P1.29
 Page 44 
Department of ECE, Dr. AIT                                                                     
CO & ARM Lab Manual                                  
Sub Code: 21ECT602
 while(1)
 {
 ++count;
 if (count > 0xF)
 count = 0;
 for (i=0; i < 25000; i++)
 {
 LPC_GPIO2->FIOPIN = data7[count];
 for (j=0;j<1000;j++);
 } }
 }
