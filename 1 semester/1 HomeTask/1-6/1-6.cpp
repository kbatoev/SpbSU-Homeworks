#include <stdio.h>

int main() {

	const int first = 0;
	const int second = 1;
	const int maxLines = 2;
	const int maxSize = 1000;
	
	char line[maxLines][maxSize];

	printf("Enter two lines S and S1: \n");
	for (int i = 0; i < maxLines; i++)
		scanf("%s", line + i);

	int answer = 0;
	for (int i = 0; line[first][i] != '\0'; i++)
	{
		int k = i;
		int j = 0;
		while (line[second][j] == line[first][k])
		{
			k++;
			j++;
			if (line[second][j] == '\0')
			{
				answer++;
				break;
			}
			if (line[first][k] == '\0')
				break;
		}
	}
	printf("There're are %d S1 in S\n", answer);


	return 0;
}