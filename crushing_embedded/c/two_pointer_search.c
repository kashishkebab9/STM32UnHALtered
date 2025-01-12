#include <stdio.h>
#include "sorting.c"

int two_pointer_search(int element_to_find, int* arr, int size) {

  int low_ind, high_ind;

  low_ind = 0;
  high_ind = size - 1;

  int found_element = 0;

  while (found_element == 0) {
    if (arr[low_ind] == element_to_find) {
      printf("Found! Index: %d\n", low_ind);
      return low_ind;
    } else {
      low_ind++;
    }
    if (arr[high_ind] == element_to_find) {
      printf("Found! Index: %d\n", high_ind);
      return high_ind;
    } else {
      high_ind--;
    }

    if(arr[high_ind] == arr[low_ind]) {
      printf("Not found!");
      return -1;
    }

  }

}


int main() {


  int arr[] = {
    84735, 592834, 28476, 391736, 145623, 972485, 238745, 67289, 384927, 918374,
    745827, 302849, 584920, 173849, 290384, 948203, 284730, 561839, 723890, 184927,
    284637, 902384, 467281, 104738, 283745, 876924, 129083, 294827, 764930, 847392,
  };

  selectionSort(arr, 30);
  two_pointer_search(84735, arr, 30);

  return 0;

}
