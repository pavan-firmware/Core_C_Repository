#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <math.h>

/*
===============================================================================
                19_FLOAT_INTEGER_CONVERSIONS.C
===============================================================================

TOPIC:
    Float and Integer Conversions

STANDARD:
    C99, C11, C17, C23

===============================================================================

CONVERSION TYPES

+----------------------+----------------------+--------------------------+
| SOURCE               | DESTINATION          | SAFE?                    |
+----------------------+----------------------+--------------------------+
| int                  | float                | Usually                  |
| int                  | double               | Yes                      |
| float                | int                  | Data Loss Possible       |
| double               | int                  | Data Loss Possible       |
| float                | uint8_t              | Overflow Possible        |
| double               | float                | Precision Loss Possible  |
+----------------------+----------------------+--------------------------+

===============================================================================

IMPORTANT RULE

INTEGER TO FLOAT

    Usually safe.

FLOAT TO INTEGER

    Decimal part is REMOVED.

    This is called:

        TRUNCATION

NOT:

    ROUNDING

===============================================================================

TRUNCATION EXAMPLES

+-------------+-------------+
| FLOAT       | INT RESULT  |
+-------------+-------------+
| 10.9        | 10          |
| 10.1        | 10          |
| -5.8        | -5          |
| -5.1        | -5          |
+-------------+-------------+

===============================================================================

ROUNDING vs TRUNCATION

TRUNCATION:

    (int)3.9

    Result:

        3

----------------------------------------

ROUNDING:

    round(3.9)

    Result:

        4

===============================================================================
*/


