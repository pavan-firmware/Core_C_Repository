#include <stdio.h>

int main(void)
{
    int control_word = 77;
    void *generic_pointer = &control_word;
    int *typed_pointer = (int *)generic_pointer;
    int **pointer_to_pointer = &typed_pointer;

    printf("value=%d\n", **pointer_to_pointer);
    return 0;
}
