#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	const int maxSize = 1000;

	cout << "Enter a file name, please:" << endl;
	char fileName[maxSize];
	cin >> fileName;

	FILE *file = fopen(fileName, "r");
	if (file == NULL)
	{
		cout << "There is not such a file" << endl;
		return 0;
	}
	
	bool isBigComment = false;
	char *line = new char[maxSize];
	while (fgets(line, maxSize, file))
	{
		int current = 0;
		bool isTextString = false;
		bool isComment = false;
		int i = 0;
		char *comment = new char[maxSize];
		while (line[current] != '\0')
		{
			if (isBigComment)
			{
				if (line[current] == '*' && line[current + 1] == '/')
				{
					isBigComment = false;
					current++;
				}
			}
			else
			if (isTextString)
			{
				while (line[current] != '"')
					current++;
				isTextString = false;
			}
			else
			if (isComment)
			{
				while (line[current] != '\0')
					comment[i++] = line[current++];
				if (comment[i - 1] == '\n')
					i--;
				comment[i] = '\0';
				current--;
				cout << comment << endl;
				isComment = false;
			}
			else
			{
				if (line[current] == '/' && line[current + 1] == '/')
				{
					isComment = true;
					comment[i++] = '/';
				}
				else
				if (line[current] == '/' && line[current + 1] == '*')
				{
					isBigComment = true;
					current++;
				}
				else
				if (line[current] == '"')
					isTextString = true;
			}
			current++;
		}
		delete[] comment;
	}	

	fclose(file);
	delete[] line;

	return 0;
}