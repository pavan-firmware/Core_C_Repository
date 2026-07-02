#include <stdio.h>
#include <stdbool.h>

/*
==============================================================================
                            04. BOOLEAN TYPE IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. _Bool (Built-in C99 Type)

2. bool
   true
   false

3. <stdbool.h>

4. Boolean Expressions

5. Relational Operators

6. Logical Operators

7. Boolean Flags

8. State Machines

9. Embedded Firmware Examples

10. Common Beginner Mistakes

==============================================================================


BOOLEAN TYPES
==============================================================================

+----------------+--------+-------------+-------------+
| Type           | Bytes  | False Value | True Value  |
+----------------+--------+-------------+-------------+
| _Bool          |   1    |      0      |      1      |
| bool           |   1    |    false    |    true     |
+----------------+--------+-------------+-------------+

NOTE:
------

bool is NOT a keyword.

It comes from:

    #include <stdbool.h>

Actually:

    bool  -> _Bool
    true  -> 1
    false -> 0

==============================================================================


BOOLEAN CONVERSIONS
==============================================================================

+----------------+----------------+
| Value          | Boolean Result |
+----------------+----------------+
| 0              | false          |
| 1              | true           |
| -1             | true           |
| 100            | true           |
| 255            | true           |
+----------------+----------------+

RULE:
------

Only ZERO is FALSE.

Everything else is TRUE.

==============================================================================


RELATIONAL OPERATORS
==============================================================================

+----------------+----------------+
| Expression     | Result         |
+----------------+----------------+
| 10 > 5         | true           |
| 10 < 5         | false          |
| 10 == 10       | true           |
| 10 != 20       | true           |
| 10 >= 5        | true           |
| 10 <= 5        | false          |
+----------------+----------------+

==============================================================================


LOGICAL OPERATORS
==============================================================================

+----------------+----------------+
| Operator       | Meaning        |
+----------------+----------------+
| &&             | Logical AND    |
| ||             | Logical OR     |
| !              | Logical NOT    |
+----------------+----------------+

==============================================================================


TRUTH TABLE
==============================================================================

AND (&&)

+-------+-------+--------+
|   A   |   B   | Result |
+-------+-------+--------+
| false | false | false  |
| false | true  | false  |
| true  | false | false  |
| true  | true  | true   |
+-------+-------+--------+


OR (||)

+-------+-------+--------+
|   A   |   B   | Result |
+-------+-------+--------+
| false | false | false  |
| false | true  | true   |
| true  | false | true   |
| true  | true  | true   |
+-------+-------+--------+


NOT (!)

+-------+--------+
|   A   | Result |
+-------+--------+
| false | true   |
| true  | false  |
+-------+--------+

==============================================================================
*/


/*
------------------------------------------------------------------------------
Embedded State Machine
------------------------------------------------------------------------------
*/

typedef enum
{
    SYSTEM_IDLE = 0,
    SYSTEM_RUNNING,
    SYSTEM_ERROR
}
SystemState;


/*
------------------------------------------------------------------------------
Compile-Time Constants
------------------------------------------------------------------------------
*/

#define TEMPERATURE_LIMIT    50
#define VOLTAGE_LIMIT        3.3f


