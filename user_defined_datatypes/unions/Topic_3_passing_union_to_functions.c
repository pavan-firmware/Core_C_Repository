#include <stdio.h>

union Data {
    int i;
    float f;
};

void printUnion(union Data data);

int main(void) {

    union Data data;
    data.i = 10;
    data.f = 220.5;

    printUnion(data); // after passing data.f then data.i data will be lost because union can hold only one of its non-static data members at a time. and gets corrupted or complier float converted value for data.i by IEEE 754 standard float binary to integer reinterpretation.
    return 0;
}

void printUnion(union Data d) {
    printf("data.i : %d\n", d.i);
    printf("data.f : %.2f\n", d.f);
}