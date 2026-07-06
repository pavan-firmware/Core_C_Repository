#include <stdio.h>

int main(void)
{
    int fault_matrix[2][3] = {
        { 0, 0, 1 },
        { 0, 1, 0 }
    };

    for (size_t row = 0; row < 2; ++row) {
        for (size_t column = 0; column < 3; ++column) {
            printf("%d ", fault_matrix[row][column]);
        }
        puts("");
    }

    return 0;
}
