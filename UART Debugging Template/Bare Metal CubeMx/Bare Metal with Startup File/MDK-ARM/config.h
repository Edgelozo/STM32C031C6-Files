#ifndef CONFIG_H_
#define CONFIG_H_

#include "stm32c031xx.h"


void SysClock_Config(void);
void GPIO_Config(void);
void Timer_Config(void);
void delay_us(uint32_t us);
void delay_ms(uint32_t ms);
	




#endif