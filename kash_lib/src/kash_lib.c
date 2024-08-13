#include <stdio.h>
#include "kash_lib.h"
#include "string.h"

int test_lsb_function() {
  char* input_char = "a";
  char output_byte[9];
  char* output_byte_string = &output_byte[0];
  kl_char_to_byte_string_lsb(input_char, output_byte_string);

  //DEBUG
  // for (int i = 0; i < CHAR_BIT; i++) {
  //   printf("%c", output_byte[i]);
  // }

  printf("\nTest 1 [CHAR_TO_BIN_LSB] Result: ");
  if (strcmp(output_byte, "10000110") == 0) {
    printf("Passed");
    return 0;
  } else {
    printf("Failed");
    return 1;
  }
}

int test_msb_function() {
  char* input_char = "a";
  char output_byte[9];
  char* output_byte_string = &output_byte[0];
  kl_char_to_byte_string_msb(input_char, output_byte_string);

  //DEBUG
  // for (int i = 0; i < CHAR_BIT; i++) {
  //   printf("%c", output_byte[i]);
  // }

  printf("\nTest 2 [CHAR_TO_BIN_MSB] Result: ");
  if (strcmp(output_byte, "01100001") == 0) {
    printf("Passed");
    return 0;
  } else {
    printf("Failed");
    return 1;
  }

}

int main() {
  printf("Initiating Testing...\n");
  test_lsb_function();
  test_msb_function();


  return 0;
}
