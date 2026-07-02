#include <stdio.h>

/*
==============================================================================
                        07. STORAGE CLASSES IN C
==============================================================================

TOPICS COVERED
------------------------------------------------------------------------------

1. auto Storage Class
2. register Storage Class
3. static Local Variables
4. static Global Variables
5. extern Variables
6. Scope
7. Lifetime
8. Linkage
9. Memory Layout
10. Embedded Firmware Examples

==============================================================================


WHAT IS A STORAGE CLASS?
==============================================================================

Storage Class decides:

    1. Scope
       (Where variable can be accessed)

    2. Lifetime
       (How long variable exists)

    3. Linkage
       (Can other files access it?)

    4. Memory Location
       (Stack, Data Section, Registers)

==============================================================================


STORAGE CLASS SUMMARY
==============================================================================

+----------+-----------+-------------+-------------+--------------+
| Keyword  | Scope     | Lifetime    | Linkage     | Memory Area  |
+----------+-----------+-------------+-------------+--------------+
| auto     | Local     | Function    | None        | Stack        |
| register | Local     | Function    | None        | CPU Register |
| static   | Local     | Entire Prog | None        | Data Segment |
| static   | Global    | Entire Prog | Internal    | Data Segment |
| extern   | Global    | Entire Prog | External    | Data Segment |
+----------+-----------+-------------+-------------+--------------+

==============================================================================


MEMORY LAYOUT
==============================================================================

+--------------------------------------------------+
|                    STACK                         |
|--------------------------------------------------|
| auto variables                                  |
| function parameters                             |
| local variables                                 |
+--------------------------------------------------+

+--------------------------------------------------+
|                    HEAP                          |
|--------------------------------------------------|
| malloc()                                        |
| calloc()                                        |
+--------------------------------------------------+

+--------------------------------------------------+
|                    BSS                           |
|--------------------------------------------------|
| Uninitialized globals                           |
| Uninitialized static variables                  |
+--------------------------------------------------+

+--------------------------------------------------+
|                    DATA                          |
|--------------------------------------------------|
| Initialized globals                             |
| Initialized static variables                    |
+--------------------------------------------------+

+--------------------------------------------------+
|                    TEXT                          |
|--------------------------------------------------|
| Program instructions                            |
| String literals                                 |
| const data                                      |
+--------------------------------------------------+

==============================================================================
*/


/*
------------------------------------------------------------------------------
GLOBAL VARIABLES
------------------------------------------------------------------------------
*/

/*
    Global Variable

    Visible from other files
    using extern.
*/

int g_system_counter = 100;


/*
    Static Global Variable

    Visible ONLY inside
    this source file.
*/

static int g_driver_state = 1;


/*
------------------------------------------------------------------------------
EXTERN DECLARATION
------------------------------------------------------------------------------
*/

extern int g_system_counter;


/*
------------------------------------------------------------------------------
AUTO STORAGE CLASS EXAMPLE
------------------------------------------------------------------------------
*/

void auto_example(void)
{
    /*
        auto is the default storage class.

        Compiler automatically adds it.
    */

    auto int temperature = 25;

    printf("AUTO Variable = %d\n",
           temperature);
}


/*
------------------------------------------------------------------------------
REGISTER STORAGE CLASS EXAMPLE
------------------------------------------------------------------------------
*/

void register_example(void)
{
    /*
        register requests the compiler
        to use CPU registers.

        Modern compilers may ignore this.
    */

    register int counter;

    printf("REGISTER Counter: ");

    for (counter = 1;
         counter <= 5;
         counter++)
    {
        printf("%d ",
               counter);
    }

    printf("\n");


    /*
        ERROR:

        Cannot take address.

        &counter

        may not exist in memory.
    */
}


/*
------------------------------------------------------------------------------
STATIC LOCAL VARIABLE
------------------------------------------------------------------------------
*/

void static_counter(void)
{
    /*
        Initialized only once.

        Value persists across
        multiple function calls.
    */

    static int count = 0;

    count++;

    printf("STATIC Count = %d\n",
           count);
}


/*
------------------------------------------------------------------------------
NORMAL LOCAL VARIABLE
------------------------------------------------------------------------------
*/

