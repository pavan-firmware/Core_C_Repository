#include <stdio.h>
#include <float.h>

/*
==============================================================================
                    03. FLOATING-POINT TYPES IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. float
2. double
3. long double

4. Floating-point literal suffixes
5. Scientific notation
6. Precision comparison
7. Type sizes
8. Type limits

9. FLT_MIN
10. FLT_MAX
11. FLT_DIG

12. DBL_MIN
13. DBL_MAX
14. DBL_DIG

15. LDBL_MIN
16. LDBL_MAX
17. LDBL_DIG

18. Embedded firmware examples
19. Common beginner mistakes

==============================================================================


FLOATING-POINT TYPE TABLE
==============================================================================

+--------------+---------+----------------------+----------------------+
| Type         | Bytes   | Minimum Value        | Maximum Value        |
+--------------+---------+----------------------+----------------------+
| float        | 4       | 1.175494e-38         | 3.402823e+38         |
| double       | 8       | 2.225074e-308        | 1.797693e+308        |
| long double  | Platform Dependent           | Platform Dependent   |
+--------------+---------+----------------------+----------------------+

==============================================================================


PRECISION TABLE
==============================================================================

+--------------+-----------------------------+
| Type         | Decimal Digits (Approx.)    |
+--------------+-----------------------------+
| float        | 6 to 7 digits               |
| double       | 15 to 16 digits             |
| long double  | 18+ digits (platform dep.)  |
+--------------+-----------------------------+

==============================================================================


FLOATING-POINT LITERAL SUFFIXES
==============================================================================

+------------+----------------------+
| Literal    | Data Type            |
+------------+----------------------+
| 3.14       | double               |
| 3.14f      | float                |
| 3.14F      | float                |
| 3.14L      | long double          |
+------------+----------------------+

==============================================================================


SCIENTIFIC NOTATION
==============================================================================

+----------------+---------------------------+
| Expression     | Actual Value              |
+----------------+---------------------------+
| 1e3            | 1000                      |
| 1e6            | 1000000                   |
| 3.3e-3         | 0.0033                    |
| 2.5e2          | 250                       |
+----------------+---------------------------+

==============================================================================
*/


/*
------------------------------------------------------------------------------
Compile-Time Constants
------------------------------------------------------------------------------
*/

#define ADC_REFERENCE_VOLTAGE    3.3f
#define TEMPERATURE_OFFSET       2.75
#define CALIBRATION_FACTOR       1.23456789012345L


int main(void)
{
    /*
    ==========================================================================
    1. FLOAT
    ==========================================================================

    Single-precision floating-point type.

    Usually:

        4 Bytes

    Precision:

        About 6 to 7 decimal digits.

    Always use:

        f

    suffix for float literals.
    */

    float sensor_voltage = 3.3f;

    float current_reading = 1.25f;


    /*
    ==========================================================================
    2. DOUBLE
    ==========================================================================

    Double-precision floating-point type.

    Usually:

        8 Bytes

    Precision:

        About 15 to 16 decimal digits.
    */

    double room_temperature = 27.456789123456;

    double humidity = 65.875;


    /*
    ==========================================================================
    3. LONG DOUBLE
    ==========================================================================

    Highest precision floating-point type.

    Size:

        Platform dependent.

    Use:

        L

    suffix.
    */

    long double pi_value =
        3.14159265358979323846L;


    /*
    ==========================================================================
    4. SCIENTIFIC NOTATION
    ==========================================================================
    */

    float milli_volts = 3.3e-3f;

    double mega_hertz = 72.0e6;


    /*
    ==========================================================================
    PRINT VARIABLE VALUES
    ==========================================================================
    */

    printf("==================================================\n");
    printf("FLOATING-POINT VALUES\n");
    printf("==================================================\n\n");

    printf("sensor_voltage       = %.2f\n",
           sensor_voltage);

    printf("current_reading      = %.2f\n",
           current_reading);

    printf("room_temperature     = %.12lf\n",
           room_temperature);

    printf("humidity             = %.3lf\n",
           humidity);

    printf("pi_value             = %.18Lf\n",
           pi_value);

    printf("milli_volts          = %e\n",
           milli_volts);

    printf("mega_hertz           = %e\n",
           mega_hertz);


    /*
    ==========================================================================
    TYPE SIZES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("TYPE SIZES\n");
    printf("==================================================\n\n");

    printf("float                = %zu bytes\n",
           sizeof(float));

    printf("double               = %zu bytes\n",
           sizeof(double));

    printf("long double          = %zu bytes\n",
           sizeof(long double));


    /*
    ==========================================================================
    FLOAT LIMITS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("FLOAT LIMITS\n");
    printf("==================================================\n\n");

    printf("FLT_MIN              = %e\n",
           FLT_MIN);

    printf("FLT_MAX              = %e\n",
           FLT_MAX);

    printf("FLT_DIG              = %d\n",
           FLT_DIG);

    /*
        FLT_DIG means:

        Maximum decimal digits that
        can be represented accurately.
    */


    /*
    ==========================================================================
    DOUBLE LIMITS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("DOUBLE LIMITS\n");
    printf("==================================================\n\n");

    printf("DBL_MIN              = %e\n",
           DBL_MIN);

    printf("DBL_MAX              = %e\n",
           DBL_MAX);

    printf("DBL_DIG              = %d\n",
           DBL_DIG);


    /*
    ==========================================================================
    LONG DOUBLE LIMITS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("LONG DOUBLE LIMITS\n");
    printf("==================================================\n\n");

    printf("LDBL_MIN             = %Le\n",
           LDBL_MIN);

    printf("LDBL_MAX             = %Le\n",
           LDBL_MAX);

    printf("LDBL_DIG             = %d\n",
           LDBL_DIG);


    /*
    ==========================================================================
    PRECISION COMPARISON
    ==========================================================================
    */

    float float_number =
        1.123456789f;

    double double_number =
        1.123456789123456;

    long double long_double_number =
        1.123456789123456789L;

    printf("\n");
    printf("==================================================\n");
    printf("PRECISION COMPARISON\n");
    printf("==================================================\n\n");

    printf("float       = %.9f\n",
           float_number);

    printf("double      = %.15lf\n",
           double_number);

    printf("long double = %.18Lf\n",
           long_double_number);


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    unsigned int adc_value = 2048U;

    float adc_voltage =
        (adc_value * ADC_REFERENCE_VOLTAGE)
        / 4095.0f;

    double calibrated_temperature =
        28.75 + TEMPERATURE_OFFSET;

    long double precise_calibration =
        CALIBRATION_FACTOR * 100.0L;

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLES\n");
    printf("==================================================\n\n");

    printf("ADC Voltage           = %.3f V\n",
           adc_voltage);

    printf("Temperature           = %.2lf C\n",
           calibrated_temperature);

    printf("Calibration Factor    = %.12Lf\n",
           precise_calibration);


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        float value = 3.14;

    3.14 is a double literal.

    Better:

        float value = 3.14f;

    --------------------------------------------------------------------------

    WRONG:

        float result = 10 / 3;

    Integer division:

        Result:

            3.0

    Better:

        float result = 10.0f / 3.0f;

    Result:

        3.333333

    --------------------------------------------------------------------------

    Floating-point numbers are NOT exact.

    Example:

        0.1 + 0.2

    may produce:

        0.30000000000000004

    Therefore:

        Never compare floats using:

            ==

    Prefer:

        tolerance checking.

    ==========================================================================
    */

    return 0;
}
