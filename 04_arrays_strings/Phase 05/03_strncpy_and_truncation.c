#include <stdio.h>
#include <string.h>

int main(void)
{
    char destination[8];
    const char *source = "firmware";

    strncpy(destination, source, sizeof(destination));
    destination[sizeof(destination) - 1] = '\0';
    puts(destination);
    return 0;
}
