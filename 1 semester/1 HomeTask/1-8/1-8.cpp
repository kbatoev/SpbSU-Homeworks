#include <stdio.h>

int factorial(int number) {

	if (number == 1)
		return 1;
	else
		return number * factorial(number - 1);
}


int main() {

	int number = 0;
	printf("Enter an integer number:\n");
	scanf("%d", &number);

	int firstAns = 1;
	for (int i = 2; i <= number; i++)
		firstAns *= i;

	int secondAns = factorial(number);

	if (firstAns == secondAns)
		printf("The factorial is %d \n", firstAns);
	else
		printf("Something wrong\n");


	return 0;
}