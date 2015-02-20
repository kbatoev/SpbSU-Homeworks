#include <iostream>
#include <stdio.h>

using namespace std;

void initialize(bool *letters)
{
	const int alphabet = 26;
	for (int i = 0; i < alphabet; i++)
		letters[i] = false;
}

bool isLetter(char letter)
{
	return (letter >= 'a' && letter <= 'z' || letter >= 'A' && letter <= 'Z'); 
}

int getCode(char letter)
{
	if (letter <= 'Z')
		return letter - 'A';
	else
		return letter - 'a';
}


int main()
{
	const int alphabet = 26;
	const int maxSize = 1000;
	const char end = '\0';
	const char space = ' ';

	cout << "Enter a file name and I show you its content: " << endl;
	char *fileName = new char[maxSize];
	cin >> fileName;


	FILE *file = fopen(fileName, "r");

	if (file == NULL)
		cout << "There is not such a file" << endl;
	else
	{
		cout << "These are words of the text:" << endl;

		char *line = new char[maxSize];
		while (fgets(line, maxSize, file))
		{	
			int current = 0;
			while (line[current] != end)
			{
				bool letters[alphabet];
				initialize(letters);

				int i = 0;
				char *word = new char[maxSize];
				while (isLetter(line[current]))
				{
					char letter = line[current];
					int code = getCode(letter);
					
					if (!letters[code])
					{
						word[i++] = line[current];
						letters[code] = true;
					}
					current++;
				}

				word[i] = end;
				cout << word << space;
				delete[] word;
				if (line[current] != end)
					current++;
			}
			cout << endl;
		}
		delete[] line;
	}

	delete[] fileName;

	return  0;
}