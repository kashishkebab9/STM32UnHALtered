#include <stdio.h>
#include <stdlib.h> // need this for malloc

int main() {

  int val = 0;
  int * val_ptr = &val;

  // some_function(val_ptr)
  
  /* The example above shows that, in order to pass a ptr into a function, I have to first
   * declare an int, then set the int address to the val_ptr
   * To make life easier, we can dynamically allocate this memory
  */

  int *val_ptr2 = (int *)malloc(sizeof(int));
  // (type cast)malloc(sizeof(type))

  // just make sure to free this after finishing use
  free(val_ptr2);





  return 0;
}
