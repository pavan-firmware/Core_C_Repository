#include <stdio.h>
#include <stdint.h>

/*
===============================================================================
                    21_VOID_POINTER_CASTING.C
===============================================================================

TOPIC:
    Void Pointer Casting

STANDARD:
    C99, C11, C17, C23

===============================================================================

WHAT IS A VOID POINTER?

Definition:

    A void pointer is a generic pointer that can store
    the address of ANY data type.

Syntax:

    void *pointer;

===============================================================================

WHY USE VOID POINTERS?

Applications:

    • Generic functions
    • Dynamic memory allocation (malloc)
    • Device drivers
    • Communication protocols
    • Embedded middleware
    • RTOS APIs

===============================================================================

VOID POINTER TABLE

+----------------------+------------------------------------------+
| OPERATION            | ALLOWED ?                                |
+----------------------+------------------------------------------+
| Store int*           | YES                                      |
| Store float*         | YES                                      |
| Store struct*        | YES                                      |
| Dereference directly | NO                                       |
| Pointer arithmetic   | NO (Standard C)                          |
| Cast back to type    | YES                                      |
+----------------------+------------------------------------------+

===============================================================================

IMPORTANT RULE

YOU CANNOT DO:

    void *ptr;

    *ptr;

Reason:

    Compiler does not know:

        • Size of data
        • Type of data

You MUST cast it first.

===============================================================================

GENERAL SYNTAX

STORE:

    void *ptr = &value;

RESTORE:

    int *int_ptr =
        (int *)ptr;

===============================================================================
*/


/*
===============================================================================
STRUCTURE FOR DEMONSTRATION
===============================================================================
*/

struct SensorData
{
    uint16_t temperature;
    uint16_t humidity;
};


/*
===============================================================================
GENERIC PRINT FUNCTION
===============================================================================
*/

void print_integer(void *data)
{
    int *value =
        (int *)data;

    printf("Integer = %d\n",
           *value);
}


/*
===============================================================================
MAIN FUNCTION
===============================================================================
*/

