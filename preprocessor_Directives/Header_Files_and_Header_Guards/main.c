#include <stdio.h>

/* Multiple include intentionally.
   Header guard prevents duplicate declarations. */
#include "gpio_driver.h"
#include "gpio_driver.h"

#include "globals.h"
#include "led.h"
#include "led.h"

int main(void)
{
    GPIO_Config_t led =
    {
        .pin = LED_PIN,
        .state = GPIO_LOW
    };

    GPIO_Init(&led);

    GPIO_Write(&led, GPIO_HIGH);

    if(GPIO_Read(&led) == GPIO_HIGH)
    {
        LED_On();
    }

    printf("GPIO Initialized %d time(s)\n", gpioInitCount);

    LED_Off();

    return 0;
}
