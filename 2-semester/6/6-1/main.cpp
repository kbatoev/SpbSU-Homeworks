#include <iostream>
#include <QTextStream>
#include <QString>

#include "tree.h"
#include "treeTest.h"

int main()
{
    TreeTest test;
    QTest::qExec(&test);


    QTextStream in(stdin);
    std::cout << "Enter expression:\n";
    QString expression = in.readLine();

    Tree *tree = new Tree(expression);

    std::cout << "Result is: ";
    std::cout << tree->count() << "\n";
    tree->print();

    delete tree;

    return 0;
}
