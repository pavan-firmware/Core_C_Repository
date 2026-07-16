#include <stdio.h>

int main(void)
{
    int sample = 12;
    const int *pointer_to_const = &sample;
    int *const const_pointer = &sample;

    printf("%d %d\n", *pointer_to_const, *const_pointer);
    return 0;
}
