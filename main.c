#include "mylib/mylib.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OFF 0
#define WAITING 1
#define BREWING 2
#define DISPENSING 3

time_t timer = 0; 

void blue() { printf("\033[0;34m"); }

void reset() { printf("\033[0m"); }

void green() { printf("\033[0;32m"); }

void red() { printf("\033[0;31m"); }

const char *get_state_string(int state) {
  switch (state) {
  case OFF:
    return "OFF";
  case WAITING:
    return "WAITING";
  case BREWING:
    return "BREWING";
  case DISPENSING:
    return "DISPENSING";
  default:
    return "INVALID";
  }
}

void update_coffee_machine(int* state, int input) {
  int s0 = *state / 2;
  int s1 = *state % 2;
  int F0 = input / 2;
  int F1 = input % 2;

  if (*state == OFF && input == 0) {
    *state = OFF;
  } else if (*state == OFF && input == 1) {
    *state = WAITING;
  } else if (*state == WAITING && input == 2) {
    *state = BREWING;
  } else if (*state == BREWING && input == 3) {
    *state = DISPENSING;
  } else if (*state == DISPENSING && input == 3) {
    *state = WAITING;
  } else if (*state == WAITING && input == 0) {
    *state = OFF;
  }
}

int main(void) {
  time_t timer = 0;
  int state = OFF;
  while (true) {
    int input;
    printf("0 for off\n1 for on\n2 for start process \nEnter Input:  ");
    scanf("%d", &input);
    update_coffee_machine(&state, input);

    while (state == BREWING || state == DISPENSING) {
      if (state == BREWING) {
        system("clear");
        blue();
        printf("Coffee machine is "
               "%s.\n\n---------------\n---------------\n----Brewing----\n-----"
               "----------\n---------------\n\n",
               get_state_string(state));
        printf("Time remaining until automatic transition: \n");
        int i;
        for (i = 10; i >= 0; i--) {
          printf("%d\n", i);
          sleep(1);
        }
        reset();
      } else if (state == DISPENSING) {
        system("clear");
        red();
        printf("Coffee machine is "
               "%s.\n\n---------------\n---------------\n---Dispensing--\n-----"
               "----------\n---------------\n\n",
               get_state_string(state));
        printf("Time remaining until automatic transition: \n");
        int i;
        for (i = 10; i >= 0; i--) {
          printf("%d\n", i);
          sleep(1);
        }
        reset();
      }
      if (time(NULL) - timer > 10) {
        if (state == BREWING) {
          state = DISPENSING;
          timer = time(NULL); 
        } else if (state == DISPENSING) {
          state = WAITING;
          timer = time(NULL);
        }
      }
    }

    if (state == OFF) {
      system("clear");
      printf("Coffee machine is "
             "%s.\n\n---------------\n---------------\n------OFF------\n-------"
             "--------\n---------------\n\n",
             get_state_string(state));
    }
    if (state == WAITING) {
      system("clear");
      green();
      printf("Coffee machine is "
             "%s.\n\n---------------\n---------------\n----Waiting----\n-------"
             "--------\n---------------\n\n",
             get_state_string(state));
      reset();
    }
  }
  return 0;
}
