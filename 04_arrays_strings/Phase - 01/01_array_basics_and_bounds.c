#include <stdio.h>

static void print_values(const int *values, size_t count)
{
    for (size_t index = 0; index < count; ++index) {
        printf("values[%zu] = %d\n", index, values[index]);
    }
}

int main(void)
{
    int calibration_points[] = { 100, 102, 101, 103 };
    print_values(calibration_points, sizeof(calibration_points) / sizeof(calibration_points[0]));
    return 0;
}
