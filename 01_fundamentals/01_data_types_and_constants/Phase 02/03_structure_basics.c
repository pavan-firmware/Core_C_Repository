#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
==============================================================================
                    03. STRUCTURE BASICS IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. What is a Structure?

2. Why do we need Structures?

3. Structure Syntax

4. Structure Declaration

5. Structure Variables

6. Member Access Operator (.)

7. Structure Initialization

8. sizeof Structure

9. Array of Structures

10. Embedded Firmware Examples

11. Common Beginner Mistakes

==============================================================================


WHAT IS A STRUCTURE?
==============================================================================

A structure is a user-defined data type.

It groups multiple variables
of different data types into
a single logical unit.

Example:

    Student

        Name
        Roll Number
        Marks

Instead of:

    char name[20];
    int roll_no;
    float marks;

We can create:

    struct Student
    {
        ...
    };

==============================================================================


WHY USE STRUCTURES?
==============================================================================

Advantages:

    ✓ Better Organization

    ✓ Logical Grouping

    ✓ Cleaner Code

    ✓ Easy Data Management

    ✓ Real World Modeling

==============================================================================


STRUCTURE SYNTAX
==============================================================================

struct StructureName
{
    member_1;

    member_2;

    member_3;
};

Example:

struct Student
{
    int roll_number;

    float marks;
};

==============================================================================


MEMBER ACCESS OPERATOR
==============================================================================

Operator:

    .

Example:

    student_1.marks

Meaning:

    Access marks member
    of student_1

==============================================================================


MEMORY LAYOUT
==============================================================================

Example:

struct Example
{
    char a;
    int  b;
};

Memory:

    +-----+
    |  a  |
    +-----+

    Padding Bytes

    +-----+
    |  b  |
    +-----+

Compiler may add padding
for alignment purposes.

==============================================================================
*/


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
};


/*
------------------------------------------------------------------------------
SENSOR STRUCTURE
------------------------------------------------------------------------------
*/

struct SensorData
{
    uint16_t temperature;

    uint16_t humidity;

    bool sensor_status;
};


/*
------------------------------------------------------------------------------
UART CONFIGURATION STRUCTURE
------------------------------------------------------------------------------
*/

struct UartConfig
{
    uint32_t baud_rate;

    uint8_t parity;

    uint8_t stop_bits;
};


int main(void)
{
    /*
    ==========================================================================
    STRUCTURE VARIABLE CREATION
    ==========================================================================
    */

    struct Student student_1;


    /*
    ==========================================================================
    MEMBER ASSIGNMENT
    ==========================================================================
    */

    student_1.roll_number = 101U;

    student_1.marks = 95.50F;

    snprintf(student_1.name,
             sizeof(student_1.name),
             "Pavan");


    /*
    ==========================================================================
    PRINT STUDENT DATA
    ==========================================================================
    */

    printf("==================================================\n");
    printf("STUDENT STRUCTURE\n");
    printf("==================================================\n\n");

    printf("Roll Number = %u\n",
           student_1.roll_number);

    printf("Name        = %s\n",
           student_1.name);

    printf("Marks       = %.2f\n",
           student_1.marks);


    /*
    ==========================================================================
    STRUCTURE INITIALIZATION
    ==========================================================================
    */

    struct SensorData dht11_sensor =
    {
        .temperature = 28,

        .humidity = 70,

        .sensor_status = true
    };


    printf("\n");
    printf("==================================================\n");
    printf("STRUCTURE INITIALIZATION\n");
    printf("==================================================\n\n");

    printf("Temperature  = %u C\n",
           dht11_sensor.temperature);

    printf("Humidity     = %u %%\n",
           dht11_sensor.humidity);

    printf("Sensor State = %d\n",
           dht11_sensor.sensor_status);


    /*
    ==========================================================================
    UART CONFIGURATION
    ==========================================================================
    */

    struct UartConfig uart1 =
    {
        .baud_rate = 115200U,

        .parity = 0U,

        .stop_bits = 1U
    };


    printf("\n");
    printf("==================================================\n");
    printf("UART CONFIGURATION\n");
    printf("==================================================\n\n");

    printf("Baud Rate = %u\n",
           uart1.baud_rate);

    printf("Parity    = %u\n",
           uart1.parity);

    printf("Stop Bits = %u\n",
           uart1.stop_bits);


    /*
    ==========================================================================
    ARRAY OF STRUCTURES
    ==========================================================================
    */

    struct Student students[2] =
    {
        {
            .roll_number = 1,
            .name = "Alice",
            .marks = 91.5F
        },

        {
            .roll_number = 2,
            .name = "Bob",
            .marks = 88.0F
        }
    };


    printf("\n");
    printf("==================================================\n");
    printf("ARRAY OF STRUCTURES\n");
    printf("==================================================\n\n");

    for (uint32_t index = 0U;
         index < 2U;
         index++)
    {
        printf("Student %u\n",
               index + 1U);

        printf("Roll No : %u\n",
               students[index].roll_number);

        printf("Name    : %s\n",
               students[index].name);

        printf("Marks   : %.2f\n\n",
               students[index].marks);
    }


    /*
    ==========================================================================
    SIZE OF STRUCTURES
    ==========================================================================
    */

    printf("==================================================\n");
    printf("STRUCTURE SIZES\n");
    printf("==================================================\n\n");

    printf("Student    = %zu Bytes\n",
           sizeof(struct Student));

    printf("SensorData = %zu Bytes\n",
           sizeof(struct SensorData));

    printf("UartConfig = %zu Bytes\n",
           sizeof(struct UartConfig));


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    struct SensorData lm35_sensor =
    {
        .temperature = 35,

        .humidity = 0,

        .sensor_status = true
    };

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED FIRMWARE EXAMPLES\n");
    printf("==================================================\n\n");

    if (lm35_sensor.sensor_status)
    {
        printf("Sensor Active\n");

        printf("Temperature = %u C\n",
               lm35_sensor.temperature);
    }


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        student.roll_number

    Without:

        struct Student student;

    ------------------------------------------------------------

    WRONG:

        student->roll_number

    For normal variables.

    Use:

        .

    Operator.

    ------------------------------------------------------------

    CORRECT:

        student.roll_number

    ------------------------------------------------------------

    Use:

        ->

    Only for:

        Structure Pointers

    (Later Pointer Phase)

    ------------------------------------------------------------

    IMPORTANT:

        Compiler may insert
        padding bytes.

        So:

            sizeof(struct)

        may be larger than
        the sum of members.

    ==========================================================================
    */

    return 0;
}
