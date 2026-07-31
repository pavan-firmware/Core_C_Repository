#include <stdio.h>

/*==========================================================
    1. STRINGIZING OPERATOR (#)
==========================================================*/

/*
    # converts the macro argument into a string.

    Input:
        STR(GPIOA)

    After preprocessing:
        "GPIOA"
*/

#define STR(x) #x


/*==========================================================
    2. TOKEN PASTING OPERATOR (##)
==========================================================*/

/*
    ## joins two tokens into one token.

    Input:
        JOIN(GPIO, A)

    After preprocessing:
        GPIOA
*/

#define JOIN(a, b) a##b


/*==========================================================
    3. DEBUG PRINT MACRO USING #
==========================================================*/

/*
    Prints

        variable_name = value

    Example:

        int speed = 50;

        PRINT_VAR(speed);

    Expands to:

        printf("speed = %d\n", speed);
*/

#define PRINT_VAR(x) \
    printf(#x " = %d\n", x)


/*==========================================================
    4. USING # AND ## TOGETHER
==========================================================*/

/*
    Suppose variables are

        value1
        value2
        value3

    SHOW(2)

    becomes

        printf("2 = %d\n", value2);
*/

#define SHOW(num) \
    printf(#num " = %d\n", value##num)


/*==========================================================
    5. EMBEDDED STYLE GPIO NAME GENERATION
==========================================================*/

/*
    JOIN(GPIO, A)

    becomes

        GPIOA

    Similar to CMSIS register names.
*/

int GPIOA = 111;
int GPIOB = 222;
int GPIOC = 333;


/*==========================================================
    6. Variables used by SHOW()
==========================================================*/

int value1 = 100;
int value2 = 200;
int value3 = 300;


/*==========================================================
    MAIN
==========================================================*/

int main(void)
{
    printf("=====================================\n");
    printf("1. Stringizing Operator (#)\n");
    printf("=====================================\n");

    /*
        STR(Embedded)

        ↓

        "Embedded"
    */

    printf("%s\n", STR(Embedded));



    printf("\n=====================================\n");
    printf("2. Token Pasting (##)\n");
    printf("=====================================\n");

    /*
        JOIN(GPIO, A)

        ↓

        GPIOA
    */

    printf("%d\n", JOIN(GPIO, A));



    printf("\n=====================================\n");
    printf("3. Debug Print Macro (#)\n");
    printf("=====================================\n");

    int speed = 50;
    int rpm   = 1500;

    /*
        PRINT_VAR(speed)

        ↓

        printf("speed = %d\n", speed);
    */

    PRINT_VAR(speed);
    PRINT_VAR(rpm);



    printf("\n=====================================\n");
    printf("4. Using # and ## Together\n");
    printf("=====================================\n");

    /*
        SHOW(1)

        #num

            "1"

        value##num

            value1

        Final

        printf("1 = %d\n", value1);
    */

    SHOW(1);
    SHOW(2);
    SHOW(3);



    printf("\n=====================================\n");
    printf("5. Token Generation\n");
    printf("=====================================\n");

    /*
        JOIN(GPIO,B)

        ↓

        GPIOB
    */

    printf("%d\n", JOIN(GPIO, B));



    printf("\n=====================================\n");
    printf("6. Another Stringizing Example\n");
    printf("=====================================\n");

    /*
        STR(STM32)

        ↓

        "STM32"
    */

    printf("%s\n", STR(STM32));



    return 0;
}