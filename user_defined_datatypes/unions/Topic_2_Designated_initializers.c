#include<stdio.h>
#include<string.h>

int main() {
     union Data {
        int i;
        float f;
        char str[20];
    };

    union Data data = { .f = 10 }; // when you need to assign members in unorder or only initialize specific members, Designated initializer to initialize the union member `f` with the value 10. This will set the value of `f` to 10 and the other members (`i` and `str`) will be uninitialized.

    printf("data.f : %.2f\n", data.f);

    return 0;

}