#include <stdio.h>
#include "sorting.c"

int binary_search(int element_to_find, const int* arr, int size){

  int low_ind, high_ind;

  low_ind = 0;
  high_ind = size - 1;

  int b_element_not_found = 0;
  int ind_to_check;

  while (b_element_not_found == 0) {
    // check the middle index between high and low
    ind_to_check = (int)((high_ind + low_ind)/2);

    if (element_to_find == arr[ind_to_check]) {
      printf("Answer: %d", ind_to_check);
      return ind_to_check;

    }

    if (element_to_find > arr[ind_to_check]) {
      low_ind = ind_to_check;
    } else {
      high_ind = ind_to_check;
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
  binary_search(84735, arr, 30);




  return 0;
}
