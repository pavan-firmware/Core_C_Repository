#include <stdio.h>

/*==========================================================
    1. SIMPLE VARIADIC MACRO

    Syntax:
        #define MACRO_NAME(...) replacement

    __VA_ARGS__
        Represents all extra arguments passed to the macro.
==========================================================*/

#define PRINT_ALL(...) printf(__VA_ARGS__)



/*==========================================================
    2. VARIADIC MACRO WITH FIXED PARAMETER

    fmt
        Fixed parameter

    ...
        Variable parameters

    __VA_ARGS__
        Expands to all variable arguments.
==========================================================*/

#define LOG(fmt, ...) printf(fmt, __VA_ARGS__)



/*==========================================================
    3. DEBUG LOG MACRO

    Adds a prefix before every message.

    Notice:

        "[DEBUG] " fmt

    Adjacent string literals are automatically joined.

==========================================================*/

#define DEBUG(fmt, ...) \
        printf("[DEBUG] " fmt, __VA_ARGS__)



/*==========================================================
    4. INFO LOG MACRO
==========================================================*/

#define INFO(fmt, ...) \
        printf("[INFO ] " fmt, __VA_ARGS__)



/*==========================================================
    5. ERROR LOG MACRO
==========================================================*/

#define ERROR(fmt, ...) \
        printf("[ERROR] " fmt, __VA_ARGS__)



/*==========================================================
    MAIN
==========================================================*/

int main(void)
{

    printf("=================================\n");
    printf("1. SIMPLE VARIADIC MACRO\n");
    printf("=================================\n");

    /*
        PRINT_ALL

        Macro receives

            "Hello World\n"

        Expands into

            printf("Hello World\n");
    */

    PRINT_ALL("Hello World\n");



    printf("\n=================================\n");
    printf("2. ONE VARIABLE ARGUMENT\n");
    printf("=================================\n");

    int temperature = 35;

    /*
        LOG receives

            fmt  -> "Temperature = %d\n"

            __VA_ARGS__

                temperature

        Expands into

            printf("Temperature = %d\n", temperature);
    */

    LOG("Temperature = %d\n", temperature);



    printf("\n=================================\n");
    printf("3. MULTIPLE VARIABLE ARGUMENTS\n");
    printf("=================================\n");

    int a = 10;
    int b = 20;
    int c = 30;

    /*
        __VA_ARGS__

        becomes

            a,b,c
    */

    LOG("Values : %d %d %d\n", a, b, c);



    printf("\n=================================\n");
    printf("4. DEBUG MACRO\n");
    printf("=================================\n");

    /*
        Expansion

        printf("[DEBUG] Value=%d\n",100);
    */

    DEBUG("Value = %d\n", 100);



    printf("\n=================================\n");
    printf("5. INFO MACRO\n");
    printf("=================================\n");

    INFO("UART Initialized at %d baud\n", 115200);



    printf("\n=================================\n");
    printf("6. ERROR MACRO\n");
    printf("=================================\n");

    int errorCode = 404;

    ERROR("Error Code = %d\n", errorCode);



    printf("\n=================================\n");
    printf("7. DIFFERENT DATA TYPES\n");
    printf("=================================\n");

    float voltage = 3.3f;
    char grade = 'A';

    /*
        __VA_ARGS__

        voltage,
        grade
    */

    LOG("Voltage = %.2f Grade = %c\n",
        voltage,
        grade);



    printf("\n=================================\n");
    printf("8. EXPRESSIONS\n");
    printf("=================================\n");

    /*
        Expressions are also accepted.
    */

    LOG("Sum = %d\n", a + b);



    printf("\n=================================\n");
    printf("9. FUNCTION CALLS\n");
    printf("=================================\n");

    LOG("Length = %zu\n", sizeof(int));



    return 0;
}