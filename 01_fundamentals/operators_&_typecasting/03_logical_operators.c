#include <stdio.h>
#include <stdbool.h>

/*
===============================================================================
                    03_LOGICAL_OPERATORS.C
===============================================================================

TOPIC:
    Logical Operators in C

PURPOSE:
    Logical operators combine or invert conditions.

    They are mostly used in:

        • if statements
        • while loops
        • for loops
        • embedded decision making
        • state machines
        • safety systems

===============================================================================

LOGICAL OPERATORS TABLE

+------------+----------------+----------------------------+------------------+
| OPERATOR   | NAME           | DESCRIPTION                | EXAMPLE          |
+------------+----------------+----------------------------+------------------+
| &&         | Logical AND    | Both conditions must true  | a && b           |
| ||         | Logical OR     | At least one must be true  | a || b           |
| !          | Logical NOT    | Reverse true/false         | !a               |
+------------+----------------+----------------------------+------------------+

===============================================================================

TRUTH TABLE : LOGICAL AND (&&)

+-------+-------+----------+
|   A   |   B   |  A && B  |
+-------+-------+----------+
|   0   |   0   |    0     |
|   0   |   1   |    0     |
|   1   |   0   |    0     |
|   1   |   1   |    1     |
+-------+-------+----------+

===============================================================================

TRUTH TABLE : LOGICAL OR (||)

+-------+-------+----------+
|   A   |   B   |  A || B  |
+-------+-------+----------+
|   0   |   0   |    0     |
|   0   |   1   |    1     |
|   1   |   0   |    1     |
|   1   |   1   |    1     |
+-------+-------+----------+

===============================================================================

TRUTH TABLE : LOGICAL NOT (!)

+-------+-------+
|   A   |  !A   |
+-------+-------+
|   0   |   1   |
|   1   |   0   |
+-------+-------+

===============================================================================

IMPORTANT:

In C:

    0       -> FALSE
    Non-Zero -> TRUE

Examples:

    100  -> TRUE
    -10  -> TRUE
    1    -> TRUE
    0    -> FALSE

===============================================================================

SHORT-CIRCUIT EVALUATION

Logical operators stop evaluating when the result
is already known.

AND (&&)

    FALSE && Anything

Result:

    FALSE

Second condition is NOT evaluated.


OR (||)

    TRUE || Anything

Result:

    TRUE

Second condition is NOT evaluated.

This is called:

    SHORT-CIRCUIT EVALUATION

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
    int humidity = 65;
    int battery_percentage = 20;

    bool sensor_ready = true;
    bool wifi_connected = false;

    bool result = false;


    /*
    ===========================================================================
    1. LOGICAL AND (&&)
    ===========================================================================

    BOTH conditions must be TRUE.

    Example:

        temperature > 30

        AND

        humidity > 60

    TRUE && TRUE

    Result:

        TRUE
    */

    result =
        (temperature > 30) &&
        (humidity > 60);

    printf("=====================================\n");
    printf("LOGICAL AND (&&)\n");
    printf("=====================================\n");

    printf("(temperature > 30) && (humidity > 60)\n");

    printf("Result = %d\n\n", result);



    /*
    ===========================================================================
    2. LOGICAL OR (||)
    ===========================================================================

    AT LEAST ONE condition must be TRUE.

    Example:

        battery < 25

        OR

        wifi_connected

    TRUE || FALSE

    Result:

        TRUE
    */

    result =
        (battery_percentage < 25) ||
        (wifi_connected);

    printf("=====================================\n");
    printf("LOGICAL OR (||)\n");
    printf("=====================================\n");

    printf("(battery < 25) || (wifi_connected)\n");

    printf("Result = %d\n\n", result);



    /*
    ===========================================================================
    3. LOGICAL NOT (!)
    ===========================================================================

    Reverses TRUE and FALSE.

    TRUE  becomes FALSE

    FALSE becomes TRUE
    */

    result = !wifi_connected;

    printf("=====================================\n");
    printf("LOGICAL NOT (!)\n");
    printf("=====================================\n");

    printf("!wifi_connected\n");

    printf("Result = %d\n\n", result);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    Start motor only if:

        Sensor Ready

        AND

        Battery > 30%
    ===========================================================================
    */

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 1\n");
    printf("=====================================\n");

    if (sensor_ready && (battery_percentage > 30))
    {
        printf("Motor Started\n");
    }
    else
    {
        printf("Motor Cannot Start\n");
    }

    printf("\n");



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    Emergency Shutdown

    If:

        Temperature > 80

        OR

        Battery < 10
    ===========================================================================
    */

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 2\n");
    printf("=====================================\n");

    temperature = 85;

    if ((temperature > 80) ||
        (battery_percentage < 10))
    {
        printf("Emergency Shutdown Activated\n");
    }

    printf("\n");



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 3

    Device Sleep Mode

    If WiFi is NOT connected,
    enter low-power mode.
    ===========================================================================
    */

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 3\n");
    printf("=====================================\n");

    if (!wifi_connected)
    {
        printf("Entering Sleep Mode\n");
    }

    printf("\n");



    /*
    ===========================================================================
    SHORT-CIRCUIT EXAMPLE
    ===========================================================================
    */

    int x = 10;
    int y = 0;

    printf("=====================================\n");
    printf("SHORT-CIRCUIT EXAMPLE\n");
    printf("=====================================\n");

    /*
        First condition:

            y != 0

        FALSE

        Therefore:

            x / y

        Never executes.

        Division by zero avoided.
    */

    if ((y != 0) && (x / y > 2))
    {
        printf("Condition TRUE\n");
    }
    else
    {
        printf("Short-Circuit Prevented Division By Zero\n");
    }

    printf("\n");



    /*
    ===========================================================================
    EXPECTED OUTPUT

    =====================================
    LOGICAL AND (&&)
    =====================================
    Result = 1

    =====================================
    LOGICAL OR (||)
    =====================================
    Result = 1

    =====================================
    LOGICAL NOT (!)
    =====================================
    Result = 1

    =====================================
    EMBEDDED EXAMPLE 1
    =====================================
    Motor Cannot Start

    =====================================
    EMBEDDED EXAMPLE 2
    =====================================
    Emergency Shutdown Activated

    =====================================
    EMBEDDED EXAMPLE 3
    =====================================
    Entering Sleep Mode

    =====================================
    SHORT-CIRCUIT EXAMPLE
    =====================================
    Short-Circuit Prevented Division By Zero

    ===========================================================================
    */

    return 0;
}
