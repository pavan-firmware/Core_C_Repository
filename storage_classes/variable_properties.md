# Variable Properties

Every variable in C can be described using these properties:

- **Scope** – Where the variable can be accessed.
- **Storage Duration** – How long memory is allocated for the variable.
- **Lifetime** – How long the variable exists during program execution.
- **Linkage** – Whether the variable can be accessed from other source files.
- **Default Initial Value** – The value assigned if the variable is not explicitly initialized.



| Variable Declaration | Scope | Storage Duration | Lifetime | Linkage | Default Initial Value |
|----------------------|-------|------------------|----------|---------|-----------------------|
| `int x;` *(inside function)* | Block | Automatic | Block execution | No linkage | Garbage (indeterminate) |
| `auto int x;` | Block | Automatic | Block execution | No linkage | Garbage (indeterminate) |
| `register int x;` | Block | Automatic | Block execution | No linkage | Garbage (indeterminate) |
| `static int x;` *(inside function)* | Block | Static | Program execution | No linkage | `0` |
| `int x;` *(outside function)* | File | Static | Program execution | External linkage | `0` |
| `static int x;` *(outside function)* | File | Static | Program execution | Internal linkage | `0` |
| `extern int x;` *(inside function)* | Block | Refers to existing object | Refers to existing object | External linkage | No initialization *(declaration only)* |
| `extern int x;` *(outside function)* | File | Refers to existing object | Refers to existing object | External linkage | No initialization *(declaration only)* |
