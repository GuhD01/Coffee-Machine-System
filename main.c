#include "mylib/mylib.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t timer = 0; 

void blue() { printf("\033[0;34m"); }

void reset() { printf("\033[0m"); }

void green() { printf("\033[0;32m"); }

void red() { printf("\033[0;31m"); }

int main(void) {
  int state = OFF;
  while (true) {
    int input;
    if (state == BREWING || state == DISPENSING) {
      input = -1; 
    } else {
      printf("0 for off\n1 for on\n2 for start process \nEnter Input:  ");
      scanf("%d", &input);
    }

    update_coffee_machine(&state, input);

    while (state == BREWING || state == DISPENSING) {
      if (state == BREWING) {
        system("clear");
        blue();
        printf("Coffee machine is "
               "%s.\n\n---------------\n---------------\n----Brewing----\n-----"
               "----------\n---------------\n\n",
               get_state_string(state));
        printf("Time remaining until brewing is finished: \n");
        int i;
        for(i=10;i>=0;i--)
        {
            printf("%d\n",i);
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
        printf("Time remaining until dispensing is finished: \n");
        int i;
        for(i=10;i>=0;i--)
        {
            printf("%d\n",i);
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


