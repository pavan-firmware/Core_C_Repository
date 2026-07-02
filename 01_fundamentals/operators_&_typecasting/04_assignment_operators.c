#include <stdio.h>

/*
===============================================================================
                    04_ASSIGNMENT_OPERATORS.C
===============================================================================

TOPIC:
    Assignment Operators in C

PURPOSE:
    Assignment operators store or update values inside variables.

===============================================================================

ASSIGNMENT OPERATORS TABLE

+------------+----------------------+---------------------------+
| OPERATOR   | NAME                 | EQUIVALENT EXPRESSION     |
+------------+----------------------+---------------------------+
| =          | Simple Assignment    | a = b                     |
| +=         | Add And Assign       | a = a + b                 |
| -=         | Subtract And Assign  | a = a - b                 |
| *=         | Multiply And Assign  | a = a * b                 |
| /=         | Divide And Assign    | a = a / b                 |
| %=         | Modulus And Assign   | a = a % b                 |
| &=         | Bitwise AND Assign   | a = a & b                 |
| |=         | Bitwise OR Assign    | a = a | b                 |
| ^=         | Bitwise XOR Assign   | a = a ^ b                 |
| <<=        | Left Shift Assign    | a = a << b                |
| >>=        | Right Shift Assign   | a = a >> b                |
+------------+----------------------+---------------------------+

===============================================================================

WHY USE COMPOUND ASSIGNMENT?

NORMAL:

    counter = counter + 1;

SHORT FORM:

    counter += 1;

Advantages:

    • Cleaner code
    • Easier to read
    • Common in embedded systems
    • Less typing
    • Expresses programmer intent clearly

===============================================================================
*/

int main(void)
{
    int value;


    /*
    ===========================================================================
    1. SIMPLE ASSIGNMENT (=)
    ===========================================================================
    */

    value = 10;

    printf("=====================================\n");
    printf("1. SIMPLE ASSIGNMENT (=)\n");
    printf("=====================================\n");

    printf("value = 10\n");
    printf("Result = %d\n\n", value);



    /*
    ===========================================================================
    2. ADD AND ASSIGN (+=)
    ===========================================================================

    value += 5

    Equivalent:

        value = value + 5
    */

    value = 10;

    value += 5;

    printf("=====================================\n");
    printf("2. ADD AND ASSIGN (+=)\n");
    printf("=====================================\n");

    printf("10 += 5\n");
    printf("Result = %d\n\n", value);



    /*
    ===========================================================================
    3. SUBTRACT AND ASSIGN (-=)
    ===========================================================================

    value -= 3

    Equivalent:

        value = value - 3
    */

    value = 10;

    value -= 3;

    printf("=====================================\n");
    printf("3. SUBTRACT AND ASSIGN (-=)\n");
    printf("=====================================\n");

    printf("10 -= 3\n");
    printf("Result = %d\n\n", value);



    /*
    ===========================================================================
    4. MULTIPLY AND ASSIGN (*=)
    ===========================================================================
    */

    value = 10;

    value *= 4;

    printf("=====================================\n");
    printf("4. MULTIPLY AND ASSIGN (*=)\n");
    printf("=====================================\n");

    printf("10 *= 4\n");
    printf("Result = %d\n\n", value);



    /*
    ===========================================================================
    5. DIVIDE AND ASSIGN (/=)
    ===========================================================================
    */

    value = 20;

    value /= 4;

    printf("=====================================\n");
    printf("5. DIVIDE AND ASSIGN (/=)\n");
    printf("=====================================\n");

    printf("20 /= 4\n");
    printf("Result = %d\n\n", value);



    /*
    ===========================================================================
    6. MODULUS AND ASSIGN (%=)
    ===========================================================================

    Returns the remainder.
    */

    value = 23;

    value %= 5;

    printf("=====================================\n");
    printf("6. MODULUS AND ASSIGN (%%=)\n");
    printf("=====================================\n");

    printf("23 %%= 5\n");
    printf("Result = %d\n\n", value);



    /*
    ===========================================================================
    7. BITWISE AND ASSIGN (&=)
    ===========================================================================

    Binary:

        14 = 1110
        10 = 1010

    Result:

             1010

        Decimal:

             10
    */

    value = 14;

    value &= 10;

    printf("=====================================\n");
    printf("7. BITWISE AND ASSIGN (&=)\n");
    printf("=====================================\n");

    printf("14 &= 10\n");
    printf("Result = %d\n\n", value);



    /*
    ===========================================================================
    8. BITWISE OR ASSIGN (|=)
    ===========================================================================

    Binary:

        12 = 1100
         3 = 0011

    Result:

            1111

    Decimal:

            15
    */

    value = 12;

    value |= 3;

    printf("=====================================\n");
    printf("8. BITWISE OR ASSIGN (|=)\n");
    printf("=====================================\n");

    printf("12 |= 3\n");
    printf("Result = %d\n\n", value);



    /*
    ===========================================================================
    9. BITWISE XOR ASSIGN (^=)
    ===========================================================================

    Binary:

        12 = 1100
        10 = 1010

    Result:

             0110

    Decimal:

              6
    */

    value = 12;

    value ^= 10;

    printf("=====================================\n");
    printf("9. BITWISE XOR ASSIGN (^=)\n");
    printf("=====================================\n");

    printf("12 ^= 10\n");
    printf("Result = %d\n\n", value);



    /*
    ===========================================================================
    10. LEFT SHIFT ASSIGN (<<=)
    ===========================================================================

    Binary:

        5 = 00000101

        Shift Left By 2:

           00010100

        Decimal:

           20
    */

    value = 5;

    value <<= 2;

    printf("=====================================\n");
    printf("10. LEFT SHIFT ASSIGN (<<=)\n");
    printf("=====================================\n");

    printf("5 <<= 2\n");
    printf("Result = %d\n\n", value);



    /*
    ===========================================================================
    11. RIGHT SHIFT ASSIGN (>>=)
    ===========================================================================

    Binary:

        20 = 00010100

        Shift Right By 2:

             00000101

        Decimal:

             5
    */

    value = 20;

    value >>= 2;

    printf("=====================================\n");
    printf("11. RIGHT SHIFT ASSIGN (>>=)\n");
    printf("=====================================\n");

    printf("20 >>= 2\n");
    printf("Result = %d\n\n", value);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    Increment System Tick
    ===========================================================================
    */

    unsigned int system_tick = 1000U;

    system_tick += 1U;

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 1\n");
    printf("=====================================\n");

    printf("System Tick = %u\n\n", system_tick);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    Set GPIO Bit

    PORT |= (1 << PIN)
    ===========================================================================
    */

    unsigned int gpio_register = 0x00U;

    gpio_register |= (1U << 3);

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 2\n");
    printf("=====================================\n");

    printf("GPIO Register = 0x%X\n\n",
           gpio_register);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 3

    Clear Specific Bits

    register &= mask
    ===========================================================================
    */

    unsigned int status_register = 0xFFU;

    status_register &= 0x0FU;

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 3\n");
    printf("=====================================\n");

    printf("Status Register = 0x%X\n",
           status_register);



    /*
    ===========================================================================
    EXPECTED OUTPUT

    value = 10
    10 += 5       -> 15
    10 -= 3       -> 7
    10 *= 4       -> 40
    20 /= 4       -> 5
    23 %= 5       -> 3
    14 &= 10      -> 10
    12 |= 3       -> 15
    12 ^= 10      -> 6
    5 <<= 2       -> 20
    20 >>= 2      -> 5

    System Tick     = 1001
    GPIO Register   = 0x8
    Status Register = 0xF

    ===========================================================================
    */

    return 0;
}
