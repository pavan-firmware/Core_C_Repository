/*  1) it is mainly used to store different data types in the same memory location. It can hold only one
    of its non-static data members at a time. 

    2) The size of the union is determined by the size of its largest member. 

    3) it is the alternative to structures. It is used to save memory when we want to store different data types in the same memory location. 
.
*/
#include<stdio.h>
#include<string.h>

int main() {

    // A union is a user-defined data type in C that allows storing different data types in the same memory location. It can hold only one of its non-static data members at a time. The size of the union is determined by the size of its largest member.
    union Data {
        int i;
        float f;
        char str[20]; // A union can have multiple members, but only one member can contain a value at any given time. The size of the union is equal to the size of its largest member. In this case, the largest member is the character array `str`, which has a size of 20 bytes. Therefore, the size of the union will be 20 bytes.
    };

    union Data data;
    union Data data1 = {100}; // only one member can be initialized at a time. Initializing the union member `i` with the value 100. This will set the value of `i` to 100 and the other members (`f` and `str`) will be uninitialized.

    //union Data data1 ={100, 220.5, "C Programming"}; // This will cause a compilation error because only one member can be initialized at a time. The correct way to initialize a union is to provide a value for only one member.

    data.i = 10; // union member assignment.
    printf("data.i : %d\n", data.i);

    data.f = 220.5; // Assigning a float value to the union member `f`. This will overwrite the previous value of `i` since both members share the same memory location.
    printf("data.f : %.2f\n", data.f);

    strcpy(data.str, "C Programming"); // Assigning a string value to the union member `str`. This will overwrite the previous value of `f` since both members share the same memory location.
    printf("data.str : %s\n", data.str);

    return 0;
}