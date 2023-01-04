#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "mylib/mylib.h"

void blue() {
    printf("\033[0;34m");
}

void reset() {
    printf("\033[0m");
}

void green() {
    printf("\033[0;32m");
}

void red() {
    printf("\033[0;31m");
}

int main(void){
    int state = OFF;
    time_t start_time = time(NULL);
    while(true){
        int input;
        printf("0 for off\n1 for on\n2 for start process \n3 for timer\nEnter Input:  ");
        scanf("%d", &input);

        if (input == INPUT_TIMER) {
            start_time = time(NULL);
        }

        update_coffee_machine(&state, input);

        if(state == OFF){
          system("clear");
          printf("Coffee machine is %s.\n\n", get_state_string(state));
        }

        if(state == WAITING){
          system("clear");
          green();
          printf("Coffee machine is %s.\n\n", get_state_string(state));
          reset();
        }

        if(state == BREWING){
          system("clear");
          blue();
          printf("Coffee machine is %s.\n\n", get_state_string(state));
          reset();
        }

        if(state == DISPENSING){
          system("clear");
          red();
          printf("Coffee machine is %s.\n\n", get_state_string(state));
          reset();
        }

        if (time(NULL) - start_time >= 10) {
            input = INPUT_TIMER;
            update_coffee_machine(&state, input);
        }
    }
    return 0;
}
