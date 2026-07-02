#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
==============================================================================
                    05. FIXED-WIDTH INTEGER TYPES IN C
==============================================================================

HEADER FILES
------------------------------------------------------------------------------

stdint.h
    Provides exact-width integer types.

inttypes.h
    Provides portable printf/scanf format macros.

==============================================================================


WHY FIXED-WIDTH TYPES?
==============================================================================

Problem:

    int
    long
    short

can have different sizes on different systems.

Example:

+----------------------+-----------+-----------+
| Data Type            | Windows   | Linux     |
+----------------------+-----------+-----------+
| short                | 2 Bytes   | 2 Bytes   |
| int                  | 4 Bytes   | 4 Bytes   |
| long                 | 4 Bytes   | 8 Bytes   |
| long long            | 8 Bytes   | 8 Bytes   |
+----------------------+-----------+-----------+

This creates portability problems.

==============================================================================


FIXED-WIDTH INTEGER TYPES
==============================================================================

+----------------------+-------+--------------------------+
| Type                 | Bytes | Range                    |
+----------------------+-------+--------------------------+
| int8_t               | 1     | -128 to 127              |
| uint8_t              | 1     | 0 to 255                 |
| int16_t              | 2     | -32768 to 32767          |
| uint16_t             | 2     | 0 to 65535              |
| int32_t              | 4     | -2147483648 to 2147483647|
| uint32_t             | 4     | 0 to 4294967295         |
| int64_t              | 8     | Very Large Signed Values |
| uint64_t             | 8     | Very Large Unsigned      |
+----------------------+-------+--------------------------+

==============================================================================


EMBEDDED INDUSTRY STANDARD
==============================================================================

Modern firmware projects prefer:

    uint8_t
    uint16_t
    uint32_t
    uint64_t

instead of:

    unsigned char
    unsigned short
    unsigned int
    unsigned long

Reason:

    Exact memory size
    Better portability
    Cleaner hardware mapping
    MISRA compliance

==============================================================================


PRINTF FORMAT MACROS
==============================================================================

+----------------------+----------------------+
| Type                 | Macro                |
+----------------------+----------------------+
| int8_t               | PRId8                |
| uint8_t              | PRIu8                |
| int16_t              | PRId16               |
| uint16_t             | PRIu16               |
| int32_t              | PRId32               |
| uint32_t             | PRIu32               |
| int64_t              | PRId64               |
| uint64_t             | PRIu64               |
+----------------------+----------------------+

Example:

    printf("%" PRIu32 "\n", value);

This is fully portable.

==============================================================================
*/


/*
------------------------------------------------------------------------------
Compile-Time Constants
------------------------------------------------------------------------------
*/

#define ADC_MAX_VALUE      ((uint16_t)4095U)
#define CPU_CLOCK_HZ       ((uint32_t)72000000U)
#define FLASH_SIZE_BYTES   ((uint64_t)16777216ULL)


