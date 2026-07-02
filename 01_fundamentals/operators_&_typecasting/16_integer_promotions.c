#include <stdio.h>
#include <stdint.h>
#include <limits.h>

/*
===============================================================================
                    16_INTEGER_PROMOTIONS.C
===============================================================================

TOPIC:
    Integer Promotions in C

STANDARD:
    C99, C11, C17, C23

===============================================================================

WHAT ARE INTEGER PROMOTIONS?

Definition:

    Integer promotions automatically convert smaller integer types
    into int or unsigned int before arithmetic operations occur.

-------------------------------------------------------------------------------

Examples:

    char  + char
    short + short
    uint8_t + uint8_t
    int8_t + int8_t

All become:

    int + int

before calculation.

===============================================================================

WHY DOES C DO THIS?

Reasons:

    1. CPU works efficiently with machine-word-sized integers.

    2. Prevent overflow during calculations.

    3. Historical compatibility.

    4. Standardized arithmetic behavior.

===============================================================================

INTEGER PROMOTION RULES

+-------------------+---------------------+------------------------+
| ORIGINAL TYPE     | PROMOTED TO         | CONDITION              |
+-------------------+---------------------+------------------------+
| char              | int                 | Usually                |
| signed char       | int                 | Usually                |
| unsigned char     | int                 | If int can hold value  |
| short             | int                 | Usually                |
| unsigned short    | int                 | If int can hold value  |
| enum              | int                 | Usually                |
+-------------------+---------------------+------------------------+

-------------------------------------------------------------------------------

If int CANNOT represent all values:

    unsigned int

is used instead.

===============================================================================

IMPORTANT RULE

SMALLER INTEGERS NEVER PARTICIPATE DIRECTLY
IN ARITHMETIC EXPRESSIONS.

Example:

    char a = 10;
    char b = 20;

    char c = a + b;

Actual Compiler Behavior:

    int temp1 = (int)a;

    int temp2 = (int)b;

    int temp3 = temp1 + temp2;

    char c = (char)temp3;

===============================================================================
*/


