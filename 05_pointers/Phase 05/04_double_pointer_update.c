#include <stdio.h>

static void increment_via_pointer(int **value_pointer)
{
    ++(**value_pointer);
}

int main(void)
{
    int sample = 9;
    int *pointer = &sample;

    increment_via_pointer(&pointer);
    printf("sample=%d\n", sample);
    return 0;
}
