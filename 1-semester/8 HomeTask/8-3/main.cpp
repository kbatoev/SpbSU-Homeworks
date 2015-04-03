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

void dfs(int current, bool *isVisited, int **graph, int vertexCount)
{
    cout << current + 1 << " ";
    isVisited[current] = true;
    for (int i = 0; i < vertexCount; i++)
        if (!isVisited[i] && graph[current][i])
            dfs(i, isVisited, graph, vertexCount);
}

int main()
{
    const int maxSize = 1000;
    char *fileName = new char[maxSize];
    fileName = "test.txt";

    ifstream in(fileName);

    int vertexCount = 0;
    int edgeNumber = 0;
    in >> vertexCount >> edgeNumber;

    int **graph = createGraph(vertexCount);
    for (int i = 0; i < edgeNumber; i++)
    {
        int vertexFrom = 0;
        int vertexTo = 0;
        in >> vertexFrom >> vertexTo;
        vertexFrom--;
        vertexTo--;
        graph[vertexFrom][vertexTo] = 1;
        graph[vertexTo][vertexFrom] = 1;
    }

    bool *isVisited = new bool[vertexCount];
    for (int i = 0; i < vertexCount; i++)
        isVisited[i] = false;

    int count = 1;
    for (int i = 0; i < vertexCount; i++)
    {
        if (!isVisited[i])
        {
            cout << count++ << " component has these(this) vertexes(vertex):" << endl;
            dfs(i, isVisited, graph, vertexCount);
            cout << endl;
        }
    }

    deleteGraph(graph, vertexCount);
    delete[] fileName;
    delete[] isVisited;
    in.close();

    return 0;
}
