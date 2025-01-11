#include <stdio.h>
#include <limits.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest) {
  *largest = INT_MIN;
  int largest_index;

  for (int i = 0; i < n; i++) {
    if (a[i] > *largest) {
      *largest = a[i];
      largest_index = i;
    }
  }

  for (int i = 0; i < n; i++) {
    if (a[i] > *second_largest && i != largest_index) {
      *second_largest = a[i];
    }
  }

  printf("largest: %d", *largest);
  printf("second_largest: %d", *second_largest);

}


int main() {

  int a[] = {10, 20, 30, 40, 10};
  int n = sizeof(a)/sizeof(int) ;

  int largest, second_largest, *l_p, *s_p;
  l_p = &largest;
  s_p = &second_largest;

  find_two_largest(a, n, l_p, s_p);

  return 0;
}
