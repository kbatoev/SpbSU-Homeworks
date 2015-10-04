#include <iostream>
#include <fstream>

#include "localnet.h"

void input(int &computers, int** &matrix, int* &os)
{
    std::ifstream in("input.txt");
    in >> computers;
    matrix = new int*[computers];
    os = new int[computers];
    for (int i = 0; i < computers; i++)
    {
        matrix[i] = new int[computers];
        for (int j = 0; j < computers; j++)
            in >> matrix[i][j];
    }
    for (int i = 0; i < computers; i++)
        in >> os[i];

    in.close();
}

void emptyMemory(LocalNet *localNet, int computers, int **matrix, int *os)
{
    delete localNet;
    for (int i = 0; i < computers; i++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] os;
}

int main()
{
    int computers = 0;
    int **matrix;
    int *os;
    input(computers, matrix, os);

    LocalNet *localNet = new LocalNet(computers, matrix, os);
    localNet->startExperiment();

    emptyMemory(localNet, computers, matrix, os);

    return 0;
}
