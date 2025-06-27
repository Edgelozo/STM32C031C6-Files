#ifndef USART_H_
#define USART_H_

#include "stm32c031xx.h"

void UART2_Config(void);
void UART2_PutC(char letter);
void UART2_PutS(char* message);
	
#endif