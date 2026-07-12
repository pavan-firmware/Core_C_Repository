#include <stdio.h>

int main(void)
{
    int table[3][2] = {
        { 1, 2 },
        { 3, 4 },
        { 5, 6 }
    };

    for (size_t row = 0; row < 3; ++row) {
        for (size_t col = 0; col < 2; ++col) {
            printf("%d ", table[row][col]);
        }
        puts("");
    }

    return 0;
}
