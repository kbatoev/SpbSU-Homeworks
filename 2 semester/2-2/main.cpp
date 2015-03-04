#include <iostream>
#include "stack.h"
#include "linkedStack.h"
#include "arrayStack.h"
#include "converterToPostfix.h"
#include "countPostfix.h"
#include "calculator.h"

using namespace std;

int main()
{

    LinkedStack *linkedStack = new LinkedStack;
    linkedStack->push(90);
    linkedStack->push(50);
    linkedStack->push(78);
    linkedStack->push(8);
    cout << linkedStack->top() << endl;
    linkedStack->pop();
    cout << linkedStack->top() << endl;
    delete linkedStack;

    ArrayStack *arrayStack = new ArrayStack;
    cout << arrayStack->top() << endl;
    arrayStack->push(5);
    arrayStack->pop();
    if (arrayStack->isEmpty())
        cout << "Is empty" << endl;
    else
        cout << "Isn't." << endl;
    arrayStack->push(7);
    arrayStack->push(45);
    arrayStack->push(23);
    cout << arrayStack->top() << endl;
    delete arrayStack;


    cout << "Enter a correct math expression: " << endl;

    char *infix = new char[1000];
    gets(infix);

    Calculator *calc = new Calculator;
    cout << calc->countExpression(infix) << endl;
    delete calc;
    delete infix;

    return 0;
}

