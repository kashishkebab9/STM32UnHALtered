#include <stdio.h>

int main() {
  int counter = 0;

  for (int i = 0; i < 1000; i++) {
    if ((i % 3 == 0) || (i % 5 == 0)) {
      counter += i;
    }
  }

  printf("%d\n", counter);


  return 0;
}
