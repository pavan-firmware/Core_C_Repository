#include <stdio.h>

/*
==============================================================================
                            06. VOID TYPE IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. What is void?

2. void Functions

3. void Parameter Lists

4. return in void Functions

5. Generic Usage of void

6. Embedded Firmware Examples

7. Common Beginner Mistakes

==============================================================================


WHAT IS void?
==============================================================================

void means:

    "Nothing"

It represents:

    No Data
    No Return Value
    No Parameters

==============================================================================


USES OF void
==============================================================================

+---------------------------+--------------------------------+
| Syntax                    | Meaning                        |
+---------------------------+--------------------------------+
| void function(void)       | No parameters                  |
| return;                   | Exit void function             |
| void *ptr                 | Generic pointer (Later Topic)  |
+---------------------------+--------------------------------+

==============================================================================


MODERN C STYLE
==============================================================================

GOOD:

    void led_init(void);

BAD:

    void led_init();

Reason:

    ()

        Old C style

        Means:

            Unknown parameters

    (void)

        Means:

            No parameters allowed

==============================================================================

*/


/*
------------------------------------------------------------------------------
FUNCTION:

    Print System Banner

RETURNS:

    Nothing
------------------------------------------------------------------------------
*/

void print_system_banner(void)
{
    printf("====================================\n");
    printf("    EMBEDDED FIRMWARE SYSTEM\n");
    printf("====================================\n");
}


/*
------------------------------------------------------------------------------
FUNCTION:

    Initialize UART Driver

RETURNS:

    Nothing
------------------------------------------------------------------------------
*/

void uart_init(void)
{
    printf("UART Initialization Complete\n");
}


/*
------------------------------------------------------------------------------
FUNCTION:

    Initialize GPIO Driver

RETURNS:

    Nothing
------------------------------------------------------------------------------
*/

void gpio_init(void)
{
    printf("GPIO Initialization Complete\n");
}


/*
------------------------------------------------------------------------------
FUNCTION:

    Software Delay

RETURNS:

    Nothing
------------------------------------------------------------------------------
*/

void software_delay(void)
{
    volatile unsigned long counter;

    for (counter = 0UL;
         counter < 100000UL;
         counter++)
    {
        /*
            Empty delay loop.
        */
    }
}


/*
------------------------------------------------------------------------------
FUNCTION:

    Early Return Example

RETURNS:

    Nothing
------------------------------------------------------------------------------
*/

void check_temperature(int temperature)
{
    if (temperature > 80)
    {
        printf("Temperature Too High\n");

        return;
    }

    printf("Temperature Normal\n");
}


int main(void)
{
    /*
    ==========================================================================
    VOID FUNCTION EXAMPLES
    ==========================================================================
    */

    printf("==================================================\n");
    printf("VOID FUNCTION EXAMPLES\n");
    printf("==================================================\n\n");

    print_system_banner();

    uart_init();

    gpio_init();


    /*
    ==========================================================================
    VOID PARAMETER LIST
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("VOID PARAMETER LIST\n");
    printf("==================================================\n\n");

    printf("Modern C Style:\n");

    printf("    void function(void)\n");


    /*
    ==========================================================================
    VOID RETURN
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("VOID RETURN EXAMPLE\n");
    printf("==================================================\n\n");

    check_temperature(40);

    check_temperature(90);


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLES\n");
    printf("==================================================\n\n");

    printf("Driver Functions:\n");

    printf("    void uart_init(void);\n");

    printf("    void spi_init(void);\n");

    printf("    void gpio_init(void);\n");

    printf("    void adc_start(void);\n");


    /*
    ==========================================================================
    SOFTWARE DELAY
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("SOFTWARE DELAY\n");
    printf("==================================================\n\n");

    printf("Starting Delay...\n");

    software_delay();

    printf("Delay Finished\n");


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        void function()

    BETTER:

        void function(void)

    ------------------------------------------------------------

    WRONG:

        return 10;

    Inside:

        void function()

    ERROR:

        Cannot return a value.

    ------------------------------------------------------------

    CORRECT:

        return;

    Used for:

        Early function exit.

    ------------------------------------------------------------

    NOTE:

        void *

        belongs to:

            Pointer Phase

        Not here.

    ==========================================================================
    */

    return 0;
}
