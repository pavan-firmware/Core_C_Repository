/*
preprocessors are not a part of compiler 
it runs before the compiler 
it do's : before the compiler
text replacement, file insertion without manually copying, removing comments, processing conditional compilation
*/

#include <stdio.h>

//#define MACRO_NAME replacement
#define LED_PIN  13
#define UART_BAUD 115200
#define BUFFER_SIZE 256

// also used in register definations
#define GPIOA_BASE 0x40010800U

// Bit masks
#define GPIO_PINS (1U << 4)

//etc.........

// shift to right logic not related to this section
void printBinary(unsigned int n) // 10
{
    for (int i = 31; i >= 0; i--)
        printf("%d", (n >> i) & 1);
}



int main(void) {
    
    printf("LED_PIN : %d\n", LED_PIN);
    printf("UART_BAUD : %d\n", UART_BAUD);
    printf("BUFFER_SIZE : %d\n", BUFFER_SIZE);
    printf("GPIOA_BASE : %x\n", GPIOA_BASE);
    printf("GPIO_PINS : %u\n", GPIO_PINS);

    printBinary(GPIO_PINS); // binary view


    return 0;
}