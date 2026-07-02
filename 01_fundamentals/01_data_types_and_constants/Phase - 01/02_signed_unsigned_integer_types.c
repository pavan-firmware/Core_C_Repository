#include <stdio.h>
#include <limits.h>

/*
==============================================================================
                02. SIGNED AND UNSIGNED INTEGER TYPES IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. short
2. unsigned short

3. int
4. unsigned int

5. long
6. unsigned long

7. long long
8. unsigned long long

9. Integer literals and suffixes

10. Format specifiers

11. Type sizes

12. Type limits

13. Embedded firmware examples

==============================================================================


INTEGER TYPE TABLE
==============================================================================

+----------------------+---------+--------------------------+--------------------------+
| Type                 | Bytes   | Minimum Value            | Maximum Value            |
+----------------------+---------+--------------------------+--------------------------+
| short                | 2       | -32,768                  | 32,767                   |
| unsigned short       | 2       | 0                        | 65,535                   |
| int                  | 4       | -2,147,483,648           | 2,147,483,647            |
| unsigned int         | 4       | 0                        | 4,294,967,295            |
| long                 | Platform Dependent             | Platform Dependent       |
| unsigned long        | Platform Dependent             | Platform Dependent       |
| long long            | 8       | -9,223,372,036,854,775,808                |
|                      |         |                          | 9,223,372,036,854,775,807|
| unsigned long long   | 8       | 0                        | 18,446,744,073,709,551,615|
+----------------------+---------+--------------------------+--------------------------+

==============================================================================


LITERAL SUFFIXES
==============================================================================

+----------+---------------------------+
| Suffix   | Meaning                   |
+----------+---------------------------+
| U        | unsigned int              |
| L        | long                      |
| UL       | unsigned long             |
| LL       | long long                 |
| ULL      | unsigned long long        |
+----------+---------------------------+

Examples:

100U
100L
100UL
100LL
100ULL

==============================================================================
*/


/*
------------------------------------------------------------------------------
Compile-Time Constants
------------------------------------------------------------------------------
*/

#define CPU_CLOCK_HZ          72000000UL
#define UART_BAUDRATE         115200U
#define EEPROM_TOTAL_BYTES    65535U
#define TOTAL_LOG_ENTRIES     1000000LL


