#include <stdio.h>
#include <limits.h>

/*
==============================================================================
                    01. BASIC CHARACTER TYPES IN C
==============================================================================

Topics Covered
------------------------------------------------------------------------------

1. char
2. signed char
3. unsigned char
4. Character literals
5. ASCII values
6. Escape sequences
7. Character arrays (strings)
8. Format specifiers
9. Type sizes
10. Type limits

==============================================================================


CHARACTER DATA TYPES
==============================================================================

+----------------+-------+-----------+----------+----------------+
| Type           | Bytes | Min Value | Max Value| Format         |
+----------------+-------+-----------+----------+----------------+
| char           |   1   | Impl. Dep | Impl.Dep | %c / %d        |
| signed char    |   1   |    -128   |    127   | %hhd           |
| unsigned char  |   1   |      0    |    255   | %hhu           |
+----------------+-------+-----------+----------+----------------+

NOTE:
------
char may behave as:

    signed char
        OR
    unsigned char

depending on compiler and platform.

Always use:

    signed char
    unsigned char

when exact behavior matters.

==============================================================================


ASCII TABLE (COMMON CHARACTERS)
==============================================================================

+-----------+-------------+-------------+
| Character | Decimal     | Hexadecimal |
+-----------+-------------+-------------+
| 'A'       | 65          | 0x41        |
| 'B'       | 66          | 0x42        |
| 'a'       | 97          | 0x61        |
| '0'       | 48          | 0x30        |
| Space     | 32          | 0x20        |
| New Line  | 10          | 0x0A        |
+-----------+-------------+-------------+

==============================================================================


ESCAPE SEQUENCES
==============================================================================

+------------+--------------------------+
| Sequence   | Meaning                  |
+------------+--------------------------+
| \n         | New Line                 |
| \t         | Horizontal Tab           |
| \\         | Backslash                |
| \'         | Single Quote             |
| \"         | Double Quote             |
| \0         | Null Character           |
+------------+--------------------------+

==============================================================================
*/


int main(void)
{
    /*
    ==========================================================================
    1. BASIC CHAR
    ==========================================================================

    Stores a single character.

    Internally:

        'A'

    is stored as:

        65

    in ASCII.
    */

    char grade = 'A';


    /*
    ==========================================================================
    2. SIGNED CHAR
    ==========================================================================

    Range:

        -128 to 127

    Useful when storing small negative values.
    */

    signed char temperature_offset = -25;


    /*
    ==========================================================================
    3. UNSIGNED CHAR
    ==========================================================================

    Range:

        0 to 255

    Commonly used in embedded systems for:

        UART data
        SPI data
        I2C data
        ADC bytes
        Raw memory buffers
    */

    unsigned char uart_data = 255U;


    /*
    ==========================================================================
    4. CHARACTER LITERALS
    ==========================================================================

    Single quotes:

        'A'
        'Z'
        '0'
        '@'

    represent a single character.
    */

    char start_symbol = '@';


    /*
    ==========================================================================
    5. ASCII VALUES
    ==========================================================================

    Characters are stored as numbers.

    Example:

        'A' = 65
        'a' = 97
        '0' = 48
    */

    char letter = 'A';


    /*
    ==========================================================================
    6. ESCAPE SEQUENCES
    ==========================================================================

    '\n' means new line.

    '\t' means tab.
    */

    char new_line_character = '\n';


    /*
    ==========================================================================
    7. CHARACTER ARRAY (STRING)
    ==========================================================================

    A string is:

        An array of characters
        ending with '\0'

    Memory:

        "HELLO"

        H E L L O \0
    */

    char firmware_name[] = "EMBEDDED-C";


    /*
    ==========================================================================
    PRINT CHARACTER VALUES
    ==========================================================================
    */

    printf("==================================================\n");
    printf("BASIC CHARACTER TYPES\n");
    printf("==================================================\n\n");


    printf("grade                 = %c\n", grade);

    printf("temperature_offset    = %hhd\n",
           temperature_offset);

    printf("uart_data             = %hhu\n",
           uart_data);

    printf("start_symbol          = %c\n",
           start_symbol);

    printf("firmware_name         = %s\n",
           firmware_name);


    /*
    ==========================================================================
    PRINT ASCII VALUES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("ASCII VALUES\n");
    printf("==================================================\n\n");

    printf("'A' ASCII Value       = %d\n", 'A');
    printf("'a' ASCII Value       = %d\n", 'a');
    printf("'0' ASCII Value       = %d\n", '0');
    printf("'@' ASCII Value       = %d\n", '@');

    /*
        Printing character as integer.

        letter = 'A'

        Internally:

            65
    */

    printf("letter Numeric Value = %d\n",
           letter);


    /*
    ==========================================================================
    ESCAPE SEQUENCE DEMONSTRATION
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("ESCAPE SEQUENCES\n");
    printf("==================================================\n\n");

    printf("Line 1\n");
    printf("Line 2\n");

    printf("\n");

    printf("Column1\tColumn2\tColumn3\n");

    printf("Backslash Example : \\\n");
    printf("Single Quote      : \'\n");
    printf("Double Quote      : \"\n");
    printf("New Line Value    : %d\n",
           new_line_character);


    /*
    ==========================================================================
    TYPE SIZES
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("TYPE SIZES\n");
    printf("==================================================\n\n");

    printf("sizeof(char)          = %zu bytes\n",
           sizeof(char));

    printf("sizeof(signed char)   = %zu bytes\n",
           sizeof(signed char));

    printf("sizeof(unsigned char) = %zu bytes\n",
           sizeof(unsigned char));


    /*
    ==========================================================================
    TYPE LIMITS
    ==========================================================================
    */

    printf("\n");
    printf("==================================================\n");
    printf("TYPE LIMITS\n");
    printf("==================================================\n\n");

    printf("CHAR_MIN              = %d\n",
           CHAR_MIN);

    printf("CHAR_MAX              = %d\n",
           CHAR_MAX);

    printf("SCHAR_MIN             = %d\n",
           SCHAR_MIN);

    printf("SCHAR_MAX             = %d\n",
           SCHAR_MAX);

    printf("UCHAR_MAX             = %u\n",
           UCHAR_MAX);


    /*
    ==========================================================================
    EMBEDDED EXAMPLE
    ==========================================================================

    unsigned char is heavily used for:

        UART
        SPI
        I2C
        EEPROM
        Flash Memory
        Sensor Registers
    */

    unsigned char sensor_register = 0xA5;

    printf("\n");
    printf("==================================================\n");
    printf("EMBEDDED EXAMPLE\n");
    printf("==================================================\n\n");

    printf("Sensor Register HEX   = 0x%X\n",
           sensor_register);

    printf("Sensor Register DEC   = %u\n",
           sensor_register);


    return 0;
}
