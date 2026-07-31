#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <stdint.h>

/* Macro */
#define LED_PIN 13

/* typedef */
typedef enum
{
    GPIO_LOW = 0,
    GPIO_HIGH = 1
} GPIO_State_t;

/* Structure Declaration */
typedef struct
{
    uint8_t pin;
    GPIO_State_t state;
} GPIO_Config_t;

/* extern variable declaration */
extern int gpioInitCount;

/* Function declarations (Prototypes) */
void GPIO_Init(GPIO_Config_t *cfg);
void GPIO_Write(GPIO_Config_t *cfg, GPIO_State_t state);
GPIO_State_t GPIO_Read(const GPIO_Config_t *cfg);

#endif
