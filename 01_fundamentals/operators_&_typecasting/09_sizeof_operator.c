#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
===============================================================================
                        09_SIZEOF_OPERATOR.C
===============================================================================

TOPIC:
    sizeof Operator

PURPOSE:
    sizeof returns the memory size (in bytes) occupied by a data type,
    variable, array, structure, union, or other object.

===============================================================================

SIZEOF OPERATOR TABLE

+----------------------+-----------------------------------------+
| EXPRESSION           | DESCRIPTION                             |
+----------------------+-----------------------------------------+
| sizeof(int)          | Size of int data type                   |
| sizeof(x)            | Size of variable x                      |
| sizeof arr           | Total array size in bytes               |
| sizeof(arr[0])       | Size of one array element               |
| sizeof(ptr)          | Size of pointer variable                |
| sizeof(struct S)     | Size of structure                       |
+----------------------+-----------------------------------------+

===============================================================================

GENERAL SYNTAX

1. Using Type

    sizeof(type)

Example:

    sizeof(int)

----------------------------------------

2. Using Variable

    sizeof(variable)

Example:

    sizeof(counter)

----------------------------------------

3. Parentheses Optional

These are equivalent:

    sizeof(int)

    sizeof int

But parentheses improve readability.

===============================================================================

RETURN TYPE

sizeof returns:

    size_t

size_t:

    • Unsigned integer type
    • Defined in stddef.h
    • Used for sizes and memory calculations

Recommended printf format:

    %zu

===============================================================================

IMPORTANT PROPERTY

sizeof is evaluated at compile time
for most normal expressions.

No runtime calculation is required.

Very efficient.

===============================================================================
*/


/*
===============================================================================
STRUCTURE EXAMPLE
===============================================================================
*/

struct SensorData
{
    uint16_t temperature;
    uint8_t  humidity;
    bool     sensor_ready;
};


/*
===============================================================================
MAIN FUNCTION
===============================================================================
*/

