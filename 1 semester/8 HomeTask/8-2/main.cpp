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

void initialize(int *distances, bool *isVisited, int vertexCount)
{
    const int infinity = 10000;
    for (int i = 0; i < vertexCount; i++)
    {
        distances[i] = infinity;
        isVisited[i] = false;
    }
}

void makeRoad(int **ways, int current, int nextVertex)
{
    int k = 0;
    while (ways[current][k])
    {
        ways[nextVertex][k] = ways[current][k];
        k++;
    }
    ways[nextVertex][k] = nextVertex + 1;
}

void dijkstra(int current, int **graph, int *distances,
              bool *isVisited, int vertexCount, int *way, int position, int **ways)
{
    for (int i = 0; i < vertexCount; i++)
    {
        isVisited[current] = true;
        way[position++] = current;
        for (int j = 0; j < vertexCount; j++)
            if (graph[current][j] && !isVisited[j] &&
                    distances[j] > distances[current] + graph[current][j])
            {
                distances[j] = distances[current] + graph[current][j];
                makeRoad(ways, current, j);
            }
        int nextVertex = 0;
        int minDistance = 0;
        for (int j = 0; j < vertexCount; j++)
            if (!isVisited[j] && (!minDistance || minDistance > distances[j]))
            {
                nextVertex = j;
                minDistance = distances[j];
            }
        current = nextVertex;
    }
}

void printRoads(int **ways, int vertexCount)
{
    cout << "Roads to every town are:" << endl;
    for (int i = 0; i < vertexCount; i++)
    {
        int j = 0;
        while (ways[i][j] && j < vertexCount)
            cout << ways[i][j++] << " ";
        cout << endl;
    }
}

int main()
{
    const int maxSize = 1000;
    char *fileName = new char[maxSize];
    //cout << "Enter name of file:" << endl;
    //cin >> fileName;
    fileName = "test.txt";

    ifstream in(fileName);

    int vertexCount = 0;
    int edgeCount = 0;
    in >> vertexCount >> edgeCount;
    int **graph = createGraph(vertexCount);

    for (int i = 0; i < edgeCount; i++)
    {
        int vertexFrom = 0;
        int vertexTo = 0;
        int length = 0;
        in >> vertexFrom >> vertexTo >> length;
        vertexFrom--;
        vertexTo--;
        graph[vertexFrom][vertexTo] = length;
        graph[vertexTo][vertexFrom] = length;
    }

    int *distances = new int[vertexCount];
    bool *isVisited = new bool[vertexCount];
    int *way = new int[vertexCount];
    initialize(distances, isVisited, vertexCount);

    int current = 0;
    int position = 0;
    distances[current] = 0;

    int **ways = createGraph(vertexCount);
    ways[current][current] = 1;
    dijkstra(current, graph, distances, isVisited, vertexCount, way, position, ways);

    cout << "Bypass is:" << endl;
    for (int i = 0; i < vertexCount; i++)
        cout << way[i] + 1 << " ";
    cout << endl;

    for (int i = 0; i < vertexCount; i++)
        cout << "Minimal distance from 1 to " << i + 1 << " is : " << distances[i] << endl;

    printRoads(ways, vertexCount);

    in.close();
    delete[] fileName;
    delete[] way;
    delete[] isVisited;
    delete[] distances;
    deleteGraph(graph, vertexCount);
    deleteGraph(ways, vertexCount);

    return 0;
}
