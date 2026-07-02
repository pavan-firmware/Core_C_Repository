#include <stdio.h>
#include <stdint.h>

/*
===============================================================================
                    15_EXPLICIT_TYPE_CASTING.C
===============================================================================

TOPIC:
    Explicit Type Casting (Manual Type Conversion)

ALSO CALLED:

    C-Style Casting

===============================================================================

WHAT IS EXPLICIT TYPE CASTING?

Definition:

    Explicit type casting means the programmer
    manually tells the compiler to convert one
    data type into another.

===============================================================================

GENERAL SYNTAX

    (target_type)expression

Examples:

    (float)10

    (int)3.14

    (char)65

    (uint16_t)adc_value

===============================================================================

CASTING TABLE

+----------------+----------------+-----------------------------+
| SOURCE TYPE    | TARGET TYPE    | EXAMPLE                     |
+----------------+----------------+-----------------------------+
| int            | float          | (float)10                   |
| float          | int            | (int)3.14f                 |
| double         | float          | (float)3.14159             |
| int            | char           | (char)65                   |
| char           | int            | (int)'A'                   |
| int            | uint8_t        | (uint8_t)300               |
+----------------+----------------+-----------------------------+

===============================================================================

IMPORTANT

EXPLICIT CASTING CAN:

    • Lose data
    • Remove decimal values
    • Overflow values
    • Change sign

Use carefully.

===============================================================================
*/


