#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
===============================================================================
            24_OPERATOR_PRECEDENCE_ASSOCIATIVITY.C
===============================================================================

TOPIC:
    Operator Precedence and Associativity

STANDARD:
    C99, C11, C17, C23

===============================================================================

WHAT IS OPERATOR PRECEDENCE?

Definition:

    Operator precedence decides:

        WHICH OPERATOR EXECUTES FIRST

-------------------------------------------------------------------------------

Example:

    10 + 5 * 2

Compiler sees:

    10 + (5 * 2)

Result:

    20

NOT:

    (10 + 5) * 2

===============================================================================

WHAT IS ASSOCIATIVITY?

Definition:

    Associativity decides:

        DIRECTION OF EVALUATION

When two operators have the SAME precedence.

-------------------------------------------------------------------------------

Example:

    100 / 10 / 2

Left To Right:

    (100 / 10) / 2

    10 / 2

    5

===============================================================================

COMPLETE PRECEDENCE TABLE

HIGHEST PRECEDENCE
===============================================================================

+-----+------------------------+--------------------+----------------+
| LVL | OPERATORS              | DESCRIPTION        | ASSOCIATIVITY  |
+-----+------------------------+--------------------+----------------+
| 1   | () [] -> . ++ --       | Postfix            | Left → Right   |
| 2   | ++ -- + - ! ~ * &      | Unary              | Right → Left   |
|     | (type) sizeof          |                    |                |
| 3   | * / %                  | Multiplicative     | Left → Right   |
| 4   | + -                    | Additive           | Left → Right   |
| 5   | << >>                  | Shift              | Left → Right   |
| 6   | < <= > >=              | Relational         | Left → Right   |
| 7   | == !=                  | Equality           | Left → Right   |
| 8   | &                      | Bitwise AND        | Left → Right   |
| 9   | ^                      | Bitwise XOR        | Left → Right   |
| 10  | |                      | Bitwise OR         | Left → Right   |
| 11  | &&                     | Logical AND        | Left → Right   |
| 12  | ||                     | Logical OR         | Left → Right   |
| 13  | ?:                     | Ternary            | Right → Left   |
| 14  | = += -= *= /= %=       | Assignment         | Right → Left   |
|     | <<= >>= &= ^= |=       |                    |                |
| 15  | ,                      | Comma              | Left → Right   |
+-----+------------------------+--------------------+----------------+

===============================================================================

BEST PRACTICE:

ALWAYS USE PARENTHESES

Even if precedence rules are known.

Reason:

    Better readability
    Easier maintenance
    MISRA compliance

===============================================================================
*/


