#include "list.h"

struct ListElement
{
    int weight;
    int vertex;
    ListElement *next;
};

struct List
{
    ListElement *head;
};

ListElement *createListElement(int weight, int vertex, ListElement *next)
{
	ListElement *element = new ListElement;
    element->weight = weight;
    element->vertex = vertex;
	element->next = next;
	return element;
}

List *createList()
{
	List *list = new List;
    ListElement *guard = createListElement(0, -1, nullptr);
	list->head = guard;
	return list;
}

List **createEdges()
{
    const int maxSize = 1000;
    List **edges = new List*[maxSize];
    for (int i = 0; i < maxSize; i++)
        edges[i] = createList();
    return edges;
}

void addEdge(int weight, int vertex, ListElement *guard)
{
	ListElement *currentElement = guard;
	ListElement *nextElement = currentElement->next;

    while (nextElement != nullptr && nextElement->weight < weight)
	{
		currentElement = nextElement;
		nextElement = currentElement->next;
	}

    ListElement *element = createListElement(weight, vertex, nextElement);
	currentElement->next = element;
}

void addEdge(int weight, int vertex, List *sortedEdges)
{
    ListElement *guard = sortedEdges->head;
    addEdge(weight, vertex, guard);
}

int getWeight(List *edges)
{
    const int infinity = 10000;
    if (edges->head->next == nullptr)
        return infinity;
    else
        return edges->head->next->weight;
}

int getNext(List *edges, bool *isAdded)
{
    ListElement *current = edges->head->next;
    ListElement *previous = edges->head;
    if (current == nullptr)
        return 0;
    else
    {
        while (isAdded[current->vertex])
        {
            ListElement *toDelete = current;
            current = current->next;
            previous->next = current;
            delete toDelete;
            if (current == nullptr)
                return 0;
        }
        return current->vertex;
    }
}

void removeEdge(int weight, int vertex, List *sortedEdges)
{
    ListElement *previous = sortedEdges->head;
    ListElement *current = previous->next;
    while (current != nullptr && (current->vertex != vertex || current->weight != weight))
    {
        previous = current;
        current = current->next;
    }

    if (current != nullptr)
    {
        previous->next = current->next;
        delete current;
    }
}

void deleteList(List *sortedEdges)
{
    ListElement *element = sortedEdges->head;
    ListElement *next = element->next;
    while (next != nullptr)
    {
        delete element;
        element = next;
        next = element->next;
    }
    delete element;
    delete sortedEdges;
}

void deleteEdges(List **edges)
{
    const int maxSize = 1000;
    for (int i = 0; i < maxSize; i++)
        deleteList(edges[i]);
    delete edges;
}
