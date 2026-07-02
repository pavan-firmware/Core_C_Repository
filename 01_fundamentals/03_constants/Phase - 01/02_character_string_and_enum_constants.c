#include <stdio.h>

typedef enum
{
    MODE_IDLE,
    MODE_ACTIVE
} SystemMode;

int main(void)
{
    char status_char = 'A';
    const char *label = "control-node";
    SystemMode mode = MODE_ACTIVE;

    printf("status_char=%c label=%s mode=%d\n", status_char, label, mode);
    return 0;
}
