#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
==============================================================================
                    02. VOLATILE QUALIFIER IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. What is volatile?

2. Why do we need volatile?

3. Compiler Optimizations

4. Hardware Register Access

5. Interrupt Service Routine (ISR) Variables

6. Global Flags

7. Memory Mapped Registers

8. Embedded Firmware Examples

9. Industry Best Practices

10. Common Beginner Mistakes

==============================================================================


WHAT IS volatile?
==============================================================================

volatile means:

    This variable can change unexpectedly.

Compiler must:

    ALWAYS read from memory.

Compiler must:

    NEVER assume the value
    remains unchanged.

==============================================================================


WHY DO WE NEED volatile?
==============================================================================

Without volatile:

    Compiler may optimize:

        while(flag == 0)
        {
        }

into:

        Infinite loop.

because:

    Compiler thinks:

        flag never changes.

But:

    ISR or Hardware
    may modify it.

==============================================================================


WHEN TO USE volatile?
==============================================================================

Use volatile for:

    ✓ Hardware Registers

    ✓ ISR Variables

    ✓ RTOS Shared Variables

    ✓ DMA Buffers

    ✓ Multi-Core Shared Data

==============================================================================


WHEN NOT TO USE volatile?
==============================================================================

Do NOT use volatile for:

    Normal Local Variables

    Function Parameters

    Standard Counters

    Ordinary Data Structures

==============================================================================


MEMORY MAPPED REGISTER EXAMPLE
==============================================================================

Example:

    #define GPIOA_ODR
        (*(volatile uint32_t*)0x40020014)

Every access:

    GPIOA_ODR

forces:

    Actual hardware memory read/write.

==============================================================================

*/


/*
------------------------------------------------------------------------------
GLOBAL ISR FLAG
------------------------------------------------------------------------------
*/

volatile bool g_button_pressed = false;


/*
------------------------------------------------------------------------------
GLOBAL SYSTEM TICK
------------------------------------------------------------------------------
*/

volatile uint32_t g_system_tick_ms = 0U;


/*
------------------------------------------------------------------------------
SIMULATED HARDWARE REGISTER
------------------------------------------------------------------------------
*/

volatile uint32_t g_uart_status_register = 0x00000001U;


/*
------------------------------------------------------------------------------
FUNCTION:

SIMULATED ISR
------------------------------------------------------------------------------
*/

void external_interrupt_handler(void)
{
    g_button_pressed = true;

    g_system_tick_ms += 1U;
}


/*
------------------------------------------------------------------------------
FUNCTION:

CHECK BUTTON STATUS
------------------------------------------------------------------------------
*/

void check_button_status(void)
{
    printf("Waiting For Button Press...\n");

    /*
        Normally:

        ISR changes this variable.

        Here:

        We simulate it manually.
    */

    external_interrupt_handler();

    while (g_button_pressed == false)
    {
        /*
            Compiler must
            reload variable
            every iteration.
        */
    }

    printf("Button Press Detected\n");
}


/*
------------------------------------------------------------------------------
FUNCTION:

READ UART STATUS REGISTER
------------------------------------------------------------------------------
*/

void read_uart_status(void)
{
    if (g_uart_status_register & 0x01U)
    {
        printf("UART TX Ready\n");
    }
}


int main(void)
{
    /*
    ==========================================================================
    GLOBAL VOLATILE VARIABLES
    ==========================================================================
    */

    printf("==================================================\n");
    printf("GLOBAL VOLATILE VARIABLES\n");
    printf("==================================================\n\n");

    printf("Button Flag = %d\n",
           g_button_pressed);

    printf("System Tick = %u\n",
           g_system_tick_ms);


    /*
    ==========================================================================
    ISR EXAMPLE
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("ISR EXAMPLE\n");
    printf("==================================================\n\n");

    check_button_status();

    printf("Updated Tick = %u ms\n",
           g_system_tick_ms);


    /*
    ==========================================================================
    HARDWARE REGISTER EXAMPLE
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("HARDWARE REGISTER EXAMPLE\n");
    printf("==================================================\n\n");

    read_uart_status();


    /*
    ==========================================================================
    LOCAL VOLATILE VARIABLE
    ==========================================================================
    */

    volatile uint32_t delay_counter;

    printf("\n");
    printf("==================================================\n");
    printf("LOCAL VOLATILE VARIABLE\n");
    printf("==================================================\n\n");

    for (delay_counter = 0U;
         delay_counter < 100000U;
         delay_counter++)
    {
        /*
            Volatile prevents
            aggressive optimization
            of this loop.
        */
    }

    printf("Software Delay Complete\n");


    /*
    ==========================================================================
    MEMORY MAPPED REGISTER EXAMPLE
    ==========================================================================

    Real Embedded Example:

        #define GPIOA_ODR
        (*(volatile uint32_t *)0x40020014)

        GPIOA_ODR |= (1U << 5);

    Meaning:

        Always access hardware memory.

    ==========================================================================
    */


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================

    Typical volatile variables:

        volatile bool button_pressed;

        volatile uint32_t system_tick;

        volatile uint8_t dma_complete;

        volatile uint16_t adc_result;

    ==========================================================================
    */


    /*
    ==========================================================================
    INDUSTRY BEST PRACTICES
    ==========================================================================

    GOOD:

        volatile uint32_t system_tick;

    ------------------------------------------------------------

    GOOD:

        volatile bool uart_rx_complete;

    ------------------------------------------------------------

    GOOD:

        volatile hardware registers.

    ------------------------------------------------------------

    Use volatile ONLY when:

        Another entity changes data:

            ISR
            Hardware
            DMA
            RTOS Task
            Another CPU Core

    ==========================================================================
    */


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        volatile makes code thread safe.

    Reality:

        volatile does NOT provide:

            Mutexes
            Atomic Operations
            Synchronization

    ------------------------------------------------------------

    WRONG:

        Using volatile everywhere.

    Reality:

        It reduces optimization
        opportunities.

    ------------------------------------------------------------

    WRONG:

        Forgetting volatile for:

            ISR flags

            Hardware registers

    This can cause:

            Infinite loops
            Incorrect behavior

    ------------------------------------------------------------

    IMPORTANT:

        volatile means:

            Always access memory.

        Nothing more.

    ==========================================================================
    */

    return 0;
}
