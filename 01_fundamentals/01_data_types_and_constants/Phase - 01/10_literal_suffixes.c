#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
==============================================================================
                        10. LITERAL SUFFIXES IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. Integer Literals
2. Integer Literal Suffixes
3. Floating Point Literal Suffixes
4. Character Literals
5. String Literals
6. Decimal Literals
7. Octal Literals
8. Hexadecimal Literals
9. Binary Literals (Compiler Extensions / C23)
10. Scientific Notation
11. Embedded Firmware Examples
12. Common Beginner Mistakes

==============================================================================


WHAT IS A LITERAL?
==============================================================================

A literal means:

    Fixed values written directly in source code.

Examples:

    100
    3.14
    'A'
    "Hello"
    0xFF
    0755

==============================================================================


INTEGER LITERAL SUFFIXES
==============================================================================

+--------------+---------------------------+
| Literal      | Data Type                 |
+--------------+---------------------------+
| 100          | int                       |
| 100U         | unsigned int              |
| 100L         | long                      |
| 100UL        | unsigned long             |
| 100LL        | long long                 |
| 100ULL       | unsigned long long        |
+--------------+---------------------------+

==============================================================================


FLOATING LITERAL SUFFIXES
==============================================================================

+--------------+---------------------------+
| Literal      | Data Type                 |
+--------------+---------------------------+
| 3.14         | double                    |
| 3.14F        | float                     |
| 3.14L        | long double               |
+--------------+---------------------------+

==============================================================================


NUMBER SYSTEMS
==============================================================================

+--------------+---------------------------+
| Literal      | Number System             |
+--------------+---------------------------+
| 100          | Decimal                   |
| 075          | Octal                     |
| 0xFF         | Hexadecimal               |
| 0b1010       | Binary (Extension/C23)    |
+--------------+---------------------------+

==============================================================================
*/


/*
------------------------------------------------------------------------------
EMBEDDED CONSTANTS
------------------------------------------------------------------------------
*/

#define CPU_CLOCK_HZ       (72000000UL)
#define FLASH_SIZE_BYTES   (16777216ULL)
#define ADC_MAX_VALUE      (4095U)


