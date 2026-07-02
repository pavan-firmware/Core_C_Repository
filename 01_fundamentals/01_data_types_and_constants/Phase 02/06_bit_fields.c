#include <stdio.h>
#include <stdint.h>

/*
==============================================================================
                        06. BIT FIELDS IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. What are Bit Fields?

2. Why do we need Bit Fields?

3. Bit Field Syntax

4. Memory Optimization

5. Hardware Register Mapping

6. Anonymous Bit Fields

7. Zero Width Bit Fields

8. Embedded Firmware Examples

9. Structure Size Analysis

10. Common Beginner Mistakes

==============================================================================


WHAT ARE BIT FIELDS?
==============================================================================

Bit fields allow structure members
to occupy a specific number of bits
instead of entire bytes.

Normal Variable:

    uint8_t mode;

Consumes:

    8 bits

Bit Field:

    unsigned mode : 3;

Consumes:

    Only 3 bits

==============================================================================


WHY USE BIT FIELDS?
==============================================================================

Advantages:

    ✓ Memory Optimization

    ✓ Hardware Register Mapping

    ✓ Protocol Packet Definitions

    ✓ Status Flags

    ✓ Control Registers

==============================================================================


BIT FIELD SYNTAX
==============================================================================

struct Example
{
    unsigned field1 : 1;

    unsigned field2 : 3;

    unsigned field3 : 4;
};

Meaning:

    field1:

        Uses 1 bit

    field2:

        Uses 3 bits

    field3:

        Uses 4 bits

==============================================================================


BIT FIELD MEMORY LAYOUT
==============================================================================

Example:

struct Register
{
    unsigned enable : 1;

    unsigned mode   : 2;

    unsigned error  : 1;

    unsigned value  : 4;
};


Bit Position:

    +---+---+---+---+---+---+---+---+
    | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
    +---+---+---+---+---+---+---+---+
      value(4)     err mode  en

==============================================================================


ANONYMOUS BIT FIELDS
==============================================================================

Example:

struct Example
{
    unsigned enable : 1;

    unsigned        : 3;

    unsigned error  : 1;
};

The unnamed field creates padding bits.

==============================================================================


ZERO WIDTH BIT FIELDS
==============================================================================

Example:

struct Example
{
    unsigned a : 4;

    unsigned   : 0;

    unsigned b : 4;
};

Zero width forces the next member
to start in a new storage unit.

==============================================================================


IMPORTANT NOTE
==============================================================================

Bit Field Layout:

    Compiler Dependent

Bit Order:

    Compiler Dependent

Alignment:

    Compiler Dependent

Therefore:

    Avoid using bit fields
    for portable network protocols.

==============================================================================

*/


/*
------------------------------------------------------------------------------
LED CONTROL REGISTER
------------------------------------------------------------------------------
*/

struct LedControlRegister
{
    unsigned led_1 : 1;

    unsigned led_2 : 1;

    unsigned led_3 : 1;

    unsigned led_4 : 1;

    unsigned reserved : 4;
};


/*
------------------------------------------------------------------------------
UART STATUS REGISTER
------------------------------------------------------------------------------
*/

struct UartStatusRegister
{
    unsigned tx_ready : 1;

    unsigned rx_ready : 1;

    unsigned parity_error : 1;

    unsigned framing_error : 1;

    unsigned overrun_error : 1;

    unsigned reserved : 3;
};


/*
------------------------------------------------------------------------------
ADC CONTROL REGISTER
------------------------------------------------------------------------------
*/

struct AdcControlRegister
{
    unsigned enable : 1;

    unsigned start_conversion : 1;

    unsigned continuous_mode : 1;

    unsigned resolution : 2;

    unsigned reserved : 3;
};


/*
------------------------------------------------------------------------------
ANONYMOUS BIT FIELD EXAMPLE
------------------------------------------------------------------------------
*/

struct AnonymousExample
{
    unsigned enable : 1;

    unsigned : 3;

    unsigned error : 1;
};


/*
------------------------------------------------------------------------------
ZERO WIDTH BIT FIELD EXAMPLE
------------------------------------------------------------------------------
*/

struct ZeroWidthExample
{
    unsigned field_a : 4;

