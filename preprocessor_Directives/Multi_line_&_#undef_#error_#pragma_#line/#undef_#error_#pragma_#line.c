/*****************************************************
 * File : main.c
 * Topic: #undef, #error, #pragma, #line
 *****************************************************/

#include <stdio.h>

/*----------------------------------------------------
    #pragma
    Compiler-specific instruction

    #pragma once -> Used ONLY in header (.h) files.

    Example:
        #pragma once

    It should NOT be used in .c files.

    Below is another pragma supported by many compilers.
-----------------------------------------------------*/

//#pragma message("Building Debug Version")



/*----------------------------------------------------
    #define
-----------------------------------------------------*/

#define CPU_CLOCK      72000000U
#define UART_BAUD      9600
#define DEBUG



/*----------------------------------------------------
    #undef

    Removes an existing macro.

    After this line UART_BAUD is NO LONGER 9600.
-----------------------------------------------------*/

#undef UART_BAUD

/* New value */

#define UART_BAUD      115200



/*----------------------------------------------------
    #error

    Used to stop compilation if configuration is wrong.

    Uncomment below to see compile-time error.
-----------------------------------------------------*/

//#ifndef STM32F103
//#error "Only STM32F103 MCU is Supported"
//#endif



/*----------------------------------------------------
    Another #error example

    Uncomment to test

    #undef CPU_CLOCK

    #ifndef CPU_CLOCK
    #error "CPU_CLOCK is Missing"
    #endif
-----------------------------------------------------*/



/*----------------------------------------------------
    #line

    Changes compiler's idea of
    current line number and file name.

    Mostly used by code generators.

    Uncomment to test.
-----------------------------------------------------*/

//#line 500 "Generated_File.c"



int main(void)
{
    printf("------------ Build Information ------------\n");

    /* Built-in predefined macros */

    printf("File      : %s\n", __FILE__);
    printf("Line      : %d\n", __LINE__);
    printf("Date      : %s\n", __DATE__);
    printf("Time      : %s\n", __TIME__);
    printf("Function  : %s\n", __func__);

#ifdef __STDC__
    printf("Standard C Compiler : Yes\n");
#endif

#ifdef __STDC_VERSION__
    printf("C Version : %ld\n", (long)__STDC_VERSION__);
#endif


    printf("\n------------ Configuration ------------\n");

    printf("CPU Clock : %u Hz\n", CPU_CLOCK);
    printf("UART Baud : %d\n", UART_BAUD);


#ifdef DEBUG
    printf("Debug Build Enabled\n");
#else
    printf("Release Build\n");
#endif


    return 0;
}