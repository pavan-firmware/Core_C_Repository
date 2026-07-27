#include <stdio.h>

union Data {
    int i;
    float f;
};

// Important: function data type must be same as return type of function. In this case, the function `create_union` returns a union of type `Data`, so the return type of the function is also `union Data`.
union Data create_union(){
    union Data d;
    d.i = 10;
    return d;
}


int main(void) {

    union Data data = create_union(); // returned union from function() is stored in variable `data` of type union Data. The function `create_union` returns a union of type `Data`, which is then assigned to the variable `data`. This allows us to access the members of the union `data` in the main function.
    printf("data.i : %d\n", data.i);

    return 0;
}