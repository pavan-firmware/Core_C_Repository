/*********************************************************************
 *              Topic 7.5 - Macro Expansion Complete Demo
 *
 * Covers:
 * 1. Object-like macro expansion
 * 2. Function-like macro expansion
 * 3. Multiple expansions
 * 4. Nested macro expansion
 * 5. Multi-level macro expansion
 * 6. Memory behavior
 * 7. Firmware-style macros
 * 8. Self-referential macro (explained only)
 *********************************************************************/

#include <stdio.h>

/*********************************************************************
 * 1. OBJECT-LIKE MACRO
 *
 * The preprocessor replaces every occurrence of MAX with 100.
 *
 * Before:
 *      MAX
 *
 * After:
 *      100
 *
 * MAX is NOT:
 *      ❌ Variable
 *      ❌ Memory
 *      ❌ Address
 *********************************************************************/
#define MAX 100

/*********************************************************************
 * 2. FUNCTION-LIKE MACRO
 *
 * Before:
 *      ADD(5,3)
 *
 * After:
 *      ((5)+(3))
 *
 * This is NOT a function call.
 *********************************************************************/
#define ADD(a,b) ((a)+(b))

/*********************************************************************
 * 3. MULTIPLE EXPANSION
 *
 * Every occurrence is replaced separately.
 *********************************************************************/
#define VALUE 10

/*********************************************************************
 * 4. NESTED MACROS
 *
 * SIZE
 *   ↓
 * VALUE
 *   ↓
 * 10
 *********************************************************************/
#define SIZE VALUE

/*********************************************************************
 * 5. MULTI-LEVEL EXPANSION
 *
 * PIN
 *  ↓
 * LED_PIN
 *  ↓
 * GPIO_PIN5
 *  ↓
 * (1U<<5)
 *********************************************************************/
#define GPIO_PIN5 (1U << 5)
#define LED_PIN GPIO_PIN5
#define PIN LED_PIN

/*********************************************************************
 * 6. SELF REFERENTIAL MACRO
 *
 * This is ONLY for explanation.
 *
 * Preprocessor disables SELF while expanding it,
 * therefore infinite recursion does NOT happen.
 *
 * If used:
 *
 * int x = SELF;
 *
 * compiler receives:
 *
 * int x = SELF;
 *
 * which causes compilation error.
 *********************************************************************/
#define SELF SELF

int main(void)
{
    /***************************************************************
     * OBJECT-LIKE EXPANSION
     ***************************************************************/
    int number = MAX;

    /*
        Source:

            int number = MAX;

        Preprocessor:

            int number = 100;
    */

    printf("MAX = %d\n", number);

    /***************************************************************
     * FUNCTION-LIKE EXPANSION
     ***************************************************************/
    int sum = ADD(20,30);

    /*
        Source:

            ADD(20,30)

        Preprocessor:

            ((20)+(30))
    */

    printf("ADD = %d\n", sum);

    /***************************************************************
     * MULTIPLE EXPANSION
     ***************************************************************/
    int a = VALUE;
    int b = VALUE;
    int c = VALUE;

    /*
        Every VALUE becomes 10

        int a = 10;
        int b = 10;
        int c = 10;
    */

    printf("Multiple Expansion = %d %d %d\n", a,b,c);

    /***************************************************************
     * NESTED EXPANSION
     ***************************************************************/
    int array[SIZE];

    /*
        SIZE
         ↓
        VALUE
         ↓
        10

        Compiler receives:

        int array[10];
    */

    printf("Array Size = %zu\n",
           sizeof(array)/sizeof(array[0]));

    /***************************************************************
     * MULTI-LEVEL EXPANSION
     ***************************************************************/
    unsigned int mask = PIN;

    /*
        PIN
         ↓
        LED_PIN
         ↓
        GPIO_PIN5
         ↓
        (1U<<5)

        Compiler receives:

        unsigned int mask = (1U<<5);
    */

    printf("Mask = %u\n", mask);

    /***************************************************************
     * MEMORY VIEW
     ***************************************************************/

    /*
        Macros DO NOT occupy memory.

        Memory contains only:

            number
            sum
            a
            b
            c
            array
            mask

        Memory does NOT contain:

            MAX
            VALUE
            SIZE
            ADD
            GPIO_PIN5
            LED_PIN
            PIN

        Because all of them disappeared after preprocessing.
    */

    return 0;
}

/*********************************************************************
 *
 * WHAT THE PREPROCESSOR DOES
 *
 * ✔ Replaces macro names
 * ✔ Expands nested macros
 * ✔ Expands function-like macros
 * ✔ Expands every occurrence
 *
 *********************************************************************/

/*********************************************************************
 *
 * WHAT THE PREPROCESSOR DOES NOT DO
 *
 * ❌ Does not allocate memory
 * ❌ Does not execute code
 * ❌ Does not type-check
 * ❌ Does not call functions
 * ❌ Does not generate machine code
 *
 *********************************************************************/

/*********************************************************************
 *
 * BUILD FLOW
 *
 * Source Code
 *      │
 *      ▼
 * Preprocessor
 *      │
 *      ▼
 * Expanded Source
 *      │
 *      ▼
 * Compiler
 *      │
 *      ▼
 * Assembly
 *      │
 *      ▼
 * Object File
 *      │
 *      ▼
 * Linker
 *      │
 *      ▼
 * Executable
 *
 *********************************************************************/