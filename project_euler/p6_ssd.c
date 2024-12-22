#include <stdio.h>
#include <math.h>
/*
 * The sum of the squares of the first ten natural numbers is,
 * 1^2+2^2...+10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 * (1+2+...+10)^2 = 3025
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is
 * 2640
 * .
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/


int main() {
	int sum_of_squares = 0;
	int square_of_sum = 0;

	for (int i = 0; i < 101; i++) {
		sum_of_squares += pow(i,2);
		square_of_sum += i;
	}

	square_of_sum = pow(square_of_sum, 2);

	int final = square_of_sum - sum_of_squares;

	printf("Final Answer: %i", final);




	return 0;

}
