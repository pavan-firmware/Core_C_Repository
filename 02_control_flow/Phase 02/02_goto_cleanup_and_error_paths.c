#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int exit_code = 0;
    int *buffer = malloc(4U * sizeof(*buffer));

    if (buffer == NULL) {
        return 1;
    }

    buffer[0] = 1;

    if (buffer[0] == 0) {
        exit_code = 0;
        goto cleanup;
    }

cleanup:
    free(buffer);
    return exit_code;
}
