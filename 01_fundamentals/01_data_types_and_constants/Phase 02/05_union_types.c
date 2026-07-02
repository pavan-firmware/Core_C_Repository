#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/*
==============================================================================
                        05. UNION TYPES IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. What is a Union?

2. Why do we need Unions?

3. Union Syntax

4. Memory Sharing

5. Union Size

6. Writing and Reading Members

7. Embedded Firmware Examples

8. Memory Optimization

9. Type Punning Basics

10. Common Beginner Mistakes

==============================================================================


WHAT IS A UNION?
==============================================================================

A union is a user-defined data type.

All members share the SAME memory location.

Unlike structures:

    Structure:

        Every member gets
        separate memory.

    Union:

        All members share
        one memory block.

==============================================================================


STRUCTURE VS UNION
==============================================================================

STRUCTURE:

struct Example
{
    char c;
    int i;
};

Memory:

    +-----+
    |  c  |
    +-----+
    |     |
    |  i  |
    |     |
    +-----+

Total Size:

    c + i + padding


UNION:

union Example
{
    char c;
    int i;
};

Memory:

    +-----+
    |  c  |
    |  i  |
    +-----+

Both use same memory.

Total Size:

    Largest member size.

==============================================================================


WHEN TO USE UNIONS?
==============================================================================

Use Cases:

    ✓ Memory Optimization

    ✓ Communication Protocols

    ✓ Register Access

    ✓ Sensor Data Formats

    ✓ Type Punning

    ✓ Packet Processing

==============================================================================


UNION MEMORY RULE
==============================================================================

IMPORTANT:

    Only ONE member should
    be considered valid
    at a time.

Writing:

    data.integer_value = 100;

Then:

    data.float_value

Result:

    Implementation dependent.

==============================================================================

*/


/*
------------------------------------------------------------------------------
BASIC UNION
------------------------------------------------------------------------------
*/

union DataValue
{
    int32_t integer_value;

    float float_value;

    char character;
};


/*
------------------------------------------------------------------------------
ADC DATA UNION
------------------------------------------------------------------------------
*/

union AdcData
{
    uint16_t raw_value;

    uint8_t bytes[2];
};


/*
------------------------------------------------------------------------------
FLOAT TO BYTE CONVERSION
------------------------------------------------------------------------------
*/

union FloatConverter
{
    float float_value;

    uint8_t bytes[4];
};


/*
------------------------------------------------------------------------------
COMMUNICATION PACKET
------------------------------------------------------------------------------
*/

union PacketData
{
    uint32_t packet_id;

    uint8_t raw_bytes[4];
};


int main(void)
{
    /*
    ==========================================================================
    BASIC UNION EXAMPLE
    ==========================================================================
    */

    union DataValue data;

    data.integer_value = 100;

    printf("==================================================\n");
    printf("BASIC UNION EXAMPLE\n");
    printf("==================================================\n\n");

    printf("Integer Value = %d\n",
           data.integer_value);


    /*
        Same memory is reused.
    */

    data.float_value = 3.14F;

    printf("Float Value   = %.2f\n",
           data.float_value);


    /*
        Previous integer value
        is no longer valid.
    */

    printf("Integer Again = %d\n",
           data.integer_value);


    /*
    ==========================================================================
    UNION SIZE
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("UNION SIZE\n");
    printf("==================================================\n\n");

    printf("sizeof(DataValue)      = %zu Bytes\n",
           sizeof(union DataValue));

    printf("sizeof(AdcData)        = %zu Bytes\n",
           sizeof(union AdcData));

    printf("sizeof(FloatConverter) = %zu Bytes\n",
           sizeof(union FloatConverter));

    printf("sizeof(PacketData)     = %zu Bytes\n",
           sizeof(union PacketData));


    /*
    ==========================================================================
    ADC EXAMPLE
    ==========================================================================
    */

    union AdcData adc_data;

    adc_data.raw_value = 0x1234U;

    printf("\n");
    printf("==================================================\n");
    printf("ADC EXAMPLE\n");
    printf("==================================================\n\n");

    printf("ADC Value = 0x%04X\n",
           adc_data.raw_value);

    printf("Byte[0]   = 0x%02X\n",
           adc_data.bytes[0]);

    printf("Byte[1]   = 0x%02X\n",
           adc_data.bytes[1]);


    /*
    ==========================================================================
    FLOAT TO BYTE CONVERSION
    ==========================================================================
    */

    union FloatConverter converter;

    converter.float_value = 3.3F;

    printf("\n");
    printf("==================================================\n");
    printf("FLOAT TO BYTE CONVERSION\n");
    printf("==================================================\n\n");

    printf("Float Value = %.2f\n",
           converter.float_value);

    printf("Bytes       = ");

    for (uint32_t index = 0U;
         index < 4U;
         index++)
    {
        printf("0x%02X ",
               converter.bytes[index]);
    }

    printf("\n");


    /*
    ==========================================================================
    COMMUNICATION PACKET EXAMPLE
    ==========================================================================
    */

    union PacketData packet;

    packet.packet_id = 0xAABBCCDDU;

    printf("\n");
    printf("==================================================\n");
    printf("COMMUNICATION PACKET\n");
    printf("==================================================\n\n");

    printf("Packet ID = 0x%08X\n",
           packet.packet_id);

    printf("Raw Bytes = ");

    for (uint32_t index = 0U;
         index < 4U;
         index++)
    {
        printf("0x%02X ",
               packet.raw_bytes[index]);
    }

    printf("\n");


    /*
    ==========================================================================
    MEMORY OPTIMIZATION EXAMPLE
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("MEMORY OPTIMIZATION\n");
    printf("==================================================\n\n");

    printf("Structure stores all members separately.\n");

    printf("Union stores only the largest member.\n");

    printf("Useful in memory-constrained MCUs.\n");


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    union PacketData uart_packet;

    uart_packet.packet_id = 0x11223344U;

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED FIRMWARE EXAMPLES\n");
    printf("==================================================\n\n");

    printf("UART Packet Bytes:\n");

    for (uint32_t index = 0U;
         index < 4U;
         index++)
    {
        printf("TX[%u] = 0x%02X\n",
               index,
               uart_packet.raw_bytes[index]);
    }


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        Writing:

            data.integer_value = 100;

        Reading:

            data.float_value

        Expecting:

            100.0

    Reality:

        Same memory is interpreted
        differently.

    ------------------------------------------------------------

    WRONG:

        Thinking:

            Union members have
            separate memory.

    Reality:

        All members share
        one memory block.

    ------------------------------------------------------------

    WRONG:

        Assuming byte order
        is identical everywhere.

    Reality:

        Depends on:

            Endianness

    ------------------------------------------------------------

    IMPORTANT:

        Union Size:

            Largest Member Size

        NOT:

            Sum of All Members

    ==========================================================================
    */

    return 0;
}
