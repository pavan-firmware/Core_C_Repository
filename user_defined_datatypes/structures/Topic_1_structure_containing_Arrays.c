#include<stdio.h>
#include<string.h>


int main(void){
    struct Student
    {
        int id;
        char name[20];
    };

    struct Student s1;

    struct Student s2 = { 28, "sai" }; // initializing the structure variable s2
    // note: we can initialize the structure variable at the time of declaration
    // we can initialize strings in the structure variable using double quotes directly
    // but we cannot initialize the structure variable after declaration
    // note: we can also initialize the structure variable using designated initializers

    struct Student s3 = { .name = "arya", .id = 29  }; 
    // initializing the structure variable s3 using designated initializers
    // order of the members does not matter when using designated initializers

    s1.id = 27;
    strcpy(s1.name, "pavan"); // copying the string "pavan" into the name array
    // note: we cannot assign a string directly to an array, we need to use strcpy function

    printf("%d\n", s1.id); // accessing the id variable
    printf("%s\n", s1.name); // accessing the name array
    printf("%c\n", s1.name[2]); // accessing the 3rd character of the name array

    printf("%d\n", s2.id); // accessing the id variable
    printf("%s\n", s2.name); // accessing the name array
    printf("%c\n", s2.name[2]); // accessing the 3rd character of the name array

    printf("%d\n", s3.id); // accessing the id variable
    printf("%s\n", s3.name); // accessing the name array
    printf("%c\n", s3.name[2]); // accessing the 3rd character of the name array

    return 0;
}