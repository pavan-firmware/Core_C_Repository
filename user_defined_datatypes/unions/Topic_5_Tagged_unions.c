// Tagged unions are a type of union that includes an additional member, often called a "tag" or "discriminator," which indicates which member of the union is currently active. This allows for safer and more structured access to the union's members, as the tag can be used to determine which member is valid at any given time.

// basically tagged unions are the combination of union and struct. It is used to store different data types in the same memory location, but with an additional member that indicates which member of the union is currently active. This allows for safer and more structured access to the union's members, as the tag can be used to determine which member is valid at any given time.

// example of tagged union in C:

#include <stdio.h>

int main(void) {
/*

1) normal way of defining tagged union without anonymous struct,enum and union. It is named struct,enum and union.

    enum Type {
        INT,
        FLOAT,
        STRING
    }; // Tag to indicate the active member

    union Data{
        int i;
        float f;
        char str[20];
    } ;

    struct TaggedUnion {
        enum Type type;
        union Data data;
    };

    struct TaggedUnion tu;
 */

 
    // Define a tagged union 
    // and this below blueprint of struct is anonymous struct,enum and union. It is not named, but it is used to define the structure of the tagged union.
    typedef struct {
        enum { INT, FLOAT, STRING } type; // Tag to indicate the active member
        union {
            int i;
            float f;
            char str[20];
        } data;
    } TaggedUnion;

    // Create an instance/variable of the tagged union
    TaggedUnion tu;

    // Assign an integer value and type
    tu.type = INT;
    tu.data.i = 10;

    // Assign a float value and type
    tu.type = FLOAT;
    tu.data.f = 3.14;

    // Assign a string value and type
    tu.type = STRING;
    snprintf(tu.data.str, sizeof(tu.data.str), "Hello, World!");

    //snprintf means "string print formatted". It is a safer version of sprintf that prevents buffer overflows by specifying the maximum number of characters to write to the destination buffer.

    // Access the active member based on the tag
    switch (tu.type) {
        case INT:
            printf("Active member is an integer: %d\n", tu.data.i);
            break;
        case FLOAT:
            printf("Active member is a float: %.2f\n", tu.data.f);
            break;
        case STRING:
            printf("Active member is a string: %s\n", tu.data.str);
            break;
    }

    return 0;
}