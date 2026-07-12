#include <stdio.h>
#include <string.h>

int main(void)
{
    char message[16] = "node";
    strncat(message, "-b", sizeof(message) - strlen(message) - 1U);
    puts(message);
    return 0;
}
