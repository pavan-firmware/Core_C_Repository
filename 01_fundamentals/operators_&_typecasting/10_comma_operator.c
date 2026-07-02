#include <stdio.h>

/*
===============================================================================
                        10_COMMA_OPERATOR.C
===============================================================================

TOPIC:
    Comma Operator (,)

PURPOSE:
    The comma operator allows multiple expressions to be evaluated
    from LEFT to RIGHT.

    The LAST expression becomes the final result.

===============================================================================

COMMA OPERATOR TABLE

+----------------------+-----------------------------------------+
| SYNTAX               | DESCRIPTION                             |
+----------------------+-----------------------------------------+
| a, b                 | Evaluate a, then b                      |
| a, b, c              | Evaluate a, b, then c                   |
| x = (a, b)           | x gets value of b                       |
| x = (a, b, c)        | x gets value of c                       |
+----------------------+-----------------------------------------+

===============================================================================

GENERAL SYNTAX

    expression1,
    expression2,
    expression3

Evaluation Order:

    LEFT  --------->  RIGHT

Final Result:

    expression3

===============================================================================

IMPORTANT:

COMMA AS A SEPARATOR

Examples:

    int a, b, c;

    printf("%d %d", a, b);

    function(a, b);

These are NOT comma operators.

They are:

    SEPARATORS

===============================================================================

REAL COMMA OPERATOR

Example:

    x = (10, 20);

Step 1:

    Evaluate 10

Step 2:

    Evaluate 20

Final Result:

    x = 20

===============================================================================

OPERATOR PRECEDENCE

Comma operator has the LOWEST precedence
among all C operators.

Example:

    x = (a = 10, a + 5);

Without parentheses:

    x = a = 10, a + 5;

Meaning changes.

Always use parentheses.

===============================================================================
*/


int main(void)
{
    int a;
    int b;
    int c;
    int result;


    /*
    ===========================================================================
    1. BASIC COMMA OPERATOR
    ===========================================================================
    */

    result = ((void)10, 20);

    /*
        Step 1:

            Evaluate 10

        Step 2:

            Evaluate 20

        Final Result:

            result = 20
    */

    printf("=========================================\n");
    printf("1. BASIC COMMA OPERATOR\n");
    printf("=========================================\n");

    printf("result = %d\n\n",
           result);



    /*
    ===========================================================================
    2. MULTIPLE EXPRESSIONS
    ===========================================================================
    */

    result = ((void)10, (void)20, (void)30, 40);

    /*
        Evaluation:

            10

            20

            30

            40

        Final Result:

            40
    */

    printf("=========================================\n");
    printf("2. MULTIPLE EXPRESSIONS\n");
    printf("=========================================\n");

    printf("result = %d\n\n",
           result);



    /*
    ===========================================================================
    3. VARIABLE ASSIGNMENTS
    ===========================================================================
    */

    result =
    (
        a = 100,
        b = 200,
        c = 300,
        a + b + c
    );

    /*
        a = 100

        b = 200

        c = 300

        Result:

            600
    */

    printf("=========================================\n");
    printf("3. VARIABLE ASSIGNMENTS\n");
    printf("=========================================\n");

    printf("a      = %d\n", a);
    printf("b      = %d\n", b);
    printf("c      = %d\n", c);
    printf("result = %d\n\n", result);



    /*
    ===========================================================================
    4. COMMA OPERATOR IN FOR LOOP
    ===========================================================================
    */

    printf("=========================================\n");
    printf("4. FOR LOOP USAGE\n");
    printf("=========================================\n");

    /*
        Initialize:

            i = 0
            j = 5

        Update:

            i++
            j--
    */

    for (int i = 0, j = 5;
         i <= j;
         i++, j--)
    {
        printf("i = %d   j = %d\n",
               i,
               j);
    }

    printf("\n");



    /*
    ===========================================================================
    5. EXPRESSION EVALUATION
    ===========================================================================
    */

    a = 5;

    result =
    (
        a = a + 10,
        a = a * 2,
        a = a - 5,
        a
    );

    /*
        Initial:

            a = 5

        Step 1:

            a = 15

        Step 2:

            a = 30

        Step 3:

            a = 25

        Result:

            25
    */

    printf("=========================================\n");
    printf("5. EXPRESSION EVALUATION\n");
    printf("=========================================\n");

    printf("a      = %d\n", a);
    printf("result = %d\n\n", result);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 1

    ADC INITIALIZATION
    ===========================================================================
    */

    unsigned int adc_enabled;
    unsigned int adc_channel;
    unsigned int adc_started;

    result =
    (
        adc_enabled = 1U,
        adc_channel = 5U,
        adc_started = 1U,
        adc_started
    );

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 1\n");
    printf("=========================================\n");

    printf("ADC Enabled = %u\n",
           adc_enabled);

    printf("ADC Channel = %u\n",
           adc_channel);

    printf("ADC Started = %u\n\n",
           adc_started);



    /*
    ===========================================================================
    EMBEDDED EXAMPLE 2

    DUAL COUNTERS
    ===========================================================================
    */

    printf("=========================================\n");
    printf("EMBEDDED EXAMPLE 2\n");
    printf("=========================================\n");

    /*
        Common in:

            DMA

            Ring Buffers

            Communication Protocols
    */

    for (unsigned int tx_index = 0,
                      rx_index = 10;

         tx_index < 5;

         tx_index++, rx_index--)
    {
        printf("TX=%u  RX=%u\n",
               tx_index,
               rx_index);
    }

    printf("\n");



    /*
    ===========================================================================
    COMMA SEPARATOR vs COMMA OPERATOR
    ===========================================================================

    SEPARATOR:

        int a, b, c;

    NOT an operator.

    ----------------------------------------

    SEPARATOR:

        printf("%d %d", a, b);

    NOT an operator.

    ----------------------------------------

    OPERATOR:

        x = (a, b);

    TRUE comma operator.

    Result:

        b

    ===========================================================================
    */



    /*
    ===========================================================================
    COMMON MISTAKES
    ===========================================================================

    WRONG:

        result = 10, 20;

    Actual:

        (result = 10), 20;

    Result:

        result = 10

    ----------------------------------------

    RIGHT:

        result = (10, 20);

    Result:

        result = 20

    ----------------------------------------

    WRONG:

        Too many expressions in one line.

    Hard to debug.

    Embedded Rule:

        Prefer readability.

    ===========================================================================
    */



    /*
    ===========================================================================
    INTERVIEW QUESTIONS
    ===========================================================================

    Q1:

        What is the value of:

            x = (10,20,30);

        Answer:

            30

    ----------------------------------------

    Q2:

        Which expression determines
        the final value?

        Answer:

            The LAST expression.

    ----------------------------------------

    Q3:

        Does comma operator evaluate
        left to right?

        Answer:

            Yes.

    ----------------------------------------

    Q4:

        Is this a comma operator?

            int a, b;

        Answer:

            No.

            It is a separator.

    ----------------------------------------

    Q5:

        Where is comma operator commonly used?

        Answer:

            for loops

    ===========================================================================
    */

    return 0;
}
