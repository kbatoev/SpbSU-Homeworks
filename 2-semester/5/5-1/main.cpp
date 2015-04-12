#include <iostream>
#include <QString>
#include <QTextStream>

#include "hashTableTest.h"
#include "list.h"
#include "hashFunctionTesting.h"

enum Choice
{
    addString = 0,
    removeString,
    findString,
    showStatistics,
    changeHashFunction,
    quit
};

int main()
{
    /*
    HashFunctionTest hashTest;
    QTest::qExec(&hashTest);

    HashTableTest tableTest;
    QTest::qExec(&tableTest);
    */


    HashTable *table = new HashTable;

    std::cout << "This program is for HashTable with Strings\n";
    std::cout << "You can:\n0 - add\n1 - remove\n2 - find\n3 - showStatistics\n";
    std::cout << "4 - change hash function \n5 - exit\n";


    bool isRunning = true;
    while (isRunning)
    {
        int command = 0;
        std::cout << "Enter next command: ";
        std::cin >> command;
        Choice current = (Choice)command;

        QTextStream qtin(stdin);
        QString text;

        switch(current)
        {
        case addString:
            std::cout << "Enter string: ";
            qtin >> text;
            table->addString(text);
            std::cout << "Added\n";
            break;
        case removeString:
            std::cout << "Enter string: ";
            qtin >> text;
            if (table->deleteString(text))
                std::cout << "Yes\n";
            else
                std::cout << "No\n";
            break;
        case findString:
            std::cout << "Enter string: ";
            qtin >> text;

            if (table->findString(text))
                std::cout << "Yes\n";
            else
                std::cout << "No\n";
            break;

        case showStatistics:
            table->showStatistics();
            break;

        case changeHashFunction:
            table->chooseHashFunction();
            break;

        case quit:
            isRunning = false;
            break;
        }
    }

    delete table;

    return 0;
}
