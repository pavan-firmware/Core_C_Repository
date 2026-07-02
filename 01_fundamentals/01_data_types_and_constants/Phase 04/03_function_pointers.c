#include <stdio.h>
#include <stdint.h>

/*
==============================================================================
                    03. FUNCTION POINTERS IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. What is a Function Pointer?

2. Function Address

3. Function Pointer Declaration

4. Assigning Functions

5. Calling Functions Through Pointers

6. Array of Function Pointers

7. Callback Functions

8. Embedded Firmware Examples

9. Industry Best Practices

10. Common Beginner Mistakes

==============================================================================


WHAT IS A FUNCTION POINTER?
==============================================================================

A function pointer stores:

    Address of a function.

Just like:

    int *

stores:

    Address of an integer.

Function Pointer:

    Stores:

        Address of a function.

==============================================================================


NORMAL FUNCTION CALL
==============================================================================

add(10, 20);

Compiler:

    Directly jumps to:

        add()

==============================================================================


FUNCTION POINTER CALL
==============================================================================

int (*operation)(int, int);

operation = add;

operation(10, 20);

OR

(*operation)(10, 20);

Both are valid.

==============================================================================


FUNCTION POINTER SYNTAX
==============================================================================

General Syntax:

    return_type
    (*pointer_name)
    (parameter_list);

Example:

    int (*math_function)
    (int, int);

==============================================================================


WHY DO WE USE FUNCTION POINTERS?
==============================================================================

Applications:

    ✓ Callbacks

    ✓ State Machines

    ✓ Interrupt Tables

    ✓ Menu Systems

    ✓ RTOS Hooks

    ✓ Driver Abstraction Layers

==============================================================================


EMBEDDED EXAMPLES
==============================================================================

Used In:

    ✓ ISR Vector Tables

    ✓ HAL Drivers

    ✓ RTOS Task Hooks

    ✓ Communication Callbacks

    ✓ Event Handlers

==============================================================================
*/


/*
------------------------------------------------------------------------------
MATHEMATICAL FUNCTIONS
------------------------------------------------------------------------------
*/

int add(int a, int b)
{
    return a + b;
}


int subtract(int a, int b)
{
    return a - b;
}


int multiply(int a, int b)
{
    return a * b;
}


int divide(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }

    return a / b;
}


/*
------------------------------------------------------------------------------
CALLBACK FUNCTION
------------------------------------------------------------------------------
*/

void uart_receive_callback(void)
{
    printf("UART Data Received\n");
}


/*
------------------------------------------------------------------------------
GENERIC CALLBACK EXECUTOR
------------------------------------------------------------------------------
*/

void execute_callback(void (*callback)(void))
{
    callback();
}


/*
------------------------------------------------------------------------------
GPIO EVENT HANDLER
------------------------------------------------------------------------------
*/

void button_pressed_handler(void)
{
    printf("Button Press Event\n");
}


void sensor_trigger_handler(void)
{
    printf("Sensor Trigger Event\n");
}


int main(void)
{
    /*
    ==========================================================================
    BASIC FUNCTION POINTER
    ==========================================================================
    */

    int (*math_operation)(int, int);

    math_operation = add;


    printf("==================================================\n");
    printf("BASIC FUNCTION POINTER\n");
    printf("==================================================\n\n");

    printf("10 + 20 = %d\n",
           math_operation(10, 20));


    /*
    ==========================================================================
    CHANGING FUNCTION ADDRESSES
    ==========================================================================
    */

    math_operation = subtract;

    printf("\n");
    printf("==================================================\n");
    printf("CHANGING FUNCTION ADDRESS\n");
    printf("==================================================\n\n");

    printf("50 - 10 = %d\n",
           math_operation(50, 10));


    math_operation = multiply;

    printf("10 * 5 = %d\n",
           math_operation(10, 5));


    math_operation = divide;

    printf("100 / 10 = %d\n",
           math_operation(100, 10));


    /*
    ==========================================================================
    FUNCTION POINTER STATE
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("FUNCTION POINTER STATE\n");
    printf("==================================================\n\n");

    printf("math_operation currently points to add()\n");
    printf("math_operation(7, 3) = %d\n",
           math_operation(7, 3));


    /*
    ==========================================================================
    CALLBACK FUNCTIONS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("CALLBACK FUNCTIONS\n");
    printf("==================================================\n\n");

    execute_callback(
        uart_receive_callback);


    /*
    ==========================================================================
    ARRAY OF FUNCTION POINTERS
    ==========================================================================
    */

    int (*operations[4])(int, int) =
    {
        add,
        subtract,
        multiply,
        divide
    };


    printf("\n");
    printf("==================================================\n");
    printf("ARRAY OF FUNCTION POINTERS\n");
    printf("==================================================\n\n");

    printf("Add      = %d\n",
           operations[0](20, 10));

    printf("Subtract = %d\n",
           operations[1](20, 10));

    printf("Multiply = %d\n",
           operations[2](20, 10));

    printf("Divide   = %d\n",
           operations[3](20, 10));


    /*
    ==========================================================================
    EVENT HANDLER EXAMPLE
    ==========================================================================
    */

    void (*event_handler)(void);


    event_handler =
        button_pressed_handler;

    printf("\n");
    printf("==================================================\n");
    printf("EVENT HANDLER EXAMPLE\n");
    printf("==================================================\n\n");

    event_handler();


    event_handler =
        sensor_trigger_handler;

    event_handler();


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLES\n");
    printf("==================================================\n\n");

    printf("Interrupt Vector Tables\n");

    printf("UART RX Callbacks\n");

    printf("Timer Expiry Handlers\n");

    printf("GPIO Interrupt Handlers\n");

    printf("RTOS Hook Functions\n");


    /*
    ==========================================================================
    STM32 ISR VECTOR TABLE EXAMPLE
    ==========================================================================

    Example:

        void (*vector_table[])(void) =
        {
            reset_handler,

            nmi_handler,

            hardfault_handler,

            systick_handler
        };

    Hardware jumps using
    function addresses.

    ==========================================================================
    */


    /*
    ==========================================================================
    INDUSTRY BEST PRACTICES
    ==========================================================================

    GOOD:

        void (*callback)(void);

    ------------------------------------------------------------

    GOOD:

        Use typedef
        for complex declarations.

        Example:

            typedef void
            (*CallbackFunction)
            (void);

    ------------------------------------------------------------

    GOOD:

        Initialize function
        pointers before use.

    ==========================================================================
    */


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        int *function(int,int);

    Meaning:

        Function returning
        int pointer.

    ------------------------------------------------------------

    CORRECT:

        int (*function)
        (int,int);

    Meaning:

        Pointer to function.

    ------------------------------------------------------------

    WRONG:

        Calling NULL
        function pointers.

    Example:

            callback();

    Without initialization.

    Undefined Behavior.

    ------------------------------------------------------------

    IMPORTANT:

        Function Name:

            add

        means:

            Address of add()

    Therefore:

            math_operation = add;

    is valid.

    ==========================================================================
    */

    return 0;
}
