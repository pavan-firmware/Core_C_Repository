#include <stdio.h>

static void print_frame(const int *frame_data, size_t frame_count)
{
    for (size_t index = 0; index < frame_count; ++index) {
        printf("%d ", frame_data[index]);
    }
    puts("");
}

int main(void)
{
    int frame[] = { 11, 22, 33 };
    print_frame(frame, sizeof(frame) / sizeof(frame[0]));
    return 0;
}
