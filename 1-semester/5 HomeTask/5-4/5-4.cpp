#include <iostream>
#include <fstream>
#include "guide.h"

using namespace std;

int main()
{
    const int maxSize = 1000;

    enum Operations
    {
        exit = 0,
        addNote = 1,
        seekPhone = 2,
        seekName = 3,
        maintainData = 4,
        start = 5
    };

    Guide *notes = createGuide();

    char fileName[maxSize];
    loadData(notes, fileName);

    cout << "It's directory of a book" << endl;
    cout << "You can do such actions:" << endl;
    cout << "0 - exit" << endl;
    cout << "1 - add a note (name and telephone)" << endl;
    cout << "2 - find telephone by name" << endl;
    cout << "3 - find name by telephone" << endl;
    cout << "4 - save all into file " << endl;

    Operations action = start;
    while (action)
    {
        cout << "Enter an action: ";
        int currentAction = 0;
        cin >> currentAction;
        action = (Operations)currentAction;

        switch (action)
        {
            case addNote:
                addItem(notes); break;

            case seekPhone:
                searchPhone(notes); break;

            case seekName:
                searchName(notes); break;

            case maintainData:
                saveData(notes, fileName); break;
        }
    }

    deleteGuide(notes);

    return 0;
}
