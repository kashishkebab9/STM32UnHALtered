#include <stdio.h>

int extern_example = 42;

void print_extern_example(int a) {
  printf("Extern input arg: %d\n", a);
  printf("Extern Example: %d\n", extern_example);
}