int main(void)
{
    /*
    ===========================================================================
    1. CHAR + CHAR
    ===========================================================================
    */

    char a = 10;
    char b = 20;

    int result = a + b;

    /*
        Actual:

            (int)a + (int)b

            10 + 20

            30
    */

    printf("=========================================\n");
    printf("1. CHAR + CHAR\n");
    printf("=========================================\n");

    printf("a      = %d\n", a);

    printf("b      = %d\n", b);

    printf("result = %d\n\n", result);



    /*
    ===========================================================================
    2. SIZEOF PROOF
    ===========================================================================
    */

    printf("=========================================\n");
    printf("2. SIZEOF PROOF\n");
    printf("=========================================\n");

    printf("sizeof(a)     = %zu bytes\n",
           sizeof(a));

    printf("sizeof(a+b)   = %zu bytes\n\n",
           sizeof(a + b));



    /*
        a:

            char

            1 byte

        a+b:

            int

            4 bytes (usually)

        PROOF:

            Integer promotion happened.
    */



    /*
    ===========================================================================
    3. SHORT + SHORT
    ===========================================================================
    */

    short x = 1000;
    short y = 2000;

    int short_result = x + y;

    printf("=========================================\n");
    printf("3. SHORT + SHORT\n");
    printf("=========================================\n");

    printf("Result = %d\n\n",
           short_result);



    /*
        Actual:

            (int)x + (int)y

            1000 + 2000

            3000
    */



    /*
    ===========================================================================
    4. UINT8_T + UINT8_T
    ===========================================================================
    */

    uint8_t adc1 = 100;
    uint8_t adc2 = 50;

    int adc_sum = adc1 + adc2;

    printf("=========================================\n");
    printf("4. UINT8_T + UINT8_T\n");
    printf("=========================================\n");

    printf("ADC Sum = %d\n\n",
           adc_sum);



    /*
        Actual:

            (int)100 + (int)50

            150
    */



    /*
    ===========================================================================
    5. INT8_T + INT8_T
    ===========================================================================
    */

    int8_t temperature1 = 20;
    int8_t temperature2 = 15;

    int temperature_sum =
        temperature1 + temperature2;

    printf("=========================================\n");
    printf("5. INT8_T + INT8_T\n");
    printf("=========================================\n");

    printf("Temperature Sum = %d\n\n",
           temperature_sum);



    /*
    ===========================================================================
    6. OVERFLOW PROTECTION EXAMPLE
    ===========================================================================
    */

    uint8_t value1 = 200;
    uint8_t value2 = 100;

    int total = value1 + value2;

    printf("=========================================\n");
    printf("6. OVERFLOW PROTECTION\n");
    printf("=========================================\n");

    printf("200 + 100 = %d\n\n",
           total);



    /*
        Without promotions:

            uint8_t:

                Maximum:

                    255

            200 + 100

                300

            Overflow!

        With promotions:

            int:

                300

            Safe.
    */



    /*
    ===========================================================================
    7. DANGEROUS ASSIGNMENT
    ===========================================================================
    */

    uint8_t small_result =
        value1 + value2;

    printf("=========================================\n");
    printf("7. DANGEROUS ASSIGNMENT\n");
    printf("=========================================\n");

    printf("Stored Value = %u\n\n",
           small_result);



    /*
        Expression:

            value1 + value2

        Produces:

            int

            300

        Assignment:

            uint8_t

        Result:

            300 % 256

            44
    */



    /*
    ===========================================================================
    8. EXPLICIT CASTING
    ===========================================================================
    */

    uint8_t safe_result =
        (uint8_t)(value1 + value2);

    printf("=========================================\n");
    printf("8. EXPLICIT CASTING\n");
    printf("=========================================\n");

    printf("Safe Result = %u\n\n",
           safe_result);



    /*
        MISRA prefers explicit conversions
        to make programmer intention clear.
    */



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    ADC AVERAGING
    ===========================================================================
    */

    uint16_t adc_channel_1 = 1000;
    uint16_t adc_channel_2 = 2000;

    uint32_t average =
        (adc_channel_1 + adc_channel_2) / 2U;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 1\n");
    printf("=========================================\n");

    printf("Average = %u\n\n",
           average);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    TEMPERATURE LOGGING
    ===========================================================================
    */

    int8_t temp_sensor_1 = 25;
    int8_t temp_sensor_2 = 30;

    int average_temp =
        (temp_sensor_1 + temp_sensor_2) / 2;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 2\n");
    printf("=========================================\n");

    printf("Average Temperature = %d\n\n",
           average_temp);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 3

    TIMER TICK COUNTER
    ===========================================================================
    */

    uint8_t tick1 = 100;
    uint8_t tick2 = 150;

    uint16_t total_ticks =
        tick1 + tick2;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 3\n");
    printf("=========================================\n");

    printf("Total Ticks = %u\n\n",
           total_ticks);



    /*
    ===========================================================================
    MEMORY VISUALIZATION

    uint8_t a

        1 byte

    uint8_t b

        1 byte

    Arithmetic:

        int + int

        4 bytes

    Result:

        int

    ===========================================================================
    */



    /*
    ===========================================================================
    MISRA C NOTES

    GOOD:

        uint16_t result =
            (uint16_t)(a + b);

    Better:

        uint32_t temp =
            (uint32_t)a + (uint32_t)b;

    Reason:

        Explicit conversions improve:

            • Safety
            • Readability
            • Static analysis
            • Maintainability

    ===========================================================================
    */



    /*
    ===========================================================================
    COMMON INTERVIEW QUESTIONS
    ===========================================================================

    Q1:

        Result type:

            char + char

        Answer:

            int

    ----------------------------------------

    Q2:

        Result type:

            short + short

        Answer:

            int

    ----------------------------------------

    Q3:

        Result type:

            uint8_t + uint8_t

        Answer:

            int

            Usually.

    ----------------------------------------

    Q4:

        Why do integer promotions exist?

        Answer:

            Better CPU efficiency
            and safer arithmetic.

    ----------------------------------------

    Q5:

        Does:

            sizeof(a + b)

        prove promotions?

        Answer:

            YES.

    ===========================================================================
    */



    return 0;
}
