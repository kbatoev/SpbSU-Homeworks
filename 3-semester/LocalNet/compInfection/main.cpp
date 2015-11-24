#include <iostream>
#include <fstream>

#include "localnet.h"
//#include "localnettest.h"

void inputFromFile(int &computers, int** &matrix, int* &os)
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

void inputFromSTD(int &computers, int** &matrix, int* &os)
{
    std::cout << "Enter number of computers:\n";
    std::cin >> computers;
    matrix = new int*[computers];
    os = new int[computers];

    std::cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < computers; i++)
    {
        matrix[i] = new int[computers];
        for (int j = 0; j < computers; j++)
            std::cin >> matrix[i][j];
    }

    std::cout << "Enter OS for every computer:\n MacOS - 1\n LinuxOS - 2\n WindowsOS - 3\n";
    for (int i = 0; i < computers; i++)
        std::cin >> os[i];
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
    //LocalNetTest test;
    //QTest::qExec(&test);


    int inputChoice = 0;
    std::cout << "Enter:\n 0 - stdin\n 1 - file (\"input.txt\")\n";
    std::cin >> inputChoice;

    int computers = 0;
    int **matrix;
    int *os;

    if (inputChoice)
        inputFromFile(computers, matrix, os);
    else
        inputFromSTD(computers, matrix, os);

    LocalNet *localNet = new LocalNet(computers, matrix, os);
    localNet->startExperiment();
    localNet->showStatistics();

    emptyMemory(localNet, computers, matrix, os);

    return 0;
}
