#include <stdio.h>

int main(void)
{
    const int samples[] = { 4, 8, 12 };
    const int *cursor = samples;
    const int *limit = samples + 3;

    while (cursor != limit) {
        printf("%d ", *cursor);
        ++cursor;
    }

    puts("");
    return 0;
}
