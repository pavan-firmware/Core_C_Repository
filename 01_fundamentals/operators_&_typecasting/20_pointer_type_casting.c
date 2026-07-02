#include <stdio.h>
#include <stdint.h>

/*
===============================================================================
                    20_POINTER_TYPE_CASTING.C
===============================================================================

TOPIC:
    Pointer Type Casting

STANDARD:
    C99, C11, C17, C23

===============================================================================

WHAT IS POINTER TYPE CASTING?

Definition:

    Converting one pointer type into another pointer type.

===============================================================================

GENERAL SYNTAX

    (new_pointer_type)old_pointer

Example:

    int *ptr;

    char *char_ptr =
        (char *)ptr;

===============================================================================

POINTER CASTING TABLE

+----------------------+----------------------+--------------------------+
| SOURCE               | DESTINATION          | PURPOSE                  |
+----------------------+----------------------+--------------------------+
| int *                | char *               | Byte access              |
| char *               | int *                | Integer access           |
| any pointer          | void *               | Generic pointer          |
| void *               | any pointer          | Type recovery            |
| uint32_t *           | uint8_t *            | Register byte access     |
+----------------------+----------------------+--------------------------+

===============================================================================

IMPORTANT RULE

POINTER CASTING CHANGES:

    HOW DATA IS INTERPRETED

IT DOES NOT CHANGE:

    Actual memory contents.

===============================================================================
*/


int main(void)
{
    /*
    ===========================================================================
    1. INT POINTER TO CHAR POINTER
    ===========================================================================
    */

    int number = 0x12345678;

    int *int_ptr = &number;

    char *char_ptr =
        (char *)int_ptr;

    printf("=========================================\n");
    printf("1. INT* TO CHAR*\n");
    printf("=========================================\n");

    printf("Integer Value = 0x%X\n",
           number);

    printf("First Byte    = 0x%X\n\n",
           (unsigned char)*char_ptr);



    /*
    ===========================================================================
    MEMORY VISUALIZATION

    number:

        0x12345678

    Little Endian:

        Address

        +------+------+
        | 78   | LSB  |
        +------+------+

        +------+------+
        | 56   |      |
        +------+------+

        +------+------+
        | 34   |      |
        +------+------+

        +------+------+
        | 12   | MSB  |
        +------+------+

    char_ptr:

        Reads one byte.

    ===========================================================================
    */



    /*
    ===========================================================================
    2. CHAR POINTER TO INT POINTER
    ===========================================================================
    */

    uint8_t buffer[4] =
    {
        0x78,
        0x56,
        0x34,
        0x12
    };

    int *buffer_ptr =
        (int *)buffer;

    printf("=========================================\n");
    printf("2. CHAR* TO INT*\n");
    printf("=========================================\n");

    printf("Value = 0x%X\n\n",
           *buffer_ptr);



    /*
    ===========================================================================
    WARNING

    This depends on:

        • Endianness
        • Alignment
        • Platform

    Embedded systems must be careful.

    ===========================================================================
    */



    /*
    ===========================================================================
    3. POINTER ARITHMETIC DIFFERENCE
    ===========================================================================
    */

    int values[3] =
    {
        100,
        200,
        300
    };

    int *iptr = values;

    char *cptr =
        (char *)values;

    printf("=========================================\n");
    printf("3. POINTER ARITHMETIC\n");
    printf("=========================================\n");

    printf("iptr      = %p\n",
           (void *)iptr);

    printf("iptr + 1  = %p\n",
           (void *)(iptr + 1));

    printf("\n");

    printf("cptr      = %p\n",
           (void *)cptr);

    printf("cptr + 1  = %p\n\n",
           (void *)(cptr + 1));



    /*
    ===========================================================================
    MEMORY VISUALIZATION

    int*

        +1

        Moves:

            sizeof(int)

            Usually:

                4 bytes

    ----------------------------------------

    char*

        +1

        Moves:

            1 byte

    ===========================================================================
    */



    /*
    ===========================================================================
    4. ACCESSING INDIVIDUAL BYTES
    ===========================================================================
    */

    uint32_t register_value =
        0xAABBCCDD;

    uint8_t *byte_ptr =
        (uint8_t *)&register_value;

    printf("=========================================\n");
    printf("4. BYTE ACCESS\n");
    printf("=========================================\n");

    for (int i = 0; i < 4; i++)
    {
        printf("Byte[%d] = 0x%X\n",
               i,
               byte_ptr[i]);
    }

    printf("\n");



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    REGISTER BYTE ACCESS
    ===========================================================================
    */

    uint32_t gpio_register =
        0x12345678;

    uint8_t *gpio_bytes =
        (uint8_t *)&gpio_register;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 1\n");
    printf("=========================================\n");

    printf("LSB = 0x%X\n\n",
           gpio_bytes[0]);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    EEPROM DATA BUFFER
    ===========================================================================
    */

    uint16_t sensor_data[2] =
    {
        1000,
        2000
    };

    uint8_t *raw_bytes =
        (uint8_t *)sensor_data;

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 2\n");
    printf("=========================================\n");

    printf("First Byte = 0x%X\n\n",
           raw_bytes[0]);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 3

    MEMORY MAPPED REGISTER
    ===========================================================================
    */

    /*
        Real Embedded Code:

        volatile uint32_t *GPIOA_ODR =
            (volatile uint32_t *)
            0x48000014;

    ----------------------------------------

        GPIOA_ODR[0]

    accesses:

        Output Data Register.

    ----------------------------------------

        Byte Access:

        volatile uint8_t *GPIO_BYTES =
            (volatile uint8_t *)
            GPIOA_ODR;

    ===========================================================================
    */



    /*
    ===========================================================================
    STRICT ALIASING RULE

    IMPORTANT:

    C compiler assumes:

        Different pointer types

    DO NOT point to the same object.

    Example:

        int *

        float *

    accessing same memory

    can produce:

        Undefined Behavior

    ===========================================================================
    */



    /*
    ===========================================================================
    SAFE EXCEPTION

    char*

    and

    unsigned char*

    are allowed to access:

        Any object's bytes.

    This is guaranteed by the C standard.

    ===========================================================================
    */



    /*
    ===========================================================================
    MISRA C RECOMMENDATIONS

    AVOID:

        Unnecessary pointer casts.

    PREFER:

        Explicit documentation.

    VERIFY:

        Alignment requirements.

    VERIFY:

        Endianness assumptions.

    ===========================================================================
    */



    /*
    ===========================================================================
    INTERVIEW QUESTIONS
    ===========================================================================

    Q1:

        Does pointer casting
        change memory contents?

        Answer:

            NO.

            Only interpretation changes.

    ----------------------------------------

    Q2:

        Which pointer type can safely
        access object bytes?

        Answer:

            char*

            unsigned char*

    ----------------------------------------

    Q3:

        Why is alignment important?

        Answer:

            Misaligned access may:

                • Slow execution
                • Cause exceptions
                • Crash on some CPUs

    ----------------------------------------

    Q4:

        What is strict aliasing?

        Answer:

            Compiler optimization rule
            about different pointer types.

    ----------------------------------------

    Q5:

        Why are pointer casts common
        in embedded systems?

        Answer:

            Register access,
            protocol parsing,
            DMA buffers,
            EEPROM handling.

    ===========================================================================
    */

    return 0;
}
