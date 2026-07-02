#include <stdio.h>

static void print_standard(const char *standard, const char *highlight)
{
    printf("%-8s : %s\n", standard, highlight);
}

int main(void)
{
    /*
        The chosen language standard affects which features are available:
        declarations can appear in loops, bool exists, variable length arrays
        may be enabled, and atomics or threads may be part of the build target.
    */

    puts("c standards and variants");
    puts("------------------------");

    print_standard("C89", "baseline ANSI C with older declaration rules");
    print_standard("C99", "for-loop declarations, // comments, bool, VLAs");
    print_standard("C11", "atomics, threads, alignas, and safer semantics");
    print_standard("C17", "bug-fix revision of the C11 family");
    print_standard("C23", "modern refinements and updated library details");

    puts("");
    puts("When writing portable firmware code, choose one target standard and keep");
    puts("feature usage aligned with the compilers that must build the project.");

    return 0;
}
