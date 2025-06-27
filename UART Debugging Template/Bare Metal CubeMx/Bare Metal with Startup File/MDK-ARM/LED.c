#include "LED.h"

static uint8_t status = 0;


void LED_Toggle(void)
{
    GPIOA->BSRR |= (status == 0) ? (1<<5) : ((1<<5) <<16);
    status = !status;  // Toggle between 0 and 1
}
