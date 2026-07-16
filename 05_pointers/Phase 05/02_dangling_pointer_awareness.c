#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *buffer = malloc(sizeof(*buffer));
    if (buffer == NULL) {
        return 1;
    }

    *buffer = 7;
    free(buffer);
    buffer = NULL;
    puts("pointer cleared after free");
    return 0;
}
