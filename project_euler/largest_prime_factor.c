#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main() {

  uint64_t input = 600851475143;
  printf("Input Val: %llu\n", input);

  int found_prime = 0;
  uint64_t prime_val = 0;
  for (int64_t i = 2; i < input; i++) {
    if (input % i == 0) {
      printf("Found Prime\n");
      printf("i: %llu\n", i);
      found_prime = 1;
      if (i > prime_val) {
        prime_val = i;
      }
    }
  }

  if (found_prime == 1)
    printf("%d", prime_val);

  return 0;
}
