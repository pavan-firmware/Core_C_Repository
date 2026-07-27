#include <stdio.h>

int main(void){

    struct Address
    {
        int pinCode;
        char city[20];
        char state[20];
    };
    
    struct Student
    {
        int id;
        char name[20];
        struct Address address; // nested structure
    };

    struct Student students[3] = { { 1, "John", { 123456, "New York", "NY" } }, { 2, "Jane", { 654321, "Los Angeles", "CA" } }, { 3, "Jim", { 987654, "Chicago", "IL" } } };
    // initializing an array of structures with 3 elements
    // here the structure Student contains another structure Address as a member 
    // so we use the another structure inside the structure Student {... { 123456, "New York", "NY" } } to initialize the nested structure Address

    students[0].address.pinCode = 456786; // modify or create by like this we can access the members of the nested structure using the dot operator after variable name created.

    // so we can access the members of the nested structure using the dot operator
    
    printf("Student 1\n");
    printf("ID: %d\n", students[0].id);
    printf("Name: %s\n", students[0].name); // accessing name string from the structure
    printf("Pin Code: %d\n", students[0].address.pinCode); // accessing pinCode from the nested structure using the dot operator to access one step inside the structure Student member address and then using the dot operator again to access the pinCode member of the nested structure Address same as all other nested structure members
    printf("City: %s\n", students[0].address.city);
    printf("State: %s\n", students[0].address.state);


    return 0;
}