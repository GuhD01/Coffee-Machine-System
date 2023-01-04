#include "mylib.h"
#include <time.h>

void update_coffee_machine(int *state, int input){
    if (*state == OFF){
        if (input == INPUT_ON){
            *state = WAITING;
        } else {
            *state = OFF;
        }
    } else if (*state == WAITING){
        if (input == INPUT_START_PROCESS){
            *state = BREWING;
        } else if (input == INPUT_OFF){
            *state = OFF;
        } else {
            *state = WAITING;
        }
    } else if (*state == BREWING){
        if (input == INPUT_TIMER){
            *state = DISPENSING;
        } else if (input == INPUT_OFF){
            *state = OFF;
        } else {
            *state = BREWING;
        }
    } else if (*state == DISPENSING){
        if (input == INPUT_TIMER){
            *state = WAITING;
        } else if (input == INPUT_OFF){
            *state = OFF;
        } else {
            *state = DISPENSING;
        }
    }
}

const char* get_state_string(int state){
    if (state == OFF){
        return "off";
    } else if (state == WAITING){
        return "waiting";
    } else if (state == BREWING){
        return "brewing";
    } else if (state == DISPENSING){
        return "dispensing";
    } else {
        return "unknown";
    }
}
