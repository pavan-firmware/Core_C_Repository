#include <stdio.h>

int main(void) {
    
    // in enum if we dont assign values to constants then in the enum default behaviour is start values from 0
    // enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
    // here by default : enum week { Sunday = 0, Monday = 1, ... };

    // explicit value assignment
    enum STATUS {SUCCESS = 100, ERROR, NETWORK}; //specific constant mention then remaining values continious EX: 100,101,102...
    enum ErrorCode {Code_SUCCESS = 0, FILE_ERROR = 100, NETWORK_ERROR = 200}; // all constants are explicit values by user
    enum Protocol {OK, BUSY, ERROR = 5, TIMEOUT = 10}; // automatic and explicit combination

    enum STATUS status;
    status = ERROR;

    enum ErrorCode error;
    error = FILE_ERROR;

    printf("status : %d\n", status);
    printf("error : %d", error);


    return 0;
}