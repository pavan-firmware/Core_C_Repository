#include <stdio.h>
#include <stdint.h>

/*
===============================================================================
                22_FUNCTION_POINTER_CASTING.C
===============================================================================

TOPIC:
    Function Pointer Casting

STANDARD:
    C99, C11, C17, C23

===============================================================================

WHAT IS A FUNCTION POINTER?

Definition:

    A function pointer stores the address
    of a function.

-------------------------------------------------------------------------------

Example:

    int add(int a, int b);

    int (*ptr)(int, int);

    ptr = add;

===============================================================================

GENERAL SYNTAX

FUNCTION:

    return_type function_name(parameters);

-------------------------------------------------------------------------------

FUNCTION POINTER:

    return_type (*pointer_name)(parameters);

-------------------------------------------------------------------------------

Example:

    void led_on(void);

    void (*callback)(void);

===============================================================================

FUNCTION POINTER TABLE

+----------------------+------------------------------------------+
| FUNCTION             | FUNCTION POINTER TYPE                    |
+----------------------+------------------------------------------+
| void f(void)         | void (*ptr)(void)                        |
| int f(int)           | int (*ptr)(int)                          |
| float f(float,float) | float (*ptr)(float,float)                |
+----------------------+------------------------------------------+

===============================================================================

IMPORTANT RULE

FUNCTION NAME:

    function_name

Actually means:

    &function_name

Both are valid:

    ptr = function_name;

    ptr = &function_name;

===============================================================================
*/


/*
===============================================================================
EXAMPLE FUNCTIONS
===============================================================================
*/

void led_on(void)
{
    printf("LED ON\n");
}


void led_off(void)
{
    printf("LED OFF\n");
}


int add(int a, int b)
{
    return a + b;
}


float multiply(float a, float b)
{
    return a * b;
}


/*
===============================================================================
MAIN FUNCTION
===============================================================================
*/

