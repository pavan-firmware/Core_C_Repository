#include <stdio.h>
#include <stdint.h>

/*
===============================================================================
                    06_BITWISE_OPERATORS.C
===============================================================================

TOPIC:
    Bitwise Operators in C

PURPOSE:
    Bitwise operators work directly on individual bits.

    They are extremely important in:

        • Embedded Systems
        • Device Drivers
        • Microcontrollers
        • Register Programming
        • Communication Protocols
        • Operating Systems

===============================================================================

BITWISE OPERATORS TABLE

+------------+----------------+-----------------------------+
| OPERATOR   | NAME           | EXAMPLE                    |
+------------+----------------+-----------------------------+
| &          | Bitwise AND    | a & b                      |
| |          | Bitwise OR     | a | b                      |
| ^          | Bitwise XOR    | a ^ b                      |
| ~          | Bitwise NOT    | ~a                         |
+------------+----------------+-----------------------------+

NOTE:

Shift operators (<< and >>) are covered separately in:

    07_shift_operators.c

===============================================================================

BINARY NUMBER SYSTEM

Decimal      Binary
--------------------------------
0            0000
1            0001
2            0010
3            0011
4            0100
5            0101
6            0110
7            0111
8            1000

===============================================================================

BITWISE AND (&)

RULE:

    1 & 1 = 1
    Everything else = 0

TRUTH TABLE

+-----+-----+-------+
|  A  |  B  | A & B |
+-----+-----+-------+
|  0  |  0  |   0   |
|  0  |  1  |   0   |
|  1  |  0  |   0   |
|  1  |  1  |   1   |
+-----+-----+-------+

===============================================================================

BITWISE OR (|)

RULE:

    If ANY bit is 1,
    result becomes 1.

TRUTH TABLE

+-----+-----+-------+
|  A  |  B  | A | B |
+-----+-----+-------+
|  0  |  0  |   0   |
|  0  |  1  |   1   |
|  1  |  0  |   1   |
|  1  |  1  |   1   |
+-----+-----+-------+

===============================================================================

BITWISE XOR (^)

RULE:

    Same Bits:

        0

    Different Bits:

        1

TRUTH TABLE

+-----+-----+-------+
|  A  |  B  | A ^ B |
+-----+-----+-------+
|  0  |  0  |   0   |
|  0  |  1  |   1   |
|  1  |  0  |   1   |
|  1  |  1  |   0   |
+-----+-----+-------+

===============================================================================

BITWISE NOT (~)

RULE:

    Invert every bit.

    0 becomes 1
    1 becomes 0

===============================================================================
*/


/*
===============================================================================
PRINT BINARY FUNCTION

This helper function prints
8-bit binary values.

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
    uint8_t a = 12;   /* 00001100 */
    uint8_t b = 10;   /* 00001010 */

    uint8_t result;


    /*
    ===========================================================================
    INPUT VALUES
    ===========================================================================
    */

    printf("=====================================\n");
    printf("INPUT VALUES\n");
    printf("=====================================\n");

    printf("a = %u = ", a);
    print_binary(a);
    printf("\n");

    printf("b = %u = ", b);
    print_binary(b);
    printf("\n\n");



    /*
    ===========================================================================
    1. BITWISE AND (&)
    ===========================================================================

    00001100

    00001010

    --------

    00001000

    Result:

        8
    */

    result = a & b;

    printf("=====================================\n");
    printf("1. BITWISE AND (&)\n");
    printf("=====================================\n");

    printf("Result = %u = ", result);
    print_binary(result);

    printf("\n\n");



    /*
    ===========================================================================
    2. BITWISE OR (|)
    ===========================================================================

    00001100

    00001010

    --------

    00001110

    Result:

        14
    */

    result = a | b;

    printf("=====================================\n");
    printf("2. BITWISE OR (|)\n");
    printf("=====================================\n");

    printf("Result = %u = ", result);
    print_binary(result);

    printf("\n\n");



    /*
    ===========================================================================
    3. BITWISE XOR (^)
    ===========================================================================

    00001100

    00001010

    --------

    00000110

    Result:

        6
    */

    result = a ^ b;

    printf("=====================================\n");
    printf("3. BITWISE XOR (^)\n");
    printf("=====================================\n");

    printf("Result = %u = ", result);
    print_binary(result);

    printf("\n\n");



    /*
    ===========================================================================
    4. BITWISE NOT (~)
    ===========================================================================

    00001100

    --------

    11110011

    Result:

        243

    NOTE:

    We use uint8_t.

    Therefore:

        Only 8 bits are considered.
    */

    result = (uint8_t)(~a);

    printf("=====================================\n");
    printf("4. BITWISE NOT (~)\n");
    printf("=====================================\n");

    printf("Result = %u = ", result);
    print_binary(result);

    printf("\n\n");



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    SET A BIT

    GPIO_PORT |= MASK

    Set Bit 3

    00000000

    OR

    00001000

    --------

    00001000
    ===========================================================================
    */

    uint8_t gpio_port = 0x00U;

    gpio_port |= (1U << 3);

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 1 : SET BIT\n");
    printf("=====================================\n");

    printf("GPIO = ");
    print_binary(gpio_port);

    printf("\n\n");



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    CLEAR A BIT

    GPIO_PORT &= ~MASK

    Initial:

        11111111

    Clear Bit 2

        11111011
    ===========================================================================
    */

    gpio_port = 0xFFU;

    gpio_port &= ~(1U << 2);

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 2 : CLEAR BIT\n");
    printf("=====================================\n");

    printf("GPIO = ");
    print_binary(gpio_port);

    printf("\n\n");



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 3

    TOGGLE A BIT

    GPIO_PORT ^= MASK

    Initial:

        00001000

    Toggle Bit 3

        00000000
    ===========================================================================
    */

    gpio_port = 0x08U;

    gpio_port ^= (1U << 3);

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 3 : TOGGLE BIT\n");
    printf("=====================================\n");

    printf("GPIO = ");
    print_binary(gpio_port);

    printf("\n\n");



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 4

    CHECK A BIT

    register & MASK

    If result != 0

        Bit is SET
    ===========================================================================
    */

    gpio_port = 0x08U;

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 4 : CHECK BIT\n");
    printf("=====================================\n");

    if (gpio_port & (1U << 3))
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
    COMMON EMBEDDED PATTERNS

    SET BIT

        reg |= (1 << n);

    CLEAR BIT

        reg &= ~(1 << n);

    TOGGLE BIT

        reg ^= (1 << n);

    CHECK BIT

        reg & (1 << n)

    ===========================================================================
    */



    /*
    ===========================================================================
    INTERVIEW QUESTIONS

    Q1:

        Which operator sets a bit?

        Answer:

            |

    -----------------------------------

    Q2:

        Which operator clears a bit?

        Answer:

            & with ~

    -----------------------------------

    Q3:

        Which operator toggles a bit?

        Answer:

            ^

    -----------------------------------

    Q4:

        Which operator checks a bit?

        Answer:

            &

    ===========================================================================
    */

    return 0;
}