int main(void)
{
    /*
    ==========================================================================
    1. BASIC BOOLEAN VARIABLES
    ==========================================================================
    */

    bool sensor_ready = true;

    bool motor_running = false;


    /*
    ==========================================================================
    2. _Bool TYPE
    ==========================================================================

    Actual built-in type introduced in C99.
    */

    _Bool system_initialized = 1;

    _Bool communication_error = 0;


    /*
    ==========================================================================
    3. BOOLEAN EXPRESSIONS
    ==========================================================================
    */

    int temperature = 45;

    bool temperature_safe =
        (temperature < TEMPERATURE_LIMIT);


    /*
    ==========================================================================
    4. RELATIONAL OPERATORS
    ==========================================================================
    */

    bool greater_than =
        (100 > 50);

    bool equal_to =
        (10 == 10);

    bool not_equal =
        (20 != 30);


    /*
    ==========================================================================
    5. LOGICAL OPERATORS
    ==========================================================================
    */

    bool system_power_ok = true;

    bool communication_ok = true;

    bool system_ready =
        (system_power_ok && communication_ok);

    bool alarm_condition =
        (motor_running || communication_error);

    bool inverter_output =
        !motor_running;


    /*
    ==========================================================================
    PRINT BASIC VALUES
    ==========================================================================
    */

    printf("==================================================\n");
    printf("BOOLEAN VARIABLES\n");
    printf("==================================================\n\n");

    printf("sensor_ready          = %d\n",
           sensor_ready);

    printf("motor_running         = %d\n",
           motor_running);

    printf("system_initialized    = %d\n",
           system_initialized);

    printf("communication_error   = %d\n",
           communication_error);


    /*
    ==========================================================================
    PRINT BOOLEAN EXPRESSIONS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("BOOLEAN EXPRESSIONS\n");
    printf("==================================================\n\n");

    printf("temperature_safe      = %d\n",
           temperature_safe);

    printf("greater_than          = %d\n",
           greater_than);

    printf("equal_to              = %d\n",
           equal_to);

    printf("not_equal             = %d\n",
           not_equal);


    /*
    ==========================================================================
    PRINT LOGICAL OPERATORS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("LOGICAL OPERATORS\n");
    printf("==================================================\n\n");

    printf("system_ready          = %d\n",
           system_ready);

    printf("alarm_condition       = %d\n",
           alarm_condition);

    printf("inverter_output       = %d\n",
           inverter_output);


    /*
    ==========================================================================
    BOOLEAN CONVERSION DEMONSTRATION
    ==========================================================================
    */

    bool value1 = 0;
    bool value2 = 1;
    bool value3 = -100;
    bool value4 = 255;

    printf("\n");
    printf("==================================================\n");
    printf("BOOLEAN CONVERSIONS\n");
    printf("==================================================\n\n");

    printf("0     -> %d\n", value1);
    printf("1     -> %d\n", value2);
    printf("-100  -> %d\n", value3);
    printf("255   -> %d\n", value4);


    /*
    ==========================================================================
    STATE MACHINE EXAMPLE
    ==========================================================================
    */

    SystemState current_state =
        SYSTEM_RUNNING;

    printf("\n");
    printf("==================================================\n");
    printf("STATE MACHINE EXAMPLE\n");
    printf("==================================================\n\n");

    if (current_state == SYSTEM_IDLE)
    {
        printf("System State : IDLE\n");
    }
    else if (current_state == SYSTEM_RUNNING)
    {
        printf("System State : RUNNING\n");
    }
    else
    {
        printf("System State : ERROR\n");
    }


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    bool uart_initialized = true;

    bool spi_initialized = true;

    bool i2c_initialized = false;

    bool peripherals_ready =
        (uart_initialized &&
         spi_initialized &&
         i2c_initialized);

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLES\n");
    printf("==================================================\n\n");

    printf("UART Ready            = %d\n",
           uart_initialized);

    printf("SPI Ready             = %d\n",
           spi_initialized);

    printf("I2C Ready             = %d\n",
           i2c_initialized);

    printf("All Peripherals Ready = %d\n",
           peripherals_ready);


    /*
    ==========================================================================
    TYPE SIZE
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("TYPE SIZE\n");
    printf("==================================================\n\n");

    printf("sizeof(bool)          = %zu bytes\n",
           sizeof(bool));

    printf("sizeof(_Bool)         = %zu bytes\n",
           sizeof(_Bool));


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        if (flag == true)

    Better:

        if (flag)

    ------------------------------------------------------------

    WRONG:

        if (flag == false)

    Better:

        if (!flag)

    ------------------------------------------------------------

    WRONG:

        bool value = 100;

    Result:

        value = true

    Because:

        Any non-zero value becomes TRUE.

    ------------------------------------------------------------

    bool is NOT a keyword.

    It requires:

        #include <stdbool.h>

    ==========================================================================
    */

    return 0;
}
