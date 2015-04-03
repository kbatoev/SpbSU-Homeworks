#include <iostream>

using namespace std;

void countLetters(char line[], int letters[])
{
	const char beginning = 'a';

	int currentIndex = 0;
	while (line[currentIndex] != '\0')
	{
		int letter = line[currentIndex] - beginning;
		letters[letter]++;
		currentIndex++;
	}
}


bool compareLetters(int line[], int figure[])
{
	const int maxLetter = 26;

	bool areSimilar = true;
	for (int i = 0; i < maxLetter; i++)
		if (line[i] != figure[i])
			areSimilar = false;

	return areSimilar;
}


int main()
{
	const int maxSize = 1000;
	const int maxLetter = 26;
	
	char line[maxSize];
	char figure[maxSize];

	cout << "Enter two lines, please:" << endl;
	cin >> line >> figure;

	int lineLetters[maxLetter];
	int figureLetters[maxLetter];
	for (int i = 0; i < maxLetter; i++)
	{
		lineLetters[i] = 0;
		figureLetters[i] = 0;
	}

	countLetters(line, lineLetters);
	countLetters(figure, figureLetters);


	bool areSimilar = compareLetters(lineLetters, figureLetters);
	
	if (areSimilar)
		cout << "Your lines are similar" << endl;
	else
		cout << "Your lines are not similar" << endl;


	return 0;
}