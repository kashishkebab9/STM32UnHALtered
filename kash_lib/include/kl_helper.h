#include <stdio.h>
#include <limits.h>

char* kl_char_to_byte_string_lsb(char *input_char, char* output_byte) {
  for (int i = 0; i < CHAR_BIT; i++) {
    if (*input_char >> i & 1) {
      output_byte[i]='1';
    } else {
      output_byte[i]='0';
    }
  }
  output_byte[CHAR_BIT] = '\0';
  return output_byte; 
}

char* kl_char_to_byte_string_msb(char *input_char, char* output_byte) {
  for (int i = 0; i < CHAR_BIT; i++) {
    if (*input_char << i & (1<<7)) {
      output_byte[i]='1';
    } else {
      output_byte[i]='0';
    }
  }
  output_byte[CHAR_BIT] = '\0';
  return output_byte; 
}

