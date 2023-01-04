#ifndef MYLIB_H
#define MYLIB_H

#define OFF 0
#define WAITING 1
#define BREWING 2
#define DISPENSING 3

#define INPUT_OFF 0
#define INPUT_ON 1
#define INPUT_START_PROCESS 2


void update_coffee_machine(int *state, int input);
const char *get_state_string(int state);

#endif
