#include <stdio.h>

typedef int (*operation_fn)(int, int);

static int add(int lhs, int rhs) { return lhs + rhs; }
static int multiply(int lhs, int rhs) { return lhs * rhs; }

int main(void)
{
    operation_fn table[] = { add, multiply };

    printf("add = %d\n", table[0](3, 5));
    printf("multiply = %d\n", table[1](3, 5));
    return 0;
}
