#include <stdio.h>

/*=========================================================
    FUNCTION-LIKE MACROS
=========================================================*/

/*
-----------------------------------------------------------
1. Simple Function-like Macro
-----------------------------------------------------------
Looks like a function.
Actually it is NOT a function.

The preprocessor replaces the text before compilation.
*/

#define ADD(a, b) ((a) + (b))

/*
Example:

ADD(10,20)

After preprocessing:

((10) + (20))
*/


/*
-----------------------------------------------------------
2. Single Parameter Macro
-----------------------------------------------------------
*/

#define SQUARE(x) ((x) * (x))

/*
Example

SQUARE(5)

↓

((5)*(5))
*/


/*
-----------------------------------------------------------
3. Multiple Parameter Macro
-----------------------------------------------------------
*/

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

/*
Example

MAX(100,200)

↓

(((100)>(200)) ? (100):(200))
*/


/*
-----------------------------------------------------------
4. Bit Manipulation Macro
(Embedded Firmware Usage)
-----------------------------------------------------------
*/

#define SET_BIT(REG, BIT) ((REG) |= (1U << (BIT)))

/*
Example

SET_BIT(PORT,3)

↓

((PORT)|=(1U<<3))
*/


/*
-----------------------------------------------------------
5. Read Bit Macro
-----------------------------------------------------------
*/

#define READ_BIT(REG, BIT) (((REG) >> (BIT)) & 1U)


/*
=========================================================
            WRONG MACROS
=========================================================
*/

/*
-----------------------------------------------------------
Wrong Example 1

NO Parentheses
-----------------------------------------------------------
*/

#define WRONG_SQUARE(x) x * x

/*
Calling

WRONG_SQUARE(2+3)

becomes

2+3*2+3

↓

11

Expected

25
*/


/*
-----------------------------------------------------------
Wrong Example 2

Missing Parentheses Around Whole Expression
-----------------------------------------------------------
*/

#define WRONG_MUL(a,b) a*b

/*
10 / WRONG_MUL(2,5)

↓

10/2*5

↓

25

Expected

1
*/


int main(void)
{
    printf("================================================\n");
    printf("FUNCTION-LIKE MACRO DEMONSTRATION\n");
    printf("================================================\n\n");

    /*
    =====================================================
    Example 1
    =====================================================
    */

    printf("Example 1 : ADD Macro\n");

    int sum = ADD(10,20);

    printf("ADD(10,20) = %d\n\n", sum);


    /*
    =====================================================
    Example 2
    =====================================================
    */

    printf("Example 2 : SQUARE Macro\n");

    int square = SQUARE(5);

    printf("SQUARE(5) = %d\n\n", square);


    /*
    =====================================================
    Example 3

    Correct Parentheses
    =====================================================
    */

    printf("Example 3 : SQUARE(2+3)\n");

    printf("Result = %d\n\n", SQUARE(2+3));



    /*
    =====================================================
    Example 4

    Wrong Macro
    =====================================================
    */

    printf("Example 4 : WRONG_SQUARE(2+3)\n");

    printf("Result = %d\n\n", WRONG_SQUARE(2+3));



    /*
    =====================================================
    Example 5

    MAX Macro
    =====================================================
    */

    printf("Example 5 : MAX\n");

    printf("MAX(100,50) = %d\n\n", MAX(100,50));



    /*
    =====================================================
    Example 6

    Embedded Style
    =====================================================
    */

    unsigned int PORT = 0;

    printf("Example 6 : SET_BIT\n");

    printf("Before = %u\n", PORT);

    SET_BIT(PORT,3);

    printf("After  = %u\n\n", PORT);



    /*
    =====================================================
    Example 7

    READ_BIT
    =====================================================
    */

    printf("Example 7 : READ_BIT\n");

    printf("Bit 3 = %u\n", READ_BIT(PORT,3));

    printf("Bit 2 = %u\n\n", READ_BIT(PORT,2));



    /*
    =====================================================
    Example 8

    Wrong Multiplication Macro
    =====================================================
    */

    printf("Example 8 : WRONG_MUL\n");

    printf("10 / WRONG_MUL(2,5) = %d\n\n",
           10 / WRONG_MUL(2,5));



    /*
    =====================================================
    Example 9

    Macro Accepts Different Types

    (No Type Checking)
    =====================================================
    */

    printf("Example 9 : No Type Checking\n");

    printf("ADD(5,6) = %d\n", ADD(5,6));

    printf("ADD(5.5,2.5) = %.2f\n", ADD(5.5,2.5));

    printf("ADD('A',5) = %d\n\n", ADD('A',5));



    /*
    =====================================================
    IMPORTANT

    Macro is NOT a function.

    There is NO function call.

    The compiler receives only expanded code.

    Example

    ADD(4,5)

    becomes

    ((4)+(5))
    =====================================================
    */



    /*
    =====================================================
    Macros DO NOT

    ✔ Allocate memory

    ✔ Have an address

    ✔ Have a return type

    ✔ Perform type checking

    ✔ Exist during program execution

    They exist ONLY before compilation.
    =====================================================
    */



    /*
    =====================================================
    Best Practice

    Always write

    ((parameter))

    Never

    parameter

    =====================================================
    */

    return 0;
}