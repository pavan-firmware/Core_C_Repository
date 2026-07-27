#include <stdio.h>

int main(void) {

    // anonymous union are used to define a union without a name, allowing direct access to its members without the need for a union variable. This can be useful in certain scenarios where you want to group related data together without creating a separate union type.
    // we can't use anonymous unions in array of unions because we need to define a union type to create an array of unions. Anonymous unions are typically used for grouping related data within a single structure or for defining temporary variables, but they cannot be used as standalone types for creating arrays.
    
    // Anonymous union declaration
    union {
        int intValue;
        float floatValue;
        char charValue;
    } anonymousUnion; // Anonymous union variable, not tag or type name

    // in structure, we can use anonymous unions to group related data together without creating a separate union type. This allows for more concise and readable code when dealing with complex data structures.

    // Structure with an anonymous union
    struct {
        int id;
        union {
            int intValue;
            float floatValue;
            char charValue;
        }; // Anonymous union within the structure
    } myStruct;

    // Initialize the anonymous union with different types of data
    anonymousUnion.intValue = 42;

    // Initialize the structure with an anonymous union
    myStruct.id = 1;
    myStruct.intValue = 100; // Accessing the anonymous union member directly


    // accessing and printing values
    printf("Anonymous Union Values:\n");
    printf("Integer Value: %d\n", anonymousUnion.intValue);
    printf("Float Value: %.2f\n", anonymousUnion.floatValue);
    printf("Character Value: %c\n", anonymousUnion.charValue);

    // accessing and printing values from the structure with an anonymous union
    printf("\nStructure with Anonymous Union:\n");
    printf("ID: %d\n", myStruct.id);
    printf("Integer Value: %d\n", myStruct.intValue);
    printf("Float Value: %.2f\n", myStruct.floatValue);
    printf("Character Value: %c\n", myStruct.charValue);

    return 0;
}