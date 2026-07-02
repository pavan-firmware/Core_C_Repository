#include <stdio.h>

static int g_message_count = 0;

static void log_message(const char *message)
{
    int local_count = 1;
    ++g_message_count;
    printf("%s | local=%d global=%d\n", message, local_count, g_message_count);
}

int main(void)
{
    log_message("first event");
    log_message("second event");
    return 0;
}
