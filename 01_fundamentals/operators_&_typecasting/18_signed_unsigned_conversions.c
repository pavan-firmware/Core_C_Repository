#include <stdio.h>
#include <stdint.h>
#include <limits.h>

/*
===============================================================================
                18_SIGNED_UNSIGNED_CONVERSIONS.C
===============================================================================

TOPIC:
    Signed and Unsigned Conversions

STANDARD:
    C99, C11, C17, C23

===============================================================================

WHAT IS A SIGNED INTEGER?

Signed integers can store:

    Positive numbers
    Negative numbers
    Zero

Example:

    int x = -10;

Range (32-bit):

    -2147483648

        TO

     2147483647

===============================================================================

WHAT IS AN UNSIGNED INTEGER?

Unsigned integers store:

    Positive numbers
    Zero

Cannot store:

    Negative numbers

Example:

    unsigned int x = 10U;

Range (32-bit):

    0

        TO

    4294967295

===============================================================================

CONVERSION TABLE

+----------------------+----------------------+--------------------------+
| SOURCE               | DESTINATION          | SAFE?                    |
+----------------------+----------------------+--------------------------+
| signed int           | unsigned int         | NO                       |
| unsigned int         | signed int           | NO                       |
| int                  | uint8_t              | NO                       |
| uint8_t              | int                  | YES                      |
| positive int         | unsigned int         | YES                      |
+----------------------+----------------------+--------------------------+

===============================================================================

TWO'S COMPLEMENT

Most modern systems use:

    TWO'S COMPLEMENT

Example:

    int x = -1;

Binary:

    11111111
    11111111
    11111111
    11111111

Unsigned interpretation:

    4294967295

===============================================================================
*/


