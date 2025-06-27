#include "main.h"
#include "config.h"
#include "USART.h"
#include "LED.h"


int main()
{
	SysClock_Config();
	GPIO_Config();
	Timer_Config();
	UART2_Config();
	
	UART2_PutS("\r\nHello World!\r\n");

	while(1)
	{
		LED_Toggle();
		delay_ms(1000);
		LED_Toggle();
		delay_ms(1000);
	}
}