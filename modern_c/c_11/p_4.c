#include <stdio.h>

void swap(int *p, int* q) {
  int temp = *p;

  printf("p: %d\n", *p);
  printf("q: %d\n", *q);

  *p = *q;
  *q = temp;

  printf("p: %d\n", *p);
  printf("q: %d\n", *q);
}

int main() {

  int p, q, *p_p, *q_p;
  p = 10;
  q = 15;
  p_p = &p;
  q_p = &q;

  swap(p_p, q_p);
  return 0;
}
