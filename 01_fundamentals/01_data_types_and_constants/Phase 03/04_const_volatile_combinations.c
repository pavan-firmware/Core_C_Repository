#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
==============================================================================
                04. CONST + VOLATILE COMBINATIONS IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. What is const volatile?

2. Why do we need const volatile?

3. Hardware Register Examples

4. Pointer Combinations

5. Read-Only Hardware Registers

6. Write-Only Hardware Registers

7. Read-Write Hardware Registers

8. Embedded Firmware Examples

9. Industry Best Practices

10. Common Beginner Mistakes

==============================================================================


WHAT IS const volatile?
==============================================================================

const:

    Prevents modification
    through the program.

volatile:

    Forces every access
    to go directly to memory.

Combination:

    const volatile

Means:

    Read Only Variable

    BUT

    Value can change
    externally.

==============================================================================


WHY DO WE NEED const volatile?
==============================================================================

Example:

    Hardware Status Register

CPU:

    Can READ

Hardware:

    Can MODIFY

Program:

    Must NOT WRITE

Perfect Candidate:

    const volatile

==============================================================================


TYPE COMBINATIONS
==============================================================================

+----------------------+-----------------------------------+
| Declaration          | Meaning                           |
+----------------------+-----------------------------------+
| const int value      | Read Only Variable                |
| volatile int value   | Memory Access Always Required     |
| const volatile int   | Read Only + External Changes      |
+----------------------+-----------------------------------+

==============================================================================


POINTER COMBINATIONS
==============================================================================

+--------------------------------------+-------------------------------+
| Declaration                          | Meaning                       |
+--------------------------------------+-------------------------------+
| const volatile int *ptr              | Pointer to const volatile     |
| volatile int *const ptr              | Const pointer to volatile     |
| const volatile int *const ptr        | Fully constant pointer        |
+--------------------------------------+-------------------------------+

==============================================================================


EMBEDDED USE CASES
==============================================================================

const:

    Lookup Tables
    Calibration Data

volatile:

    ISR Flags
    DMA Buffers
    Hardware Registers

const volatile:

    Status Registers
    Sensor Read Registers
    Timer Counters
    ADC Data Registers

==============================================================================
*/


/*
------------------------------------------------------------------------------
SIMULATED HARDWARE REGISTERS
------------------------------------------------------------------------------
*/

/*
    Read Only Status Register

    Hardware updates this.

    Software only reads.
*/

const volatile uint32_t g_adc_status_register =
    0x00000001U;


/*
    Read/Write Register

    Hardware and software
    both access it.
*/

volatile uint32_t g_uart_control_register =
    0x00000000U;


/*
------------------------------------------------------------------------------
FUNCTION:

READ ADC STATUS
------------------------------------------------------------------------------
*/

void read_adc_status(
    const volatile uint32_t *status_register)
{
    printf("ADC Status = 0x%08X\n",
           *status_register);
}


/*
------------------------------------------------------------------------------
FUNCTION:

ENABLE UART
------------------------------------------------------------------------------
*/

void enable_uart(
    volatile uint32_t *control_register)
{
    *control_register |= 0x01U;
}


/*
------------------------------------------------------------------------------
FUNCTION:

PRINT LOOKUP TABLE
------------------------------------------------------------------------------
*/

void print_lookup_table(
    const uint16_t *lookup_table,
    uint32_t size)
{
    for (uint32_t index = 0U;
         index < size;
         index++)
    {
        printf("%u ",
               lookup_table[index]);
    }

    printf("\n");
}


int main(void)
{
    /*
    ==========================================================================
    CONST VOLATILE VARIABLE
    ==========================================================================
    */

    printf("==================================================\n");
    printf("CONST VOLATILE VARIABLE\n");
    printf("==================================================\n\n");

    printf("ADC Status Register = 0x%08X\n",
           g_adc_status_register);


    /*
        NOT ALLOWED:

        g_adc_status_register = 10;

        Reason:

            const
    */


    /*
    ==========================================================================
    READ ONLY HARDWARE REGISTER
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("READ ONLY HARDWARE REGISTER\n");
    printf("==================================================\n\n");

    read_adc_status(
        &g_adc_status_register);


    /*
    ==========================================================================
    READ WRITE HARDWARE REGISTER
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("READ WRITE HARDWARE REGISTER\n");
    printf("==================================================\n\n");

    printf("Before = 0x%08X\n",
           g_uart_control_register);

    enable_uart(
        &g_uart_control_register);

    printf("After  = 0x%08X\n",
           g_uart_control_register);


    /*
    ==========================================================================
    CONST POINTER TO VOLATILE DATA
    ==========================================================================
    */

    volatile int sensor_value = 100;

    volatile int *const sensor_pointer =
        &sensor_value;

    printf("\n");
    printf("==================================================\n");
    printf("CONST POINTER TO VOLATILE DATA\n");
    printf("==================================================\n\n");

    printf("Before = %d\n",
           *sensor_pointer);

    *sensor_pointer = 200;

    printf("After  = %d\n",
           *sensor_pointer);


    /*
        NOT ALLOWED:

        sensor_pointer = &another_variable;

        because:

            const pointer
    */


    /*
    ==========================================================================
    CONST LOOKUP TABLE
    ==========================================================================
    */

    const uint16_t sine_lookup_table[8] =
    {
        0,
        707,
        1000,
        707,
        0,
        707,
        1000,
        707
    };


    printf("\n");
    printf("==================================================\n");
    printf("CONST LOOKUP TABLE\n");
    printf("==================================================\n\n");

    print_lookup_table(
        sine_lookup_table,
        8U);


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLES\n");
    printf("==================================================\n\n");

    printf("const:\n");

    printf("    Calibration Tables\n");

    printf("    CRC Lookup Tables\n");

    printf("    Sine Wave Tables\n");

    printf("\n");

    printf("volatile:\n");

    printf("    ISR Flags\n");

    printf("    DMA Buffers\n");

    printf("    Hardware Registers\n");

    printf("\n");

    printf("const volatile:\n");

    printf("    Timer Counters\n");

    printf("    ADC Result Registers\n");

    printf("    Status Registers\n");


    /*
    ==========================================================================
    INDUSTRY BEST PRACTICES
    ==========================================================================

    GOOD:

        const volatile
        uint32_t STATUS_REG;

    Meaning:

        Read Only

        But hardware changes it.

    ------------------------------------------------------------

    GOOD:

        const lookup tables.

    ------------------------------------------------------------

    GOOD:

        volatile hardware registers.

    ------------------------------------------------------------

    Use:

        const volatile

    ONLY when:

        External hardware
        modifies the data.

    ==========================================================================
    */


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        Thinking:

            const volatile
            is contradictory.

    Reality:

        Both work together.

        const:

            Software cannot modify.

        volatile:

            Hardware may modify.

    ------------------------------------------------------------

    WRONG:

        Using:

            volatile

        for lookup tables.

    Better:

            const

    ------------------------------------------------------------

    WRONG:

        Forgetting:

            const volatile

        for hardware status registers.

    This may cause:

            Invalid optimizations.

    ------------------------------------------------------------

    IMPORTANT:

        Embedded Firmware:

            const

                Read Only

            volatile

                Changes Externally

            const volatile

                Read Only
                +
                Changes Externally

    ==========================================================================
    */

    return 0;
}
