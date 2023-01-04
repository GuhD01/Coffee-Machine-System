#include "mylib.h"
#include <time.h>

extern time_t timer;

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
            timer = time(NULL); 
        } else if (input == INPUT_OFF){
            *state = OFF;
        } else {
            *state = WAITING;
        }
    } else if (*state == BREWING || *state == DISPENSING){
        if (time(NULL) - timer > 10){
            if (*state == BREWING){
                *state = DISPENSING;
                timer = time(NULL); 
            } else if (*state == DISPENSING){
                *state = WAITING;
                timer = time(NULL); 
            }
        }
    }
}



const char *get_state_string(int state) {
  if (state == OFF) {
    return "off";
  } else if (state == WAITING) {
    return "waiting";
  } else if (state == BREWING) {
    return "brewing";
  } else if (state == DISPENSING) {
    return "dispensing";
  }
  return "unknown";
}
