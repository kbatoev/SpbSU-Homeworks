#include <stdio.h>

int cntSize(char* line) {

	int i = 0;
	while (line[i] != '\0')
		i++;

	return i;
}

int main() {

	const int maxSize = 1000;

	char line[maxSize];
	printf("Enter a line please:\n");
	scanf("%s", line);

	int lineSize = cntSize(line);

	int i = 0;
	int j = lineSize - 1;

	while (i < j && line[i] == line[j])
	{
		i++;
		j--;
	}

	if (i >= j)
		printf("Yes, line is a palindrome\n");
	else
		printf("No, line isn't a palindrome\n");

	return 0;
}