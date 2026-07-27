#include <stdio.h>

int main(void) {
    
    union Data {
        int intValue;
        float floatValue;
        char charValue;
    };

    union Data dataArray[3];

    // Initialize the union array with different types of data
    dataArray[0].intValue = 42;
    dataArray[1].floatValue = 3.14f;
    dataArray[2].charValue = 'A';

    // Access and print the values from the union array
    printf("Union Array Values:\n");
    printf("Integer Value: %d\n", dataArray[0].intValue);
    printf("Float Value: %.2f\n", dataArray[1].floatValue);
    printf("Character Value: %c\n", dataArray[2].charValue);
    

    return 0;
}