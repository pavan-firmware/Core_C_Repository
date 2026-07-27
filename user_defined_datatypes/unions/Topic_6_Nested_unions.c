#include <stdio.h>

int main(void) {
    
    // here NestedUnion represents either an int or a float or an inner union that can hold either a char or a double.
    union NestedUnion {
        int intValue;
        float floatValue;
        union {
            char charValue;
            double doubleValue;
        } innerUnion; // anonymous inner union
    } myUnion;

    // or separately define the inner union and then use it in the outer union

    union childUnion {
        char charValue;
        double doubleValue;
    }; // Define the inner union separately

    union NestedUnion2 {
        int intValue;
        float floatValue;
        union childUnion innerUnion; // Use the separately defined inner union
    } myUnion2;

    // Initialize the nested union
    myUnion.intValue = 10;
    myUnion2.innerUnion.charValue = 'A';


    // Access the nested union members
    printf("Nested Union 1:\n");
    printf("Integer value: %d\n", myUnion.intValue);

    printf("Nested Union 2:\n");
    printf("Character value: %c\n", myUnion2.innerUnion.charValue);


    return 0;
}