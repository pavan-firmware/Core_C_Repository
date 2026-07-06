#include <stdio.h>

static int handle_frame(int frame_ok)
{
    if (!frame_ok) {
        puts("frame rejected");
        return -1;
    }

    puts("frame accepted");
    return 0;
}

int main(void)
{
    return handle_frame(1);
}
