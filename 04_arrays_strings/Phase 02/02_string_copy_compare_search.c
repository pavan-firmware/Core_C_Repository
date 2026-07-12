#include <stdio.h>
#include <string.h>

int main(void)
{
    char label[24];
    const char *source = "telemetry";

    strncpy(label, source, sizeof(label));
    label[sizeof(label) - 1] = '\0';

    printf("compare=%d\n", strcmp(label, "telemetry"));
    printf("search=%s\n", strstr(label, "metry"));
    return 0;
}
