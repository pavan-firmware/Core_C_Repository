#include <stdio.h>

/*==========================================================
    USER CONFIGURATION
    Uncomment/comment these lines to see different outputs.
==========================================================*/

//#define DEBUG            // Enable Debug Build
#define STM32             // Target MCU
//#define ESP32           // Another MCU
#define VERSION 2         // Software Version
#define USE_LCD           // Enable LCD Feature
//#define BOOTLOADER      // Bootloader Build

/*==========================================================
    MAIN PROGRAM
==========================================================*/

int main(void)
{
    printf("Program Started\n\n");

    /*------------------------------------------------------
      1. #ifdef
      Execute code ONLY if macro is defined.
    ------------------------------------------------------*/

#ifdef DEBUG
    printf("[DEBUG] Debug Mode Enabled\n");
#endif

    /*
    If DEBUG is NOT defined,
    compiler completely removes this code.
    */


    /*------------------------------------------------------
      2. #ifndef
      Execute code ONLY if macro is NOT defined.
    ------------------------------------------------------*/

#ifndef DEBUG
    printf("[INFO] Release Build\n");
#endif


    /*------------------------------------------------------
      3. #if
      Compare compile-time constant values.
    ------------------------------------------------------*/

#if VERSION == 1
    printf("Software Version 1\n");

#elif VERSION == 2
    printf("Software Version 2\n");

#elif VERSION == 3
    printf("Software Version 3\n");

#else
    printf("Unknown Version\n");

#endif


    /*------------------------------------------------------
      4. Platform Selection
    ------------------------------------------------------*/

#ifdef STM32

    printf("Running on STM32\n");

#elif defined(ESP32)

    printf("Running on ESP32\n");

#else

    printf("Unknown Hardware\n");

#endif


    /*------------------------------------------------------
      5. Optional Feature
    ------------------------------------------------------*/

#ifdef USE_LCD

    printf("LCD Initialized\n");

#else

    printf("LCD Disabled\n");

#endif


    /*------------------------------------------------------
      6. Bootloader / Application
    ------------------------------------------------------*/

#ifndef BOOTLOADER

    printf("Application Started\n");

#else

    printf("Bootloader Started\n");

#endif


    /*------------------------------------------------------
      7. Multiple Conditions
    ------------------------------------------------------*/

#if VERSION == 2 && defined(STM32)

    printf("STM32 Version 2 Build\n");

#endif


    /*------------------------------------------------------
      8. Nested Conditional Compilation
    ------------------------------------------------------*/

#ifdef DEBUG

    printf("Debug Enabled\n");

    #ifdef STM32

        printf("Debugging STM32\n");

    #endif

#endif


    /*------------------------------------------------------
      Program End
    ------------------------------------------------------*/

    printf("\nProgram Finished\n");

    return 0;
}