int main(void)
{
    /*
    ===========================================================================
    1. MULTIPLICATION BEFORE ADDITION
    ===========================================================================
    */

    int result1 =
        10 + 5 * 2;

    /*
        Compiler:

            10 + (5 * 2)

            10 + 10

            20
    */

    printf("=========================================\n");
    printf("1. MULTIPLICATION BEFORE ADDITION\n");
    printf("=========================================\n");

    printf("10 + 5 * 2 = %d\n\n",
           result1);



    /*
    ===========================================================================
    2. PARENTHESES CHANGE PRIORITY
    ===========================================================================
    */

    int result2 =
        (10 + 5) * 2;

    /*
        First:

            10 + 5

            15

        Then:

            15 * 2

            30
    */

    printf("=========================================\n");
    printf("2. PARENTHESES\n");
    printf("=========================================\n");

    printf("(10 + 5) * 2 = %d\n\n",
           result2);



    /*
    ===========================================================================
    3. LEFT TO RIGHT ASSOCIATIVITY
    ===========================================================================
    */

    int result3 =
        100 / 10 / 2;

    /*
        Left To Right:

            (100 / 10)

                10

            10 / 2

                5
    */

    printf("=========================================\n");
    printf("3. LEFT TO RIGHT\n");
    printf("=========================================\n");

    printf("100 / 10 / 2 = %d\n\n",
           result3);



    /*
    ===========================================================================
    4. RIGHT TO LEFT ASSOCIATIVITY
    ===========================================================================
    */

    int a;
    int b;
    int c;

    a = b = c = 100;

    /*
        Compiler:

            c = 100

            b = c

            a = b
    */

    printf("=========================================\n");
    printf("4. RIGHT TO LEFT\n");
    printf("=========================================\n");

    printf("a = %d\n", a);

    printf("b = %d\n", b);

    printf("c = %d\n\n", c);



    /*
    ===========================================================================
    5. RELATIONAL vs LOGICAL
    ===========================================================================
    */

    int value =
        10 > 5 && 20 > 15;

    /*
        First:

            10 > 5

                TRUE

            20 > 15

                TRUE

        Then:

            TRUE && TRUE

                TRUE

        Result:

            1
    */

    printf("=========================================\n");
    printf("5. RELATIONAL AND LOGICAL\n");
    printf("=========================================\n");

    printf("Result = %d\n\n",
           value);



    /*
    ===========================================================================
    6. BITWISE PRECEDENCE
    ===========================================================================
    */

    int bit_result =
        10 | (4 & 3);

    /*
        First:

            4 & 3

                0

        Then:

            10 | 0

                10
    */

    printf("=========================================\n");
    printf("6. BITWISE PRECEDENCE\n");
    printf("=========================================\n");

    printf("Result = %d\n\n",
           bit_result);



    /*
    ===========================================================================
    7. SHIFT OPERATOR PRECEDENCE
    ===========================================================================
    */

    int shift_result =
        (2 + 3) << 1;

    /*
        First:

            2 + 3

                5

        Then:

            5 << 1

                10
    */

    printf("=========================================\n");
    printf("7. SHIFT PRECEDENCE\n");
    printf("=========================================\n");

    printf("Result = %d\n\n",
           shift_result);



    /*
    ===========================================================================
    8. TERNARY OPERATOR
    ===========================================================================
    */

    int maximum =
        (20 > 10)
        ? 20
        : 10;

    printf("=========================================\n");
    printf("8. TERNARY OPERATOR\n");
    printf("=========================================\n");

    printf("Maximum = %d\n\n",
           maximum);



    /*
    ===========================================================================
    9. COMMA OPERATOR
    ===========================================================================
    */

    int comma_result =
        ((void)10, (void)20, 30);

    /*
        Last value:

            30
    */

    printf("=========================================\n");
    printf("9. COMMA OPERATOR\n");
    printf("=========================================\n");

    printf("Result = %d\n\n",
           comma_result);



    /*
    ===========================================================================
    10. SIZEOF PRECEDENCE
    ===========================================================================
    */

    int array[10];

    size_t size =
        sizeof array / sizeof array[0];

    printf("=========================================\n");
    printf("10. SIZEOF EXAMPLE\n");
    printf("=========================================\n");

    printf("Elements = %zu\n\n",
           size);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    GPIO BIT SET
    ===========================================================================
    */

    uint32_t gpio_odr = 0;

    gpio_odr |= (1U << 5);

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 1\n");
    printf("=========================================\n");

    printf("GPIO = 0x%08X\n\n",
           gpio_odr);



    /*
    ===========================================================================
    WHY PARENTHESES?

    GOOD:

        gpio_odr |= (1U << 5);

    BAD:

        gpio_odr |= 1U << 5;

    Both work.

    But parentheses improve readability.

    ===========================================================================
    */



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    ADC VOLTAGE
    ===========================================================================
    */

    uint16_t adc = 2048;

    float voltage =
        ((float)adc * 3.3f)
        / 4095.0f;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 2\n");
    printf("=========================================\n");

    printf("Voltage = %.3f V\n\n",
           voltage);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 3

    FLAG CHECKING
    ===========================================================================
    */

    uint8_t status_register =
        0x20;

    bool flag_set =
        ((status_register & (1U << 5)) != 0U);

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 3\n");
    printf("=========================================\n");

    printf("Flag Set = %d\n\n",
           flag_set);



    /*
    ===========================================================================
    COMMON MISTAKES
    ===========================================================================

    WRONG:

        int x = 5 + 2 << 1;

    People expect:

        5 + (2 << 1)

    Actual:

        (5 + 2) << 1

    Result:

        14

    ----------------------------------------

    WRONG:

        if (status & 0x20 == 0)

    Actual:

        status & (0x20 == 0)

    WRONG!

    CORRECT:

        if ((status & 0x20) == 0)

    ----------------------------------------

    WRONG:

        a = b = c + d

    Understand:

        a = (b = (c + d))

    ===========================================================================
    */



    /*
    ===========================================================================
    MISRA C RECOMMENDATIONS
    ===========================================================================

    ALWAYS USE:

        Parentheses.

    Example:

        GOOD:

            if ((status & FLAG_MASK) != 0U)

        BAD:

            if (status & FLAG_MASK)

    Benefits:

        • Better readability
        • Less ambiguity
        • Easier code review
        • Safer maintenance
        • Better static analysis

    ===========================================================================
    */



    /*
    ===========================================================================
    INTERVIEW QUESTIONS
    ===========================================================================

    Q1:

        Which has higher precedence?

            *

        or

            +

        Answer:

            *

    ----------------------------------------

    Q2:

        Associativity of assignment?

        Answer:

            Right To Left

    ----------------------------------------

    Q3:

        Associativity of multiplication?

        Answer:

            Left To Right

    ----------------------------------------

    Q4:

        Highest precedence operator?

        Answer:

            Postfix operators:

                ()
                []
                .
                ->
                ++
                --

    ----------------------------------------

    Q5:

        Lowest precedence operator?

        Answer:

            Comma Operator

    ----------------------------------------

    Q6:

        MISRA recommendation?

        Answer:

            Always use parentheses.

    ===========================================================================
    */

    return 0;
}