int main(void)
{
    /*
    ===========================================================================
    1. SIGNED TO UNSIGNED
    ===========================================================================
    */

    int signed_value = -1;

    unsigned int unsigned_value =
        (unsigned int)signed_value;

    printf("=========================================\n");
    printf("1. SIGNED TO UNSIGNED\n");
    printf("=========================================\n");

    printf("Signed Value   = %d\n",
           signed_value);

    printf("Unsigned Value = %u\n\n",
           unsigned_value);



    /*
    ===========================================================================
    MEMORY VISUALIZATION

    Signed:

        -1

    Binary:

        11111111
        11111111
        11111111
        11111111

    Unsigned:

        4294967295

    Same bits.

    Different interpretation.

    ===========================================================================
    */



    /*
    ===========================================================================
    2. UNSIGNED TO SIGNED
    ===========================================================================
    */

    unsigned int large_number =
        UINT_MAX;

    int converted_number =
        (int)large_number;

    printf("=========================================\n");
    printf("2. UNSIGNED TO SIGNED\n");
    printf("=========================================\n");

    printf("Unsigned = %u\n",
           large_number);

    printf("Signed   = %d\n\n",
           converted_number);



    /*
    ===========================================================================
    3. SAFE CONVERSION
    ===========================================================================
    */

    int positive_value = 100;

    unsigned int safe_unsigned =
        (unsigned int)positive_value;

    printf("=========================================\n");
    printf("3. SAFE CONVERSION\n");
    printf("=========================================\n");

    printf("Result = %u\n\n",
           safe_unsigned);



    /*
    ===========================================================================
    4. UINT8_T WRAPPING
    ===========================================================================
    */

    int large_integer = 300;

    uint8_t small_value =
        (uint8_t)large_integer;

    printf("=========================================\n");
    printf("4. UINT8_T WRAPPING\n");
    printf("=========================================\n");

    printf("Original Value = %d\n",
           large_integer);

    printf("Converted Value = %u\n\n",
           small_value);



    /*
    ===========================================================================
    CALCULATION

    uint8_t:

        Maximum:

            255

    Calculation:

        300 % 256

        44

    Result:

        44

    ===========================================================================
    */



    /*
    ===========================================================================
    5. SIGNED VS UNSIGNED COMPARISON
    ===========================================================================
    */

    int signed_number = -1;

    unsigned int unsigned_number = 1U;

    printf("=========================================\n");
    printf("5. SIGNED VS UNSIGNED COMPARISON\n");
    printf("=========================================\n");

    if (signed_number < (int)unsigned_number)
    {
        printf("-1 is smaller\n");
    }
    else
    {
        printf("-1 is NOT smaller\n");
    }

    printf("\n");



    /*
    ===========================================================================
    DANGER

    Compiler converts:

        signed_number

    into:

        unsigned int

    Therefore:

        -1

    becomes:

        4294967295

    Comparison:

        4294967295 < 1

    FALSE

    Very common bug in embedded systems.

    ===========================================================================
    */



    /*
    ===========================================================================
    6. LOOP BUG EXAMPLE
    ===========================================================================
    */

    printf("=========================================\n");
    printf("6. UNSIGNED LOOP BUG\n");
    printf("=========================================\n");

    /*
        WRONG:

        for (unsigned int i = 5; i >= 0; i--)

        Infinite loop!

        Reason:

            i never becomes negative.
    */

    printf("See comments for infinite-loop example.\n\n");



    /*
    ===========================================================================
    CORRECT VERSION

        for (int i = 5; i >= 0; i--)

    OR

        for (unsigned int i = 5; i > 0; i--)

    ===========================================================================
    */



    /*
    ===========================================================================
    7. EMBEDDED EXAMPLE

    ADC OFFSET CALCULATION
    ===========================================================================
    */

    uint16_t adc_reading = 1000U;

    int16_t offset = -50;

    int32_t corrected_value =
        (int32_t)adc_reading + offset;

    printf("=========================================\n");
    printf("7. ADC OFFSET\n");
    printf("=========================================\n");

    printf("Corrected ADC = %ld\n\n",
           (long)corrected_value);



    /*
    ===========================================================================
    WHY INT32_T?

    BAD:

        uint16_t + int16_t

    May cause unexpected conversions.

    GOOD:

        (int32_t)adc_reading

    Explicit conversion.

    Safer arithmetic.

    ===========================================================================
    */



    /*
    ===========================================================================
    8. EMBEDDED EXAMPLE

    TEMPERATURE SENSOR
    ===========================================================================
    */

    int8_t temperature = -10;

    uint8_t raw_data =
        (uint8_t)temperature;

    printf("=========================================\n");
    printf("8. TEMPERATURE SENSOR\n");
    printf("=========================================\n");

    printf("Temperature = %d\n",
           temperature);

    printf("Raw Data    = %u\n\n",
           raw_data);



    /*
    ===========================================================================
    Binary:

        -10

        11110110

    Unsigned:

        246

    ===========================================================================
    */



    /*
    ===========================================================================
    9. EMBEDDED EXAMPLE

    TIMER WRAPAROUND
    ===========================================================================
    */

    uint8_t timer_counter = 255;

    timer_counter++;

    printf("=========================================\n");
    printf("9. TIMER WRAPAROUND\n");
    printf("=========================================\n");

    printf("Counter = %u\n\n",
           timer_counter);



    /*
    ===========================================================================
    Calculation:

        255 + 1

        256

        256 % 256

        0

    Unsigned overflow:

        WELL DEFINED

    Signed overflow:

        UNDEFINED BEHAVIOR

    ===========================================================================
    */



    /*
    ===========================================================================
    SIGNED vs UNSIGNED OVERFLOW

    UNSIGNED:

        Defined by standard.

        Wrap around.

    Example:

        UINT_MAX + 1

        becomes

        0

    ----------------------------------------

    SIGNED:

        Undefined Behavior.

    Example:

        INT_MAX + 1

    Compiler may:

        • Wrap
        • Optimize away
        • Produce unexpected results

    Never rely on it.

    ===========================================================================
    */



    /*
    ===========================================================================
    MISRA C RECOMMENDATIONS

    AVOID:

        signed + unsigned

    AVOID:

        implicit sign conversions

    PREFER:

        Explicit casting.

    Example:

        int32_t result =
            (int32_t)adc_value + offset;

    Benefits:

        • Safer arithmetic
        • Easier debugging
        • Static analysis friendly
        • Better portability

    ===========================================================================
    */



    /*
    ===========================================================================
    INTERVIEW QUESTIONS
    ===========================================================================

    Q1:

        What happens when:

            (unsigned int)-1

        ?

        Answer:

            4294967295

            On 32-bit systems.

    ----------------------------------------

    Q2:

        Is unsigned overflow defined?

        Answer:

            YES

            It wraps around.

    ----------------------------------------

    Q3:

        Is signed overflow defined?

        Answer:

            NO

            Undefined Behavior.

    ----------------------------------------

    Q4:

        Why avoid signed and unsigned comparisons?

        Answer:

            Automatic conversions can
            produce unexpected results.

    ----------------------------------------

    Q5:

        Why is this dangerous?

            if (-1 < 1U)

        Answer:

            -1 becomes a large
            unsigned number.

    ===========================================================================
    */



    return 0;
}
