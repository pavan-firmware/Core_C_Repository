#include <stdio.h>

int main(void){

    struct Student
    {
        int id;
        char name[20];
        int marks[4];
    };

    struct Student students[3] = { { 1, "John", { 85, 90, 78, 92 } }, { 2, "Jane", { 88, 85, 80, 87 } }, { 3, "Jim", { 92, 88, 90, 85 } } };
    // initializing an array of structures with 3 elements

    // accessing the elements of the array of structures
   

    printf("Student 1\n");
    printf("ID: %d\n", students[0].id);
    printf("Name: %s\n", students[0].name); // accessing name string from the structure

    // by normal method
    printf("Marks: %d\n", students[0].marks[0]); // nested arrays access

    // by using a loop method
    printf("Marks: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", students[0].marks[i]);  
    }
    printf("\n");

    return 0;
}