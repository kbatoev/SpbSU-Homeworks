#include <stdio.h>

int main() {

	printf("Enter one number x:\n");
	int number = 0;
	scanf("%d", &number);

	int square = number * number;
	int answer = (square + 1) * (square + number);

	printf("The expression x^4 + x^3 + x^2 + x = %d\n", answer);

	return 0;
}