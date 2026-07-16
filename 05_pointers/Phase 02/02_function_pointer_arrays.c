#include <stdio.h>

typedef int (*operation_fn)(int, int);

static int add(int lhs, int rhs) { return lhs + rhs; }
static int multiply(int lhs, int rhs) { return lhs * rhs; }

int main(void)
{
    operation_fn operations[] = { add, multiply };
    printf("add=%d multiply=%d\n", operations[0](2, 3), operations[1](2, 3));
    return 0;
}
