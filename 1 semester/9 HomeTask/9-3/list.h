#pragma once

#include <iostream>

using namespace std;

struct ListElement;

struct List;

List *createList();
List **createEdges();

int getWeight(List *edges);
int getNext(List *edges, bool *isAdded);
void addEdge(int weight, int vertex, List *sortedEdges);
void removeEdge(int weight, int vertex, List *sortedEdges);


void deleteList(List *sortedEdges);
void deleteEdges(List **edges);
