#include <stdio.h>

/*
===============================================================================
                    01_ARITHMETIC_OPERATORS.C
===============================================================================

TOPIC:
    Arithmetic Operators in C

LEARNING GOALS:
    1. Addition Operator (+)
    2. Subtraction Operator (-)
    3. Multiplication Operator (*)
    4. Division Operator (/)
    5. Modulus Operator (%)
    6. Unary Plus (+)
    7. Unary Minus (-)
    8. Integer Division
    9. Floating-Point Division
   10. Operator Precedence

===============================================================================

ARITHMETIC OPERATORS TABLE

+------------+----------------+-----------------------+------------------+
| OPERATOR   | NAME           | PURPOSE               | EXAMPLE          |
+------------+----------------+-----------------------+------------------+
| +          | Addition       | Add two values        | a + b            |
| -          | Subtraction    | Subtract values       | a - b            |
| *          | Multiplication | Multiply values       | a * b            |
| /          | Division       | Divide values         | a / b            |
| %          | Modulus        | Get remainder         | a % b            |
| +a         | Unary Plus     | Positive sign         | +a               |
| -a         | Unary Minus    | Negative sign         | -a               |
+------------+----------------+-----------------------+------------------+

===============================================================================

OPERATOR PRECEDENCE

HIGHER PRIORITY
----------------
Unary +, Unary -
*
/
%
+
-

LOWER PRIORITY

Example:

    10 + 5 * 2

Step 1:

    5 * 2 = 10

Step 2:

    10 + 10 = 20

===============================================================================
*/

int main(void)
{
    /*
    ===========================================================================
    INPUT VALUES
    ===========================================================================
    */

    int a = 20;
    int b = 7;

    float voltage = 3.3f;
    float current = 0.5f;


    /*
    ===========================================================================
    1. ADDITION OPERATOR (+)
    ===========================================================================

    Formula:

        result = a + b

    Example:

        20 + 7

        Result = 27
    */

    int addition_result = a + b;


    /*
    ===========================================================================
    2. SUBTRACTION OPERATOR (-)
    ===========================================================================

    Formula:

        result = a - b

    Example:

        20 - 7

        Result = 13
    */

    int subtraction_result = a - b;


    /*
    ===========================================================================
    3. MULTIPLICATION OPERATOR (*)
    ===========================================================================

    Formula:

        result = a * b

    Example:

        20 * 7

        Result = 140
    */

    int multiplication_result = a * b;


    /*
    ===========================================================================
    4. INTEGER DIVISION (/)
    ===========================================================================

    IMPORTANT:

        Integer division REMOVES decimal values.

    Example:

        20 / 7

        Actual:

            2.85714

        Integer Result:

            2
    */

    int integer_division_result = a / b;


    /*
    ===========================================================================
    5. MODULUS OPERATOR (%)
    ===========================================================================

    PURPOSE:

        Returns the REMAINDER.

    Example:

        20 / 7

        Quotient:

            2

        Multiplication:

            2 * 7 = 14

        Remainder:

            20 - 14 = 6
    */

    int modulus_result = a % b;


    /*
    ===========================================================================
    6. FLOATING-POINT DIVISION
    ===========================================================================

    IMPORTANT:

        At least ONE operand must be float.

    Example:

        20.0 / 7

        Result:

            2.857143
    */

    float floating_division_result = (float)a / b;


    /*
    ===========================================================================
    7. UNARY PLUS OPERATOR (+)
    ===========================================================================

    PURPOSE:

        Makes a value explicitly positive.

    Usually not used much in real projects.

    Example:

        +20

        Result:

            20
    */

    int unary_plus_result = +a;


    /*
    ===========================================================================
    8. UNARY MINUS OPERATOR (-)
    ===========================================================================

    PURPOSE:

        Changes sign.

    Example:

        -20

        Result:

            -20
    */

    int unary_minus_result = -a;


    /*
    ===========================================================================
    9. EMBEDDED SYSTEM EXAMPLE
    ===========================================================================

    Power Formula:

        Power = Voltage × Current

    Example:

        3.3 × 0.5

        Result:

        1.65 Watts
    */

    float power_consumption = voltage * current;


    /*
    ===========================================================================
    10. OPERATOR PRECEDENCE EXAMPLE
    ===========================================================================

    Expression:

        10 + 5 * 2

    Step 1:

        5 * 2 = 10

    Step 2:

        10 + 10 = 20
    */

    int precedence_result = 10 + 5 * 2;


    /*
    ===========================================================================
    PRINT RESULTS
    ===========================================================================
    */

    printf("=====================================\n");
    printf("ARITHMETIC OPERATORS OUTPUT\n");
    printf("=====================================\n\n");

    printf("a = %d\n", a);
    printf("b = %d\n\n", b);


    printf("Addition              : %d\n", addition_result);

    printf("Subtraction           : %d\n", subtraction_result);

    printf("Multiplication        : %d\n", multiplication_result);

    printf("Integer Division      : %d\n", integer_division_result);

    printf("Modulus               : %d\n", modulus_result);

    printf("Float Division        : %.6f\n",
           floating_division_result);

    printf("Unary Plus            : %d\n",
           unary_plus_result);

    printf("Unary Minus           : %d\n",
           unary_minus_result);

    printf("Power Consumption     : %.2f Watts\n",
           power_consumption);

    printf("Precedence Example    : %d\n",
           precedence_result);


    /*
    ===========================================================================
    EXPECTED OUTPUT

    a = 20
    b = 7

    Addition              : 27
    Subtraction           : 13
    Multiplication        : 140
    Integer Division      : 2
    Modulus               : 6
    Float Division        : 2.857143
    Unary Plus            : 20
    Unary Minus           : -20
    Power Consumption     : 1.65 Watts
    Precedence Example    : 20

    ===========================================================================
    */

    return 0;
}
