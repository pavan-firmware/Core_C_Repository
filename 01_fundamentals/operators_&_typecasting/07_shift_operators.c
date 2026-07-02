#include <stdio.h>
#include <stdint.h>

/*
===============================================================================
                    07_SHIFT_OPERATORS.C
===============================================================================

TOPIC:
    Shift Operators in C

PURPOSE:
    Shift operators move bits left or right.

    These operators are heavily used in:

        • Embedded Systems
        • Register Programming
        • Communication Protocols
        • Bit Manipulation
        • Device Drivers
        • Operating Systems

===============================================================================

SHIFT OPERATORS TABLE

+------------+----------------+-----------------------------+
| OPERATOR   | NAME           | EXAMPLE                    |
+------------+----------------+-----------------------------+
| <<         | Left Shift     | value << n                 |
| >>         | Right Shift    | value >> n                 |
+------------+----------------+-----------------------------+

===============================================================================

LEFT SHIFT (<<)

GENERAL FORM:

    value << n

Means:

    Move all bits LEFT by n positions.

Each LEFT SHIFT multiplies by 2.

Example:

    5 << 1

Binary:

    00000101

Shift Left By 1:

    00001010

Decimal:

    10

===============================================================================

RIGHT SHIFT (>>)

GENERAL FORM:

    value >> n

Means:

    Move all bits RIGHT by n positions.

Each RIGHT SHIFT divides by 2.

Example:

    20 >> 1

Binary:

    00010100

Shift Right By 1:

    00001010

Decimal:

    10

===============================================================================

IMPORTANT:

LEFT SHIFT:

    x << n

Equivalent to:

    x × (2^n)

RIGHT SHIFT:

    x >> n

Equivalent to:

    x / (2^n)

ONLY TRUE FOR:

    Unsigned integers.

===============================================================================

DANGEROUS CASES

UNDEFINED BEHAVIOR:

    1 << 32

Reason:

    Shift count >= bit width.

----------------------------------------

UNDEFINED BEHAVIOR:

    -10 << 1

Reason:

    Left shift on negative signed integers.

----------------------------------------

GOOD PRACTICE:

    Use unsigned integers.

===============================================================================
*/


/*
===============================================================================
PRINT BINARY

Prints 8-bit binary representation.

Example:

    13

becomes

    00001101

===============================================================================
*/

void print_binary(uint8_t value)
{
    for (int bit = 7; bit >= 0; bit--)
    {
        printf("%d", (value >> bit) & 1U);
    }
}


int main(void)
{
    uint8_t value;
    uint8_t result;


    /*
    ===========================================================================
    1. LEFT SHIFT BY 1
    ===========================================================================
    */

    value = 5;

    /*
        Decimal:

            5

        Binary:

            00000101

        Shift:

            << 1

        Result:

            00001010

            10
    */

    result = value << 1;

    printf("=====================================\n");
    printf("1. LEFT SHIFT BY 1\n");
    printf("=====================================\n");

    printf("Input  : ");
    print_binary(value);

    printf("\n");

    printf("Result : ");
    print_binary(result);

    printf(" (%u)\n\n", result);



    /*
    ===========================================================================
    2. LEFT SHIFT BY 2
    ===========================================================================
    */

    value = 5;

    result = value << 2;

    /*
        5 * (2^2)

        5 * 4

        20
    */

    printf("=====================================\n");
    printf("2. LEFT SHIFT BY 2\n");
    printf("=====================================\n");

    printf("Input  : ");
    print_binary(value);

    printf("\n");

    printf("Result : ");
    print_binary(result);

    printf(" (%u)\n\n", result);



    /*
    ===========================================================================
    3. RIGHT SHIFT BY 1
    ===========================================================================
    */

    value = 20;

    result = value >> 1;

    /*
        20 / 2

        10
    */

    printf("=====================================\n");
    printf("3. RIGHT SHIFT BY 1\n");
    printf("=====================================\n");

    printf("Input  : ");
    print_binary(value);

    printf("\n");

    printf("Result : ");
    print_binary(result);

    printf(" (%u)\n\n", result);



    /*
    ===========================================================================
    4. RIGHT SHIFT BY 2
    ===========================================================================
    */

    value = 20;

    result = value >> 2;

    /*
        20 / 4

        5
    */

    printf("=====================================\n");
    printf("4. RIGHT SHIFT BY 2\n");
    printf("=====================================\n");

    printf("Input  : ");
    print_binary(value);

    printf("\n");

    printf("Result : ");
    print_binary(result);

    printf(" (%u)\n\n", result);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    GENERATE BIT MASK

    Create:

        00001000

    Bit Number:

        3
    ===========================================================================
    */

    uint8_t bit_mask = (1U << 3);

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 1 : BIT MASK\n");
    printf("=====================================\n");

    printf("Mask = ");
    print_binary(bit_mask);

    printf("\n\n");



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    EXTRACT HIGH NIBBLE

    High Nibble:

        Upper 4 bits

    Example:

        0xAB

        Binary:

        10101011

        Shift Right By 4:

        00001010

        Result:

        0x0A
    ===========================================================================
    */

    uint8_t data = 0xAB;

    uint8_t high_nibble = data >> 4;

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 2 : HIGH NIBBLE\n");
    printf("=====================================\n");

    printf("Data        = 0x%X\n", data);
    printf("High Nibble = 0x%X\n\n", high_nibble);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 3

    EXTRACT LOW NIBBLE

    Mask:

        00001111
    ===========================================================================
    */

    uint8_t low_nibble = data & 0x0F;

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 3 : LOW NIBBLE\n");
    printf("=====================================\n");

    printf("Low Nibble = 0x%X\n\n", low_nibble);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 4

    PACK TWO 4-BIT VALUES

    High:

        1010

    Low:

        0101

    Result:

        10100101

        0xA5
    ===========================================================================
    */

    uint8_t high = 0x0A;
    uint8_t low  = 0x05;

    uint8_t packed_data =
        (high << 4) | low;

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 4 : PACK DATA\n");
    printf("=====================================\n");

    printf("Packed Data = 0x%X\n\n",
           packed_data);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 5

    EXTRACT INDIVIDUAL BIT

    Check:

        Bit 3
    ===========================================================================
    */

    uint8_t register_value = 0x08;

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 5 : CHECK BIT\n");
    printf("=====================================\n");

    if ((register_value >> 3) & 1U)
    {
        printf("Bit 3 is SET\n");
    }
    else
    {
        printf("Bit 3 is CLEAR\n");
    }

    printf("\n");



    /*
    ===========================================================================
    ARITHMETIC VS LOGICAL RIGHT SHIFT
    ===========================================================================

    UNSIGNED:

        Always Logical Shift

        Zeros are inserted.

    Example:

        10000000

        >>

        01000000

    ----------------------------------------

    SIGNED:

        Compiler dependent.

        Usually Arithmetic Shift.

    Example:

        10000000

        >>

        11000000

    Sign bit preserved.

    Embedded Rule:

        Prefer unsigned integers.

    ===========================================================================
    */



    /*
    ===========================================================================
    INTERVIEW QUESTIONS

    Q1:

        What does:

            1 << 3

        produce?

        Answer:

            8

    ----------------------------------------

    Q2:

        What does:

            32 >> 2

        produce?

        Answer:

            8

    ----------------------------------------

    Q3:

        Which shift should be preferred in embedded systems?

        Answer:

            Unsigned shifts.

    ----------------------------------------

    Q4:

        Why avoid shifting negative integers?

        Answer:

            Undefined or implementation-defined behavior.

    ===========================================================================
    */



    return 0;
}
