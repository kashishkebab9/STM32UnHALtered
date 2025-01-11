#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec) {
  printf("Total sec: %li \n", total_sec);

  *hr = total_sec / 3600;
  total_sec = total_sec - (*hr * 3600);
  *min = total_sec / 60 ;
  total_sec = total_sec - (*min * 60);
  *sec = total_sec;

  printf("hr: %d \n", *hr);
  printf("min: %d \n", *min);
  printf("sec: %d \n", *sec);

}

int main() {

  int hr, min, sec;
  int *hr_p, *min_p, *sec_p;

  hr_p = &hr;
  min_p = &min;
  sec_p = &sec;
  long total_sec = 20000;

  split_time(total_sec, hr_p, min_p, sec_p);

  return 0;
}
