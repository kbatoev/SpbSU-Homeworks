#include "list.h"

struct ListElement
{
    MyString *line;
    int amountOfWord;
    ListElement *next;
};

struct List
{
    ListElement *head;
};

ListElement *createListElement(MyString *line, ListElement *next)
{
    ListElement *element = new ListElement;
    element->line = line;
    element->next = next;
    element->amountOfWord = 1;
    return element;
}

List *createList()
{
    List *list = new List;
    MyString *emptyLine = createString("");
    ListElement *guard = createListElement(emptyLine, nullptr);
    list->head = guard;
    return list;
}

int addElement(MyString *newLine, ListElement *guard)
{
    int amountOfDifferentWords = 1;
    ListElement *current = guard;
    ListElement *next = guard->next;
    while (next != nullptr)
    {
        if (areEqual(newLine, next->line))
        {
            next->amountOfWord++;
            break;
        }
        current = next;
        next = next->next;
        amountOfDifferentWords++;
    }
    if (next == nullptr)
        current->next = createListElement(newLine, next);
    return amountOfDifferentWords;
}

void addElement(MyString *newLine, List *list)
{
    int newAmount = addElement(newLine, list->head);
    if (newAmount > list->head->amountOfWord)
        list->head->amountOfWord = newAmount;
}

void deleteList(List *list)
{
    ListElement *element = list->head;
    ListElement *next = element->next;
    while (next != nullptr)
    {
        MyString *current = element->line;
        deleteString(current);
        delete element;
        element = next;
        next = element->next;
    }
    delete element;
    delete list;
}

bool showNext(List *list)
{
    return list->head->next == nullptr;
}

int getAmount(List *list)
{
    return list->head->amountOfWord;
}

void printList(List *list, ofstream &out)
{
    ListElement *current = list->head->next;

    while (current != nullptr)
    {
        out << current->amountOfWord << " ";
        printString(current->line, out);
        out << endl;
        current = current->next;
    }
}

void printList(List *list)
{
    ListElement *current = list->head->next;

    while (current != nullptr)
    {
        cout << current->amountOfWord << " ";
        printString(current->line);
        cout << endl;
        current = current->next;
    }
}
