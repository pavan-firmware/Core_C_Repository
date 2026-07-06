#include <stdio.h>

int main(void)
{
    int retry_budget = 3;

    while (1) {
        puts("polling...");
        --retry_budget;
        if (retry_budget <= 0) {
            break;
        }
    }

    return 0;
}
