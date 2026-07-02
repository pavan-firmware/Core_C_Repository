#include <stdio.h>

/*
    A C program is organized into translation units, declarations, statements,
    blocks, and functions. This example shows a small program with a helper,
    scoped blocks, and a comment section that a compiler ignores.
*/

static void print_banner(void)
{
    puts("main, headers, comments, and blocks");
}

int main(void)
{
    print_banner();

    {
        int build_stage = 1;
        printf("active block stage = %d\n", build_stage);
    }

    puts("main executes the program entry path.");
    return 0;
}
