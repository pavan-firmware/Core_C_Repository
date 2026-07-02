#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
==============================================================================
                    03. RESTRICT QUALIFIER IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. What is restrict?

2. Why do we need restrict?

3. Pointer Aliasing

4. Compiler Optimizations

5. restrict Function Parameters

6. Memory Copy Examples

7. Embedded Firmware Examples

8. Industry Best Practices

9. Common Beginner Mistakes

==============================================================================


WHAT IS restrict?
==============================================================================

restrict was introduced in:

    C99

Purpose:

    Tell the compiler:

        This pointer is the ONLY way
        to access this memory region.

==============================================================================


WHY DO WE NEED restrict?
==============================================================================

Without restrict:

    Compiler must assume:

        Two pointers may point to
        the same memory.

Example:

    add(a, b, c);

Compiler thinks:

    a, b, c

might overlap.

So:

    Some optimizations
    become impossible.

==============================================================================


WITH restrict
==============================================================================

Example:

    void add(
        int *restrict a,
        int *restrict b,
        int *restrict c
    );

Compiler now knows:

    a, b, c

refer to different memory regions.

Better optimizations become possible.

==============================================================================


POINTER ALIASING
==============================================================================

Aliasing means:

    Multiple pointers access
    the same memory.

Example:

    int value = 10;

    int *ptr1 = &value;

    int *ptr2 = &value;

Both pointers:

    Alias each other.

==============================================================================


RESTRICT RULE
==============================================================================

If:

    int *restrict ptr;

Then:

    During ptr lifetime:

        That memory must NOT
        be accessed through
        another pointer.

Violating this rule:

    Undefined Behavior.

==============================================================================


WHEN TO USE restrict?
==============================================================================

Good Use Cases:

    ✓ DSP Algorithms

    ✓ Image Processing

    ✓ Matrix Operations

    ✓ Memory Copy Functions

    ✓ Embedded Signal Processing

==============================================================================


WHEN NOT TO USE restrict?
==============================================================================

Do NOT use restrict when:

    Multiple pointers may
    access same memory.

==============================================================================

*/


/*
------------------------------------------------------------------------------
FUNCTION:

NORMAL ARRAY ADDITION
------------------------------------------------------------------------------
*/

void add_arrays_normal(
    const int *array_1,
    const int *array_2,
    int *result,
    uint32_t size)
{
    for (uint32_t index = 0U;
         index < size;
         index++)
    {
        result[index] =
            array_1[index] +
            array_2[index];
    }
}


/*
------------------------------------------------------------------------------
FUNCTION:

RESTRICT ARRAY ADDITION
------------------------------------------------------------------------------
*/

void add_arrays_restrict(
    const int *restrict array_1,
    const int *restrict array_2,
    int *restrict result,
    uint32_t size)
{
    for (uint32_t index = 0U;
         index < size;
         index++)
    {
        result[index] =
            array_1[index] +
            array_2[index];
    }
}


/*
------------------------------------------------------------------------------
FUNCTION:

RESTRICT MEMORY COPY
------------------------------------------------------------------------------
*/

void fast_copy(
    uint8_t *restrict destination,
    const uint8_t *restrict source,
    uint32_t size)
{
    for (uint32_t index = 0U;
         index < size;
         index++)
    {
        destination[index] =
            source[index];
    }
}


int main(void)
{
    /*
    ==========================================================================
    NORMAL ARRAY PROCESSING
    ==========================================================================
    */

    int array_1[5] =
    {
        1, 2, 3, 4, 5
    };

    int array_2[5] =
    {
        10, 20, 30, 40, 50
    };

    int result[5] =
    {
        0
    };


    add_arrays_normal(
        array_1,
        array_2,
        result,
        5U);


    printf("==================================================\n");
    printf("NORMAL ARRAY ADDITION\n");
    printf("==================================================\n\n");

    for (uint32_t index = 0U;
         index < 5U;
         index++)
    {
        printf("%d ",
               result[index]);
    }

    printf("\n");


    /*
    ==========================================================================
    RESTRICT ARRAY PROCESSING
    ==========================================================================
    */

    memset(result,
           0,
           sizeof(result));

    add_arrays_restrict(
        array_1,
        array_2,
        result,
        5U);


    printf("\n");
    printf("==================================================\n");
    printf("RESTRICT ARRAY ADDITION\n");
    printf("==================================================\n\n");

    for (uint32_t index = 0U;
         index < 5U;
         index++)
    {
        printf("%d ",
               result[index]);
    }

    printf("\n");


    /*
    ==========================================================================
    MEMORY COPY EXAMPLE
    ==========================================================================
    */

    uint8_t source_buffer[5] =
    {
        0x11,
        0x22,
        0x33,
        0x44,
        0x55
    };

    uint8_t destination_buffer[5] =
    {
        0
    };


    fast_copy(
        destination_buffer,
        source_buffer,
        5U);


    printf("\n");
    printf("==================================================\n");
    printf("FAST COPY EXAMPLE\n");
    printf("==================================================\n\n");

    for (uint32_t index = 0U;
         index < 5U;
         index++)
    {
        printf("0x%02X ",
               destination_buffer[index]);
    }

    printf("\n");


    /*
    ==========================================================================
    POINTER ALIASING EXAMPLE
    ==========================================================================
    */

    int value = 100;

    int *pointer_1 = &value;

    int *pointer_2 = &value;

    printf("\n");
    printf("==================================================\n");
    printf("POINTER ALIASING\n");
    printf("==================================================\n\n");

    printf("Pointer 1 = %d\n",
           *pointer_1);

    printf("Pointer 2 = %d\n",
           *pointer_2);

    printf("\n");

    printf("These pointers alias the same memory.\n");

    printf("restrict cannot be used here.\n");


    /*
    ==========================================================================
    EMBEDDED FIRMWARE EXAMPLES
    ==========================================================================

    Typical Usage:

        DSP Filters

        FFT Processing

        Audio Buffers

        Image Buffers

        DMA Processing

    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLES\n");
    printf("==================================================\n\n");

    printf("restrict improves:\n");

    printf("DSP Algorithms\n");

    printf("Signal Processing\n");

    printf("Memory Operations\n");

    printf("Image Processing\n");


    /*
    ==========================================================================
    INDUSTRY BEST PRACTICES
    ==========================================================================

    GOOD:

        void copy(
            uint8_t *restrict dst,
            const uint8_t *restrict src
        );

    ------------------------------------------------------------

    GOOD:

        DSP functions using
        restrict pointers.

    ------------------------------------------------------------

    Use restrict ONLY when:

        Memory regions
        never overlap.

    ==========================================================================
    */


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        Thinking:

            restrict creates
            a new pointer.

    Reality:

        It is only a promise
        to the compiler.

    ------------------------------------------------------------

    WRONG:

        Using restrict when
        pointers overlap.

    Example:

        fast_copy(buffer,
                  buffer,
                  10);

    Undefined Behavior.

    ------------------------------------------------------------

    WRONG:

        Expecting:

            restrict

        to improve all code.

    Reality:

        Mostly useful in:

            High Performance Code

            DSP

            Embedded Signal Processing

    ------------------------------------------------------------

    IMPORTANT:

        restrict means:

            This pointer is the
            exclusive accessor
            to this memory.

    ==========================================================================
    */

    return 0;
}
