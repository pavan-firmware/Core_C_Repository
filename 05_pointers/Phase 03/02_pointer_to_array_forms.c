#include <stdio.h>

int main(void)
{
    int matrix[2][2] = {
        { 1, 2 },
        { 3, 4 }
    };
    int (*row_pointer)[2] = matrix;

    printf("%d %d\n", row_pointer[1][0], row_pointer[1][1]);
    return 0;
}
