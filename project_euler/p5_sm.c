// 2520 is the smallest number that can be divided by each of the numbers from to
// without any remainder.

// What is the smallest positive number that is evenly divisible by all of the numbers from
// 1 to 20 ?

#include <stdio.h>
#include <stdbool.h>

int main() {
  bool found_val = false;
  bool break_ = false;
  int counter = 1;

  while (!found_val) {

    for (int i = 1; i < 21; i++) {
      if (counter % i != 0 ) {
        
        break_ = true; 
        break;
      } 
    }

    if(break_ == true) {
      break_ = false;
      counter++;
    } else {
      found_val = true;
    }

  }
  printf("Val: %d", counter);
  

  return 0;
}
