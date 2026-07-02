#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
==============================================================================
                        02. TYPEDEF KEYWORD IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. What is typedef?

2. Why use typedef?

3. Primitive Type Aliasing

4. Structure Type Aliasing

5. Enum Type Aliasing

6. Pointer Type Aliasing

7. Function Pointer Type Aliasing

8. Embedded Firmware Examples

9. Industry Best Practices

10. Common Beginner Mistakes

==============================================================================


WHAT IS typedef?
==============================================================================

typedef creates:

    A NEW NAME (ALIAS)

for an existing data type.

Syntax:

    typedef existing_type new_name;

Example:

    typedef unsigned int uint;

    uint value = 100;

Equivalent To:

    unsigned int value = 100;

==============================================================================


WHY USE typedef?
==============================================================================

Advantages:

    ✓ Better Readability

    ✓ Easier Maintenance

    ✓ Platform Independence

    ✓ Cleaner APIs

    ✓ Embedded Industry Standard

==============================================================================


PRIMITIVE TYPE ALIASES
==============================================================================

Example:

    typedef uint8_t  u8;
    typedef uint16_t u16;
    typedef uint32_t u32;
    typedef uint64_t u64;

Modern Embedded Projects:

    Usually prefer:

        uint8_t
        uint16_t
        uint32_t

Instead of:

        unsigned int
        unsigned long

==============================================================================


TYPEDEF WITH STRUCTURES
==============================================================================

WITHOUT typedef:

    struct SensorData sensor;

WITH typedef:

    SensorData sensor;

Much cleaner.

==============================================================================


TYPEDEF WITH FUNCTION POINTERS
==============================================================================

WITHOUT typedef:

    void (*callback)(void);

WITH typedef:

    typedef void (*CallbackFunction)(void);

    CallbackFunction callback;

==============================================================================

*/


/*
------------------------------------------------------------------------------
PRIMITIVE TYPE ALIASES
------------------------------------------------------------------------------
*/

typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;

typedef float       f32;
typedef double      f64;


/*
------------------------------------------------------------------------------
ARRAY TYPE ALIAS
------------------------------------------------------------------------------
*/

typedef char DeviceName[32];


/*
------------------------------------------------------------------------------
POINTER TYPE ALIAS
------------------------------------------------------------------------------
*/

typedef int* IntPointer;


/*
------------------------------------------------------------------------------
ENUM TYPE ALIAS
------------------------------------------------------------------------------
*/

typedef enum
{
    MOTOR_STOP = 0,
    MOTOR_START = 1
}
MotorState;


/*
------------------------------------------------------------------------------
STRUCTURE TYPE ALIAS
------------------------------------------------------------------------------
*/

typedef struct
{
    u16 temperature;

    u16 humidity;

    u8 sensor_id;
}
SensorData;


/*
------------------------------------------------------------------------------
FUNCTION POINTER TYPE ALIAS
------------------------------------------------------------------------------
*/

typedef void (*CallbackFunction)(void);


/*
------------------------------------------------------------------------------
CALLBACK FUNCTION
------------------------------------------------------------------------------
*/

void uart_rx_callback(void)
{
    printf("UART RX Callback Executed\n");
}