int main(void)
{
    /*
    ===========================================================================
    1. INT TO FLOAT
    ===========================================================================
    */

    int sensor_count = 100;

    float sensor_count_float =
        (float)sensor_count;

    printf("=========================================\n");
    printf("1. INT TO FLOAT\n");
    printf("=========================================\n");

    printf("Integer = %d\n",
           sensor_count);

    printf("Float   = %.2f\n\n",
           sensor_count_float);



    /*
    ===========================================================================
    2. FLOAT TO INT
    ===========================================================================
    */

    float temperature = 27.89f;

    int integer_temperature =
        (int)temperature;

    /*
        Decimal part is LOST.

        27.89

            ↓

        27
    */

    printf("=========================================\n");
    printf("2. FLOAT TO INT\n");
    printf("=========================================\n");

    printf("Float   = %.2f\n",
           temperature);

    printf("Integer = %d\n\n",
           integer_temperature);



    /*
    ===========================================================================
    3. DOUBLE TO FLOAT
    ===========================================================================
    */

    double pi_double = 3.141592653589793;

    float pi_float =
        (float)pi_double;

    /*
        Some precision is lost.

        double:

            More precision

        float:

            Less precision
    */

    printf("=========================================\n");
    printf("3. DOUBLE TO FLOAT\n");
    printf("=========================================\n");

    printf("Double = %.15lf\n",
           pi_double);

    printf("Float  = %.7f\n\n",
           pi_float);



    /*
    ===========================================================================
    4. INT TO CHAR
    ===========================================================================
    */

    int ascii_number = 65;

    char letter =
        (char)ascii_number;

    /*
        ASCII:

            65

            ↓

            'A'
    */

    printf("=========================================\n");
    printf("4. INT TO CHAR\n");
    printf("=========================================\n");

    printf("ASCII Number = %d\n",
           ascii_number);

    printf("Character    = %c\n\n",
           letter);



    /*
    ===========================================================================
    5. CHAR TO INT
    ===========================================================================
    */

    char grade = 'B';

    int ascii_value =
        (int)grade;

    printf("=========================================\n");
    printf("5. CHAR TO INT\n");
    printf("=========================================\n");

    printf("Character   = %c\n",
           grade);

    printf("ASCII Value = %d\n\n",
           ascii_value);



    /*
    ===========================================================================
    ASCII TABLE

    +-----------+------------+
    | CHARACTER | ASCII      |
    +-----------+------------+
    | A         | 65         |
    | B         | 66         |
    | C         | 67         |
    | a         | 97         |
    | b         | 98         |
    | 0         | 48         |
    | 1         | 49         |
    +-----------+------------+

    ===========================================================================
    */



    /*
    ===========================================================================
    6. LARGE INTEGER TO UINT8_T
    ===========================================================================
    */

    int large_value = 300;

    uint8_t small_value =
        (uint8_t)large_value;

    /*
        uint8_t:

            Maximum:

                255

        Calculation:

            300 % 256

            44
    */

    printf("=========================================\n");
    printf("6. INT TO UINT8_T\n");
    printf("=========================================\n");

    printf("Original Value = %d\n",
           large_value);

    printf("Converted Value = %u\n\n",
           small_value);



    /*
    ===========================================================================
    MEMORY VISUALIZATION

    int

        300

        00000000 00000000 00000001 00101100

    uint8_t

        Take only last 8 bits

        00101100

        Decimal:

            44

    ===========================================================================
    */



    /*
    ===========================================================================
    7. SIGNED TO UNSIGNED CAST
    ===========================================================================
    */

    int negative_number = -1;

    uint32_t unsigned_number =
        (uint32_t)negative_number;

    printf("=========================================\n");
    printf("7. SIGNED TO UNSIGNED\n");
    printf("=========================================\n");

    printf("Signed   = %d\n",
           negative_number);

    printf("Unsigned = %u\n\n",
           unsigned_number);



    /*
    ===========================================================================
    TWO'S COMPLEMENT

    -1

    Binary:

        11111111 11111111
        11111111 11111111

    uint32_t:

        4294967295

    ===========================================================================
    */



    /*
    ===========================================================================
    8. EMBEDDED EXAMPLE

    ADC TO VOLTAGE CONVERSION
    ===========================================================================
    */

    uint16_t adc_value = 2048;

    float voltage =
        ((float)adc_value * 3.3f) / 4095.0f;

    printf("=========================================\n");
    printf("8. EMBEDDED EXAMPLE\n");
    printf("=========================================\n");

    printf("ADC Value = %u\n",
           adc_value);

    printf("Voltage   = %.3f V\n\n",
           voltage);



    /*
    ===========================================================================
    WHY CAST HERE?

    WRONG:

        adc_value * 3 / 4095

    Integer arithmetic happens.

    CORRECT:

        (float)adc_value

    Floating-point arithmetic happens.

    ===========================================================================
    */



    /*
    ===========================================================================
    9. EMBEDDED EXAMPLE

    UART DATA BYTE
    ===========================================================================
    */

    int received_data = 300;

    uint8_t uart_byte =
        (uint8_t)received_data;

    printf("=========================================\n");
    printf("9. UART EXAMPLE\n");
    printf("=========================================\n");

    printf("Received Data = %d\n",
           received_data);

    printf("UART Byte     = %u\n\n",
           uart_byte);



    /*
    ===========================================================================
    MISRA C RECOMMENDATIONS

    GOOD:

        Explicit casts make programmer
        intention clear.

    Example:

        uint16_t result =
            (uint16_t)(a + b);

    Benefits:

        • Better readability
        • Fewer warnings
        • Safer conversions
        • Static analysis friendly

    ===========================================================================
    */



    /*
    ===========================================================================
    COMMON MISTAKES
    ===========================================================================

    WRONG:

        int x = (int)3.99f;

        Expect:

            4

        Actual:

            3

    ----------------------------------------

    WRONG:

        uint8_t value =
            (uint8_t)300;

        Expect:

            300

        Actual:

            44

    ----------------------------------------

    WRONG:

        float result =
            (float)(5 / 2);

        Result:

            2.0

    Because:

        Integer division happens first.

    CORRECT:

        (float)5 / 2

        Result:

            2.5

    ===========================================================================
    */

    float wrong_result =
        (float)(5 / 2);

    float correct_result =
        (float)5 / 2;

    printf("=========================================\n");
    printf("COMMON MISTAKE EXAMPLE\n");
    printf("=========================================\n");

    printf("(float)(5 / 2) = %.2f\n",
           wrong_result);

    printf("(float)5 / 2   = %.2f\n\n",
           correct_result);



    /*
    ===========================================================================
    INTERVIEW QUESTIONS
    ===========================================================================

    Q1:

        What is explicit type casting?

        Answer:

            Manual conversion by programmer.

    ----------------------------------------

    Q2:

        Syntax?

        Answer:

            (type)expression

    ----------------------------------------

    Q3:

        Result:

            (int)3.99

        Answer:

            3

    ----------------------------------------

    Q4:

        Result:

            (char)65

        Answer:

            A

    ----------------------------------------

    Q5:

        Result:

            (uint8_t)300

        Answer:

            44

    ----------------------------------------

    Q6:

        Why use explicit casts in
        embedded systems?

        Answer:

            Better readability,
            MISRA compliance,
            safer conversions.

    ===========================================================================
    */

    return 0;
}
