#include <stdio.h>
#include <string.h>

int main(void)
{
    char command[] = "mode=active;rate=100";
    char *token = strtok(command, ";");

    while (token != NULL) {
        puts(token);
        token = strtok(NULL, ";");
    }

    return 0;
}
