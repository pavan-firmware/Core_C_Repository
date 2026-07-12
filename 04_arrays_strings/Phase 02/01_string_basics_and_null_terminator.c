#include <stdio.h>

int main(void)
{
    char device_label[] = "control-node";

    printf("label = %s\n", device_label);
    printf("first = %c\n", device_label[0]);
    printf("terminator byte = %d\n", device_label[12]);
    return 0;
}
