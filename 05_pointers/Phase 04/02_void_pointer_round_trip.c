#include <stdio.h>

int main(void)
{
    int sample = 99;
    void *generic_pointer = &sample;
    int *typed_pointer = generic_pointer;

    printf("value=%d\n", *typed_pointer);
    return 0;
}
