/*
=========================================================
      #define (Object-like Macros)
=========================================================

This program demonstrates:

1. Basic object-like macros
2. Macro replacement
3. Compiler view
4. No memory allocation
5. No address
6. No data type
7. Using macros as constants
8. Using macros in arrays
9. Using macros in expressions
10. Using macros for strings
11. Firmware-style macros
12. Common mistakes (commented)
=========================================================
*/

#include <stdio.h>

/*-------------------------------------------------------
  BASIC OBJECT-LIKE MACROS
-------------------------------------------------------*/

/*
MAX is NOT a variable.

The preprocessor simply replaces MAX with 100.

Compiler never sees MAX.
*/

#define MAX 100

/*
Floating-point macro.
*/

#define PI 3.14159

/*
String macro.
*/

#define COMPANY "OpenAI"

/*
Character macro.
*/

#define GRADE 'A'

/*
Boolean-style macros.

(No memory allocated.)
*/

#define TRUE 1
#define FALSE 0

/*
Firmware configuration macro.
*/

#define UART_BAUDRATE 115200

/*
GPIO Pin number.
*/

#define LED_PIN 13

/*
Buffer size.
*/

#define BUFFER_SIZE 8

/*
Register Base Address
(Example only)
*/

#define GPIOA_BASE 0x40010800U

/*
Expression macro
(Not a function)

Preprocessor replaces DOUBLE with (2)

Compiler receives:
5 * (2)
*/

#define DOUBLE 2

int main(void)
{
    printf("============== BASIC MACROS ==============\n");

    /*
    Compiler receives:

    printf("%d\n",100);
    */

    printf("MAX = %d\n", MAX);

    /*
    Compiler receives:

    printf("%f\n",3.14159);
    */

    printf("PI = %.5f\n", PI);

    /*
    Compiler receives:

    printf("%s\n","OpenAI");
    */

    printf("Company = %s\n", COMPANY);

    printf("Grade = %c\n", GRADE);

    printf("TRUE = %d\n", TRUE);

    printf("FALSE = %d\n", FALSE);


    printf("\n============== ARRAY ==============\n");

    /*
    Compiler receives:

    int numbers[8];
    */

    int numbers[BUFFER_SIZE];

    printf("Array Size = %d\n", BUFFER_SIZE);

    printf("\n============== EXPRESSION ==============\n");

    /*
    Compiler receives

    int value = 100 + 20;
    */

    int value = MAX + 20;

    printf("Value = %d\n", value);

    printf("\n============== FIRMWARE STYLE ==============\n");

    printf("UART Baudrate = %d\n", UART_BAUDRATE);

    printf("LED Pin = %d\n", LED_PIN);

    /*
    Register Address

    This is NOT hardware access.

    Just printing address value.
    */

    printf("GPIO Base Address = 0x%X\n", GPIOA_BASE);

    printf("\n============== MACRO IN MATH ==============\n");

    /*
    Compiler receives

    5 * 2
    */

    int result = 5 * DOUBLE;

    printf("Result = %d\n", result);

    printf("\n============== IMPORTANT FACTS ==============\n");

    /*
    Macros occupy NO MEMORY.

    Variables DO occupy memory.
    */

    int variable = MAX;

    printf("Variable = %d\n", variable);

    /*
    Variable has address.
    */

    printf("Address of variable = %p\n", (void *)&variable);

    /*
    Uncommenting below will produce compilation error.

    Because MAX is NOT a variable.

    printf("%p",&MAX);
    */

    /*
    Uncommenting below also produces error.

    After preprocessing:

    100 = 50;

    Invalid C code.

    MAX = 50;
    */

    return 0;
}