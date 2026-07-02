#include <stdio.h>

static void print_stage(const char *stage, const char *description)
{
    printf("%-12s : %s\n", stage, description);
}

int main(void)
{
    /*
        A C build typically moves through preprocessing, compilation,
        assembly, linking, and loading. The compiler transforms source into
        an internal model, then emits machine code for the target platform.
    */

    const char *stages[][2] =
    {
        {"preprocess", "expand macros and include headers"},
        {"compile", "analyze syntax and generate intermediate form"},
        {"assemble", "convert assembly into object code"},
        {"link", "resolve symbols across translation units"},
        {"load", "map the executable and start runtime setup"}
    };

    puts("compilation and toolchain flow");
    puts("------------------------------");

    for (size_t index = 0; index < sizeof stages / sizeof stages[0]; ++index)
    {
        print_stage(stages[index][0], stages[index][1]);
    }

    puts("");
    puts("Toolchain examples:");
    puts("- GCC and Clang are common hosted compilers");
    puts("- cross-compilers target another CPU or ABI");
    puts("- build flags control warnings, optimization, and ABI assumptions");

    return 0;
}
