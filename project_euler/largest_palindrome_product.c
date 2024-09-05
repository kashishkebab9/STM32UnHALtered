#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two -digit numbers is
9009 = 91*99
Find the largest palindrome made from the product of two 3-digit numbers.
*/

int num_places(int n) {
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7;
    if (n < 100000000) return 8;
    if (n < 1000000000) return 9;
    return 10;
}

bool is_palindrome(int input) {
    int num_pl = num_places(input);
    char int_to_str[num_pl];
    sprintf(int_to_str, "%d", input);
    char int_to_str_reversed[num_pl];
    for (int i = 0; i < num_pl; i++) {
        int_to_str_reversed[num_pl-1-i] = int_to_str[i];
    }
    // printf("int_to_str: %s \n", int_to_str);
    // printf("int_to_str_reversed: %s \n", int_to_str_reversed);

    if (strcmp(int_to_str,int_to_str_reversed) == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int palindrome_num = 0;
    for (int i = 999; i >0 ; i--) {
        for (int j = 999; j>0; j--) {
            if (is_palindrome(i*j)) {
                if ((i*j) > palindrome_num) {
                    palindrome_num = i*j;
                    printf("i: %d, j: %d\n", i, j);
                    printf("product: %d\n", i* j);
                }
            }
            
        }
    }

    return 0;
}