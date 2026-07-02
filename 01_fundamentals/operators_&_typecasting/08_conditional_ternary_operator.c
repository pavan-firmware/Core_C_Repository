#include <stdio.h>
#include <stdbool.h>

/*
===============================================================================
                08_CONDITIONAL_TERNARY_OPERATOR.C
===============================================================================

TOPIC:
    Conditional (Ternary) Operator

OPERATOR:

    ? :

PURPOSE:
    A shorthand version of if-else.

===============================================================================

TERNARY OPERATOR TABLE

+-------------+------------------------+---------------------------+
| OPERATOR    | NAME                   | EXAMPLE                   |
+-------------+------------------------+---------------------------+
| ? :         | Conditional Operator   | a>b ? a : b              |
+-------------+------------------------+---------------------------+

===============================================================================

GENERAL SYNTAX

    condition
        ? value_if_true
        : value_if_false;

===============================================================================

VISUAL REPRESENTATION

                    condition
                        |
            +-----------+-----------+
            |                       |
          TRUE                   FALSE
            |                       |
            v                       v

    value_if_true           value_if_false

===============================================================================

IF-ELSE EQUIVALENT

TERNARY:

    max = (a > b) ? a : b;

----------------------------------------

IF-ELSE:

    if (a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }

===============================================================================

WHEN TO USE?

GOOD:

    max = (a > b) ? a : b;

----------------------------------------

BAD:

    Multiple nested conditions.

    if-else is usually easier to read.

===============================================================================
*/

int main(void)
{
    int a = 20;
    int b = 15;

    int result;


    /*
    ===========================================================================
    1. BASIC TERNARY OPERATOR
    ===========================================================================
    */

    result = (a > b) ? a : b;

    /*
        Condition:

            20 > 15

            TRUE

        Result:

            20
    */

    printf("=====================================\n");
    printf("1. BASIC TERNARY OPERATOR\n");
    printf("=====================================\n");

    printf("Maximum = %d\n\n", result);



    /*
    ===========================================================================
    2. MINIMUM VALUE EXAMPLE
    ===========================================================================
    */

    result = (a < b) ? a : b;

    /*
        Condition:

            20 < 15

            FALSE

        Result:

            15
    */

    printf("=====================================\n");
    printf("2. MINIMUM VALUE EXAMPLE\n");
    printf("=====================================\n");

    printf("Minimum = %d\n\n", result);



    /*
    ===========================================================================
    3. EVEN OR ODD
    ===========================================================================
    */

    int number = 25;

    const char *message =
        (number % 2 == 0)
            ? "Even"
            : "Odd";

    printf("=====================================\n");
    printf("3. EVEN OR ODD\n");
    printf("=====================================\n");

    printf("%d is %s\n\n",
           number,
           message);



    /*
    ===========================================================================
    4. PASS OR FAIL
    ===========================================================================
    */

    int marks = 85;

    const char *result_text =
        (marks >= 35)
            ? "PASS"
            : "FAIL";

    printf("=====================================\n");
    printf("4. PASS OR FAIL\n");
    printf("=====================================\n");

    printf("Student Result = %s\n\n",
           result_text);



    /*
    ===========================================================================
    5. NESTED TERNARY OPERATOR
    ===========================================================================

    WARNING:

        Too much nesting reduces readability.

    Prefer if-else when logic becomes complex.
    */

    int x = 10;
    int y = 20;
    int z = 30;

    int maximum =
        (x > y)
            ? ((x > z) ? x : z)
            : ((y > z) ? y : z);

    printf("=====================================\n");
    printf("5. NESTED TERNARY OPERATOR\n");
    printf("=====================================\n");

    printf("Maximum = %d\n\n",
           maximum);



    /*
    ===========================================================================
    IF-ELSE VERSION OF ABOVE CODE
    ===========================================================================

    if (x > y)
    {
        if (x > z)
        {
            maximum = x;
        }
        else
        {
            maximum = z;
        }
    }
    else
    {
        if (y > z)
        {
            maximum = y;
        }
        else
        {
            maximum = z;
        }
    }

    ===========================================================================
    */



    /*
    ===========================================================================
    6. OPERATOR PRECEDENCE
    ===========================================================================

    Ternary operator has lower precedence
    than arithmetic operators.

    Example:

        a + b > c
            ? x
            : y

    Arithmetic executes first.

    Comparison executes second.

    Ternary executes last.
    ===========================================================================
    */

    int value =
        (10 + 5 > 12)
            ? 100
            : 200;

    printf("=====================================\n");
    printf("6. OPERATOR PRECEDENCE\n");
    printf("=====================================\n");

    printf("Value = %d\n\n",
           value);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    ADC THRESHOLD CHECK
    ===========================================================================
    */

    unsigned int adc_value = 3500U;

    const char *adc_status =
        (adc_value > 3000U)
            ? "HIGH"
            : "NORMAL";

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 1\n");
    printf("=====================================\n");

    printf("ADC Status = %s\n\n",
           adc_status);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    BATTERY MONITORING
    ===========================================================================
    */

    float battery_voltage = 3.1f;

    const char *battery_state =
        (battery_voltage < 3.3f)
            ? "LOW BATTERY"
            : "BATTERY OK";

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 2\n");
    printf("=====================================\n");

    printf("Battery State = %s\n\n",
           battery_state);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 3

    MOTOR CONTROL
    ===========================================================================
    */

    bool sensor_ready = true;

    const char *motor_state =
        sensor_ready
            ? "MOTOR START"
            : "MOTOR STOP";

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 3\n");
    printf("=====================================\n");

    printf("%s\n\n",
           motor_state);



    /*
    ===========================================================================
    COMMON MISTAKES
    ===========================================================================

    WRONG:

        a > b ? a;

    Missing false condition.

    ----------------------------------------

    WRONG:

        a > b ? a : b : c;

    Invalid syntax.

    ----------------------------------------

    HARD TO READ:

        a > b
            ? x
            : c > d
                ? y
                : z;

    Prefer if-else.

    ===========================================================================
    */



    /*
    ===========================================================================
    INTERVIEW QUESTIONS
    ===========================================================================

    Q1:

        Which operator is called
        the ternary operator?

        Answer:

            ? :

    ----------------------------------------

    Q2:

        Why is it called ternary?

        Answer:

            It uses three operands.

            condition
            true_value
            false_value

    ----------------------------------------

    Q3:

        Is ternary faster than if-else?

        Answer:

            Usually no practical difference.

            Compiler optimizations decide.

    ----------------------------------------

    Q4:

        When should nested ternary
        operators be avoided?

        Answer:

            When readability decreases.

    ===========================================================================
    */



    return 0;
}
