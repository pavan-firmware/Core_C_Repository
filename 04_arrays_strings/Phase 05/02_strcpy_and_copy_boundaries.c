#include <stdio.h>
#include <string.h>

int main(void)
{
    char destination[16];
    const char *source = "controller";

    strcpy(destination, source);
    puts(destination);
    return 0;
}
