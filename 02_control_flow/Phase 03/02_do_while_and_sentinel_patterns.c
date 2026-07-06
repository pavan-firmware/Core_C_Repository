#include <stdio.h>

int main(void)
{
    const int sensor_trace[] = { 10, 11, 12, -1 };
    size_t index = 0;

    do {
        printf("trace[%zu] = %d\n", index, sensor_trace[index]);
        ++index;
    } while ((index < sizeof(sensor_trace) / sizeof(sensor_trace[0])) && (sensor_trace[index] >= 0));

    return 0;
}
