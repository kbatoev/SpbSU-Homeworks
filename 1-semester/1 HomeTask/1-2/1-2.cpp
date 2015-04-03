#include <stdio.h>

void makePositive(int* number, int* cntNegs) {
	if (*number < 0)
	{
		*(number) *= -1;
		*(cntNegs) += 1;
	}
}

int main() {

	printf("Enter divident and divisor: \n");
	int divident = 0;
	int divisor = 1;
	scanf("%d %d", &divident, &divisor);

	if (divisor)
	{
		int cntNegs = 0;
		makePositive(&divident, &cntNegs);
		makePositive(&divisor, &cntNegs);


		bool isPositive = true;
		if (cntNegs % 2)
			isPositive = false;
		
		int quotient = 0;
		while (divident > quotient * divisor)
			quotient++;
		if (quotient * divisor > divident)
			quotient--;


		if (!isPositive)
			quotient *= -1;
		
		printf("The quotient of division:\nA / B = %d\n", quotient);
	}
	else
	{
		printf("Divisor can not be 0 !\n");
	}

	return 0;
}