int main(void)
{
    /*
    ==========================================================================
    1. SHORT
    ==========================================================================

    Typically:

        2 Bytes

    Range:

        -32768 to 32767

    Useful for:

        Small signed values
    */

    short room_temperature = 28;


    /*
    ==========================================================================
    2. UNSIGNED SHORT
    ==========================================================================

    Range:

        0 to 65535

    Cannot store negative values.
    */

    unsigned short adc_count = 4095U;


    /*
    ==========================================================================
    3. INT
    ==========================================================================

    Most commonly used integer type.

    Usually:

        4 Bytes
    */

    int motor_speed = -1500;


    /*
    ==========================================================================
    4. UNSIGNED INT
    ==========================================================================

    Stores only positive numbers.

    Common in embedded firmware.
    */

    unsigned int system_ticks = 100000U;


    /*
    ==========================================================================
    5. LONG
    ==========================================================================

    Linux:

        8 Bytes

    Windows:

        4 Bytes

    Always platform dependent.
    */

    long file_offset = 500000L;


    /*
    ==========================================================================
    6. UNSIGNED LONG
    ==========================================================================

    Commonly used for:

        System clocks
        Timer counters
    */

    unsigned long cpu_clock = CPU_CLOCK_HZ;


    /*
    ==========================================================================
    7. LONG LONG
    ==========================================================================

    Added in C99.

    Usually:

        8 Bytes
    */

    long long total_distance_mm = 5000000000LL;


    /*
    ==========================================================================
    8. UNSIGNED LONG LONG
    ==========================================================================

    Maximum:

        18,446,744,073,709,551,615
    */

    unsigned long long flash_memory_size =
        16000000000ULL;


    /*
    ==========================================================================
    PRINT VARIABLES
    ==========================================================================
    */

    printf("==================================================\n");
    printf("SIGNED AND UNSIGNED INTEGER TYPES\n");
    printf("==================================================\n\n");

    printf("room_temperature      = %hd\n",
           room_temperature);

    printf("adc_count             = %hu\n",
           adc_count);

    printf("motor_speed           = %d\n",
           motor_speed);

    printf("system_ticks          = %u\n",
           system_ticks);

    printf("file_offset           = %ld\n",
           file_offset);

    printf("cpu_clock             = %lu\n",
           cpu_clock);

    printf("total_distance_mm     = %lld\n",
           total_distance_mm);

    printf("flash_memory_size     = %llu\n",
           flash_memory_size);


    /*
    ==========================================================================
    PRINT CONSTANTS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("COMPILE-TIME CONSTANTS\n");
    printf("==================================================\n\n");

    printf("CPU_CLOCK_HZ          = %lu\n",
           CPU_CLOCK_HZ);

    printf("UART_BAUDRATE         = %u\n",
           UART_BAUDRATE);

    printf("EEPROM_TOTAL_BYTES    = %u\n",
           EEPROM_TOTAL_BYTES);

    printf("TOTAL_LOG_ENTRIES     = %lld\n",
           TOTAL_LOG_ENTRIES);


    /*
    ==========================================================================
    TYPE SIZES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("TYPE SIZES\n");
    printf("==================================================\n\n");

    printf("short                 = %zu bytes\n",
           sizeof(short));

    printf("unsigned short        = %zu bytes\n",
           sizeof(unsigned short));

    printf("int                   = %zu bytes\n",
           sizeof(int));

    printf("unsigned int          = %zu bytes\n",
           sizeof(unsigned int));

    printf("long                  = %zu bytes\n",
           sizeof(long));

    printf("unsigned long         = %zu bytes\n",
           sizeof(unsigned long));

    printf("long long             = %zu bytes\n",
           sizeof(long long));

    printf("unsigned long long    = %zu bytes\n",
           sizeof(unsigned long long));


    /*
    ==========================================================================
    TYPE LIMITS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("TYPE LIMITS\n");
    printf("==================================================\n\n");

    printf("SHRT_MIN              = %hd\n",
           SHRT_MIN);

    printf("SHRT_MAX              = %hd\n",
           SHRT_MAX);

    printf("USHRT_MAX             = %hu\n",
           USHRT_MAX);

    printf("INT_MIN               = %d\n",
           INT_MIN);

    printf("INT_MAX               = %d\n",
           INT_MAX);

    printf("UINT_MAX              = %u\n",
           UINT_MAX);

    printf("LONG_MIN              = %ld\n",
           LONG_MIN);

    printf("LONG_MAX              = %ld\n",
           LONG_MAX);

    printf("ULONG_MAX             = %lu\n",
           ULONG_MAX);

    printf("LLONG_MIN             = %lld\n",
           LLONG_MIN);

    printf("LLONG_MAX             = %lld\n",
           LLONG_MAX);

    printf("ULLONG_MAX            = %llu\n",
           ULLONG_MAX);


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    unsigned int adc_raw_value = 2048U;

    unsigned long system_uptime_ms = 12345678UL;

    unsigned long long total_packets_received =
        5000000000ULL;

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLES\n");
    printf("==================================================\n\n");

    printf("ADC Raw Value         = %u\n",
           adc_raw_value);

    printf("System Uptime (ms)    = %lu\n",
           system_uptime_ms);

    printf("Total Packets         = %llu\n",
           total_packets_received);


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        unsigned int value = -1;

    RESULT:

        4294967295

    Because:

        Negative number gets converted
        into unsigned representation.

    --------------------------------------------------------------------------

    WRONG:

        int x = 5000000000;

    Integer overflow may occur.

    Use:

        long long
        or
        int64_t

    ==========================================================================
    */

    return 0;
}
