#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>
#include <stdint.h>

/*
==============================================================================
                    08. TYPE SIZES AND LIMITS IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. sizeof Operator

2. Character Type Sizes
   - char
   - signed char
   - unsigned char

3. Integer Type Sizes
   - short
   - int
   - long
   - long long

4. Floating Point Sizes
   - float
   - double
   - long double

5. Boolean Type Size

6. Fixed Width Integer Sizes

7. limits.h Macros

8. float.h Macros

9. Embedded Firmware Examples

10. Common Beginner Mistakes

==============================================================================


WHAT IS sizeof ?
==============================================================================

sizeof is an operator.

It returns:

    Number of bytes occupied by:

        1. Data Types
        2. Variables
        3. Structures
        4. Arrays

Examples:

    sizeof(int)

    sizeof(float)

    sizeof(variable)

==============================================================================


TYPE SIZE TABLE
==============================================================================

+----------------------+---------------------------+
| Data Type            | Typical Size (Bytes)      |
+----------------------+---------------------------+
| char                 | 1                         |
| short                | 2                         |
| int                  | 4                         |
| long                 | 8 (Linux) / 4 (Windows)   |
| long long            | 8                         |
| float                | 4                         |
| double               | 8                         |
| long double          | 16 (Usually Linux)        |
| bool                 | 1                         |
+----------------------+---------------------------+

==============================================================================


INTEGER LIMIT MACROS
==============================================================================

Header File:

    #include <limits.h>

Examples:

    CHAR_MIN
    CHAR_MAX

    INT_MIN
    INT_MAX

    LONG_MIN
    LONG_MAX

==============================================================================


FLOATING POINT LIMIT MACROS
==============================================================================

Header File:

    #include <float.h>

Examples:

    FLT_MIN
    FLT_MAX
    FLT_DIG

    DBL_MIN
    DBL_MAX
    DBL_DIG

    LDBL_MIN
    LDBL_MAX
    LDBL_DIG

==============================================================================
*/

int main(void)
{
    /*
    ==========================================================================
    CHARACTER TYPE SIZES
    ==========================================================================
    */

    printf("==================================================\n");
    printf("CHARACTER TYPE SIZES\n");
    printf("==================================================\n\n");

    printf("char                 = %zu bytes\n",
           sizeof(char));

    printf("signed char          = %zu bytes\n",
           sizeof(signed char));

    printf("unsigned char        = %zu bytes\n",
           sizeof(unsigned char));


    /*
    ==========================================================================
    INTEGER TYPE SIZES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("INTEGER TYPE SIZES\n");
    printf("==================================================\n\n");

    printf("short                = %zu bytes\n",
           sizeof(short));

    printf("unsigned short       = %zu bytes\n",
           sizeof(unsigned short));

    printf("int                  = %zu bytes\n",
           sizeof(int));

    printf("unsigned int         = %zu bytes\n",
           sizeof(unsigned int));

    printf("long                 = %zu bytes\n",
           sizeof(long));

    printf("unsigned long        = %zu bytes\n",
           sizeof(unsigned long));

    printf("long long            = %zu bytes\n",
           sizeof(long long));

    printf("unsigned long long   = %zu bytes\n",
           sizeof(unsigned long long));


    /*
    ==========================================================================
    FLOATING POINT TYPE SIZES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("FLOATING POINT TYPE SIZES\n");
    printf("==================================================\n\n");

    printf("float                = %zu bytes\n",
           sizeof(float));

    printf("double               = %zu bytes\n",
           sizeof(double));

    printf("long double          = %zu bytes\n",
           sizeof(long double));


    /*
    ==========================================================================
    BOOLEAN TYPE SIZE
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("BOOLEAN TYPE SIZE\n");
    printf("==================================================\n\n");

    printf("bool                 = %zu bytes\n",
           sizeof(bool));


    /*
    ==========================================================================
    FIXED WIDTH INTEGER TYPE SIZES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("FIXED WIDTH TYPE SIZES\n");
    printf("==================================================\n\n");

    printf("int8_t               = %zu bytes\n",
           sizeof(int8_t));

    printf("uint8_t              = %zu bytes\n",
           sizeof(uint8_t));

    printf("int16_t              = %zu bytes\n",
           sizeof(int16_t));

    printf("uint16_t             = %zu bytes\n",
           sizeof(uint16_t));

    printf("int32_t              = %zu bytes\n",
           sizeof(int32_t));

    printf("uint32_t             = %zu bytes\n",
           sizeof(uint32_t));

    printf("int64_t              = %zu bytes\n",
           sizeof(int64_t));

    printf("uint64_t             = %zu bytes\n",
           sizeof(uint64_t));


    /*
    ==========================================================================
    CHARACTER LIMITS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("CHARACTER LIMITS\n");
    printf("==================================================\n\n");

    printf("CHAR_MIN             = %d\n",
           CHAR_MIN);

    printf("CHAR_MAX             = %d\n",
           CHAR_MAX);

    printf("SCHAR_MIN            = %d\n",
           SCHAR_MIN);

    printf("SCHAR_MAX            = %d\n",
           SCHAR_MAX);

    printf("UCHAR_MAX            = %u\n",
           UCHAR_MAX);


    /*
    ==========================================================================
    INTEGER LIMITS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("INTEGER LIMITS\n");
    printf("==================================================\n\n");

    printf("SHRT_MIN             = %d\n",
           SHRT_MIN);

    printf("SHRT_MAX             = %d\n",
           SHRT_MAX);

    printf("USHRT_MAX            = %u\n",
           USHRT_MAX);

    printf("INT_MIN              = %d\n",
           INT_MIN);

    printf("INT_MAX              = %d\n",
           INT_MAX);

    printf("UINT_MAX             = %u\n",
           UINT_MAX);

    printf("LONG_MIN             = %ld\n",
           LONG_MIN);

    printf("LONG_MAX             = %ld\n",
           LONG_MAX);

    printf("ULONG_MAX            = %lu\n",
           ULONG_MAX);

    printf("LLONG_MIN            = %lld\n",
           LLONG_MIN);

    printf("LLONG_MAX            = %lld\n",
           LLONG_MAX);

    printf("ULLONG_MAX           = %llu\n",
           ULLONG_MAX);


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
        float can represent accurately.
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
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    uint16_t adc_resolution = 4095U;

    uint32_t cpu_clock_hz = 72000000U;

    float reference_voltage = 3.3F;

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLES\n");
    printf("==================================================\n\n");

    printf("ADC Resolution       = %u\n",
           adc_resolution);

    printf("CPU Clock            = %u Hz\n",
           cpu_clock_hz);

    printf("Reference Voltage    = %.2f V\n",
           reference_voltage);


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        printf("%d", sizeof(int));

    CORRECT:

        printf("%zu", sizeof(int));

    ------------------------------------------------------------

    WRONG:

        Assuming:

            int is always 4 bytes

    Reality:

        C Standard does not guarantee it.

    ------------------------------------------------------------

    WRONG:

        Hardcoding:

            2147483647

    BETTER:

            INT_MAX

    From:

            limits.h

    ------------------------------------------------------------

    BEST PRACTICE:

        Embedded Firmware:

            Prefer:

                uint8_t
                uint16_t
                uint32_t
                int32_t

        Instead of:

                int
                long

    ==========================================================================
    */

    return 0;
}
