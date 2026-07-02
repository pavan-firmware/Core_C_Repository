#include <stdio.h>

static void print_application_area(const char *domain, const char *examples)
{
    printf("%-18s : %s\n", domain, examples);
}

int main(void)
{
    /*
        C remains a strong choice where the program must be compact, portable,
        and predictable. Embedded firmware uses that predictability to control
        peripherals, memory layout, and timing-sensitive behavior.
    */

    const char *milestones[] =
    {
        "Dennis Ritchie created C at Bell Labs.",
        "C powered the UNIX ecosystem.",
        "C influenced many modern systems languages.",
        "C continues to dominate low-level software."
    };

    const char *applications[] =
    {
        "Operating systems and kernels",
        "Embedded firmware and drivers",
        "Compilers, linkers, and debuggers",
        "Networking stacks and protocol parsers"
    };

    puts("history, features, and applications of C");
    puts("----------------------------------------");

    for (size_t index = 0; index < sizeof milestones / sizeof milestones[0]; ++index)
    {
        printf("%zu. %s\n", index + 1, milestones[index]);
    }

    puts("");
    print_application_area("systems", applications[0]);
    print_application_area("embedded", applications[1]);
    print_application_area("tooling", applications[2]);
    print_application_area("networking", applications[3]);

    puts("");
    puts("Core strengths:");
    puts("- direct memory control");
    puts("- predictable translation to machine code");
    puts("- small runtime assumptions");
    puts("- excellent portability when written carefully");

    return 0;
}
