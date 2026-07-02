#include <stdio.h>
#include <stdint.h>

/*
==============================================================================
                        02. POINTER BASICS IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. What is a Pointer?

2. Memory Address

3. Address Of Operator (&)

4. Dereference Operator (*)

5. Pointer Declaration

6. NULL Pointer

7. Pointer Arithmetic

8. Arrays and Pointers

9. Embedded Firmware Examples

10. Common Beginner Mistakes

==============================================================================


WHAT IS A POINTER?
==============================================================================

A pointer is a variable that stores:

    Memory Address

Example:

    int value = 100;

    int *ptr = &value;

Memory:

    +-------------+
    | value = 100 |
    +-------------+
         ^
         |
         +------ ptr

==============================================================================


ADDRESS OF OPERATOR (&)
==============================================================================

Operator:

    &

Purpose:

    Get memory address of a variable.

Example:

    int number = 10;

    &number

==============================================================================


DEREFERENCE OPERATOR (*)
==============================================================================

Operator:

    *

Purpose:

    Access value stored at address.

Example:

    int number = 10;

    int *ptr = &number;

    *ptr

Result:

    10

==============================================================================


POINTER DECLARATION
==============================================================================

Syntax:

    data_type *pointer_name;

Examples:

    int *ptr;

    float *temperature_ptr;

    char *name_ptr;

==============================================================================


NULL POINTER
==============================================================================

NULL means:

    Pointer points to nothing.

Example:

    int *ptr = NULL;

Good Practice:

    Initialize pointers with NULL.

==============================================================================


POINTER ARITHMETIC
==============================================================================

Example:

    int numbers[3];

    int *ptr = numbers;

    ptr++;

Moves:

    sizeof(int) bytes.

Not:

    1 byte.

==============================================================================

*/


int main(void)
{
    /*
    ==========================================================================
    INTEGER POINTER
    ==========================================================================
    */

    int number = 100;

    int *number_ptr = &number;


    printf("==================================================\n");
    printf("INTEGER POINTER\n");
    printf("==================================================\n\n");

    printf("Value         = %d\n",
           number);

    printf("Address       = %p\n",
           (void *)&number);

    printf("Pointer Value = %p\n",
           (void *)number_ptr);

    printf("Dereference   = %d\n",
           *number_ptr);


    /*
    ==========================================================================
    MODIFY VALUE USING POINTER
    ==========================================================================
    */

    *number_ptr = 500;

    printf("\n");
    printf("==================================================\n");
    printf("MODIFY USING POINTER\n");
    printf("==================================================\n\n");

    printf("Updated Value = %d\n",
           number);


    /*
    ==========================================================================
    FLOAT POINTER
    ==========================================================================
    */

    float temperature = 28.75F;

    float *temperature_ptr =
        &temperature;


    printf("\n");
    printf("==================================================\n");
    printf("FLOAT POINTER\n");
    printf("==================================================\n\n");

    printf("Temperature = %.2f\n",
           *temperature_ptr);


    /*
    ==========================================================================
    CHARACTER POINTER
    ==========================================================================
    */

    char grade = 'A';

    char *grade_ptr =
        &grade;


    printf("\n");
    printf("==================================================\n");
    printf("CHARACTER POINTER\n");
    printf("==================================================\n\n");

    printf("Grade = %c\n",
           *grade_ptr);


    /*
    ==========================================================================
    NULL POINTER
    ==========================================================================
    */

    int *null_pointer = NULL;


    printf("\n");
    printf("==================================================\n");
    printf("NULL POINTER\n");
    printf("==================================================\n\n");

    printf("NULL Address = %p\n",
           (void *)null_pointer);


    /*
        Always check before use.
    */

    if (null_pointer == NULL)
    {
        printf("Pointer is NULL\n");
    }


    /*
    ==========================================================================
    POINTER ARITHMETIC
    ==========================================================================
    */

    int values[5] =
    {
        10,
        20,
        30,
        40,
        50
    };

    int *array_ptr =
        values;


    printf("\n");
    printf("==================================================\n");
    printf("POINTER ARITHMETIC\n");
    printf("==================================================\n\n");

    printf("First Value  = %d\n",
           *array_ptr);

    array_ptr++;

    printf("Second Value = %d\n",
           *array_ptr);

    array_ptr++;

    printf("Third Value  = %d\n",
           *array_ptr);


    /*
    ==========================================================================
    ARRAYS AND POINTERS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("ARRAYS AND POINTERS\n");
    printf("==================================================\n\n");

    printf("values[0]     = %d\n",
           values[0]);

    printf("*(values + 0) = %d\n",
           *(values + 0));

    printf("values[1]     = %d\n",
           values[1]);

    printf("*(values + 1) = %d\n",
           *(values + 1));


    /*
    ==========================================================================
    POINTER SIZE
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("POINTER SIZE\n");
    printf("==================================================\n\n");

    printf("sizeof(int *)   = %zu Bytes\n",
           sizeof(int *));

    printf("sizeof(float *) = %zu Bytes\n",
           sizeof(float *));

    printf("sizeof(char *)  = %zu Bytes\n",
           sizeof(char *));


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================
    */

    volatile uint32_t gpio_output_register =
        0x00000000U;

    volatile uint32_t *gpio_ptr =
        &gpio_output_register;


    *gpio_ptr |= (1U << 5U);


    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLES\n");
    printf("==================================================\n\n");

    printf("GPIO Register = 0x%08X\n",
           *gpio_ptr);


    /*
    ==========================================================================
    INDUSTRY BEST PRACTICES
    ==========================================================================

    GOOD:

        int *ptr = NULL;

    ------------------------------------------------------------

    GOOD:

        Check NULL before use.

    ------------------------------------------------------------

    GOOD:

        Cast pointers when
        printing addresses.

            (void *)

    ------------------------------------------------------------

    GOOD:

        Use descriptive names:

            temperature_ptr

            uart_buffer_ptr

    ==========================================================================
    */


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        int *ptr;

        *ptr = 10;

    Problem:

        Uninitialized pointer.

    Undefined Behavior.

    ------------------------------------------------------------

    WRONG:

        Dereferencing NULL.

            *NULL

    Program Crash.

    ------------------------------------------------------------

    WRONG:

        Confusing:

            ptr

        with:

            *ptr

        ptr:

            Address

        *ptr:

            Value at address

    ------------------------------------------------------------

    IMPORTANT:

        Pointer Arithmetic:

            ptr + 1

        means:

            Next object

        NOT:

            Next byte

    ==========================================================================
    */

    return 0;
}
