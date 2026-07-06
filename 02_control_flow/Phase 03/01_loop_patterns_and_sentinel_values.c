#include <stdio.h>

int main(void)
{
    const int sensor_stream[] = { 12, 14, 15, -1, 18 };
    size_t index = 0;

    while ((index < sizeof(sensor_stream) / sizeof(sensor_stream[0])) && (sensor_stream[index] >= 0)) {
        printf("sensor[%zu]=%d\n", index, sensor_stream[index]);
        ++index;
    }

    return 0;
}
