/*
scope: block/file
storage duration: static/static
lifetime: program ends/program ends
linkage: no/internal linkage
*/

#include <stdio.h>

// private global variable scope only this file access and modify and use fun() inside current file only no external files access
// prevent from extern by mistake usage or variable name matched
static char task_done = '1';

void debounce_button_state(void);

int main(void) {

    debounce_button_state(); // 0
    debounce_button_state(); // 1

    // without static no prev value is store automatic destroy after fun() end from the stack
    //0
    //0

    return 0;
}

void debounce_button_state(void){
    // without static no prev value is store automatic destroy after fun() end from the stack
    // only create variable once at fun() start and use that first created one all time no variable creation all time
    static char btn_state = '0';  // block within the fun() to other block use this usecase: preserve the data 
    printf("btn_state : %c",btn_state);
    btn_state = btn_state == '0' ? '1' : '0'; 
}
