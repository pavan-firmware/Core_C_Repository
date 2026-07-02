#include <stdio.h>
#include <stdint.h>

/*
===============================================================================
                    14_IMPLICIT_TYPE_CASTING.C
===============================================================================

TOPIC:
    Implicit Type Casting
    (Automatic Type Conversion)

===============================================================================

WHAT IS IMPLICIT TYPE CASTING?

Definition:

    Automatic conversion performed by the compiler
    without programmer intervention.

    Also called:

        Automatic Type Conversion

===============================================================================

GENERAL RULE

SMALLER TYPE
      ↓
LARGER TYPE

Examples:

    char
      ↓
    int

    int
      ↓
    float

    float
      ↓
    double

===============================================================================

WHY DOES C DO THIS?

Reasons:

    1. Prevent data loss
    2. Perform arithmetic correctly
    3. Follow machine architecture rules
    4. Simplify programming

===============================================================================

TYPE HIERARCHY

LOWER RANK
---------------------------------

char

short

int

unsigned int

long

long long

float

double

long double

---------------------------------
HIGHER RANK

Usually:

    Lower Rank

        ↓

    Higher Rank

===============================================================================

IMPLICIT CONVERSION TABLE

+--------------+---------------+-----------------------------+
| SOURCE       | DESTINATION   | AUTOMATIC?                 |
+--------------+---------------+-----------------------------+
| char         | int           | YES                        |
| short        | int           | YES                        |
| int          | float         | YES                        |
| float        | double        | YES                        |
| int          | double        | YES                        |
+--------------+---------------+-----------------------------+

===============================================================================
*/


int main(void)
{
    /*
    ===========================================================================
    1. CHAR TO INT
    ===========================================================================
    */

    char letter = 'A';

    int ascii_value = letter;

    /*
        Compiler:

            int ascii_value =
                (int)letter;

        ASCII:

            A = 65
    */

    printf("=========================================\n");
    printf("1. CHAR TO INT\n");
    printf("=========================================\n");

    printf("Character   = %c\n", letter);

    printf("ASCII Value = %d\n\n",
           ascii_value);



    /*
    ===========================================================================
    2. INT TO FLOAT
    ===========================================================================
    */

    int temperature = 25;

    float temperature_float = temperature;

    /*
        Compiler:

            (float)temperature

        Result:

            25.000000
    */

    printf("=========================================\n");
    printf("2. INT TO FLOAT\n");
    printf("=========================================\n");

    printf("Integer = %d\n",
           temperature);

    printf("Float   = %.2f\n\n",
           temperature_float);



    /*
    ===========================================================================
    3. FLOAT TO DOUBLE
    ===========================================================================
    */

    float voltage = 3.3f;

    double high_precision_voltage = voltage;

    printf("=========================================\n");
    printf("3. FLOAT TO DOUBLE\n");
    printf("=========================================\n");

    printf("Float  = %.2f\n",
           voltage);

    printf("Double = %.15lf\n\n",
           high_precision_voltage);



    /*
    ===========================================================================
    4. INTEGER ARITHMETIC CONVERSION
    ===========================================================================
    */

    char a = 10;
    char b = 20;

    /*
        Compiler performs:

            int + int

        NOT:

            char + char
    */

    int result = a + b;

    printf("=========================================\n");
    printf("4. CHAR ARITHMETIC\n");
    printf("=========================================\n");

    printf("Result = %d\n\n",
           result);



    /*
    ===========================================================================
    MEMORY VISUALIZATION

    a

        char

        1 byte

    b

        char

        1 byte

    Arithmetic:

        int + int

        Result:

            int

            4 bytes

    ===========================================================================
    */



    /*
    ===========================================================================
    5. INT + FLOAT
    ===========================================================================
    */

    int sensor_value = 100;

    float scale_factor = 1.5f;

    /*
        Compiler:

            (float)sensor_value

        Expression:

            100.0f * 1.5f

        Result:

            150.0f
    */

    float scaled_value =
        sensor_value * scale_factor;

    printf("=========================================\n");
    printf("5. INT + FLOAT\n");
    printf("=========================================\n");

    printf("Scaled Value = %.2f\n\n",
           scaled_value);



    /*
    ===========================================================================
    6. FLOAT + DOUBLE
    ===========================================================================
    */

    float current = 2.5f;

    double resistance = 10.0;

    /*
        Compiler:

            (double)current

        Result:

            double
    */

    double power =
        current * resistance;

    printf("=========================================\n");
    printf("6. FLOAT + DOUBLE\n");
    printf("=========================================\n");

    printf("Power = %.2lf\n\n",
           power);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    ADC VOLTAGE CALCULATION
    ===========================================================================
    */

    uint16_t adc_value = 2048;

    /*
        Compiler:

            (float)adc_value

        Automatic conversion happens.
    */

    float adc_voltage =
        adc_value * 3.3f / 4095.0f;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 1\n");
    printf("=========================================\n");

    printf("ADC Voltage = %.3f V\n\n",
           adc_voltage);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    TEMPERATURE CONVERSION
    ===========================================================================
    */

    int temperature_celsius = 30;

    /*
        Formula:

            F = C * 1.8 + 32

        Integer automatically becomes float.
    */

    float temperature_fahrenheit =
        temperature_celsius * 1.8f + 32.0f;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 2\n");
    printf("=========================================\n");

    printf("Temperature = %.2f F\n\n",
           temperature_fahrenheit);



    /*
    ===========================================================================
    COMMON MISTAKES
    ===========================================================================

    EXPECTING:

        float result =
            5 / 2;

    Actual:

        2.0

    Reason:

        Integer division happens first.

    ----------------------------------------

    CORRECT:

        float result =
            5.0f / 2;

    Result:

        2.5

    ===========================================================================
    */

    float wrong_result = 5 / 2;

    float correct_result = 5.0f / 2;

    printf("=========================================\n");
    printf("COMMON MISTAKE EXAMPLE\n");
    printf("=========================================\n");

    printf("5 / 2     = %.2f\n",
           wrong_result);

    printf("5.0 / 2   = %.2f\n\n",
           correct_result);



    /*
    ===========================================================================
    INTERVIEW QUESTIONS
    ===========================================================================

    Q1:

        What is implicit type casting?

        Answer:

            Automatic conversion performed
            by the compiler.

    ----------------------------------------

    Q2:

        Which has higher rank?

            int

            float

        Answer:

            float

    ----------------------------------------

    Q3:

        Result type:

            int + float

        Answer:

            float

    ----------------------------------------

    Q4:

        Result:

            5 / 2

        Answer:

            2

    ----------------------------------------

    Q5:

        Result:

            5.0 / 2

        Answer:

            2.5

    ===========================================================================
    */

    return 0;
}