int main(void)
{
    /*
    ==========================================================================
    PRIMITIVE TYPE ALIASES
    ==========================================================================
    */

    u8 led_status = 1U;

    u16 adc_value = 2048U;

    u32 system_tick = 1000000U;

    u64 total_packets = 5000000000ULL;


    /*
    ==========================================================================
    FLOATING POINT ALIASES
    ==========================================================================
    */

    f32 voltage = 3.3F;

    f64 temperature = 27.56789;


    /*
    ==========================================================================
    ARRAY TYPE ALIAS
    ==========================================================================
    */

    DeviceName device_name =
        "STM32 Sensor Board";


    /*
    ==========================================================================
    POINTER TYPE ALIAS
    ==========================================================================
    */

    int value = 100;

    IntPointer value_ptr =
        &value;


    /*
    ==========================================================================
    STRUCTURE TYPE ALIAS
    ==========================================================================
    */

    SensorData dht11_sensor =
    {
        .temperature = 28,

        .humidity = 70,

        .sensor_id = 1
    };


    /*
    ==========================================================================
    ENUM TYPE ALIAS
    ==========================================================================
    */

    MotorState motor_state =
        MOTOR_START;


    /*
    ==========================================================================
    FUNCTION POINTER TYPE ALIAS
    ==========================================================================
    */

    CallbackFunction callback =
        uart_rx_callback;


    /*
    ==========================================================================
    PRIMITIVE TYPEDEFS
    ==========================================================================
    */

    printf("==================================================\n");
    printf("PRIMITIVE TYPEDEFS\n");
    printf("==================================================\n\n");

    printf("LED Status    = %u\n",
           led_status);

    printf("ADC Value     = %u\n",
           adc_value);

    printf("System Tick   = %u\n",
           system_tick);

    printf("Total Packets = %" PRIu64 "\n",
           total_packets);


    /*
    ==========================================================================
    FLOAT TYPEDEFS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("FLOAT TYPEDEFS\n");
    printf("==================================================\n\n");

    printf("Voltage       = %.2f V\n",
           voltage);

    printf("Temperature   = %.5lf C\n",
           temperature);


    /*
    ==========================================================================
    ARRAY TYPEDEF
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("ARRAY TYPEDEF\n");
    printf("==================================================\n\n");

    printf("Device Name   = %s\n",
           device_name);


    /*
    ==========================================================================
    POINTER TYPEDEF
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("POINTER TYPEDEF\n");
    printf("==================================================\n\n");

    printf("Value         = %d\n",
           *value_ptr);


    /*
    ==========================================================================
    STRUCTURE TYPEDEF
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("STRUCTURE TYPEDEF\n");
    printf("==================================================\n\n");

    printf("Temperature   = %u C\n",
           dht11_sensor.temperature);

    printf("Humidity      = %u %%\n",
           dht11_sensor.humidity);

    printf("Sensor ID     = %u\n",
           dht11_sensor.sensor_id);


    /*
    ==========================================================================
    ENUM TYPEDEF
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("ENUM TYPEDEF\n");
    printf("==================================================\n\n");

    printf("Motor State   = %d\n",
           motor_state);


    /*
    ==========================================================================
    FUNCTION POINTER TYPEDEF
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("FUNCTION POINTER TYPEDEF\n");
    printf("==================================================\n\n");

    callback();


    /*
    ==========================================================================
    TYPE SIZES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("TYPE SIZES\n");
    printf("==================================================\n\n");

    printf("u8            = %zu Bytes\n",
           sizeof(u8));

    printf("u16           = %zu Bytes\n",
           sizeof(u16));

    printf("u32           = %zu Bytes\n",
           sizeof(u32));

    printf("u64           = %zu Bytes\n",
           sizeof(u64));

    printf("SensorData    = %zu Bytes\n",
           sizeof(SensorData));


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    typedef struct
    {
        u32 baud_rate;

        u8 parity;

        u8 stop_bits;
    }
    UartConfig;


    UartConfig uart1 =
    {
        .baud_rate = 115200U,

        .parity = 0U,

        .stop_bits = 1U
    };


    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLES\n");
    printf("==================================================\n\n");

    printf("UART Baud Rate = %u\n",
           uart1.baud_rate);

    printf("UART Parity    = %u\n",
           uart1.parity);

    printf("UART Stop Bits = %u\n",
           uart1.stop_bits);


    /*
    ==========================================================================
    INDUSTRY BEST PRACTICES
    ==========================================================================

    GOOD:

        typedef struct
        {
            ...
        }
        SensorData;

    ------------------------------------------------------------

    GOOD:

        typedef void
        (*CallbackFunction)(void);

    ------------------------------------------------------------

    GOOD:

        typedef enum
        {
            ...
        }
        MotorState;

    ------------------------------------------------------------

    Modern Embedded Projects:

        Prefer:

            uint8_t
            uint16_t
            uint32_t

        over:

            u8
            u16
            u32

        unless project coding standards
        explicitly require aliases.

    ==========================================================================
    */


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        typedef creates
        a completely new type.

    Reality:

        typedef only creates
        an alias.

    ------------------------------------------------------------

    WRONG:

        typedef int* IntPtr;

        IntPtr a, b;

    Reality:

        Both a and b
        are pointers.

    ------------------------------------------------------------

    WRONG:

        Using typedef
        for everything.

    Use typedef only when:

        ✓ It improves readability

        ✓ It simplifies APIs

        ✓ It matches project standards

    ==========================================================================
    */

    return 0;
}
