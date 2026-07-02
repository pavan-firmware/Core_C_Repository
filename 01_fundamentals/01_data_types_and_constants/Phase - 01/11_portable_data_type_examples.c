#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
==============================================================================
                PORTABLE CORE C DATA TYPE EXAMPLES
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. Character types
2. Fixed-width integer types
3. Boolean values
4. Floating-point values
5. Literal suffixes
6. Format specifiers
7. Size and limit inspection
8. File-scope and static storage examples

==============================================================================
*/

#define SAMPLE_RATE_HZ        (1000U)
#define FRAME_BUFFER_BYTES    (256U)
#define DEVICE_NAME           "core-c-telemetry-node"

uint32_t g_uptime_ms = 0U;
static bool g_configuration_loaded = false;

static void print_type_summary(void)
{
    printf("char bytes            = %zu\n", sizeof(char));
    printf("int bytes             = %zu\n", sizeof(int));
    printf("uint16_t bytes        = %zu\n", sizeof(uint16_t));
    printf("uint32_t bytes        = %zu\n", sizeof(uint32_t));
    printf("float bytes           = %zu\n", sizeof(float));
    printf("bool bytes            = %zu\n", sizeof(bool));
}

static void print_value_selection_guide(void)
{
    puts("Value selection guide:");
    puts("  - bool          : state flags");
    puts("  - uint16_t      : compact counters");
    puts("  - uint32_t      : timers and timestamps");
    puts("  - float         : measured analog values");
    puts("  - uint8_t[]     : raw byte buffers");
}

int main(void)
{
    const char system_name[] = DEVICE_NAME;
    const uint16_t adc_sample_mv = 2048U;
    const uint32_t timestamp_ms = 125000UL;
    const float measured_voltage = 3.300F;
    bool ready_state = true;

    print_type_summary();
    print_value_selection_guide();

    printf("System name           = %s\n", system_name);
    printf("ADC sample            = %u\n", (unsigned)adc_sample_mv);
    printf("Timestamp             = %lu\n", (unsigned long)timestamp_ms);
    printf("Measured voltage      = %.3f V\n", measured_voltage);
    printf("Ready state           = %d\n", ready_state);
    printf("Sample rate           = %u Hz\n", SAMPLE_RATE_HZ);
    printf("Frame buffer size     = %u bytes\n", FRAME_BUFFER_BYTES);

    g_uptime_ms = timestamp_ms;
    g_configuration_loaded = true;
    printf("Uptime                = %lu ms\n", (unsigned long)g_uptime_ms);
    printf("Configuration loaded  = %s\n",
           g_configuration_loaded ? "true" : "false");

    return 0;
}
