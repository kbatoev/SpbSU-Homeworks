#include <stdio.h>

double countDegree(double number, int power) {

	if (power == 1)
		return number;

	double half = countDegree(number, power / 2);
	double result = half * half;

	if (power % 2) 
		result *= number;
	
	return result;
}


int main() {


	double number = 0;
	int power = 0;
	printf("Enter two numbers A and N: \n");
	scanf("%lf %d", &number, &power);
	
	double answer = 0;
	if (number) 
	{
		if (power)
		{
			bool isPositive = true;
			if (power < 0)
			{
				isPositive = false;
				power *= -1;
			}
			answer = countDegree(number, power);
			if (!isPositive)
				answer = 1.0 / answer;
		}
		else
			answer = 1.0;
	}

	printf("A^N = ""%lf""\n", answer);


	return 0;
}