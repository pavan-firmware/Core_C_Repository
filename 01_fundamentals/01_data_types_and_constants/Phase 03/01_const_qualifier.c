#include <stdio.h>
#include <stdint.h>

/*
==============================================================================
                    01. CONST QUALIFIER IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. What is const?

2. Why use const?

3. Const Variables

4. Const Local Variables

5. Const Global Variables

6. Pointer to Const

7. Const Pointer

8. Const Pointer to Const

9. Function Parameters with const

10. Embedded Firmware Examples

11. Common Beginner Mistakes

==============================================================================


WHAT IS const?
==============================================================================

const means:

    Read Only

Once initialized,
the value cannot be modified.

Example:

    const int MAX_USERS = 100;

    MAX_USERS = 200;

Result:

    Compiler Error

==============================================================================


WHY USE const?
==============================================================================

Advantages:

    ✓ Prevents Accidental Changes

    ✓ Improves Code Safety

    ✓ Self Documentation

    ✓ Compiler Optimizations

    ✓ Better API Design

==============================================================================


CONST VARIABLE SYNTAX
==============================================================================

const int value = 100;

Equivalent:

int const value = 100;

Both are exactly same.

==============================================================================


POINTER COMBINATIONS
==============================================================================

+--------------------------------+-----------------------------+
| Declaration                    | Meaning                     |
+--------------------------------+-----------------------------+
| const int *ptr                 | Pointer to Const            |
| int *const ptr                 | Const Pointer               |
| const int *const ptr           | Const Pointer to Const      |
+--------------------------------+-----------------------------+

==============================================================================


POINTER TO CONST
==============================================================================

const int *ptr;

Can Change:

    ptr = &another_variable;

Cannot Change:

    *ptr = 100;

==============================================================================


CONST POINTER
==============================================================================

int *const ptr = &value;

Can Change:

    *ptr = 100;

Cannot Change:

    ptr = &another_variable;

==============================================================================


CONST POINTER TO CONST
==============================================================================

const int *const ptr = &value;

Cannot Change:

    *ptr

Cannot Change:

    ptr

==============================================================================


EMBEDDED USE CASES
==============================================================================

Common Uses:

    ✓ Hardware Configuration

    ✓ Lookup Tables

    ✓ Driver APIs

    ✓ Function Parameters

    ✓ Calibration Data

==============================================================================
*/


/*
------------------------------------------------------------------------------
GLOBAL CONSTANTS
------------------------------------------------------------------------------
*/

const uint32_t SYSTEM_CLOCK_HZ = 72000000U;

const float ADC_REFERENCE_VOLTAGE = 3.3F;


/*
------------------------------------------------------------------------------
FUNCTION:

READ ONLY STRING
------------------------------------------------------------------------------
*/

void print_device_name(const char *device_name)
{
    /*
        Cannot modify:

            device_name[0]

        because:

            Pointer To Const
    */

    printf("Device Name = %s\n",
           device_name);
}


/*
------------------------------------------------------------------------------
FUNCTION:

READ ONLY SENSOR DATA
------------------------------------------------------------------------------
*/

void print_temperature(const float *temperature)
{
    printf("Temperature = %.2f C\n",
           *temperature);
}


int main(void)
{
    /*
    ==========================================================================
    CONST LOCAL VARIABLES
    ==========================================================================
    */

    const int max_users = 100;

    const float pi = 3.14159F;

    printf("==================================================\n");
    printf("CONST LOCAL VARIABLES\n");
    printf("==================================================\n\n");

    printf("Max Users = %d\n",
           max_users);

    printf("PI        = %.5f\n",
           pi);


    /*
    ==========================================================================
    CONST GLOBAL VARIABLES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("CONST GLOBAL VARIABLES\n");
    printf("==================================================\n\n");

    printf("System Clock = %u Hz\n",
           SYSTEM_CLOCK_HZ);

    printf("ADC VREF     = %.2f V\n",
           ADC_REFERENCE_VOLTAGE);


    /*
    ==========================================================================
    POINTER TO CONST
    ==========================================================================
    */

    int sensor_value = 100;

    int another_value = 200;

    const int *ptr_to_const =
        &sensor_value;

    printf("\n");
    printf("==================================================\n");
    printf("POINTER TO CONST\n");
    printf("==================================================\n\n");

    printf("Value = %d\n",
           *ptr_to_const);

    /*
        Allowed:

            Change pointer
    */

    ptr_to_const = &another_value;

    printf("New Value = %d\n",
           *ptr_to_const);


    /*
        NOT ALLOWED:

        *ptr_to_const = 300;
    */


    /*
    ==========================================================================
    CONST POINTER
    ==========================================================================
    */

    int value = 500;

    int *const const_pointer =
        &value;

    printf("\n");
    printf("==================================================\n");
    printf("CONST POINTER\n");
    printf("==================================================\n\n");

    printf("Before = %d\n",
           *const_pointer);

    *const_pointer = 600;

    printf("After  = %d\n",
           *const_pointer);


    /*
        NOT ALLOWED:

        const_pointer = &sensor_value;
    */


    /*
    ==========================================================================
    CONST POINTER TO CONST
    ==========================================================================
    */

    const int fixed_value = 1000;

    const int *const fully_const_pointer =
        &fixed_value;

    printf("\n");
    printf("==================================================\n");
    printf("CONST POINTER TO CONST\n");
    printf("==================================================\n\n");

    printf("Value = %d\n",
           *fully_const_pointer);


    /*
        NOT ALLOWED:

        *fully_const_pointer = 10;

        fully_const_pointer = &value;
    */


    /*
    ==========================================================================
    FUNCTION PARAMETERS
    ==========================================================================
    */

    const char board_name[] =
        "STM32F407 Discovery";

    float room_temperature = 27.5F;

    printf("\n");
    printf("==================================================\n");
    printf("CONST FUNCTION PARAMETERS\n");
    printf("==================================================\n\n");

    print_device_name(board_name);

    print_temperature(&room_temperature);


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    const uint16_t adc_resolution = 4095U;

    const uint8_t uart_stop_bits = 1U;

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLES\n");
    printf("==================================================\n\n");

    printf("ADC Resolution = %u\n",
           adc_resolution);

    printf("UART Stop Bits = %u\n",
           uart_stop_bits);


    /*
    ==========================================================================
    INDUSTRY BEST PRACTICES
    ==========================================================================

    GOOD:

        void function(const char *str);

    Reason:

        Function promises
        not to modify data.

    ------------------------------------------------------------

    GOOD:

        const uint32_t clock = 72000000U;

    Better than:

        #define CLOCK 72000000

    because:

        Type safety exists.

    ------------------------------------------------------------

    GOOD:

        const lookup tables

    for:

        CRC

        Sine Waves

        Calibration Data

    ==========================================================================
    */


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        const means:

            Compile Time Constant

    Reality:

        const means:

            Read Only Variable

    ------------------------------------------------------------

    WRONG:

        Confusing:

            const int *ptr

        with:

            int *const ptr

    They are completely different.

    ------------------------------------------------------------

    WRONG:

        Not using const
        in function parameters.

    Better:

        Add const whenever
        modification is not required.

    ==========================================================================
    */

    return 0;
}
