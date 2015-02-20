#include <iostream>
#include <fstream>

using namespace std;

int **createGraph(int vertexCount)
{
    int **graph = new int*[vertexCount];
    for (int i = 0; i < vertexCount; i++)
    {
        graph[i] = new int[vertexCount];
        for (int j = 0; j < vertexCount; j++)
            graph[i][j] = 0;
    }
    return graph;
}

void deleteGraph(int **graph, int vertexCount)
{
    for (int i = 0; i < vertexCount; i++)
    {
        delete[] graph[i];
        graph[i] = nullptr;
    }
    delete[] graph;
    graph = nullptr;
}

void nameVertex(int vertex, int vertexCount, char &currentName, char *names, int **graph)
{
    const char noName = '0';
    names[vertex] = currentName++;
    for (int i = 0; i < vertexCount; i++)
        if (graph[vertex][i] && names[i] == noName)
            nameVertex(i, vertexCount, currentName, names, graph);
}

int main()
{
    const int maxSize = 1000;
    char *fileName = new char[maxSize];
    cout << "Enter name of file:" << endl;
    cin >> fileName;

    ifstream in(fileName);

    if (!in.is_open())
        cout << "Error: there's no such file." << endl;
    else
    {
        int vertexCount = 0;
        int edgeCount = 0;
        in >> vertexCount >> edgeCount;
        int **graph = createGraph(vertexCount);

        for (int i = 0; i < edgeCount; i++)
        {
            int vertexFrom = 0;
            int vertexTo = 0;
            in >> vertexFrom >> vertexTo;
            vertexFrom--;
            vertexTo--;
            graph[vertexFrom][vertexTo] = 1;
        }

        char names[vertexCount];
        const char noName = '0';
        for (int i = 0; i < vertexCount; i++)
            names[i] = noName;

        int firstVertex = 0;
        in >> firstVertex;
        firstVertex--;
        char currentName = 'A';
        nameVertex(firstVertex, vertexCount, currentName, names, graph);

        cout << "Names are:" << endl;
        for (int i = 0; i < vertexCount; i++)
            cout << names[i] << " ";

        deleteGraph(graph, vertexCount);
    }

    in.close();
    delete[] fileName;

    return 0;
}

