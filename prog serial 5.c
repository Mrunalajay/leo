program hello world serial
#include "LPC17xx.h"
 #define FOSC    12000000             
#define FCCLK   (FOSC  * 8)         
#define FCCO    (FCCLK * 3)        
#define FPCLK   (FCCLK / 4)        
 #define UART0_BPS     9600                   
 void UART0_Init (void)
 {
 unsigned int usFdiv;
 LPC_PINCON->PINSEL0 |= (1 << 4);           
LPC_PINCON->PINSEL0 |= (1 << 6);           
LPC_UART0->LCR  = 0x83;                          
usFdiv = (FPCLK / 16) / UART0_BPS;          
LPC_UART0->DLM  = usFdiv / 256;
 LPC_UART0->DLL  = usFdiv % 256; 
LPC_UART0->LCR  = 0x03;                    
LPC_UART0->FCR  = 0x06;       
}
 int UART0_SendByte (int ucData)
 {
 while (!(LPC_UART0->LSR & 0x20));
 return (LPC_UART0->THR = ucData);
 }
 void UART0_SendString (unsigned char *s) 
{
 while (*s != 0) 
UART0_SendByte(*s++);
 }
 int main(void)
 {
 UART0_Init();
 UART0_SendString("HELLO WORLD !!!");
 UART0_SendByte(0x0D); UART0_SendByte(0x0A); 
 }