void normal_counter(void)
{
    /*
        Created every function call.

        Destroyed every function call.
    */

    int count = 0;

    count++;

    printf("NORMAL Count = %d\n",
           count);
}


/*
------------------------------------------------------------------------------
EMBEDDED DRIVER EXAMPLE
------------------------------------------------------------------------------
*/

void uart_driver_init(void)
{
    /*
        Initialize UART only once.
    */

    static int initialization_done = 0;

    if (initialization_done == 0)
    {
        printf("UART Initialization Done\n");

        initialization_done = 1;
    }
    else
    {
        printf("UART Already Initialized\n");
    }
}


int main(void)
{
    /*
    ==========================================================================
    AUTO STORAGE CLASS
    ==========================================================================
    */

    printf("==================================================\n");
    printf("AUTO STORAGE CLASS\n");
    printf("==================================================\n\n");

    auto_example();


    /*
    ==========================================================================
    REGISTER STORAGE CLASS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("REGISTER STORAGE CLASS\n");
    printf("==================================================\n\n");

    register_example();


    /*
    ==========================================================================
    STATIC LOCAL VARIABLES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("STATIC LOCAL VARIABLES\n");
    printf("==================================================\n\n");

    static_counter();
    static_counter();
    static_counter();


    /*
    ==========================================================================
    NORMAL LOCAL VARIABLES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("NORMAL LOCAL VARIABLES\n");
    printf("==================================================\n\n");

    normal_counter();
    normal_counter();
    normal_counter();


    /*
    ==========================================================================
    GLOBAL VARIABLES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("GLOBAL VARIABLES\n");
    printf("==================================================\n\n");

    printf("Global Counter = %d\n",
           g_system_counter);


    /*
    ==========================================================================
    STATIC GLOBAL VARIABLES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("STATIC GLOBAL VARIABLES\n");
    printf("==================================================\n\n");

    printf("Driver State = %d\n",
           g_driver_state);


    /*
    ==========================================================================
    EXTERN VARIABLES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("EXTERN VARIABLES\n");
    printf("==================================================\n\n");

    printf("Extern Counter = %d\n",
           g_system_counter);


    /*
    ==========================================================================
    EMBEDDED DRIVER EXAMPLE
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED DRIVER EXAMPLE\n");
    printf("==================================================\n\n");

    uart_driver_init();
    uart_driver_init();
    uart_driver_init();


    /*
    ==========================================================================
    SCOPE SUMMARY
    ==========================================================================

    Local Variable:

        Visible only inside function.

    Global Variable:

        Visible everywhere.

    Static Global Variable:

        Visible only inside current file.

    ==========================================================================
    */


    /*
    ==========================================================================
    LIFETIME SUMMARY
    ==========================================================================

    auto:

        Created:
            Function Entry

        Destroyed:
            Function Exit

    static:

        Created:
            Program Start

        Destroyed:
            Program End

    global:

        Created:
            Program Start

        Destroyed:
            Program End

    ==========================================================================
    */


    /*
    ==========================================================================
    EMBEDDED FIRMWARE USAGE
    ==========================================================================

    auto:

        Temporary calculations
        Loop variables

    register:

        Rarely used today

    static local:

        Driver initialization flags
        State machines
        Counters

    static global:

        Private driver variables

    extern:

        Shared system variables

    ==========================================================================
    */


    /*
    ==========================================================================
    COMMON BEGINNER MISTAKES
    ==========================================================================

    WRONG:

        static means constant.

    Reality:

        static changes:

            Scope
            Lifetime
            Linkage

        NOT mutability.

    ------------------------------------------------------------

    WRONG:

        register guarantees CPU register usage.

    Reality:

        Modern compilers decide.

    ------------------------------------------------------------

    WRONG:

        extern creates memory.

    Reality:

        extern only declares.

    Definition:

        int counter = 0;

    Declaration:

        extern int counter;

    ------------------------------------------------------------

    WRONG:

        Using too many global variables.

    Better:

        Use static globals
        whenever possible.

    ==========================================================================
    */

    return 0;
}
