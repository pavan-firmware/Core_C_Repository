/*
using #include directive

#include is a preprocessor directive that tells the preprocessor:
"Take the contents of another file and insert them here before compilation."
*/

// 1. System Header
// Angle brackets (< >) tell the preprocessor: Search the compiler's system include directories.
#include <stdio.h> // it includes the stdio.h header file to this file before compilation

// 2. User Header
/*
Double quotes (" ") tell the preprocessor:

Search the current project directory first.
If not found, search the system include directories.

Used for your own header files.
*/
#include "student.h"

/*
when it reach to compiler stage the total file looks like this
Total single file

header file
...
....
.....

main.c 
....
.....
......
*/

int main(void) {

    // all these are not declare in this file actually, these are coming from the stduent.h file 
    // #include include or insert/merge all the data to this file before complier reach
    // then compiler think actually these all belongs to this file
    printf("LED_PIN : %d\n", LED_PIN);
    printf("UART_BAUD : %d\n", UART_BAUD);
    printf("BUFFER_SIZE : %d\n", BUFFER_SIZE);
    return 0;
}