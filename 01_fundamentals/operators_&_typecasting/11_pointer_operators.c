#include <stdio.h>
#include <stdint.h>

/*
===============================================================================
                        11_POINTER_OPERATORS.C
===============================================================================

TOPIC:
    Pointer Operators in C

OPERATORS:

    &   Address-Of Operator
    *   Dereference Operator

===============================================================================

POINTER OPERATORS TABLE

+------------+----------------------+--------------------------------------+
| OPERATOR   | NAME                 | PURPOSE                              |
+------------+----------------------+--------------------------------------+
| &          | Address-Of           | Get variable memory address          |
| *          | Dereference          | Access value at an address           |
+------------+----------------------+--------------------------------------+

===============================================================================

GENERAL SYNTAX

ADDRESS OF:

    &variable

Example:

    int x = 10;

    &x

Returns:

    Memory address of x

-------------------------------------------------------------------------------

DEREFERENCE:

    *pointer

Example:

    int *ptr = &x;

    *ptr

Returns:

    Value stored at x

===============================================================================

MEMORY VISUALIZATION

VARIABLE:

    int number = 100;

Assume:

    Address:

        0x1000

Memory:

    +---------+
    |   100   |
    +---------+
       0x1000

-------------------------------------------------------------------------------

POINTER:

    int *ptr = &number;

Memory:

    ptr
     |
     |
     +-------> 0x1000

===============================================================================

IMPORTANT:

&

    Gives address.

*

    Gives value at address.

===============================================================================
*/


