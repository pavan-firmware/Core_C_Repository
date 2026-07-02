#include <stdio.h>
#include <stdbool.h>

/*
===============================================================================
                    02_RELATIONAL_OPERATORS.C
===============================================================================

TOPIC:
    Relational Operators in C

PURPOSE:
    Relational operators compare two values.

    The result is always:

        true  (1)
        false (0)

===============================================================================

RELATIONAL OPERATORS TABLE

+------------+---------------------------+--------------------------+
| OPERATOR   | NAME                      | EXAMPLE                  |
+------------+---------------------------+--------------------------+
| ==         | Equal To                  | a == b                   |
| !=         | Not Equal To              | a != b                   |
| >          | Greater Than              | a > b                    |
| <          | Less Than                 | a < b                    |
| >=         | Greater Than Or Equal To  | a >= b                   |
| <=         | Less Than Or Equal To     | a <= b                   |
+------------+---------------------------+--------------------------+

===============================================================================

IMPORTANT:

TRUE  = 1
FALSE = 0

In C:

    Any non-zero value = TRUE
    Zero               = FALSE

===============================================================================

COMMON BEGINNER MISTAKES

WRONG:

    if (a = b)

RIGHT:

    if (a == b)

Reason:

    =  --> Assignment Operator
    == --> Comparison Operator

===============================================================================
*/

int main(void)
{
    /*
    ===========================================================================
    INPUT VALUES
    ===========================================================================
    */

    int temperature = 35;
    int threshold   = 30;
    int set_point   = 35;

    bool result = false;


    /*
    ===========================================================================
    1. EQUAL TO (==)
    ===========================================================================

    Checks whether both values are equal.

    Example:

        35 == 35

        Result:

            TRUE (1)
    */

    result = (temperature == set_point);

    printf("=====================================\n");
    printf("EQUAL TO (==)\n");
    printf("=====================================\n");

    printf("%d == %d --> %d\n\n",
           temperature,
           set_point,
           result);



    /*
    ===========================================================================
    2. NOT EQUAL TO (!=)
    ===========================================================================

    Checks whether values are different.

    Example:

        35 != 30

        Result:

            TRUE (1)
    */

    result = (temperature != threshold);

    printf("=====================================\n");
    printf("NOT EQUAL TO (!=)\n");
    printf("=====================================\n");

    printf("%d != %d --> %d\n\n",
           temperature,
           threshold,
           result);



    /*
    ===========================================================================
    3. GREATER THAN (>)
    ===========================================================================

    Example:

        35 > 30

        Result:

            TRUE (1)
    */

    result = (temperature > threshold);

    printf("=====================================\n");
    printf("GREATER THAN (>)\n");
    printf("=====================================\n");

    printf("%d > %d --> %d\n\n",
           temperature,
           threshold,
           result);



    /*
    ===========================================================================
    4. LESS THAN (<)
    ===========================================================================

    Example:

        35 < 30

        Result:

            FALSE (0)
    */

    result = (temperature < threshold);

    printf("=====================================\n");
    printf("LESS THAN (<)\n");
    printf("=====================================\n");

    printf("%d < %d --> %d\n\n",
           temperature,
           threshold,
           result);



    /*
    ===========================================================================
    5. GREATER THAN OR EQUAL TO (>=)
    ===========================================================================

    Example:

        35 >= 35

        Result:

            TRUE (1)
    */

    result = (temperature >= set_point);

    printf("=====================================\n");
    printf("GREATER THAN OR EQUAL TO (>=)\n");
    printf("=====================================\n");

    printf("%d >= %d --> %d\n\n",
           temperature,
           set_point,
           result);



    /*
    ===========================================================================
    6. LESS THAN OR EQUAL TO (<=)
    ===========================================================================

    Example:

        30 <= 35

        Result:

            TRUE (1)
    */

    result = (threshold <= temperature);

    printf("=====================================\n");
    printf("LESS THAN OR EQUAL TO (<=)\n");
    printf("=====================================\n");

    printf("%d <= %d --> %d\n\n",
           threshold,
           temperature,
           result);



    /*
    ===========================================================================
    EMBEDDED SYSTEM EXAMPLES
    ===========================================================================
    */


    /*
    --------------------------------------------------
    Example 1:

    Temperature Protection System
    --------------------------------------------------
    */

    if (temperature > threshold)
    {
        printf("WARNING: Temperature exceeds threshold!\n");
    }


    /*
    --------------------------------------------------
    Example 2:

    ADC Range Validation
    --------------------------------------------------
    */

    unsigned int adc_value = 4095U;

    if (adc_value <= 4095U)
    {
        printf("ADC value is valid.\n");
    }


    /*
    --------------------------------------------------
    Example 3:

    Battery Low Detection
    --------------------------------------------------
    */

    float battery_voltage = 3.2f;

    if (battery_voltage < 3.3f)
    {
        printf("Battery Low!\n");
    }


    /*
    ===========================================================================
    EXPECTED OUTPUT

    =====================================
    EQUAL TO (==)
    =====================================
    35 == 35 --> 1

    =====================================
    NOT EQUAL TO (!=)
    =====================================
    35 != 30 --> 1

    =====================================
    GREATER THAN (>)
    =====================================
    35 > 30 --> 1

    =====================================
    LESS THAN (<)
    =====================================
    35 < 30 --> 0

    =====================================
    GREATER THAN OR EQUAL TO (>=)
    =====================================
    35 >= 35 --> 1

    =====================================
    LESS THAN OR EQUAL TO (<=)
    =====================================
    30 <= 35 --> 1

    WARNING: Temperature exceeds threshold!
    ADC value is valid.
    Battery Low!

    ===========================================================================
    */

    return 0;
}
