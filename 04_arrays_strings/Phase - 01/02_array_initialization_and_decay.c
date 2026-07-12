#include <stdio.h>

static void print_first_element(const int *values)
{
    printf("first=%d\n", values[0]);
}

int main(void)
{
    int samples[] = { 5, 10, 15, 20 };
    print_first_element(samples);
    return 0;
}
