#include "config.h"


void SysClock_Config(void)
{
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY));
	
	RCC->APBENR1 |= RCC_APBENR1_PWREN;
	
	FLASH->ACR |= FLASH_ACR_ICEN | FLASH_ACR_LATENCY_0;
	
	RCC->CFGR |= RCC_CFGR_SW_0;
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE);
}

void GPIO_Config(void)
{
	RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
	
	GPIOA->MODER &= ~GPIO_MODER_MODE5;  
	GPIOA->MODER |= GPIO_MODER_MODE5_0;  
	
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT5;  
	GPIOA->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED5;  
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD5;  
}	

void Timer_Config(void)
{
	RCC->APBENR1 |= (1<<1);
	
	TIM3->ARR = 0xfff - 1;
	TIM3->PSC = 48 - 1;
	TIM3->CR1 = 0;
	TIM3->CR1 |= (1<<0);
	
	while (!(TIM3->SR & (1<<0)));
}

void delay_us(uint32_t us) 
{
	TIM3->CNT = 0;
	while (TIM3->CNT < us);
}

void delay_ms(uint32_t ms)
{
	for (uint16_t i = 0; i < ms; i++)
	{
		delay_us(1000);
	}
}

