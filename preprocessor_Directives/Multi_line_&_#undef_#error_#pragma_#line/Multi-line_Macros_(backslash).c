#include <stdio.h>

/*----------------------------------------------------------
    Simple helper functions
----------------------------------------------------------*/
void LED_ON(void)
{
    printf("LED ON\n");
}

void LED_OFF(void)
{
    printf("LED OFF\n");
}

void Delay(void)
{
    printf("Delay 500 ms\n");
}

/*==========================================================
    1. SIMPLE MULTI-LINE MACRO
    Uses '\' to continue the macro onto the next line.
==========================================================*/

#define PRINT_INFO()               \
    printf("Embedded\n");          \
    printf("Firmware\n");          \
    printf("Engineering\n");

/*==========================================================
    2. MULTI-LINE MACRO WITH ARGUMENT
==========================================================*/

#define PRINT_NUMBER(x)            \
    printf("Value = %d\n", x);

/*==========================================================
    3. MULTIPLE STATEMENTS
==========================================================*/

#define BLINK_LED()                \
    LED_ON();                      \
    Delay();                       \
    LED_OFF();

/*
WARNING

This macro expands to

LED_ON();
Delay();
LED_OFF();

This is NOT SAFE inside if-else.

Example

if(flag)
    BLINK_LED();
else
    printf("OFF");

After expansion

if(flag)
    LED_ON();
Delay();
LED_OFF();
else
    printf("OFF");

Compilation Error
*/

/*==========================================================
    4. PROFESSIONAL WAY
       do { } while(0)
==========================================================*/

#define SAFE_BLINK()               \
    do                             \
    {                              \
        LED_ON();                  \
        Delay();                   \
        LED_OFF();                 \
    } while(0)

/*
Expansion

do
{
    LED_ON();
    Delay();
    LED_OFF();
}while(0);

Acts like ONE statement.
Safe inside if-else.
*/

/*==========================================================
    5. DEBUG MACRO
==========================================================*/

#define DEBUG_PRINT(msg)                 \
    do                                   \
    {                                    \
        printf("[DEBUG] %s\n", msg);     \
    } while(0)

/*==========================================================
    6. ERROR HANDLER
==========================================================*/

#define ERROR_HANDLER()                  \
    do                                   \
    {                                    \
        printf("Fatal Error\n");         \
        LED_ON();                        \
    } while(0)

/*==========================================================
    MAIN
==========================================================*/

int main(void)
{
    int button = 1;

    printf("Example 1\n");
    PRINT_INFO();

    printf("\n");

    printf("Example 2\n");
    PRINT_NUMBER(100);

    printf("\n");

    printf("Example 3\n");
    BLINK_LED();

    printf("\n");

    printf("Example 4\n");

    if(button)
        SAFE_BLINK();
    else
        printf("Button Not Pressed\n");

    printf("\n");

    printf("Example 5\n");
    DEBUG_PRINT("UART Initialized");

    printf("\n");

    printf("Example 6\n");
    ERROR_HANDLER();

    return 0;
}