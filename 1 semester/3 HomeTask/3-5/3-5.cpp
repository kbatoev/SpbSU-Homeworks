#include <iostream>
#include "list.h"

using namespace std;

int main()
{

	List *sortedList = createList();

	int check = 1;

	while (check)
	{
		cout << "If you want to finish program, enter 0" << endl;
		cout << "If you want to add element, enter 1" << endl;
		cout << "If you want to remove element, enter 2" << endl;
		cout << "If you want to see all list, enter 3" << endl;
		
		cin >> check;
		if (check == 1)
		{
			int number = 0;
			cout << "Enter a value, that you want to add:" << endl;
			cin >> number;
			addElement(number, sortedList);
		}
		if (check == 2)
		{
			int number = 0;
			cout << "Enter a value, that you want to remove:" << endl;
			cin >> number;
			removeElement(number, sortedList);
		}
		if (check == 3)
		{
			cout << "Our List has these elements: " << endl;
			printList(sortedList);
		}
	}

	cout << "Program is finished" << endl;

	deleteList(sortedList);

	return 0;
}