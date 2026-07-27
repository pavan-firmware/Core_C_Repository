/*
scope: block
storage duration: automatic
lifetime: automatic
linkage: no linkage
*/


#include <stdio.h>

int main(void) {
    float temp = 30;
    auto float humidity = 23.4;

    // both are same by default compiler uses the auto class for local variables

    printf("temperature : %.2f", temp);
    printf("humidity : %.2f", humidity);


    return 0;
}