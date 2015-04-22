#include "operatorNode.h"

OperatorNode::OperatorNode()
{
    way = left;
    leftChild = nullptr;
    rightChild = nullptr;
    operation = none;
}

OperatorNode::OperatorNode(QChar symbol)
{
    for (int i = 0; i < 4; i++)
        if (charOperations[i] == symbol)
            operation = operationList[i];
    leftChild = nullptr;
    rightChild = nullptr;
    way = left;
}

OperatorNode::~OperatorNode()
{
    delete leftChild; // что будет, если не удалить их собственные ссылки ?
    delete rightChild;
}

int OperatorNode::count()
{
    transformToQChar();
    return countOperator(leftChild->count(), rightChild->count());
}

void OperatorNode::print()
{
    std::cout << "(";
    leftChild->print();
    char action = (char)this->transformToQChar().unicode();
    std::cout << " " << action << " ";
    rightChild->print();
    std::cout << ")";
}

QChar OperatorNode::transformToQChar()
{
    for (int i = 0; i < 4; i++)
        if (operation == operationList[i])
            return charOperations[i];
}


int OperatorNode::countOperator(int operand1, int operand2)
{
    switch (operation)
    {
    case addition:
        return operand1 + operand2;
    case subtraction:
        return operand1 - operand2;
    case multiplication:
        return operand1 * operand2;
    case division:
        return operand1 / operand2;
    }
    return 0;
}

