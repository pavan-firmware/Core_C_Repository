#include <stdio.h>

/*
==============================================================================
                        01. ENUM TYPES IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. What is enum?

2. Why use enum?

3. Basic enum Syntax

4. Automatic Enumerator Values

5. Explicit Enumerator Values

6. Enum Variables

7. Enum Size

8. Switch Case with enum

9. Embedded Firmware Examples

10. Common Beginner Mistakes

==============================================================================


WHAT IS AN ENUM?
==============================================================================

enum means:

    User-defined integer constants.

Instead of writing:

    led_state = 0;
    led_state = 1;

We can write:

    led_state = LED_OFF;
    led_state = LED_ON;

This makes code:

    ✓ More Readable
    ✓ Easier to Maintain
    ✓ Easier to Debug
    ✓ Self-Documenting

==============================================================================


BASIC ENUM SYNTAX
==============================================================================

enum LedState
{
    LED_OFF,
    LED_ON
};

Actual Values:

    LED_OFF = 0
    LED_ON  = 1

Compiler automatically assigns values.

==============================================================================


AUTOMATIC ENUM VALUES
==============================================================================

enum Color
{
    RED,
    GREEN,
    BLUE,
    WHITE
};

Compiler Assigns:

    RED   = 0
    GREEN = 1
    BLUE  = 2
    WHITE = 3

==============================================================================


EXPLICIT ENUM VALUES
==============================================================================

enum ErrorCode
{
    ERROR_NONE  = 0,
    ERROR_UART  = 100,
    ERROR_SPI   = 200,
    ERROR_I2C   = 300
};

==============================================================================


EMBEDDED FIRMWARE USE CASES
==============================================================================

Enums are commonly used for:

    ✓ State Machines

    ✓ Error Codes

    ✓ Driver States

    ✓ Communication Protocols

    ✓ Menu Systems

    ✓ Task States

    ✓ Device Modes

==============================================================================
*/


/*
------------------------------------------------------------------------------
LED STATES
------------------------------------------------------------------------------
*/

enum LedState
{
    LED_OFF,
    LED_ON
};


/*
------------------------------------------------------------------------------
SYSTEM STATES
------------------------------------------------------------------------------
*/

enum SystemState
{
    SYSTEM_IDLE,
    SYSTEM_RUNNING,
    SYSTEM_SLEEP,
    SYSTEM_ERROR
};


/*
------------------------------------------------------------------------------
ERROR CODES
------------------------------------------------------------------------------
*/

enum ErrorCode
{
    ERROR_NONE      = 0,
    ERROR_UART_FAIL = 100,
    ERROR_SPI_FAIL  = 200,
    ERROR_I2C_FAIL  = 300
};


/*
------------------------------------------------------------------------------
DEVICE MODES
------------------------------------------------------------------------------
*/

enum DeviceMode
{
    MODE_LOW_POWER   = 1,
    MODE_NORMAL      = 5,
    MODE_PERFORMANCE = 10
};


int main(void)
{
    /*
    ==========================================================================
    ENUM VARIABLES
    ==========================================================================
    */

    enum LedState led_status =
        LED_ON;

    enum SystemState current_state =
        SYSTEM_RUNNING;

    enum ErrorCode error_status =
        ERROR_UART_FAIL;

    enum DeviceMode device_mode =
        MODE_PERFORMANCE;


    /*
    ==========================================================================
    AUTOMATIC ENUM VALUES
    ==========================================================================
    */

    printf("==================================================\n");
    printf("AUTOMATIC ENUM VALUES\n");
    printf("==================================================\n\n");

    printf("LED_OFF        = %d\n",
           LED_OFF);

    printf("LED_ON         = %d\n",
           LED_ON);

    printf("\n");

    printf("SYSTEM_IDLE    = %d\n",
           SYSTEM_IDLE);

    printf("SYSTEM_RUNNING = %d\n",
           SYSTEM_RUNNING);

    printf("SYSTEM_SLEEP   = %d\n",
           SYSTEM_SLEEP);

    printf("SYSTEM_ERROR   = %d\n",
           SYSTEM_ERROR);


    /*
    ==========================================================================
    EXPLICIT ENUM VALUES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("EXPLICIT ENUM VALUES\n");
    printf("==================================================\n\n");

    printf("ERROR_NONE      = %d\n",
           ERROR_NONE);

    printf("ERROR_UART_FAIL = %d\n",
           ERROR_UART_FAIL);

    printf("ERROR_SPI_FAIL  = %d\n",
           ERROR_SPI_FAIL);

    printf("ERROR_I2C_FAIL  = %d\n",
           ERROR_I2C_FAIL);


    /*
    ==========================================================================
    DEVICE MODES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("DEVICE MODES\n");
    printf("==================================================\n\n");

    printf("MODE_LOW_POWER   = %d\n",
           MODE_LOW_POWER);

    printf("MODE_NORMAL      = %d\n",
           MODE_NORMAL);

    printf("MODE_PERFORMANCE = %d\n",
           MODE_PERFORMANCE);


    /*
    ==========================================================================
    ENUM VARIABLES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("ENUM VARIABLES\n");
    printf("==================================================\n\n");

    printf("LED Status    = %d\n",
           led_status);

    printf("System State  = %d\n",
           current_state);

    printf("Error Status  = %d\n",
           error_status);

    printf("Device Mode   = %d\n",
           device_mode);


    /*
    ==========================================================================
    SWITCH CASE WITH ENUM
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("SWITCH CASE WITH ENUM\n");
    printf("==================================================\n\n");

    switch (current_state)
    {
        case SYSTEM_IDLE:

            printf("System State : IDLE\n");

            break;


        case SYSTEM_RUNNING:

            printf("System State : RUNNING\n");

            break;


        case SYSTEM_SLEEP:

            printf("System State : SLEEP\n");

            break;


        case SYSTEM_ERROR:

            printf("System State : ERROR\n");

            break;


        default:

            printf("Unknown State\n");

            break;
    }


    /*
    ==========================================================================
    ENUM SIZE
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("ENUM SIZE\n");
    printf("==================================================\n\n");

    printf("sizeof(enum LedState)    = %zu bytes\n",
           sizeof(enum LedState));

    printf("sizeof(enum SystemState) = %zu bytes\n",
           sizeof(enum SystemState));

    printf("sizeof(enum ErrorCode)   = %zu bytes\n",
           sizeof(enum ErrorCode));


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    enum SystemState firmware_state =
        SYSTEM_IDLE;

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED FIRMWARE EXAMPLES\n");
    printf("==================================================\n\n");

    if (firmware_state == SYSTEM_IDLE)
    {
        printf("Firmware Waiting For Events\n");
    }

    if (led_status == LED_ON)
    {
        printf("LED Driver Enabled\n");
    }

    if (error_status == ERROR_UART_FAIL)
    {
        printf("UART Communication Error\n");
    }


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        led_state = 1;

    BETTER:

        led_state = LED_ON;

    ------------------------------------------------------------

    WRONG:

        Assuming enum size
        is always 4 bytes.

    Reality:

        Compiler dependent.

    ------------------------------------------------------------

    WRONG:

        Using magic numbers:

            error = 300;

    BETTER:

            error = ERROR_I2C_FAIL;

    ------------------------------------------------------------

    BEST PRACTICE:

        Use enums for:

            States
            Error Codes
            Modes
            Driver Status

    ==========================================================================
    */

    return 0;
}
