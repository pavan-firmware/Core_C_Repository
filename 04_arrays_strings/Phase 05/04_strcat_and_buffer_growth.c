#include <stdio.h>
#include <string.h>

int main(void)
{
    char message[32] = "node";
    strcat(message, "-alpha");
    puts(message);
    return 0;
}
