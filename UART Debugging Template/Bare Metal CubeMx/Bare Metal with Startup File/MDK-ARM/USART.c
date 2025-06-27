#include "USART.h"

void UART2_Config(void)
{
	GPIOA->MODER &= ~((3<<4) | (3<<6));
	GPIOA->MODER |= (2<<4) | (2<<6);
	GPIOA->OSPEEDR |= (3<<4) | (3<<6);
	GPIOA->AFR[0] |= (1<<8) | (1<<12);
	
	RCC->APBENR1 |= (1<<17);
	
	USART2->CR1 = 0;
	
	USART2->CR1 &= ~((1 << 12) | (1<<28));
	
	USART2->CR2 &= ~((1<<13) | (1<<12));
	
	USART2->BRR = 417;
	
	USART2->CR2 &= ~((1<<13) | (1<<12));
	
	USART2->CR1 |= (1<<0);
	
	USART2->CR1 |= (1<<2) | (1<<3);
}

void UART2_PutC(char letter)
{
	while((USART2->ISR & (1<<7)) == 0);
	
	USART2->TDR = 0x000000ff & letter;
}

void UART2_PutS(char* message)
{
	while(*message)
	{
		UART2_PutC(*message++);
	}
	
	while ((USART2->ISR & (1<<6)) == 0);
}