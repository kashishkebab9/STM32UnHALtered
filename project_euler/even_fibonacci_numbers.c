#include <stdio.h>
#define THRESHOLD 4000000

int main() {

  int val_1, val_2, even_sum_counter;
  val_1 = 1;
  val_2 = 2;

  even_sum_counter = 2;
  
  while (val_1 < THRESHOLD && val_2 < THRESHOLD) {
    val_1 = val_1 + val_2;
    val_2 = val_1 + val_2;

    if (val_1 % 2 == 0) {
      even_sum_counter += val_1;
    }

    if (val_2 % 2 == 0) {
      even_sum_counter += val_2;
    }
  }

  printf("%d\n", even_sum_counter);


  

  return 0;
}
