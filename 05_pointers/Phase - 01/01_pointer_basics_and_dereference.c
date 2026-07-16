#include <stdio.h>

int main(void)
{
    int bus_voltage = 3300;
    int *voltage_pointer = &bus_voltage;

    printf("bus_voltage = %d\n", *voltage_pointer);
    return 0;
}
