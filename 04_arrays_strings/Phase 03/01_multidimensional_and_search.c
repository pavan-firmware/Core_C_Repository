#include <stdio.h>
#include <string.h>

int main(void)
{
    int gain_table[2][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 }
    };

    const char *command = "set mode active";

    printf("gain_table[1][2] = %d\n", gain_table[1][2]);
    printf("mode found = %s\n", strstr(command, "mode"));
    return 0;
}
