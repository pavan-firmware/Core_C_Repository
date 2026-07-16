#include <stdio.h>

int main(void)
{
    const int samples[] = { 2, 4, 6, 8 };
    const int *cursor = samples;
    const int *limit = samples + (sizeof(samples) / sizeof(samples[0]));

    while (cursor < limit) {
        printf("%d ", *cursor);
        ++cursor;
    }

    puts("");
    return 0;
}