int main(void)
{
    /*
    ===========================================================================
    1. SIZE OF BASIC DATA TYPES
    ===========================================================================
    */

    printf("=========================================\n");
    printf("1. BASIC DATA TYPE SIZES\n");
    printf("=========================================\n");

    printf("char        : %zu bytes\n", sizeof(char));
    printf("short       : %zu bytes\n", sizeof(short));
    printf("int         : %zu bytes\n", sizeof(int));
    printf("long        : %zu bytes\n", sizeof(long));
    printf("long long   : %zu bytes\n", sizeof(long long));

    printf("\n");

    printf("float       : %zu bytes\n", sizeof(float));
    printf("double      : %zu bytes\n", sizeof(double));

    printf("\n");

    printf("bool        : %zu bytes\n", sizeof(bool));

    printf("\n\n");



    /*
    ===========================================================================
    2. SIZE OF VARIABLES
    ===========================================================================
    */

    int counter = 100;

    float voltage = 3.3f;

    char grade = 'A';

    printf("=========================================\n");
    printf("2. VARIABLE SIZES\n");
    printf("=========================================\n");

    printf("counter : %zu bytes\n",
           sizeof(counter));

    printf("voltage : %zu bytes\n",
           sizeof(voltage));

    printf("grade   : %zu bytes\n",
           sizeof(grade));

    printf("\n\n");



    /*
    ===========================================================================
    3. ARRAY SIZE CALCULATION
    ===========================================================================
    */

    int numbers[5] = {10, 20, 30, 40, 50};

    printf("=========================================\n");
    printf("3. ARRAY SIZE\n");
    printf("=========================================\n");

    printf("Total Array Size      : %zu bytes\n",
           sizeof(numbers));

    printf("Single Element Size   : %zu bytes\n",
           sizeof(numbers[0]));

    printf("Number Of Elements    : %zu\n",
           sizeof(numbers) / sizeof(numbers[0]));

    printf("\n\n");



    /*
    ===========================================================================
    ARRAY MEMORY VISUALIZATION

    numbers[5]

    +-------+-------+-------+-------+-------+
    |  10   |  20   |  30   |  40   |  50   |
    +-------+-------+-------+-------+-------+

    int = 4 bytes

    Total:

        5 * 4

        20 bytes

    ===========================================================================
    */



    /*
    ===========================================================================
    4. POINTER SIZE
    ===========================================================================
    */

    int value = 100;

    int *ptr = &value;

    printf("=========================================\n");
    printf("4. POINTER SIZE\n");
    printf("=========================================\n");

    printf("Value Size   : %zu bytes\n",
           sizeof(value));

    printf("Pointer Size : %zu bytes\n",
           sizeof(ptr));

    printf("\n");



    /*
    ===========================================================================
    IMPORTANT

    sizeof(*ptr)

        Size of data pointed to.

    sizeof(ptr)

        Size of pointer itself.

    ===========================================================================
    */

    printf("Size Of Data (*ptr) : %zu bytes\n",
           sizeof(*ptr));

    printf("\n\n");



    /*
    ===========================================================================
    5. STRUCTURE SIZE
    ===========================================================================
    */

    struct SensorData sensor;

    printf("=========================================\n");
    printf("5. STRUCTURE SIZE\n");
    printf("=========================================\n");

    printf("Structure Size : %zu bytes\n",
           sizeof(sensor));

    printf("\n\n");



    /*
    ===========================================================================
    STRUCTURE MEMORY LAYOUT

    temperature

        uint16_t

        2 bytes

    humidity

        uint8_t

        1 byte

    sensor_ready

        bool

        1 byte

    Actual size may include:

        PADDING

    ===========================================================================
    */



    /*
    ===========================================================================
    6. STRING SIZE
    ===========================================================================
    */

    char firmware[] = "STM32";

    printf("=========================================\n");
    printf("6. STRING SIZE\n");
    printf("=========================================\n");

    printf("String Size : %zu bytes\n",
           sizeof(firmware));

    printf("\n");



    /*
    ===========================================================================
    MEMORY LAYOUT

    "STM32"

    +-----+-----+-----+-----+-----+-----+
    |  S  |  T  |  M  |  3  |  2  | \0  |
    +-----+-----+-----+-----+-----+-----+

    Total:

        6 bytes

    Null character included.

    ===========================================================================
    */

    printf("\n");



    /*
    ===========================================================================
    7. EMBEDDED EXAMPLE

    UART TX BUFFER
    ===========================================================================
    */

    uint8_t uart_tx_buffer[128];

    printf("=========================================\n");
    printf("7. EMBEDDED EXAMPLE\n");
    printf("=========================================\n");

    printf("UART Buffer Size : %zu bytes\n",
           sizeof(uart_tx_buffer));

    printf("\n\n");



    /*
    ===========================================================================
    8. EMBEDDED EXAMPLE

    DMA TRANSFER LENGTH
    ===========================================================================
    */

    uint16_t adc_samples[64];

    size_t sample_count =
        sizeof(adc_samples) /
        sizeof(adc_samples[0]);

    printf("=========================================\n");
    printf("8. DMA SAMPLE COUNT\n");
    printf("=========================================\n");

    printf("ADC Sample Count : %zu\n",
           sample_count);

    printf("\n\n");



    /*
    ===========================================================================
    COMMON MISTAKES
    ===========================================================================

    WRONG:

        int *ptr;

        sizeof(ptr)

    Expecting:

        Size of int

    Actual:

        Size of pointer.

    ----------------------------------------

    WRONG:

        Function Parameter:

        void process(int arr[])

        sizeof(arr)

    Actual:

        Size of pointer.

    Because:

        Arrays decay into pointers.

    ===========================================================================
    */



    /*
    ===========================================================================
    INTERVIEW QUESTIONS
    ===========================================================================

    Q1:

        What does sizeof return?

        Answer:

            size_t

    ----------------------------------------

    Q2:

        Is sizeof runtime or compile time?

        Answer:

            Mostly compile time.

    ----------------------------------------

    Q3:

        Does sizeof include '\0' in strings?

        Answer:

            Yes.

    ----------------------------------------

    Q4:

        Why does sizeof(array) work in main
        but not inside functions?

        Answer:

            Arrays decay into pointers
            when passed to functions.

    ----------------------------------------

    Q5:

        Difference:

            sizeof(ptr)

            sizeof(*ptr)

        Answer:

            ptr:

                Pointer size

            *ptr:

                Data size

    ===========================================================================
    */



    return 0;
}
