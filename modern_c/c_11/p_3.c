#include <stdio.h>
void avg_sum(double a[], int n, double* avg, double* sum) {
  for (int i = 0; i < n; i++) {
    *sum += a[i];
  }

  *avg = *sum / n;
  printf("sum: %f", *sum);
  printf("sum: %f", *avg);
}

int main() {
  double a[] = {10.0, 12.0, 120.0, 18.0};
  int n = sizeof(a)/sizeof(double);

  double avg = 0;
  double sum = 0;

  double *avg_p = &avg;
  double *sum_p = &sum;

  avg_sum(a, n, avg_p, sum_p);
  return 0;
}
