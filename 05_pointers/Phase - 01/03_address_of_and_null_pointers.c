#include <stdio.h>

int main(void)
{
    int control_word = 45;
    int *pointer = &control_word;
    int *null_pointer = NULL;

    printf("address=%p value=%d\n", (void *)pointer, *pointer);
    printf("null=%p\n", (void *)null_pointer);
    return 0;
}