int main(void)
{
    /*
    ==========================================================================
    DECIMAL LITERALS
    ==========================================================================
    */

    int decimal_number = 100;

    printf("==================================================\n");
    printf("DECIMAL LITERALS\n");
    printf("==================================================\n\n");

    printf("Decimal Number = %d\n",
           decimal_number);


    /*
    ==========================================================================
    UNSIGNED LITERALS
    ==========================================================================
    */

    unsigned int unsigned_number = 100U;

    printf("\n");
    printf("==================================================\n");
    printf("UNSIGNED LITERALS\n");
    printf("==================================================\n\n");

    printf("Unsigned Number = %u\n",
           unsigned_number);


    /*
    ==========================================================================
    LONG LITERALS
    ==========================================================================
    */

    long system_ticks = 100000L;

    unsigned long cpu_frequency = 72000000UL;

    printf("\n");
    printf("==================================================\n");
    printf("LONG LITERALS\n");
    printf("==================================================\n\n");

    printf("System Ticks = %ld\n",
           system_ticks);

    printf("CPU Frequency = %lu\n",
           cpu_frequency);


    /*
    ==========================================================================
    LONG LONG LITERALS
    ==========================================================================
    */

    long long total_packets = 5000000000LL;

    unsigned long long flash_size =
        16000000000ULL;

    printf("\n");
    printf("==================================================\n");
    printf("LONG LONG LITERALS\n");
    printf("==================================================\n\n");

    printf("Total Packets = %lld\n",
           total_packets);

    printf("Flash Size    = %llu\n",
           flash_size);


    /*
    ==========================================================================
    FLOATING POINT LITERALS
    ==========================================================================
    */

    float voltage = 3.3F;

    double pi = 3.141592653589793;

    long double accurate_pi =
        3.14159265358979323846L;

    printf("\n");
    printf("==================================================\n");
    printf("FLOATING POINT LITERALS\n");
    printf("==================================================\n\n");

    printf("Float       = %.2f\n",
           voltage);

    printf("Double      = %.15lf\n",
           pi);

    printf("Long Double = %.18Lf\n",
           accurate_pi);


    /*
    ==========================================================================
    CHARACTER LITERALS
    ==========================================================================
    */

    char grade = 'A';

    printf("\n");
    printf("==================================================\n");
    printf("CHARACTER LITERALS\n");
    printf("==================================================\n\n");

    printf("Character = %c\n",
           grade);

    printf("ASCII     = %d\n",
           grade);


    /*
    ==========================================================================
    STRING LITERALS
    ==========================================================================
    */

    char course_name[] = "Embedded C";

    printf("\n");
    printf("==================================================\n");
    printf("STRING LITERALS\n");
    printf("==================================================\n\n");

    printf("Course = %s\n",
           course_name);


    /*
    ==========================================================================
    OCTAL LITERALS
    ==========================================================================
    */

    /*
        075 means:

            7 × 8^1
          + 5 × 8^0

        = 61 decimal
    */

    int octal_value = 075;

    printf("\n");
    printf("==================================================\n");
    printf("OCTAL LITERALS\n");
    printf("==================================================\n\n");

    printf("075 = %d\n",
           octal_value);


    /*
    ==========================================================================
    HEXADECIMAL LITERALS
    ==========================================================================
    */

    int hex_value = 0xFF;

    printf("\n");
    printf("==================================================\n");
    printf("HEXADECIMAL LITERALS\n");
    printf("==================================================\n\n");

    printf("0xFF (Decimal) = %d\n",
           hex_value);

    printf("0xFF (Hex)     = 0x%X\n",
           hex_value);


    /*
    ==========================================================================
    BINARY LITERALS
    ==========================================================================
    */

    /*
        NOTE:

        0b literals are:

            GCC Extension
            Clang Extension
            C23 Standard

        Not portable to older C standards.
    */

    int binary_value = 0xAA;

    printf("\n");
    printf("==================================================\n");
    printf("BINARY LITERALS\n");
    printf("==================================================\n\n");

    printf("0xAA       = %d\n",
           binary_value);


    /*
    ==========================================================================
    SCIENTIFIC NOTATION
    ==========================================================================
    */

    double kilo = 1e3;

    double mega = 1e6;

    double milli = 3.3e-3;

    printf("\n");
    printf("==================================================\n");
    printf("SCIENTIFIC NOTATION\n");
    printf("==================================================\n\n");

    printf("1e3    = %.0lf\n",
           kilo);

    printf("1e6    = %.0lf\n",
           mega);

    printf("3.3e-3 = %lf\n",
           milli);


    /*
    ==========================================================================
    FIXED WIDTH INTEGER LITERALS
    ==========================================================================
    */

    uint32_t system_counter = 1000U;

    uint64_t packet_counter =
        10000000000ULL;

    printf("\n");
    printf("==================================================\n");
    printf("FIXED WIDTH INTEGER LITERALS\n");
    printf("==================================================\n\n");

    printf("System Counter = %" PRIu32 "\n",
           system_counter);

    printf("Packet Counter = %" PRIu64 "\n",
           packet_counter);


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    uint16_t adc_resolution =
        ADC_MAX_VALUE;

    uint32_t cpu_clock =
        CPU_CLOCK_HZ;

    uint64_t flash_memory =
        FLASH_SIZE_BYTES;

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLES\n");
    printf("==================================================\n\n");

    printf("ADC Resolution = %u\n",
           adc_resolution);

    printf("CPU Clock      = %u Hz\n",
           cpu_clock);

    printf("Flash Memory   = %" PRIu64 " Bytes\n",
           flash_memory);


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        float voltage = 3.3;

    BETTER:

        float voltage = 3.3F;

    Because:

        3.3 is a double literal.

    ------------------------------------------------------------

    WRONG:

        long long size = 5000000000;

    BETTER:

        long long size = 5000000000LL;

    ------------------------------------------------------------

    WRONG:

        int value = 08;

    ERROR:

        Leading zero means:

            OCTAL

        Octal digits:

            0 to 7 only.

    ------------------------------------------------------------

    WRONG:

        Assuming:

            0b1010

        works everywhere.

    Reality:

        Portable only in:

            C23
            GCC
            Clang

    ==========================================================================
    */

    return 0;
}