int main(void)
{
    /*
    ===========================================================================
    1. BASIC FUNCTION POINTER
    ===========================================================================
    */

    void (*callback)(void);

    callback = led_on;

    printf("=========================================\n");
    printf("1. BASIC FUNCTION POINTER\n");
    printf("=========================================\n");

    callback();

    printf("\n");



    /*
    ===========================================================================
    FUNCTION MEMORY

        callback

            |

            v

        led_on()

    ===========================================================================
    */



    /*
    ===========================================================================
    2. USING & OPERATOR
    ===========================================================================
    */

    callback = &led_off;

    printf("=========================================\n");
    printf("2. USING & OPERATOR\n");
    printf("=========================================\n");

    callback();

    printf("\n");



    /*
    ===========================================================================
    BOTH ARE SAME

        callback = led_off;

        callback = &led_off;

    Both store the same function address.

    ===========================================================================
    */



    /*
    ===========================================================================
    3. FUNCTION POINTER WITH PARAMETERS
    ===========================================================================
    */

    int (*math_operation)(int, int);

    math_operation = add;

    int result =
        math_operation(10, 20);

    printf("=========================================\n");
    printf("3. FUNCTION POINTER WITH PARAMETERS\n");
    printf("=========================================\n");

    printf("Result = %d\n\n",
           result);



    /*
    ===========================================================================
    4. FLOAT FUNCTION POINTER
    ===========================================================================
    */

    float (*multiply_ptr)(float, float);

    multiply_ptr = multiply;

    float answer =
        multiply_ptr(2.5f, 4.0f);

    printf("=========================================\n");
    printf("4. FLOAT FUNCTION POINTER\n");
    printf("=========================================\n");

    printf("Answer = %.2f\n\n",
           answer);



    /*
    ===========================================================================
    5. FUNCTION POINTER CASTING
    ===========================================================================

    WARNING:

        Function pointer casting is dangerous.

    Only do this when absolutely necessary.

    ===========================================================================
    */

    void (*generic_function)(void);

    generic_function =
        (void (*)(void))led_on;

    printf("=========================================\n");
    printf("5. FUNCTION POINTER CASTING\n");
    printf("=========================================\n");

    generic_function();

    printf("\n");



    /*
    ===========================================================================
    IMPORTANT

    SAFE:

        Same signatures.

    DANGEROUS:

        Different signatures.

    ===========================================================================
    */



    /*
    ===========================================================================
    WRONG EXAMPLE

        int add(int,int);

        void (*ptr)(void);

        ptr = (void (*)(void))add;

    Calling:

        ptr();

    produces:

        Undefined Behavior

    ===========================================================================
    */



    /*
    ===========================================================================
    6. ARRAY OF FUNCTION POINTERS
    ===========================================================================
    */

    void (*led_functions[2])(void) =
    {
        led_on,
        led_off
    };

    printf("=========================================\n");
    printf("6. ARRAY OF FUNCTION POINTERS\n");
    printf("=========================================\n");

    led_functions[0]();

    led_functions[1]();

    printf("\n");



    /*
    ===========================================================================
    MEMORY VISUALIZATION

    led_functions

    +----------------+
    | led_on address |
    +----------------+
    | led_off addr   |
    +----------------+

    ===========================================================================
    */



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    INTERRUPT VECTOR TABLE
    ===========================================================================
    */

    /*
        ARM Cortex-M:

        void (*vector_table[])(void)
        {
            Reset_Handler,
            NMI_Handler,
            HardFault_Handler,
            ...
        };

    CPU jumps to these addresses
    during interrupts.

    ===========================================================================
    */



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    DRIVER CALLBACKS
    ===========================================================================
    */

    /*
        typedef void
        (*uart_callback_t)
        (
            uint8_t data
        );

    Driver:

        uart_register_callback(callback);

    ===========================================================================
    */



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 3

    BOOTLOADER JUMP
    ===========================================================================
    */

    /*
        Application Start Address:

            0x08004000

    Function Pointer:

        void (*app_reset_handler)(void);

        app_reset_handler =
            (void (*)(void))
            0x08004000;

    Jump:

        app_reset_handler();

    ---------------------------------------------------------------------------

    Common in:

        STM32 Bootloaders

        OTA Firmware Updates

    ===========================================================================
    */



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 4

    DYNAMIC DRIVER SELECTION
    ===========================================================================
    */

    /*
        SPI Driver:

            spi_send()

    UART Driver:

            uart_send()

    Function Pointer:

        tx_function = spi_send;

    or

        tx_function = uart_send;

    Runtime selection becomes possible.

    ===========================================================================
    */



    /*
    ===========================================================================
    MISRA C RECOMMENDATIONS
    ===========================================================================

    AVOID:

        Function pointer casts.

    AVOID:

        Incompatible function signatures.

    PREFER:

        Exact typedefs.

    Example:

        typedef void
        (*callback_t)(void);

    Benefits:

        • Better readability
        • Strong typing
        • Safer code
        • Better static analysis

    ===========================================================================
    */



    /*
    ===========================================================================
    COMMON MISTAKES
    ===========================================================================

    WRONG:

        void (*ptr)(void);

        ptr = add;

    Different signatures.

    Undefined behavior.

    ----------------------------------------

    WRONG:

        Calling NULL function pointer.

        ptr();

    Crash.

    ----------------------------------------

    CORRECT:

        if (ptr != NULL)
        {
            ptr();
        }

    ===========================================================================
    */



    /*
    ===========================================================================
    INTERVIEW QUESTIONS
    ===========================================================================

    Q1:

        What is a function pointer?

        Answer:

            A pointer that stores
            a function address.

    ----------------------------------------

    Q2:

        Are these equivalent?

            ptr = func;

            ptr = &func;

        Answer:

            YES

    ----------------------------------------

    Q3:

        Why avoid function pointer casts?

        Answer:

            Undefined behavior with
            incompatible signatures.

    ----------------------------------------

    Q4:

        Where are function pointers used
        in embedded systems?

        Answer:

            Interrupts,
            callbacks,
            bootloaders,
            drivers.

    ----------------------------------------

    Q5:

        What is an interrupt vector table?

        Answer:

            An array of function pointers
            used by the CPU to handle
            interrupts.

    ===========================================================================
    */

    return 0;
}
