#include <stdio.h>

int main() {

	const int maxSize = 1000;

	char line[maxSize];

	printf("Enter a line, please: \n");
	scanf("%s", line); // ввод строки

	int balance = 0; // баланс скобок

	int i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '(')
			balance++;
		if (line[i] == ')')
			if (balance) // если баланс больше 0
				balance--;
			else
			{
				printf("Rule of nesting of brackets isn't executed\n");
				return 0;
			}
		i++;
	}

	if (balance)
		printf("Amount of left brackets is more than right ones\n");
	else
		printf("Entered line is correct\n");

	return 0;
}