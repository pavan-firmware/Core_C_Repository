/*
scope: block
storage duration: automatic
lifetime: From entering the block until leaving the block
linkage: no linkage
*/


// modern compilers already use best optimized way of using register class automatically
// note register class is just an suggestion to complier not a command to do it
// it only use our suggestion when cpu registers are free otherwise use memory
// modern compilers already handle this tasks automatically

#include <stdio.h>

int main(void) {
    
    register int i = 0;

    for (i; i < 5; i++)
    {
        printf("status ok count done : %d \n",i);
    }
    

    return 0;
}