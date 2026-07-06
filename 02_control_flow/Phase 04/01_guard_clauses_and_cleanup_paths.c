#include <stdio.h>

static int process_frame(int frame_valid)
{
    if (!frame_valid) {
        puts("reject frame");
        return 1;
    }

    puts("accept frame");
    return 0;
}

int main(void)
{
    return process_frame(1);
}