    unsigned : 0;

    unsigned field_b : 4;
};


int main(void)
{
    /*
    ==========================================================================
    LED CONTROL REGISTER
    ==========================================================================
    */

    struct LedControlRegister led_register =
    {
        .led_1 = 1,

        .led_2 = 0,

        .led_3 = 1,

        .led_4 = 1
    };


    printf("==================================================\n");
    printf("LED CONTROL REGISTER\n");
    printf("==================================================\n\n");

    printf("LED1 = %u\n",
           led_register.led_1);

    printf("LED2 = %u\n",
           led_register.led_2);

    printf("LED3 = %u\n",
           led_register.led_3);

    printf("LED4 = %u\n",
           led_register.led_4);


    /*
    ==========================================================================
    UART STATUS REGISTER
    ==========================================================================
    */

    struct UartStatusRegister uart_status =
    {
        .tx_ready = 1,

        .rx_ready = 1,

        .parity_error = 0,

        .framing_error = 0,

        .overrun_error = 0
    };


    printf("\n");
    printf("==================================================\n");
    printf("UART STATUS REGISTER\n");
    printf("==================================================\n\n");

    printf("TX Ready       = %u\n",
           uart_status.tx_ready);

    printf("RX Ready       = %u\n",
           uart_status.rx_ready);

    printf("Parity Error   = %u\n",
           uart_status.parity_error);

    printf("Framing Error  = %u\n",
           uart_status.framing_error);

    printf("Overrun Error  = %u\n",
           uart_status.overrun_error);


    /*
    ==========================================================================
    ADC CONTROL REGISTER
    ==========================================================================
    */

    struct AdcControlRegister adc_control =
    {
        .enable = 1,

        .start_conversion = 1,

        .continuous_mode = 1,

        .resolution = 3
    };


    printf("\n");
    printf("==================================================\n");
    printf("ADC CONTROL REGISTER\n");
    printf("==================================================\n\n");

    printf("Enable           = %u\n",
           adc_control.enable);

    printf("Start Conversion = %u\n",
           adc_control.start_conversion);

    printf("Continuous Mode  = %u\n",
           adc_control.continuous_mode);

    printf("Resolution       = %u\n",
           adc_control.resolution);


    /*
    ==========================================================================
    STRUCTURE SIZES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("BIT FIELD SIZES\n");
    printf("==================================================\n\n");

    printf("LedControlRegister  = %zu Bytes\n",
           sizeof(struct LedControlRegister));

    printf("UartStatusRegister  = %zu Bytes\n",
           sizeof(struct UartStatusRegister));

    printf("AdcControlRegister  = %zu Bytes\n",
           sizeof(struct AdcControlRegister));

    printf("AnonymousExample    = %zu Bytes\n",
           sizeof(struct AnonymousExample));

    printf("ZeroWidthExample    = %zu Bytes\n",
           sizeof(struct ZeroWidthExample));


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED FIRMWARE EXAMPLES\n");
    printf("==================================================\n\n");

    if (uart_status.tx_ready)
    {
        printf("UART Transmitter Ready\n");
    }

    if (adc_control.enable)
    {
        printf("ADC Module Enabled\n");
    }

    if (adc_control.start_conversion)
    {
        printf("ADC Conversion Started\n");
    }


    /*
    ==========================================================================
    BIT FIELD LIMITATIONS
    ==========================================================================

    Bit Fields Are:

        Compiler Dependent

        Architecture Dependent

        Endianness Dependent

    Therefore:

        Be careful when using
        them in communication
        protocols.

    ==========================================================================
    */


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        Assuming:

            Bit layout is identical
            on every compiler.

    Reality:

        Compiler dependent.

    ------------------------------------------------------------

    WRONG:

        Using:

            signed bit fields

    Better:

            unsigned bit fields

    Especially in embedded systems.

    ------------------------------------------------------------

    WRONG:

        Using bit fields for
        portable network packets.

    Better:

        Use:

            Bitwise Operators

            Masks

            Shifts

    ------------------------------------------------------------

    IMPORTANT:

        Bit fields help:

            Memory optimization

        But:

            Portability may decrease.

    ==========================================================================
    */

    return 0;
}
