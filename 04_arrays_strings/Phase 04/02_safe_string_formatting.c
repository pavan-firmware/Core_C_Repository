#include <stdio.h>

int main(void)
{
    char buffer[32];
    int device_id = 7;

    snprintf(buffer, sizeof(buffer), "dev-%03d", device_id);
    puts(buffer);
    return 0;
}
