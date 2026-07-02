#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
==============================================================================
                        09. FORMAT SPECIFIERS IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. printf Format Specifiers
2. scanf Format Specifiers
3. Integer Format Specifiers
4. Floating Point Format Specifiers
5. Character Format Specifiers
6. String Format Specifiers
7. Pointer Format Specifiers
8. size_t Format Specifiers
9. Fixed Width Integer Format Specifiers
10. Escape Sequences
11. Field Width and Precision
12. Embedded Firmware Examples
13. Common Beginner Mistakes

==============================================================================


PRINTF FORMAT SPECIFIERS
==============================================================================

+------------+--------------------------+----------------------+
| Specifier  | Data Type                | Example              |
+------------+--------------------------+----------------------+
| %c         | char                     | 'A'                  |
| %s         | string                   | "Hello"              |
| %d         | signed int               | -100                 |
| %i         | signed int               | -100                 |
| %u         | unsigned int             | 100                  |
| %o         | octal                    | 755                  |
| %x         | hexadecimal (lowercase)  | ff                   |
| %X         | hexadecimal (uppercase)  | FF                   |
| %f         | float/double             | 3.141593             |
| %e         | scientific notation      | 3.14e+00             |
| %E         | scientific notation      | 3.14E+00             |
| %g         | shortest representation  | 3.14                 |
| %a         | hexadecimal float        | 0x1.9p+1             |
| %p         | pointer address          | 0x7ffd1234           |
| %%         | print % symbol           | %                    |
+------------+--------------------------+----------------------+

==============================================================================


LENGTH MODIFIERS
==============================================================================

+------------+--------------------------+----------------------+
| Modifier   | Data Type                | Example              |
+------------+--------------------------+----------------------+
| hh         | char                     | %hhd                 |
| h          | short                    | %hd                  |
| (none)     | int                      | %d                   |
| l          | long                     | %ld                  |
| ll         | long long                | %lld                 |
| z          | size_t                   | %zu                  |
| L          | long double              | %Lf                  |
+------------+--------------------------+----------------------+

==============================================================================


SCANF FORMAT SPECIFIERS
==============================================================================

+------------+--------------------------+
| Specifier  | Data Type                |
+------------+--------------------------+
| %c         | char                     |
| %s         | string                   |
| %d         | int                      |
| %u         | unsigned int             |
| %hd        | short                    |
| %hu        | unsigned short           |
| %ld        | long                     |
| %lu        | unsigned long            |
| %lld       | long long                |
| %llu       | unsigned long long       |
| %f         | float                    |
| %lf        | double                   |
| %Lf        | long double              |
+------------+--------------------------+

==============================================================================


ESCAPE SEQUENCES
==============================================================================

+------------+--------------------------+
| Sequence   | Meaning                  |
+------------+--------------------------+
| \n         | New Line                 |
| \t         | Horizontal Tab           |
| \\         | Backslash                |
| \'         | Single Quote             |
| \"         | Double Quote             |
| \0         | Null Character           |
+------------+--------------------------+

==============================================================================
*/

