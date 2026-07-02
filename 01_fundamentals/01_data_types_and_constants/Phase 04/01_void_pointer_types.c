#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
==============================================================================
                    01. VOID POINTER TYPES IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. What is a void pointer?

2. Generic Pointers

3. Type Casting

4. Dereferencing Rules

5. Pointer Arithmetic Limitations

6. Generic Functions

7. Embedded Firmware Examples

8. Industry Best Practices

9. Common Beginner Mistakes

==============================================================================


WHAT IS A VOID POINTER?
==============================================================================

void *

means:

    Generic Pointer

A void pointer can store:

    int address

    float address

    char address

    struct address

    any data type address

==============================================================================


BASIC SYNTAX
==============================================================================

int value = 100;

void *ptr = &value;

==============================================================================


IMPORTANT RULE
==============================================================================

WRONG:

    printf("%d", *ptr);

Reason:

    Compiler does not know
    what data type ptr points to.

==============================================================================


CORRECT WAY
==============================================================================

printf("%d", *(int *)ptr);

Steps:

    1. Convert void *
       to int *

    2. Dereference it

==============================================================================


VOID POINTER ARITHMETIC
==============================================================================

WRONG:

    ptr++;

Standard C:

    ERROR

Reason:

    Compiler does not know
    object size.

==============================================================================


CORRECT:

    int *int_ptr;

    int_ptr++;

==============================================================================


EMBEDDED USE CASES
==============================================================================

void pointers are used in:

    ✓ malloc()

    ✓ Generic Drivers

    ✓ RTOS APIs

    ✓ DMA APIs

    ✓ Callback Systems

    ✓ Device Frameworks

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

    float marks;
};


/*
------------------------------------------------------------------------------
GENERIC PRINT FUNCTION
------------------------------------------------------------------------------
*/

void print_integer(void *data)
{
    printf("Integer Value = %d\n",
           *(int *)data);
}


/*
------------------------------------------------------------------------------
GENERIC FLOAT FUNCTION
------------------------------------------------------------------------------
*/

void print_float(void *data)
{
    printf("Float Value = %.2f\n",
           *(float *)data);
}


/*
------------------------------------------------------------------------------
GENERIC STRUCTURE FUNCTION
------------------------------------------------------------------------------
*/

void print_student(void *data)
{
    struct Student *student =
        (struct Student *)data;

    printf("Roll Number = %u\n",
           student->roll_number);

    printf("Marks       = %.2f\n",
           student->marks);
}


int main(void)
{
    /*
    ==========================================================================
    INTEGER EXAMPLE
    ==========================================================================
    */

    int number = 100;

    void *generic_pointer =
        &number;


    printf("==================================================\n");
    printf("INTEGER EXAMPLE\n");
    printf("==================================================\n\n");

    printf("Address = %p\n",
           generic_pointer);

    printf("Value   = %d\n",
           *(int *)generic_pointer);


    /*
    ==========================================================================
    FLOAT EXAMPLE
    ==========================================================================
    */

    float temperature = 28.75F;

    generic_pointer =
        &temperature;


    printf("\n");
    printf("==================================================\n");
    printf("FLOAT EXAMPLE\n");
    printf("==================================================\n\n");

    printf("Address = %p\n",
           generic_pointer);

    printf("Value   = %.2f\n",
           *(float *)generic_pointer);


    /*
    ==========================================================================
    CHARACTER EXAMPLE
    ==========================================================================
    */

    char grade = 'A';

    generic_pointer =
        &grade;


    printf("\n");
    printf("==================================================\n");
    printf("CHARACTER EXAMPLE\n");
    printf("==================================================\n\n");

    printf("Address = %p\n",
           generic_pointer);

    printf("Value   = %c\n",
           *(char *)generic_pointer);


    /*
    ==========================================================================
    STRUCTURE EXAMPLE
    ==========================================================================
    */

    struct Student student_1 =
    {
        .roll_number = 101U,

        .marks = 95.50F
    };

    generic_pointer =
        &student_1;


    printf("\n");
    printf("==================================================\n");
    printf("STRUCTURE EXAMPLE\n");
    printf("==================================================\n\n");

    print_student(
        generic_pointer);


    /*
    ==========================================================================
    GENERIC FUNCTIONS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("GENERIC FUNCTIONS\n");
    printf("==================================================\n\n");

    print_integer(
        &number);

    print_float(
        &temperature);


    /*
    ==========================================================================
    SIZE OF VOID POINTER
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("VOID POINTER SIZE\n");
    printf("==================================================\n\n");

    printf("sizeof(void *) = %zu Bytes\n",
           sizeof(void *));


    /*
    ==========================================================================
    POINTER CONVERSIONS
    ==========================================================================
    */

    int sensor_value = 500;

    int *sensor_pointer =
        &sensor_value;

    void *generic_sensor_pointer =
        sensor_pointer;

    int *restored_pointer =
        (int *)generic_sensor_pointer;


    printf("\n");
    printf("==================================================\n");
    printf("POINTER CONVERSIONS\n");
    printf("==================================================\n\n");

    printf("Original Value = %d\n",
           *sensor_pointer);

    printf("Restored Value = %d\n",
           *restored_pointer);


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLES\n");
    printf("==================================================\n\n");

    printf("malloc() returns:\n");

    printf("    void *\n");

    printf("\n");

    printf("RTOS task arguments:\n");

    printf("    void *parameter\n");

    printf("\n");

    printf("Generic driver APIs:\n");

    printf("    void *config\n");

    printf("\n");

    printf("DMA buffers:\n");

    printf("    void *buffer\n");


    /*
    ==========================================================================
    INDUSTRY BEST PRACTICES
    ==========================================================================

    GOOD:

        void *generic_data;

    ------------------------------------------------------------

    GOOD:

        Cast before dereferencing.

            *(int *)ptr

    ------------------------------------------------------------

    GOOD:

        Use void pointers
        for generic interfaces.

    ==========================================================================
    */


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        *void_pointer

    ERROR:

        Type unknown.

    ------------------------------------------------------------

    WRONG:

        void_pointer++;

    Standard C:

        Not allowed.

    ------------------------------------------------------------

    WRONG:

        Casting to wrong type.

        Example:

            int value = 100;

            printf("%f",
                   *(float *)&value);

    Undefined Behavior.

    ------------------------------------------------------------

    IMPORTANT:

        void *

        means:

            Generic Address

        NOT:

            Generic Value

    ==========================================================================
    */

    return 0;
}
