#include <stdio.h>
#include <stdint.h>

/*
===============================================================================
                17_USUAL_ARITHMETIC_CONVERSIONS.C
===============================================================================

TOPIC:
    Usual Arithmetic Conversions

STANDARD:
    C99, C11, C17, C23

===============================================================================

WHAT ARE USUAL ARITHMETIC CONVERSIONS?

Definition:

    After integer promotions, the compiler converts operands
    to a COMMON TYPE before performing arithmetic operations.

This process is called:

    USUAL ARITHMETIC CONVERSIONS

===============================================================================

PROCESS FLOW

    SMALL TYPES

        char
        short
        uint8_t
        int8_t

            |

            v

    INTEGER PROMOTIONS

            |

            v

    USUAL ARITHMETIC CONVERSIONS

            |

            v

    COMMON TYPE

            |

            v

    FINAL CALCULATION

===============================================================================

TYPE CONVERSION RANK

LOWEST
-------------------------------------------------------------------------------

char

short

int

unsigned int

long

unsigned long

long long

unsigned long long

float

double

long double

-------------------------------------------------------------------------------
HIGHEST

===============================================================================

COMMON CONVERSION RULES

+----------------------+---------------------+---------------------------+
| OPERAND 1            | OPERAND 2           | RESULT TYPE              |
+----------------------+---------------------+---------------------------+
| int                  | float               | float                    |
| int                  | double              | double                   |
| float                | double              | double                   |
| double               | long double         | long double              |
| signed int           | unsigned int        | Usually unsigned int     |
| uint8_t              | int                 | int                      |
+----------------------+---------------------+---------------------------+

===============================================================================
*/


