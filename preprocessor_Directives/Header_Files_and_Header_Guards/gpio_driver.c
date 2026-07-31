#include <stdio.h>
#include "gpio_driver.h"

void GPIO_Init(GPIO_Config_t *cfg)
{
    gpioInitCount++;
    printf("GPIO Init : Pin %u\n", cfg->pin);
}

void GPIO_Write(GPIO_Config_t *cfg, GPIO_State_t state)
{
    cfg->state = state;
    printf("GPIO Write : %s\n", state ? "HIGH":"LOW");
}

GPIO_State_t GPIO_Read(const GPIO_Config_t *cfg)
{
    return cfg->state;
}
