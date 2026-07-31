/******************************************************************************
 * Demonstrates:
 * -------------
 * 1. __FILE__
 * 2. __LINE__
 * 3. __DATE__
 * 4. __TIME__
 * 5. __STDC__
 * 6. __STDC_VERSION__
 * 7. __func__ (Predefined Identifier)
 *
 * Note:
 * -----
 * __func__ is NOT a preprocessor macro.
 * It is a predefined identifier automatically created by the compiler
 * inside every function.
 ******************************************************************************/

#include <stdio.h>

/*------------------------------------------------------------
    DEBUG_PRINT()

    This macro demonstrates using:
        __FILE__
        __LINE__

    Every time this macro is used,
    the current file name and line number are printed.

    Important:
    ----------
    __FILE__ and __LINE__ change depending on
    where this macro is called.
-------------------------------------------------------------*/
#define DEBUG_PRINT() \
    printf("[DEBUG] File : %s | Line : %d\n", __FILE__, __LINE__)

/*------------------------------------------------------------
    ERROR(msg)

    Demonstrates a simple error logging macro.

    Uses:
        __FILE__
        __LINE__

-------------------------------------------------------------*/
#define ERROR(msg) \
    printf("[ERROR] %s | File:%s | Line:%d\n", msg, __FILE__, __LINE__)


/*------------------------------------------------------------
    Example Function

    Demonstrates:
        __func__

    __func__ contains the current function name.

    It is NOT a macro.
-------------------------------------------------------------*/
void UART_Init(void)
{
    printf("\n========== __func__ ==========\n");

    printf("Current Function : %s\n", __func__);

    /*
        Output:

        UART_Init
    */
}


/*------------------------------------------------------------
    Another function

    Used only to show that __func__ changes automatically.
-------------------------------------------------------------*/
void GPIO_Init(void)
{
    printf("\n========== __func__ ==========\n");

    printf("Current Function : %s\n", __func__);
}


int main(void)
{
    printf("=====================================\n");
    printf("      PREDEFINED MACROS DEMO\n");
    printf("=====================================\n");


    /*******************************************************
                    __FILE__
    ********************************************************/

    printf("\n========== __FILE__ ==========\n");

    printf("Current File : %s\n", __FILE__);

    /*
        What?

            Returns current source file name.

        Example Output

            predefined_macros_demo.c

        What it is NOT?

            NOT current folder
            NOT executable name
            NOT runtime generated
    */


    /*******************************************************
                    __LINE__
    ********************************************************/

    printf("\n========== __LINE__ ==========\n");

    printf("Current Line : %d\n", __LINE__);

    /*
        What?

            Current source code line number.

        Every occurrence expands
        to its own line number.

        Example

            printf("%d\n", __LINE__);
            printf("%d\n", __LINE__);

        Output

            95
            96

        What it is NOT?

            NOT fixed.
            Changes according to source line.
    */


    /*******************************************************
                    __DATE__
    ********************************************************/

    printf("\n========== __DATE__ ==========\n");

    printf("Compilation Date : %s\n", __DATE__);

    /*
        Example Output

            Jul 30 2026

        What?

            Date when source code
            was compiled.

        What it is NOT?

            NOT today's date.
            NOT runtime date.
    */


    /*******************************************************
                    __TIME__
    ********************************************************/

    printf("\n========== __TIME__ ==========\n");

    printf("Compilation Time : %s\n", __TIME__);

    /*
        Example Output

            10:45:17

        What?

            Time when compiler built
            this program.

        What it is NOT?

            NOT current clock time.
            NOT updated while running.
    */


    /*******************************************************
                    __STDC__
    ********************************************************/

    printf("\n========== __STDC__ ==========\n");

#ifdef __STDC__

    printf("__STDC__ = %d\n", __STDC__);

    /*
        Usually prints

            1

        Meaning

            Compiler supports
            Standard C.

    */

#else

    printf("__STDC__ Not Supported\n");

#endif


    /*******************************************************
                __STDC_VERSION__
    ********************************************************/

    printf("\n========== __STDC_VERSION__ ==========\n");

#ifdef __STDC_VERSION__

    printf("%ld\n", (long)__STDC_VERSION__);

    /*
        Possible Outputs

        199409L  -> C95

        199901L  -> C99

        201112L  -> C11

        201710L  -> C17

        202311L  -> C23
    */

#else

    printf("Compiler does not define __STDC_VERSION__\n");

#endif


    /*******************************************************
                    __func__
    ********************************************************/

    UART_Init();

    GPIO_Init();



    /*******************************************************
            DEBUG MACRO USING FILE + LINE
    ********************************************************/

    printf("\n========== DEBUG MACRO ==========\n");

    DEBUG_PRINT();

    DEBUG_PRINT();

    DEBUG_PRINT();

    /*
        Example Output

        [DEBUG] File : predefined_macros_demo.c | Line : 180
        [DEBUG] File : predefined_macros_demo.c | Line : 181
        [DEBUG] File : predefined_macros_demo.c | Line : 182

        Notice:

            File stays same.

            Line changes.
    */


    /*******************************************************
                ERROR MACRO
    ********************************************************/

    printf("\n========== ERROR MACRO ==========\n");

    ERROR("UART Timeout");

    ERROR("GPIO Configuration Failed");


    return 0;
}