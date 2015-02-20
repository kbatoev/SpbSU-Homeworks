#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

int **createGraph(int vertexCount)
{
    int **graph = new int*[vertexCount];
    for (int i = 0; i < vertexCount; i++)
    {
        graph[i] = new int[vertexCount - 1];
        for (int j = 0; j < vertexCount - 1; j++)
            graph[i][j] = 0;
    }
    return graph;
}

void deleteGraph(int **graph, int vertexCount)
{
    for (int i = 0; i < vertexCount; i++)
        delete[] graph[i];
    delete[] graph;
}

void primFindMST(int **graph, List **edges, int vertexCount)
{
    bool *isAdded = new bool[vertexCount];
    for (int i = 0; i < vertexCount; i++)
        isAdded[i] = false;
    isAdded[0] = true;
    int amountOfAddedVertexes = 1;
    while (amountOfAddedVertexes < vertexCount)
    {
        int min = 0;
        int next = -1;
        int prev = -1;
        for (int i = 0; i < vertexCount; i++)
        {
            int nextVertex = getNext(edges[i], isAdded);
            int currentWeight = getWeight(edges[i]);
            if (isAdded[i] && !isAdded[nextVertex] && (!min || min > currentWeight))
            {
                prev = i;
                next = nextVertex;
                min = currentWeight;
            }
        }
        isAdded[next] = true;
        graph[prev][amountOfAddedVertexes - 1] = min;
        graph[next][amountOfAddedVertexes - 1] = min;
        removeEdge(min, next, edges[prev]);
        removeEdge(min, prev, edges[next]);
        amountOfAddedVertexes++;
    }
    delete[] isAdded;
}

int main()
{
    ifstream in("test.txt");
    List **edges = createEdges();

    int vertexCount = 0;
    int edgeCount = 0;
    in >> vertexCount >> edgeCount;
    for (int i = 0; i < edgeCount; i++)
    {
        int weight = 0;
        int vertexFrom = 0;
        int vertexTo = 0;
        in >> vertexFrom >> vertexTo >> weight;
        vertexFrom--;
        vertexTo--;
        addEdge(weight, vertexTo, edges[vertexFrom]);
        addEdge(weight, vertexFrom, edges[vertexTo]);
    }

    int **graph = createGraph(vertexCount);

    primFindMST(graph, edges, vertexCount);
    edgeCount = vertexCount - 1;

    cout << "This is incidence matrix of minimum spanning tree:" << endl;
    for (int i = 0; i < vertexCount; i++)
    {
        for (int j = 0; j < edgeCount; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }

    cout << "This is another variation of MST:" << endl;
    for (int i = 0; i < edgeCount; i++)
    {
        int firstVertex = 0;
        int secondVertex = 0;
        for (int j = 0; j < vertexCount; j++)
        {
            if (graph[j][i])
                if (!firstVertex)
                    firstVertex = j + 1;
                else
                {
                    secondVertex = j + 1;
                    cout << "Between vertex " << firstVertex << " and "
                         << secondVertex << " is edge " << graph[j][i] << endl;
                    break;
                }
        }
    }

    in.close();
    deleteEdges(edges);
    deleteGraph(graph, vertexCount);

    return 0;
}

