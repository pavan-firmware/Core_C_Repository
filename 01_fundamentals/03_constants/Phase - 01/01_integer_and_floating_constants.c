#include <stdio.h>

int main(void)
{
    int retry_limit = 3;
    double voltage_reference = 3.300;

    printf("retry_limit=%d\n", retry_limit);
    printf("voltage_reference=%.3f\n", voltage_reference);
    return 0;
}
