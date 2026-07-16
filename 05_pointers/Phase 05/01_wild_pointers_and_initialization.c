#include <stdio.h>

int main(void)
{
    int control_word = 42;
    int *initialized_pointer = &control_word;

    printf("value=%d\n", *initialized_pointer);
    return 0;
}
