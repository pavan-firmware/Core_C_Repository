#include <stdio.h>

/*
===============================================================================
                05_INCREMENT_DECREMENT_OPERATORS.C
===============================================================================

TOPIC:
    Increment (++) and Decrement (--) Operators

PURPOSE:
    These operators increase or decrease a value by 1.

===============================================================================

INCREMENT/DECREMENT OPERATORS TABLE

+------------+-------------------+-----------------------------+
| OPERATOR   | NAME              | EQUIVALENT EXPRESSION       |
+------------+-------------------+-----------------------------+
| ++a        | Pre-Increment     | a = a + 1 (before use)      |
| a++        | Post-Increment    | use a, then a = a + 1       |
| --a        | Pre-Decrement     | a = a - 1 (before use)      |
| a--        | Post-Decrement    | use a, then a = a - 1       |
+------------+-------------------+-----------------------------+

===============================================================================

VISUAL REPRESENTATION

PRE-INCREMENT

    ++a

    Step 1:
        a = a + 1

    Step 2:
        Use updated value

----------------------------------------

POST-INCREMENT

    a++

    Step 1:
        Use current value

    Step 2:
        a = a + 1

===============================================================================

IMPORTANT:

    ++ and -- only change by ONE.

    a++;

    means:

        a = a + 1;

===============================================================================

COMMON EMBEDDED USE CASES

1. Loop Counters
2. Timer Ticks
3. Buffer Indexes
4. State Machine Counters
5. Retry Counters

===============================================================================

DANGEROUS CODE (UNDEFINED BEHAVIOR)

NEVER WRITE:

    i = i++;

    x = ++x + x++;

    printf("%d", i++ + ++i);

Reason:

    Undefined Behavior (UB)

Compiler may produce different results.

===============================================================================
*/

int main(void)
{
    int a;
    int result;


    /*
    ===========================================================================
    1. PRE-INCREMENT (++a)
    ===========================================================================
    */

    a = 10;

    /*
        Step 1:

            a = 11

        Step 2:

            result = 11
    */

    result = ++a;

    printf("=====================================\n");
    printf("1. PRE-INCREMENT (++a)\n");
    printf("=====================================\n");

    printf("Result = %d\n", result);
    printf("a      = %d\n\n", a);



    /*
    ===========================================================================
    2. POST-INCREMENT (a++)
    ===========================================================================
    */

    a = 10;

    /*
        Step 1:

            result = 10

        Step 2:

            a = 11
    */

    result = a++;

    printf("=====================================\n");
    printf("2. POST-INCREMENT (a++)\n");
    printf("=====================================\n");

    printf("Result = %d\n", result);
    printf("a      = %d\n\n", a);



    /*
    ===========================================================================
    3. PRE-DECREMENT (--a)
    ===========================================================================
    */

    a = 10;

    /*
        Step 1:

            a = 9

        Step 2:

            result = 9
    */

    result = --a;

    printf("=====================================\n");
    printf("3. PRE-DECREMENT (--a)\n");
    printf("=====================================\n");

    printf("Result = %d\n", result);
    printf("a      = %d\n\n", a);



    /*
    ===========================================================================
    4. POST-DECREMENT (a--)
    ===========================================================================
    */

    a = 10;

    /*
        Step 1:

            result = 10

        Step 2:

            a = 9
    */

    result = a--;

    printf("=====================================\n");
    printf("4. POST-DECREMENT (a--)\n");
    printf("=====================================\n");

    printf("Result = %d\n", result);
    printf("a      = %d\n\n", a);



    /*
    ===========================================================================
    5. SIMPLE LOOP COUNTER EXAMPLE
    ===========================================================================
    */

    printf("=====================================\n");
    printf("5. LOOP COUNTER EXAMPLE\n");
    printf("=====================================\n");

    for (int i = 0; i < 5; i++)
    {
        printf("i = %d\n", i);
    }

    printf("\n");



    /*
    ===========================================================================
    6. REVERSE LOOP EXAMPLE
    ===========================================================================
    */

    printf("=====================================\n");
    printf("6. REVERSE LOOP EXAMPLE\n");
    printf("=====================================\n");

    for (int i = 5; i > 0; i--)
    {
        printf("i = %d\n", i);
    }

    printf("\n");



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    SYSTEM TICK COUNTER
    ===========================================================================
    */

    unsigned int system_tick = 1000U;

    system_tick++;

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 1\n");
    printf("=====================================\n");

    printf("System Tick = %u\n\n",
           system_tick);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    BUFFER INDEX
    ===========================================================================
    */

    unsigned int buffer_index = 0U;

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 2\n");
    printf("=====================================\n");

    printf("Current Index = %u\n",
           buffer_index++);

    printf("Next Index    = %u\n\n",
           buffer_index);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 3

    RETRY COUNTER
    ===========================================================================
    */

    int retry_count = 3;

    printf("=====================================\n");
    printf("EMBEDDED EXAMPLE 3\n");
    printf("=====================================\n");

    while (retry_count > 0)
    {
        printf("Retry Remaining = %d\n",
               retry_count);

        retry_count--;
    }

    printf("\n");



    /*
    ===========================================================================
    PRE vs POST SUMMARY
    ===========================================================================

    +----------------+----------------------+----------------------+
    | OPERATOR       | UPDATE HAPPENS       | VALUE RETURNED       |
    +----------------+----------------------+----------------------+
    | ++a            | BEFORE USE           | NEW VALUE            |
    | a++            | AFTER USE            | OLD VALUE            |
    | --a            | BEFORE USE           | NEW VALUE            |
    | a--            | AFTER USE            | OLD VALUE            |
    +----------------+----------------------+----------------------+

    ===========================================================================

    EXAMPLE:

        int x = 10;

        int a = ++x;

            x = 11
            a = 11

    --------------------------------------

        int x = 10;

        int b = x++;

            b = 10
            x = 11

    ===========================================================================
    */



    /*
    ===========================================================================
    EXPECTED OUTPUT

    PRE-INCREMENT

        Result = 11
        a      = 11

    POST-INCREMENT

        Result = 10
        a      = 11

    PRE-DECREMENT

        Result = 9
        a      = 9

    POST-DECREMENT

        Result = 10
        a      = 9

    LOOP:

        0 1 2 3 4

    REVERSE:

        5 4 3 2 1

    System Tick:

        1001

    Buffer:

        Current Index = 0
        Next Index    = 1

    Retry:

        3
        2
        1

    ===========================================================================
    */

    return 0;
}
