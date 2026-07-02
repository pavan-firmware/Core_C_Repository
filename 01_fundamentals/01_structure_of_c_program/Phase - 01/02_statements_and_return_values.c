#include <stdio.h>

static int validate_configuration(void)
{
    const int flash_ready = 1;
    const int clock_ready = 1;
    return flash_ready && clock_ready;
}

static int build_status(void)
{
    int configuration_ok = validate_configuration();
    if (!configuration_ok)
    {
        return 1;
    }

    return 0;
}

int main(void)
{
    int status = build_status();
    printf("status=%d\n", status);

    if (status == 0)
    {
        puts("program completed with success");
    }
    else
    {
        puts("program completed with failure");
    }

    return status;
}
