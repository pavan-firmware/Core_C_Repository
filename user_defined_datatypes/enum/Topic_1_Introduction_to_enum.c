#include <stdio.h>

int main(void) {
    
    // enum is a user-defined data type in C that consists of integral constants.
    // It is used to assign names to integral constants, which makes a program easy to read and maintain.
    enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

    // if you don't assign any value to the enumerators, they will be assigned values starting from 0 by default. So, Sunday will be 0, Monday will be 1, and so on.
    
    enum week today = Sunday; 
    // enum week today = Laptop; //if you enter an not defined name like "Laptop" to it, then it give error

    // if you enter not mentioned value as integer in enum, it will may not give an error. For example, if you try to assign a value of 7 to the variable today, it accepts it without any error. But it is not a good practice to assign a value that is not defined in the enum.

    // then why use enum? The main advantage of using enum is that it makes the code more readable and maintainable. Instead of using magic numbers, you can use meaningful names for the constants.
    
    printf("Today is %d\n", today); // Output: Today is 1 (since Monday is the second enumerator, and enumeration starts from 0)

    return 0;
}