int main(void)
{
    /*
    ===========================================================================
    1. INT + FLOAT
    ===========================================================================
    */

    int count = 10;

    float scale = 2.5f;

    /*
        Compiler:

            (float)count

        Expression:

            10.0f + 2.5f

        Result:

            float
    */

    float result_float =
        count + scale;

    printf("=========================================\n");
    printf("1. INT + FLOAT\n");
    printf("=========================================\n");

    printf("count        = %d\n", count);

    printf("scale        = %.2f\n", scale);

    printf("result       = %.2f\n\n",
           result_float);



    /*
    ===========================================================================
    2. INT + DOUBLE
    ===========================================================================
    */

    int temperature = 25;

    double offset = 1.75;

    /*
        Compiler:

            (double)temperature

        Result:

            double
    */

    double final_temperature =
        temperature + offset;

    printf("=========================================\n");
    printf("2. INT + DOUBLE\n");
    printf("=========================================\n");

    printf("Result = %.3lf\n\n",
           final_temperature);



    /*
    ===========================================================================
    3. FLOAT + DOUBLE
    ===========================================================================
    */

    float voltage = 3.3f;

    double correction = 0.123456789;

    /*
        Compiler:

            (double)voltage

        Result:

            double
    */

    double corrected_voltage =
        voltage + correction;

    printf("=========================================\n");
    printf("3. FLOAT + DOUBLE\n");
    printf("=========================================\n");

    printf("Result = %.9lf\n\n",
           corrected_voltage);



    /*
    ===========================================================================
    4. DOUBLE + LONG DOUBLE
    ===========================================================================
    */

    double pi = 3.141592653589793;

    long double epsilon = 0.000000000001L;

    /*
        Compiler:

            (long double)pi

        Result:

            long double
    */

    long double value =
        pi + epsilon;

    printf("=========================================\n");
    printf("4. DOUBLE + LONG DOUBLE\n");
    printf("=========================================\n");

    printf("Result = %.15Lf\n\n",
           value);



    /*
    ===========================================================================
    5. SIGNED + UNSIGNED
    ===========================================================================
    */

    int signed_number = -10;

    unsigned int unsigned_number = 20U;

    /*
        Usually:

            signed_number

                becomes

            unsigned int

        Dangerous conversion!
    */

    unsigned int mixed_result =
        signed_number + unsigned_number;

    printf("=========================================\n");
    printf("5. SIGNED + UNSIGNED\n");
    printf("=========================================\n");

    printf("signed_number   = %d\n",
           signed_number);

    printf("unsigned_number = %u\n",
           unsigned_number);

    printf("result          = %u\n\n",
           mixed_result);



    /*
    ===========================================================================
    DANGER

    -10

    becomes

    4294967286

    Then:

    4294967286 + 20

    Result:

    10

    Platform dependent details may vary.

    Avoid mixing signed and unsigned types.

    ===========================================================================
    */



    /*
    ===========================================================================
    6. UINT8_T + INT
    ===========================================================================
    */

    uint8_t adc_value = 100;

    int calibration = -20;

    /*
        uint8_t

            -> int

        Expression:

            int + int
    */

    int calibrated_adc =
        adc_value + calibration;

    printf("=========================================\n");
    printf("6. UINT8_T + INT\n");
    printf("=========================================\n");

    printf("Result = %d\n\n",
           calibrated_adc);



    /*
    ===========================================================================
    7. INTEGER DIVISION VS FLOAT DIVISION
    ===========================================================================
    */

    int a = 5;
    int b = 2;

    float wrong_result =
        a / b;

    float correct_result =
        (float)a / b;

    printf("=========================================\n");
    printf("7. DIVISION EXAMPLE\n");
    printf("=========================================\n");

    printf("a / b           = %.2f\n",
           wrong_result);

    printf("(float)a / b    = %.2f\n\n",
           correct_result);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    ADC VOLTAGE CALCULATION
    ===========================================================================
    */

    uint16_t adc_reading = 2048;

    float reference_voltage = 3.3f;

    /*
        Compiler:

            (float)adc_reading

        Result:

            float
    */

    float adc_voltage =
        adc_reading * reference_voltage / 4095.0f;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 1\n");
    printf("=========================================\n");

    printf("ADC Voltage = %.3f V\n\n",
           adc_voltage);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    POWER CALCULATION

    Power:

        P = V × I
    ===========================================================================
    */

    float current = 2.5f;

    double power =
        voltage * current;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 2\n");
    printf("=========================================\n");

    printf("Power = %.3lf W\n\n",
           power);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 3

    TEMPERATURE AVERAGING
    ===========================================================================
    */

    int sensor1 = 30;
    int sensor2 = 35;

    float average =
        (sensor1 + sensor2) / 2.0f;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 3\n");
    printf("=========================================\n");

    printf("Average Temperature = %.2f\n\n",
           average);



    /*
    ===========================================================================
    MEMORY VISUALIZATION

    int + float

        int

            4 bytes

            ↓

        float

            4 bytes

            ↓

        float + float

            ↓

        float result

    ---------------------------------------------------------------------------

    float + double

        float

            ↓

        double

            ↓

        double + double

            ↓

        double result

    ===========================================================================
    */



    /*
    ===========================================================================
    MISRA C RECOMMENDATIONS

    AVOID:

        signed + unsigned

    AVOID:

        implicit precision changes

    PREFER:

        Explicit casts

    Example:

        float voltage =
            ((float)adc_value * 3.3f) / 4095.0f;

    Benefits:

        • Clear intent
        • Static analysis friendly
        • Fewer surprises
        • Better portability

    ===========================================================================
    */



    /*
    ===========================================================================
    INTERVIEW QUESTIONS
    ===========================================================================

    Q1:

        Result type:

            int + float

        Answer:

            float

    ----------------------------------------

    Q2:

        Result type:

            float + double

        Answer:

            double

    ----------------------------------------

    Q3:

        Result type:

            double + long double

        Answer:

            long double

    ----------------------------------------

    Q4:

        Why avoid signed and unsigned arithmetic?

        Answer:

            Unexpected conversions
            and hard-to-find bugs.

    ----------------------------------------

    Q5:

        Which happens first?

            Integer promotions

        OR

            Usual arithmetic conversions

        Answer:

            Integer promotions happen first.

    ===========================================================================
    */

    return 0;
}
