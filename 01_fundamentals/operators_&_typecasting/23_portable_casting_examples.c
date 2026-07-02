#include <stdio.h>
#include <stdint.h>

/*
===============================================================================
                PORTABLE CORE C CASTING EXAMPLES
===============================================================================

This file keeps the casting discussion grounded in standard C:

1. Integer to floating-point conversion
2. Floating-point to integer conversion
3. Narrowing with explicit intent
4. Void-pointer round-trips
5. Const-aware pointer handling
6. Function pointer selection

===============================================================================
*/

typedef struct
{
    uint16_t frame_id;
    uint16_t sample_count;
} FrameHeader;

typedef int (*binary_operation)(int lhs, int rhs);

static int add(int lhs, int rhs)
{
    return lhs + rhs;
}

static int multiply(int lhs, int rhs)
{
    return lhs * rhs;
}

int main(void)
{
    uint16_t adc_value = 2048U;
    float voltage = ((float)adc_value * 3.3f) / 4095.0f;

    printf("ADC value            = %u\n", (unsigned)adc_value);
    printf("Converted voltage    = %.3f V\n", voltage);

    double temperature_c = 27.9;
    int whole_celsius = (int)temperature_c;
    printf("Temperature rounded down = %d C\n", whole_celsius);

    uint32_t raw_word = 0x12345678U;
    uint8_t first_byte = (uint8_t)(raw_word & 0xFFU);
    printf("First byte           = 0x%02X\n", (unsigned)first_byte);

    FrameHeader header = { .frame_id = 9U, .sample_count = 4U };
    void *generic_pointer = &header;
    FrameHeader *typed_pointer = (FrameHeader *)generic_pointer;
    printf("Frame id             = %u\n", (unsigned)typed_pointer->frame_id);
    printf("Sample count         = %u\n", (unsigned)typed_pointer->sample_count);

    const int command_left = 6;
    const int command_right = 7;
    binary_operation operation = add;
    printf("add(%d, %d)          = %d\n",
           command_left, command_right, operation(command_left, command_right));
    operation = multiply;
    printf("multiply(%d, %d)     = %d\n",
           command_left, command_right, operation(command_left, command_right));

    /*
        Core rule:
        cast only when the conversion is intentional, documented, and safe.
    */

    return 0;
}
