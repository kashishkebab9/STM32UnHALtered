#include <stdio.h>
#include <limits.h>

// File for implementation on different sorting algorithms all on C Arrays
int* insertionSort(int* outputArray, int size) {
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      int val = outputArray[i];
      int j = i-1;
      while (val < outputArray[j]) {
        if (j == 0) {
          break;
        }
        j--;
      }
      int j_val = outputArray[j];
      // shift all elements between j and i by 1:
      for (int k = i- 1; k > j; k--) {
        outputArray[k + 1] = outputArray[k];
      }
      
      if (j == 0 && val < j_val ) {
        outputArray[0] = val;
        outputArray[1] = j_val;
        
      } else {
        outputArray[j + 1] = val;
      }
    }
  }
  return outputArray;
}

void selectionSort(int* inputArray, int size) {
  // takes the most minimum value and appends to the front
  for (int i = 0; i < size; i++) {
    int min_val = INT_MAX;
    int j_ind = 0;
    for (int j= i; j < size; j++) {
      if (inputArray[j] < min_val) {
        min_val = inputArray[j];
        j_ind = j;
      }
    }
    // min_val now contains the most minimum value in the sequence
    // swap these two indices
    inputArray[j_ind] = inputArray[i];
    inputArray[i] = min_val;
    
  }
}

int main() {

  int arr[] = {
    84735, 592834, 28476, 391736, 145623, 972485, 238745, 67289, 384927, 918374,
    745827, 302849, 584920, 173849, 290384, 948203, 284730, 561839, 723890, 184927,
    284637, 902384, 467281, 104738, 283745, 876924, 129083, 294827, 764930, 847392
  };
  // insertionSort(arr, 30);
  selectionSort(arr, 30);
  return 0;
}
