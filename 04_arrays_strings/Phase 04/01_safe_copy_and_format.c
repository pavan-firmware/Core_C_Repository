#include <stdio.h>
#include <string.h>

int main(void)
{
    char label[16];
    const char *source = "control";

    memset(label, 0, sizeof(label));
    snprintf(label, sizeof(label), "%s", source);
    puts(label);
    return 0;
}
