#include <stdio.h>
#include <stdint.h>

/*
==============================================================================
                    04. POINTER TYPE CASTING IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. What is Pointer Type Casting?

2. Why do we need Pointer Casting?

3. Implicit Pointer Conversion

4. Explicit Pointer Conversion

5. void* to Other Pointers

6. Integer Pointer Casting

7. Structure Pointer Casting

8. Type Punning Basics

9. Embedded Firmware Examples

10. Common Beginner Mistakes

==============================================================================


WHAT IS POINTER TYPE CASTING?
==============================================================================

Pointer Type Casting means:

    Converting one pointer type
    into another pointer type.

Example:

    int value = 100;

    int *int_ptr = &value;

    void *generic_ptr = int_ptr;

    int *new_ptr =
        (int *)generic_ptr;

==============================================================================


WHY DO WE NEED POINTER CASTING?
==============================================================================

Applications:

    ✓ Generic Functions

    ✓ malloc()

    ✓ Hardware Registers

    ✓ Driver Frameworks

    ✓ Communication Buffers

    ✓ Legacy APIs

==============================================================================


IMPLICIT CONVERSION
==============================================================================

Allowed:

    int *ptr;

    void *generic_ptr = ptr;

Compiler:

    Automatically converts.

==============================================================================


EXPLICIT CONVERSION
==============================================================================

Required:

    void *generic_ptr;

    int *ptr =
        (int *)generic_ptr;

==============================================================================


IMPORTANT RULE
==============================================================================

WRONG:

    float value = *(float *)int_ptr;

Reason:

    Different data types.

Can cause:

    Undefined Behavior.

==============================================================================


TYPE PUNNING
==============================================================================

Type Punning means:

    Reading memory using
    another data type.

Example:

    uint32_t value;

    uint8_t *byte_ptr =
        (uint8_t *)&value;

Used in:

    Embedded Systems

    Communication Drivers

    DMA Buffers

==============================================================================


EMBEDDED USE CASES
==============================================================================

Common Uses:

    ✓ Memory Mapped Registers

    ✓ UART Buffers

    ✓ DMA Buffers

    ✓ Generic Driver APIs

    ✓ RTOS Task Parameters

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
    int *number =
        (int *)data;

    printf("Integer = %d\n",
           *number);
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
    INT POINTER TO VOID POINTER
    ==========================================================================
    */

    int value = 100;

    int *int_ptr =
        &value;

    void *generic_ptr =
        int_ptr;


    printf("==================================================\n");
    printf("INT TO VOID POINTER\n");
    printf("==================================================\n\n");

    printf("Value = %d\n",
           *(int *)generic_ptr);


    /*
    ==========================================================================
    VOID POINTER TO INT POINTER
    ==========================================================================
    */

    int *new_int_ptr =
        (int *)generic_ptr;


    printf("\n");
    printf("==================================================\n");
    printf("VOID TO INT POINTER\n");
    printf("==================================================\n\n");

    printf("Value = %d\n",
           *new_int_ptr);


    /*
    ==========================================================================
    FLOAT POINTER CASTING
    ==========================================================================
    */

    float temperature = 28.75F;

    void *float_generic_ptr =
        &temperature;


    printf("\n");
    printf("==================================================\n");
    printf("FLOAT POINTER CASTING\n");
    printf("==================================================\n\n");

    printf("Temperature = %.2f\n",
           *(float *)float_generic_ptr);


    /*
    ==========================================================================
    STRUCTURE POINTER CASTING
    ==========================================================================
    */

    struct Student student_1 =
    {
        .roll_number = 101,

        .marks = 95.50F
    };


    printf("\n");
    printf("==================================================\n");
    printf("STRUCTURE POINTER CASTING\n");
    printf("==================================================\n\n");

    print_student(
        &student_1);


    /*
    ==========================================================================
    TYPE PUNNING EXAMPLE
    ==========================================================================
    */

    uint32_t register_value =
        0xAABBCCDDU;

    uint8_t *byte_pointer =
        (uint8_t *)&register_value;


    printf("\n");
    printf("==================================================\n");
    printf("TYPE PUNNING EXAMPLE\n");
    printf("==================================================\n\n");

    printf("Register Value = 0x%08X\n",
           register_value);

    printf("\n");

    for (uint32_t index = 0U;
         index < sizeof(register_value);
         index++)
    {
        printf("Byte[%u] = 0x%02X\n",
               index,
               byte_pointer[index]);
    }


    /*
    ==========================================================================
    GENERIC FUNCTION EXAMPLE
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("GENERIC FUNCTION EXAMPLE\n");
    printf("==================================================\n\n");

    print_integer(
        &value);


    /*
    ==========================================================================
    MEMORY MAPPED REGISTER EXAMPLE
    ==========================================================================
    */

    volatile uint32_t gpio_register =
        0x00000000U;

    volatile uint32_t *gpio_ptr =
        (volatile uint32_t *)&gpio_register;

    *gpio_ptr |= (1U << 5U);


    printf("\n");
    printf("==================================================\n");
    printf("MEMORY MAPPED REGISTER\n");
    printf("==================================================\n\n");

    printf("GPIO Register = 0x%08X\n",
           *gpio_ptr);


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLES\n");
    printf("==================================================\n\n");

    printf("malloc() returns void *\n");

    printf("DMA Buffers use pointer casting\n");

    printf("UART Drivers use generic pointers\n");

    printf("Memory Mapped Registers use casting\n");

    printf("RTOS Task Parameters use void *\n");


    /*
    ==========================================================================
    INDUSTRY BEST PRACTICES
    ==========================================================================

    GOOD:

        void *generic_ptr;

        int *ptr =
            (int *)generic_ptr;

    ------------------------------------------------------------

    GOOD:

        Use explicit casts
        when type conversion
        is necessary.

    ------------------------------------------------------------

    GOOD:

        Preserve:

            const

            volatile

        qualifiers.

    Example:

        volatile uint32_t *ptr;

    ==========================================================================
    */


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        float *ptr =
            (float *)&integer;

    Undefined Behavior.

    ------------------------------------------------------------

    WRONG:

        Dereferencing:

            void *

    Without casting.

    ------------------------------------------------------------

    WRONG:

        Ignoring:

            const

            volatile

        qualifiers.

    ------------------------------------------------------------

    IMPORTANT:

        Pointer Casting:

            Changes interpretation
            of memory.

        It does NOT:

            Change actual data.

    ------------------------------------------------------------

    TYPE PUNNING:

        Powerful

        But:

            Must be used carefully.

    ==========================================================================
    */

    return 0;
}
