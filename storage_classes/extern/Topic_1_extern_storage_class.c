/*
scope: block/file
storage duration: Static (of the referred object)
lifetime: Program ends (of the referred object)
linkage: External
*/

// extern itself does not create a variable. It only refers to a variable that is defined somewhere


#include <stdio.h>

int main(void) {
    
    extern int cpu_clock; // if you access static global variables from the other files give compile error
    // you can access auto or normal global variables

    printf("clk: %u", cpu_clock);
    return 0;
}