int main(void)
{
    /*
    ===========================================================================
    1. INT TO FLOAT
    ===========================================================================
    */

    int count = 100;

    float count_float =
        (float)count;

    printf("=========================================\n");
    printf("1. INT TO FLOAT\n");
    printf("=========================================\n");

    printf("Integer = %d\n", count);

    printf("Float   = %.2f\n\n",
           count_float);



    /*
    ===========================================================================
    2. INT TO DOUBLE
    ===========================================================================
    */

    int temperature = 25;

    double temperature_double =
        (double)temperature;

    printf("=========================================\n");
    printf("2. INT TO DOUBLE\n");
    printf("=========================================\n");

    printf("Double = %.15lf\n\n",
           temperature_double);



    /*
    ===========================================================================
    3. FLOAT TO INT
    ===========================================================================
    */

    float voltage = 3.99f;

    int voltage_int =
        (int)voltage;

    printf("=========================================\n");
    printf("3. FLOAT TO INT\n");
    printf("=========================================\n");

    printf("Float   = %.2f\n", voltage);

    printf("Integer = %d\n\n",
           voltage_int);



    /*
        TRUNCATION:

            3.99

            ↓

            3
    */



    /*
    ===========================================================================
    4. NEGATIVE FLOAT TO INT
    ===========================================================================
    */

    float negative_value = -5.87f;

    int negative_integer =
        (int)negative_value;

    printf("=========================================\n");
    printf("4. NEGATIVE FLOAT TO INT\n");
    printf("=========================================\n");

    printf("Float   = %.2f\n",
           negative_value);

    printf("Integer = %d\n\n",
           negative_integer);



    /*
        TRUNCATION:

            -5.87

            ↓

            -5
    */



    /*
    ===========================================================================
    5. ROUNDING EXAMPLE
    ===========================================================================
    */

    float number = 3.8f;

    int truncation_result =
        (int)number;

    int rounding_result =
        (int)roundf(number);

    printf("=========================================\n");
    printf("5. ROUNDING vs TRUNCATION\n");
    printf("=========================================\n");

    printf("Original   = %.2f\n", number);

    printf("Truncation = %d\n",
           truncation_result);

    printf("Rounding   = %d\n\n",
           rounding_result);



    /*
    ===========================================================================
    6. DOUBLE TO FLOAT
    ===========================================================================
    */

    double pi =
        3.141592653589793;

    float pi_float =
        (float)pi;

    printf("=========================================\n");
    printf("6. DOUBLE TO FLOAT\n");
    printf("=========================================\n");

    printf("Double = %.15lf\n", pi);

    printf("Float  = %.7f\n\n",
           pi_float);



    /*
        Some precision is lost.

        double:

            ~15 digits

        float:

            ~7 digits
    */



    /*
    ===========================================================================
    7. LARGE INTEGER TO FLOAT
    ===========================================================================
    */

    int large_integer =
        16777217;

    float float_value =
        (float)large_integer;

    printf("=========================================\n");
    printf("7. LARGE INTEGER TO FLOAT\n");
    printf("=========================================\n");

    printf("Integer = %d\n",
           large_integer);

    printf("Float   = %.0f\n\n",
           float_value);



    /*
        float:

            24 bits precision

        Not all large integers
        can be represented exactly.
    */



    /*
    ===========================================================================
    8. FLOAT TO UINT8_T
    ===========================================================================
    */

    float sensor_data = 300.75f;

    uint8_t byte_data =
        (uint8_t)sensor_data;

    printf("=========================================\n");
    printf("8. FLOAT TO UINT8_T\n");
    printf("=========================================\n");

    printf("Float Value = %.2f\n",
           sensor_data);

    printf("Byte Value  = %u\n\n",
           byte_data);



    /*
        Step 1:

            300.75

                ↓

            300

        Step 2:

            300 % 256

                ↓

            44
    */



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    ADC TO VOLTAGE
    ===========================================================================
    */

    uint16_t adc_value = 2048;

    float adc_voltage =
        ((float)adc_value * 3.3f)
        / 4095.0f;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 1\n");
    printf("=========================================\n");

    printf("ADC Value = %u\n",
           adc_value);

    printf("Voltage   = %.3f V\n\n",
           adc_voltage);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    VOLTAGE TO ADC
    ===========================================================================
    */

    float measured_voltage = 1.65f;

    uint16_t converted_adc =
        (uint16_t)
        (
            measured_voltage
            * 4095.0f
            / 3.3f
        );

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 2\n");
    printf("=========================================\n");

    printf("Voltage = %.2f V\n",
           measured_voltage);

    printf("ADC     = %u\n\n",
           converted_adc);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 3

    TEMPERATURE SENSOR
    ===========================================================================
    */

    float sensor_temperature =
        28.75f;

    int display_temperature =
        (int)sensor_temperature;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 3\n");
    printf("=========================================\n");

    printf("Sensor Temperature  = %.2f\n",
           sensor_temperature);

    printf("Display Temperature = %d\n\n",
           display_temperature);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 4

    PWM DUTY CYCLE
    ===========================================================================
    */

    float duty_cycle = 75.5f;

    uint16_t pwm_value =
        (uint16_t)
        (
            duty_cycle
            * 65535.0f
            / 100.0f
        );

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 4\n");
    printf("=========================================\n");

    printf("Duty Cycle = %.2f %%\n",
           duty_cycle);

    printf("PWM Value  = %u\n\n",
           pwm_value);



    /*
    ===========================================================================
    FLOAT LIMITS
    ===========================================================================
    */

    printf("=========================================\n");
    printf("FLOAT LIMITS\n");
    printf("=========================================\n");

    printf("FLT_DIG = %d\n",
           FLT_DIG);

    printf("DBL_DIG = %d\n\n",
           DBL_DIG);



    /*
        FLT_DIG:

            About 6-7 digits

        DBL_DIG:

            About 15 digits
    */



    /*
    ===========================================================================
    MISRA C RECOMMENDATIONS
    ===========================================================================

    GOOD:

        uint16_t adc =
            (uint16_t)
            (
                voltage * 4095.0f
                / 3.3f
            );

    Benefits:

        • Explicit programmer intent
        • Better static analysis
        • Fewer compiler warnings
        • Improved readability

    ===========================================================================
    */



    /*
    ===========================================================================
    COMMON MISTAKES
    ===========================================================================

    WRONG:

        int x = (int)3.99f;

        Expect:

            4

        Actual:

            3

    ----------------------------------------

    WRONG:

        float result = 5 / 2;

        Result:

            2.0

    ----------------------------------------

    CORRECT:

        float result = 5.0f / 2;

        Result:

            2.5

    ----------------------------------------

    WRONG:

        uint8_t value =
            (uint8_t)300.0f;

        Result:

            44

    ===========================================================================
    */



    /*
    ===========================================================================
    INTERVIEW QUESTIONS
    ===========================================================================

    Q1:

        Result:

            (int)3.99

        Answer:

            3

    ----------------------------------------

    Q2:

        Is casting from float to int
        rounding or truncation?

        Answer:

            Truncation

    ----------------------------------------

    Q3:

        How many digits can float
        represent accurately?

        Answer:

            About 6 to 7 digits

    ----------------------------------------

    Q4:

        How many digits can double
        represent accurately?

        Answer:

            About 15 digits

    ----------------------------------------

    Q5:

        Why use explicit casts in
        embedded systems?

        Answer:

            Better readability,
            MISRA compliance,
            safer conversions.

    ===========================================================================
    */

    return 0;
}
