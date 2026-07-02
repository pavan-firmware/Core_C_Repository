#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
==============================================================================
                    04. NESTED STRUCTURES IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. What are Nested Structures?

2. Why do we need Nested Structures?

3. Structure Inside Structure

4. Member Access Using Dot Operator

5. Deep Nested Access

6. Structure Initialization

7. Array of Nested Structures

8. Embedded Firmware Examples

9. Memory Layout

10. Common Beginner Mistakes

==============================================================================


WHAT ARE NESTED STRUCTURES?
==============================================================================

Nested Structure means:

    A structure containing another structure
    as one of its members.

Example:

    struct Address
    {
        ...
    };

    struct Student
    {
        struct Address address;
    };

==============================================================================


WHY USE NESTED STRUCTURES?
==============================================================================

Advantages:

    ✓ Better Organization

    ✓ Real World Modeling

    ✓ Code Reusability

    ✓ Modular Design

    ✓ Easier Maintenance

==============================================================================


REAL WORLD EXAMPLES
==============================================================================

Student
│
├── Personal Information
│   ├── Name
│   └── Age
│
└── Address
    ├── City
    ├── State
    └── PIN Code


Embedded System
│
├── Sensor Data
│   ├── Temperature
│   └── Humidity
│
└── UART Configuration
    ├── Baud Rate
    ├── Parity
    └── Stop Bits

==============================================================================
*/


/*
------------------------------------------------------------------------------
ADDRESS STRUCTURE
------------------------------------------------------------------------------
*/

struct Address
{
    char city[30];

    char state[30];

    uint32_t pin_code;
};


/*
------------------------------------------------------------------------------
STUDENT STRUCTURE
------------------------------------------------------------------------------
*/

struct Student
{
    uint32_t roll_number;

    char name[30];

    float marks;

    struct Address address;
};


/*
------------------------------------------------------------------------------
UART CONFIGURATION
------------------------------------------------------------------------------
*/

struct UartConfig
{
    uint32_t baud_rate;

    uint8_t parity;

    uint8_t stop_bits;
};


/*
------------------------------------------------------------------------------
SENSOR DATA
------------------------------------------------------------------------------
*/

struct SensorData
{
    float temperature;

    float humidity;

    bool sensor_status;
};


/*
------------------------------------------------------------------------------
EMBEDDED DEVICE STRUCTURE
------------------------------------------------------------------------------
*/

struct EmbeddedDevice
{
    char device_name[30];

    struct UartConfig uart;

    struct SensorData sensor;
};


int main(void)
{
    /*
    ==========================================================================
    STUDENT NESTED STRUCTURE
    ==========================================================================
    */

    struct Student student_1 =
    {
        .roll_number = 101,

        .name = "Pavan",

        .marks = 95.50F,

        .address =
        {
            .city = "Hyderabad",

            .state = "Telangana",

            .pin_code = 500001
        }
    };


    printf("==================================================\n");
    printf("STUDENT NESTED STRUCTURE\n");
    printf("==================================================\n\n");

    printf("Roll Number = %u\n",
           student_1.roll_number);

    printf("Name        = %s\n",
           student_1.name);

    printf("Marks       = %.2f\n",
           student_1.marks);

    printf("City        = %s\n",
           student_1.address.city);

    printf("State       = %s\n",
           student_1.address.state);

    printf("PIN Code    = %u\n",
           student_1.address.pin_code);


    /*
    ==========================================================================
    EMBEDDED DEVICE EXAMPLE
    ==========================================================================
    */

    struct EmbeddedDevice stm32_board =
    {
        .device_name = "STM32F407",

        .uart =
        {
            .baud_rate = 115200,

            .parity = 0,

            .stop_bits = 1
        },

        .sensor =
        {
            .temperature = 28.5F,

            .humidity = 70.0F,

            .sensor_status = true
        }
    };


    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED DEVICE STRUCTURE\n");
    printf("==================================================\n\n");

    printf("Device Name = %s\n",
           stm32_board.device_name);

    printf("Baud Rate   = %u\n",
           stm32_board.uart.baud_rate);

    printf("Parity      = %u\n",
           stm32_board.uart.parity);

    printf("Stop Bits   = %u\n",
           stm32_board.uart.stop_bits);

    printf("Temperature = %.2f C\n",
           stm32_board.sensor.temperature);

    printf("Humidity    = %.2f %%\n",
           stm32_board.sensor.humidity);

    printf("Sensor OK   = %d\n",
           stm32_board.sensor.sensor_status);


    /*
    ==========================================================================
    ARRAY OF NESTED STRUCTURES
    ==========================================================================
    */

    struct Student students[2] =
    {
        {
            .roll_number = 1,

            .name = "Alice",

            .marks = 90.0F,

            .address =
            {
                .city = "Mumbai",

                .state = "Maharashtra",

                .pin_code = 400001
            }
        },

        {
            .roll_number = 2,

            .name = "Bob",

            .marks = 88.5F,

            .address =
            {
                .city = "Chennai",

                .state = "Tamil Nadu",

                .pin_code = 600001
            }
        }
    };


    printf("\n");
    printf("==================================================\n");
    printf("ARRAY OF NESTED STRUCTURES\n");
    printf("==================================================\n\n");

    for (uint32_t index = 0U;
         index < 2U;
         index++)
    {
        printf("Student %u\n",
               index + 1U);

        printf("Name  : %s\n",
               students[index].name);

        printf("City  : %s\n",
               students[index].address.city);

        printf("State : %s\n\n",
               students[index].address.state);
    }


    /*
    ==========================================================================
    SIZE OF NESTED STRUCTURES
    ==========================================================================
    */

    printf("==================================================\n");
    printf("STRUCTURE SIZES\n");
    printf("==================================================\n\n");

    printf("Address        = %zu Bytes\n",
           sizeof(struct Address));

    printf("Student        = %zu Bytes\n",
           sizeof(struct Student));

    printf("UartConfig     = %zu Bytes\n",
           sizeof(struct UartConfig));

    printf("SensorData     = %zu Bytes\n",
           sizeof(struct SensorData));

    printf("EmbeddedDevice = %zu Bytes\n",
           sizeof(struct EmbeddedDevice));


    /*
    ==========================================================================
    MEMORY ACCESS EXAMPLES
    ==========================================================================

    Access Levels:

        student_1.name

    Single Level Access

    ------------------------------------------------------------

        student_1.address.city

    Double Level Access

    ------------------------------------------------------------

        stm32_board.uart.baud_rate

    Nested Structure Access

    ------------------------------------------------------------

        stm32_board.sensor.temperature

    Deep Nested Access

    ==========================================================================
    */


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        student.city

    CORRECT:

        student.address.city

    ------------------------------------------------------------

    WRONG:

        uart.baud_rate

    Without:

        device.uart.baud_rate

    ------------------------------------------------------------

    WRONG:

        Thinking:

            Nested structures
            create pointers.

    Reality:

        Nested structures
        are stored directly
        inside parent structures.

    ------------------------------------------------------------

    IMPORTANT:

        Parent structure size
        includes all nested
        structure sizes and
        possible padding bytes.

    ==========================================================================
    */

    return 0;
}