int main(void)
{
    /*
    ===========================================================================
    1. ADDRESS-OF OPERATOR (&)
    ===========================================================================
    */

    int number = 100;

    int *ptr = &number;

    printf("=========================================\n");
    printf("1. ADDRESS-OF OPERATOR (&)\n");
    printf("=========================================\n");

    printf("number      = %d\n", number);

    printf("&number     = %p\n",
           (void *)&number);

    printf("ptr         = %p\n\n",
           (void *)ptr);



    /*
    ===========================================================================
    2. DEREFERENCE OPERATOR (*)
    ===========================================================================
    */

    printf("=========================================\n");
    printf("2. DEREFERENCE OPERATOR (*)\n");
    printf("=========================================\n");

    printf("*ptr        = %d\n\n",
           *ptr);



    /*
    ===========================================================================
    3. MODIFY VALUE THROUGH POINTER
    ===========================================================================
    */

    *ptr = 500;

    /*
        Memory:

            Before:

                100

            After:

                500
    */

    printf("=========================================\n");
    printf("3. MODIFY THROUGH POINTER\n");
    printf("=========================================\n");

    printf("number      = %d\n", number);

    printf("*ptr        = %d\n\n",
           *ptr);



    /*
    ===========================================================================
    4. POINTER DECLARATION STYLES
    ===========================================================================
    */

    int value1 = 10;
    int value2 = 20;

    int *pointer1 = &value1;

    int * pointer2 = &value2;

    /*
        Preferred Style:

            int *ptr;

        Reason:

            Easier to understand that:

                ptr

            is the pointer.
    */

    printf("=========================================\n");
    printf("4. POINTER DECLARATION\n");
    printf("=========================================\n");

    printf("*pointer1   = %d\n",
           *pointer1);

    printf("*pointer2   = %d\n\n",
           *pointer2);



    /*
    ===========================================================================
    5. NULL POINTER
    ===========================================================================
    */

    int *null_ptr = NULL;

    printf("=========================================\n");
    printf("5. NULL POINTER\n");
    printf("=========================================\n");

    printf("null_ptr    = %p\n\n",
           (void *)null_ptr);



    /*
    ===========================================================================
    IMPORTANT:

    NEVER DO:

        *null_ptr

    Result:

        Undefined Behavior

        Usually:

            Segmentation Fault

    ===========================================================================
    */



    /*
    ===========================================================================
    6. SAFE NULL CHECK
    ===========================================================================
    */

    printf("=========================================\n");
    printf("6. SAFE NULL CHECK\n");
    printf("=========================================\n");

    if (null_ptr != NULL)
    {
        printf("%d\n", *null_ptr);
    }
    else
    {
        printf("Pointer is NULL\n");
    }

    printf("\n");



    /*
    ===========================================================================
    7. DOUBLE POINTER
    ===========================================================================
    */

    int sensor_value = 250;

    int *sensor_ptr = &sensor_value;

    int **double_ptr = &sensor_ptr;

    printf("=========================================\n");
    printf("7. DOUBLE POINTER\n");
    printf("=========================================\n");

    printf("sensor_value   = %d\n",
           sensor_value);

    printf("*sensor_ptr    = %d\n",
           *sensor_ptr);

    printf("**double_ptr   = %d\n\n",
           **double_ptr);



    /*
    ===========================================================================
    MEMORY VISUALIZATION

    sensor_value

        Address:

            0x1000

    sensor_ptr

        Stores:

            0x1000

    double_ptr

        Stores:

            Address of sensor_ptr

    ---------------------------------------------------------------------------

        double_ptr
             |
             v

        sensor_ptr
             |
             v

        sensor_value

    ===========================================================================
    */



    /*
    ===========================================================================
    8. POINTER TO DIFFERENT DATA TYPES
    ===========================================================================
    */

    char grade = 'A';

    float voltage = 3.3f;

    char *char_ptr = &grade;

    float *float_ptr = &voltage;

    printf("=========================================\n");
    printf("8. POINTER TO DIFFERENT TYPES\n");
    printf("=========================================\n");

    printf("*char_ptr    = %c\n",
           *char_ptr);

    printf("*float_ptr   = %.2f\n\n",
           *float_ptr);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    GPIO REGISTER ACCESS
    ===========================================================================
    */

    uint32_t gpio_register = 0x00000001U;

    uint32_t *gpio_ptr = &gpio_register;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 1\n");
    printf("=========================================\n");

    printf("GPIO Register = 0x%08X\n",
           *gpio_ptr);

    printf("\n");



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    FUNCTION PARAMETER BY REFERENCE
    ===========================================================================
    */

    uint16_t adc_value = 2048U;

    uint16_t *adc_ptr = &adc_value;

    *adc_ptr = 3000U;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 2\n");
    printf("=========================================\n");

    printf("ADC Value = %u\n",
           adc_value);

    printf("\n");



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 3

    MEMORY MAPPED IO

    Example:

        STM32 GPIOA ODR

    Address:

        0x48000014

    Real Embedded Code:

        volatile uint32_t *GPIOA_ODR =
            (volatile uint32_t *)0x48000014;

    Then:

        *GPIOA_ODR |= (1U << 5);

    This turns ON an LED.

    ===========================================================================
    */



    /*
    ===========================================================================
    COMMON MISTAKES
    ===========================================================================

    WRONG:

        int *ptr;

        *ptr = 10;

    Reason:

        Pointer not initialized.

    ----------------------------------------

    WRONG:

        int *ptr = NULL;

        *ptr

    Reason:

        NULL dereference.

    ----------------------------------------

    WRONG:

        int value = 10;

        int *ptr;

        ptr = value;

    Correct:

        ptr = &value;

    ===========================================================================
    */



    /*
    ===========================================================================
    INTERVIEW QUESTIONS
    ===========================================================================

    Q1:

        What does & do?

        Answer:

            Returns memory address.

    ----------------------------------------

    Q2:

        What does * do?

        Answer:

            Dereferences a pointer.

    ----------------------------------------

    Q3:

        What is NULL?

        Answer:

            A pointer that points to nothing.

    ----------------------------------------

    Q4:

        What is a double pointer?

        Answer:

            A pointer to another pointer.

    ----------------------------------------

    Q5:

        Why are pointers important in embedded systems?

        Answer:

            They provide direct access
            to hardware registers
            and memory locations.

    ===========================================================================
    */



    return 0;
}