int main(void)
{
    /*
    ===========================================================================
    1. INT POINTER TO VOID POINTER
    ===========================================================================
    */

    int number = 100;

    void *generic_ptr =
        &number;

    int *int_ptr =
        (int *)generic_ptr;

    printf("=========================================\n");
    printf("1. INT TO VOID POINTER\n");
    printf("=========================================\n");

    printf("Number = %d\n\n",
           *int_ptr);



    /*
    ===========================================================================
    MEMORY VISUALIZATION

    number

        Address:

            0x1000

    generic_ptr

        Stores:

            0x1000

    But:

        Type information

    is lost.

    Therefore:

        Explicit cast required.

    ===========================================================================
    */



    /*
    ===========================================================================
    2. FLOAT TO VOID POINTER
    ===========================================================================
    */

    float voltage = 3.3f;

    generic_ptr =
        &voltage;

    float *float_ptr =
        (float *)generic_ptr;

    printf("=========================================\n");
    printf("2. FLOAT TO VOID POINTER\n");
    printf("=========================================\n");

    printf("Voltage = %.2f\n\n",
           *float_ptr);



    /*
    ===========================================================================
    3. CHARACTER POINTER
    ===========================================================================
    */

    char grade = 'A';

    generic_ptr =
        &grade;

    char *char_ptr =
        (char *)generic_ptr;

    printf("=========================================\n");
    printf("3. CHAR TO VOID POINTER\n");
    printf("=========================================\n");

    printf("Grade = %c\n\n",
           *char_ptr);



    /*
    ===========================================================================
    4. STRUCTURE POINTER
    ===========================================================================
    */

    struct SensorData sensor =
    {
        30,
        65
    };

    generic_ptr =
        &sensor;

    struct SensorData *sensor_ptr =
        (struct SensorData *)generic_ptr;

    printf("=========================================\n");
    printf("4. STRUCTURE POINTER\n");
    printf("=========================================\n");

    printf("Temperature = %u\n",
           sensor_ptr->temperature);

    printf("Humidity    = %u\n\n",
           sensor_ptr->humidity);



    /*
    ===========================================================================
    5. GENERIC FUNCTION
    ===========================================================================
    */

    printf("=========================================\n");
    printf("5. GENERIC FUNCTION\n");
    printf("=========================================\n");

    print_integer(&number);

    printf("\n");



    /*
    ===========================================================================
    HOW malloc() WORKS

    Prototype:

        void *malloc(size_t size);

    Example:

        int *ptr =
            (int *)malloc(sizeof(int));

    malloc returns:

        void*

    Programmer converts:

        void*

            ↓

        int*

    ===========================================================================
    */



    /*
    ===========================================================================
    6. POINTER COMPARISON
    ===========================================================================
    */

    int value1 = 10;
    int value2 = 20;

    void *ptr1 = &value1;
    void *ptr2 = &value2;

    printf("=========================================\n");
    printf("6. POINTER COMPARISON\n");
    printf("=========================================\n");

    printf("ptr1 = %p\n",
           ptr1);

    printf("ptr2 = %p\n\n",
           ptr2);



    /*
    ===========================================================================
    7. VOID POINTER SIZE
    ===========================================================================
    */

    printf("=========================================\n");
    printf("7. VOID POINTER SIZE\n");
    printf("=========================================\n");

    printf("sizeof(void *) = %zu bytes\n\n",
           sizeof(void *));



    /*
        Modern Systems:

            64-bit:

                8 bytes

            32-bit:

                4 bytes
    */



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    GENERIC DRIVER API
    ===========================================================================
    */

    /*
        Example:

        void uart_send(void *buffer,
                       uint32_t length);

    Buffer may contain:

        char*

        uint8_t*

        struct*

    ===========================================================================
    */



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    RTOS TASK PARAMETERS
    ===========================================================================
    */

    /*
        FreeRTOS:

        void task_function(void *parameters)

    Parameters may be:

        int*

        struct*

        device handles

        configuration data

    ===========================================================================
    */



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 3

    GENERIC CALLBACK DATA
    ===========================================================================
    */

    /*
        Driver callback:

        void event_handler(void *context)

    context:

        User-defined data

        Driver information

        Device objects

    ===========================================================================
    */



    /*
    ===========================================================================
    POINTER ARITHMETIC

    STANDARD C:

        NOT ALLOWED

    WRONG:

        void *ptr;

        ptr++;

    ERROR

    ---------------------------------------------------------------------------

    CORRECT:

        uint8_t *byte_ptr =
            (uint8_t *)ptr;

        byte_ptr++;

    ===========================================================================
    */



    /*
    ===========================================================================
    COMMON MISTAKES
    ===========================================================================

    WRONG:

        void *ptr;

        *ptr

    Reason:

        Unknown data type.

    ----------------------------------------

    WRONG:

        ptr++

    Standard C:

        Not allowed.

    ----------------------------------------

    WRONG:

        Cast to incorrect type.

        int value = 100;

        float *ptr =
            (float *)&value;

    Result:

        Undefined behavior.

    ===========================================================================
    */



    /*
    ===========================================================================
    MISRA C RECOMMENDATIONS
    ===========================================================================

    Avoid:

        Unnecessary void pointer casts.

    Prefer:

        Strong typing.

    Document:

        Expected data type.

    Verify:

        Correct conversions.

    ===========================================================================
    */



    /*
    ===========================================================================
    INTERVIEW QUESTIONS
    ===========================================================================

    Q1:

        What is a void pointer?

        Answer:

            Generic pointer that can store
            any address.

    ----------------------------------------

    Q2:

        Can we dereference void* directly?

        Answer:

            NO

    ----------------------------------------

    Q3:

        Why does malloc return void*?

        Answer:

            Generic memory allocation.

    ----------------------------------------

    Q4:

        Is pointer arithmetic allowed
        on void*?

        Answer:

            NO (Standard C)

    ----------------------------------------

    Q5:

        Where are void pointers used
        in embedded systems?

        Answer:

            RTOS,
            Drivers,
            Generic APIs,
            Middleware.

    ===========================================================================
    */

    return 0;
}