int main(void)
{
    /*
    ==========================================================================
    CHARACTER FORMAT SPECIFIERS
    ==========================================================================
    */

    char grade = 'A';

    printf("==================================================\n");
    printf("CHARACTER FORMAT SPECIFIERS\n");
    printf("==================================================\n\n");

    printf("Character      : %c\n",
           grade);

    printf("ASCII Value    : %d\n",
           grade);


    /*
    ==========================================================================
    STRING FORMAT SPECIFIERS
    ==========================================================================
    */

    char course_name[] = "Embedded C";

    printf("\n");
    printf("==================================================\n");
    printf("STRING FORMAT SPECIFIERS\n");
    printf("==================================================\n\n");

    printf("Course Name    : %s\n",
           course_name);


    /*
    ==========================================================================
    INTEGER FORMAT SPECIFIERS
    ==========================================================================
    */

    int signed_number = -100;

    unsigned int unsigned_number = 100U;

    printf("\n");
    printf("==================================================\n");
    printf("INTEGER FORMAT SPECIFIERS\n");
    printf("==================================================\n\n");

    printf("%%d             : %d\n",
           signed_number);

    printf("%%i             : %i\n",
           signed_number);

    printf("%%u             : %u\n",
           unsigned_number);

    printf("%%o             : %o\n",
           unsigned_number);

    printf("%%x             : %x\n",
           unsigned_number);

    printf("%%X             : %X\n",
           unsigned_number);


    /*
    ==========================================================================
    LENGTH MODIFIERS
    ==========================================================================
    */

    short short_number = -250;

    long long_number = 100000L;

    long long huge_number = 5000000000LL;

    printf("\n");
    printf("==================================================\n");
    printf("LENGTH MODIFIERS\n");
    printf("==================================================\n\n");

    printf("short          : %hd\n",
           short_number);

    printf("long           : %ld\n",
           long_number);

    printf("long long      : %lld\n",
           huge_number);


    /*
    ==========================================================================
    FLOATING POINT FORMAT SPECIFIERS
    ==========================================================================
    */

    float voltage = 3.3F;

    double pi = 3.141592653589793;

    long double precise_pi =
        3.1415926535897932384626L;

    printf("\n");
    printf("==================================================\n");
    printf("FLOAT FORMAT SPECIFIERS\n");
    printf("==================================================\n\n");

    printf("%%f             : %f\n",
           voltage);

    printf("%%.2f           : %.2f\n",
           voltage);

    printf("%%e             : %e\n",
           pi);

    printf("%%E             : %E\n",
           pi);

    printf("%%g             : %g\n",
           pi);

    printf("%%a             : %a\n",
           pi);

    printf("%%Lf            : %.20Lf\n",
           precise_pi);


    /*
    ==========================================================================
    POINTER FORMAT SPECIFIERS
    ==========================================================================
    */

    int sensor_value = 100;

    int *sensor_pointer = &sensor_value;

    printf("\n");
    printf("==================================================\n");
    printf("POINTER FORMAT SPECIFIERS\n");
    printf("==================================================\n\n");

    printf("Pointer Address: %p\n",
           (void *)sensor_pointer);


    /*
    ==========================================================================
    SIZE_T FORMAT SPECIFIERS
    ==========================================================================
    */

    size_t buffer_size =
        sizeof(uint32_t) * 10U;

    printf("\n");
    printf("==================================================\n");
    printf("SIZE_T FORMAT SPECIFIERS\n");
    printf("==================================================\n\n");

    printf("Buffer Size    : %zu Bytes\n",
           buffer_size);


    /*
    ==========================================================================
    FIXED WIDTH INTEGER FORMAT SPECIFIERS
    ==========================================================================
    */

    int32_t system_ticks = -1000;

    uint64_t packet_counter =
        5000000000ULL;

    printf("\n");
    printf("==================================================\n");
    printf("FIXED WIDTH INTEGER SPECIFIERS\n");
    printf("==================================================\n\n");

    printf("System Ticks   : %" PRId32 "\n",
           system_ticks);

    printf("Packet Counter : %" PRIu64 "\n",
           packet_counter);


    /*
    ==========================================================================
    FIELD WIDTH AND PRECISION
    ==========================================================================
    */

    int number = 42;

    double value = 123.456789;

    printf("\n");
    printf("==================================================\n");
    printf("FIELD WIDTH AND PRECISION\n");
    printf("==================================================\n\n");

    printf("[%5d]\n",
           number);

    printf("[%10d]\n",
           number);

    printf("[%-10d]\n",
           number);

    printf("[%.2f]\n",
           value);

    printf("[%10.2f]\n",
           value);


    /*
    ==========================================================================
    ESCAPE SEQUENCES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("ESCAPE SEQUENCES\n");
    printf("==================================================\n\n");

    printf("Line 1\n");
    printf("Line 2\n");

    printf("Column1\tColumn2\tColumn3\n");

    printf("Backslash : \\\n");

    printf("Single Quote : \'\n");

    printf("Double Quote : \"\n");

    printf("Percentage : %%\n");


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    uint16_t adc_value = 2048U;

    float adc_voltage =
        (adc_value * 3.3F) / 4095.0F;

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED FIRMWARE EXAMPLES\n");
    printf("==================================================\n\n");

    printf("ADC Value      : %u\n",
           adc_value);

    printf("ADC Voltage    : %.3f V\n",
           adc_voltage);

    printf("ADC Hex Value  : 0x%X\n",
           adc_value);


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        printf("%d", float_value);

    CORRECT:

        printf("%f", float_value);

    ------------------------------------------------------------

    WRONG:

        printf("%d", sizeof(int));

    CORRECT:

        printf("%zu", sizeof(int));

    ------------------------------------------------------------

    WRONG:

        scanf("%f", &double_value);

    CORRECT:

        scanf("%lf", &double_value);

    ------------------------------------------------------------

    IMPORTANT:

        printf:

            float
            double

        Both use:

            %f

    But:

        scanf:

            float  -> %f

            double -> %lf

    ==========================================================================
    */

    return 0;
}
