#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *command = "set output mode";
    printf("space=%s\n", strchr(command, ' '));
    printf("output=%s\n", strstr(command, "output"));
    return 0;
}