int main(void)
{
    /*
    ==========================================================================
    int8_t
    ==========================================================================

    Exactly:

        8 Bits
        1 Byte
    */

    int8_t temperature_offset = -25;


    /*
    ==========================================================================
    uint8_t
    ==========================================================================

    Commonly used for:

        UART
        SPI
        I2C
        Raw Buffers
        Registers
    */

    uint8_t sensor_address = 0x68;


    /*
    ==========================================================================
    int16_t
    ==========================================================================
    */

    int16_t motor_rpm_offset = -1200;


    /*
    ==========================================================================
    uint16_t
    ==========================================================================

    Very common for:

        ADC
        Timers
        Hardware Registers
    */

    uint16_t adc_value = 2048U;


    /*
    ==========================================================================
    int32_t
    ==========================================================================
    */

    int32_t encoder_position = -250000;


    /*
    ==========================================================================
    uint32_t
    ==========================================================================

    Most common embedded integer type.
    */

    uint32_t system_ticks = 1000000U;


    /*
    ==========================================================================
    int64_t
    ==========================================================================
    */

    int64_t total_distance_mm =
        -5000000000LL;


    /*
    ==========================================================================
    uint64_t
    ==========================================================================
    */

    uint64_t flash_write_count =
        15000000000ULL;


    /*
    ==========================================================================
    PRINT VALUES
    ==========================================================================
    */

    printf("==================================================\n");
    printf("FIXED-WIDTH INTEGER VALUES\n");
    printf("==================================================\n\n");

    printf("temperature_offset   = %" PRId8 "\n",
           temperature_offset);

    printf("sensor_address       = %" PRIu8 "\n",
           sensor_address);

    printf("motor_rpm_offset     = %" PRId16 "\n",
           motor_rpm_offset);

    printf("adc_value            = %" PRIu16 "\n",
           adc_value);

    printf("encoder_position     = %" PRId32 "\n",
           encoder_position);

    printf("system_ticks         = %" PRIu32 "\n",
           system_ticks);

    printf("total_distance_mm    = %" PRId64 "\n",
           total_distance_mm);

    printf("flash_write_count    = %" PRIu64 "\n",
           flash_write_count);


    /*
    ==========================================================================
    TYPE SIZES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("TYPE SIZES\n");
    printf("==================================================\n\n");

    printf("int8_t      = %zu bytes\n",
           sizeof(int8_t));

    printf("uint8_t     = %zu bytes\n",
           sizeof(uint8_t));

    printf("int16_t     = %zu bytes\n",
           sizeof(int16_t));

    printf("uint16_t    = %zu bytes\n",
           sizeof(uint16_t));

    printf("int32_t     = %zu bytes\n",
           sizeof(int32_t));

    printf("uint32_t    = %zu bytes\n",
           sizeof(uint32_t));

    printf("int64_t     = %zu bytes\n",
           sizeof(int64_t));

    printf("uint64_t    = %zu bytes\n",
           sizeof(uint64_t));


    /*
    ==========================================================================
    TYPE LIMITS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("TYPE LIMITS\n");
    printf("==================================================\n\n");

    printf("INT8_MIN    = %" PRId8 "\n",
           INT8_MIN);

    printf("INT8_MAX    = %" PRId8 "\n",
           INT8_MAX);

    printf("UINT8_MAX   = %" PRIu8 "\n",
           UINT8_MAX);

    printf("INT16_MIN   = %" PRId16 "\n",
           INT16_MIN);

    printf("INT16_MAX   = %" PRId16 "\n",
           INT16_MAX);

    printf("UINT16_MAX  = %" PRIu16 "\n",
           UINT16_MAX);

    printf("INT32_MIN   = %" PRId32 "\n",
           INT32_MIN);

    printf("INT32_MAX   = %" PRId32 "\n",
           INT32_MAX);

    printf("UINT32_MAX  = %" PRIu32 "\n",
           UINT32_MAX);

    printf("INT64_MIN   = %" PRId64 "\n",
           INT64_MIN);

    printf("INT64_MAX   = %" PRId64 "\n",
           INT64_MAX);

    printf("UINT64_MAX  = %" PRIu64 "\n",
           UINT64_MAX);


    /*
    ==========================================================================
    EMBEDDED EXAMPLES
    ==========================================================================
    */

    uint16_t adc_raw_value = ADC_MAX_VALUE;

    uint32_t cpu_clock_hz = CPU_CLOCK_HZ;

    uint64_t flash_size = FLASH_SIZE_BYTES;

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLES\n");
    printf("==================================================\n\n");

    printf("ADC Maximum Value    = %" PRIu16 "\n",
           adc_raw_value);

    printf("CPU Clock (Hz)       = %" PRIu32 "\n",
           cpu_clock_hz);

    printf("Flash Size (Bytes)   = %" PRIu64 "\n",
           flash_size);


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        printf("%u", uint32_value);

    Better:

        printf("%" PRIu32, uint32_value);

    This guarantees portability.

    --------------------------------------------------------------------------

    WRONG:

        unsigned long value;

    Better:

        uint32_t value;

    Reason:

        unsigned long size changes
        between operating systems.

    --------------------------------------------------------------------------

    Embedded Industry Standard:

        uint8_t
        uint16_t
        uint32_t
        uint64_t

    are preferred in production firmware.

    ==========================================================================
    */

    return 0;
}
