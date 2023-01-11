#include "mylib.h"

void states(int s0, int s1, int f0, int f1, int* S0, int* S1) {
  *S0 = !s1 && !f0 || !s0 && !f0 && !f1 || !s0 && !f0 && f1 || s1 && f0 && !f1;
  *S1 = s0 && s1 || !s0 && !f0 && !f1 && s1 || s1 && f0 && f1 || s0 && f0 && f1;
}


