#include "localnet.h"
#include "msystem.h"
#include "lsystem.h"
#include "wsystem.h"

LocalNet::LocalNet(int computers, int **matrix, int *os) : computers(computers), addingProbability(0)
{
    map = new int*[computers];
    for (int i = 0; i < computers; ++i)
    {
        map[i] = new int[computers];
        for (int j = 0; j < computers; j++)
        {
            map[i][j] = matrix[i][j];
        }
    }

    arrayOfSystems = new ISystem*[computers];
    for (int i = 0; i < computers; i++)
    {
        OS currentSystem = OS(os[i]);
        switch (currentSystem)
        {
        case MOS:
            arrayOfSystems[i] = new MSystem();
            break;
        case LOS:
            arrayOfSystems[i] = new LSystem();
            break;
        case WOS:
            arrayOfSystems[i] = new WSystem();
            break;
        }
    }
}

LocalNet::LocalNet(int computers, int **matrix, int *os, int addition) : LocalNet(computers, matrix, os)
{
    addingProbability = addition;
}

LocalNet::~LocalNet()
{
    for (int i = 0; i < computers; i++)
    {
        delete[] map[i];
        delete arrayOfSystems[i];
    }
    delete[] map;
    delete[] arrayOfSystems;
}

void LocalNet::startExperimentWithOutput()
{
    arrayOfSystems[firstComputer]->makeInfected(); // made first computer infected
    numbersOfInfected.append(firstComputer);

    iteration = 1;
    while (numbersOfInfected.size() < computers)
    {
        showStatistics();
        renewSystemsStatus();
        for (int i = 0; i < numbersOfInfected.size(); i++)
        {
            int number = numbersOfInfected.at(i);
            ISystem *system = arrayOfSystems[number];

            int j = 0;
            while (j < computers)
            {
                if (map[number][j] && arrayOfSystems[j]->isHealthy())
                    system->tryToInfectNeighbour(arrayOfSystems[j], addingProbability);
                j++;
            }
        }
        iteration++;
    }
    showStatistics();
}

void LocalNet::startExperiment()
{
    arrayOfSystems[firstComputer]->makeInfected(); // made first computer infected
    numbersOfInfected.append(firstComputer);

    iteration = 1;
    while (numbersOfInfected.size() < computers)
    {
        for (int i = 0; i < numbersOfInfected.size(); i++)
        {
            int number = numbersOfInfected.at(i);
            ISystem *system = arrayOfSystems[number];

            int j = 0;
            while (j < computers)
            {
                if (map[number][j] && arrayOfSystems[j]->isHealthy())
                    system->tryToInfectNeighbour(arrayOfSystems[j], addingProbability);
                j++;
            }
        }
        renewSystemsStatus();
        iteration++;
    }
}

int LocalNet::getIterationNumber()
{
    return iteration;
}

void LocalNet::showStatistics()
{
    std::cout << "Iteration " << iteration << ":\n";
    for (int i = 0; i < computers; i++)
        std::cout << i + 1 << ": " << "os: " << arrayOfSystems[i]->getName().toStdString()
                  << " " << arrayOfSystems[i]->getQStringStatus().toStdString() << "\n";
    std::cout << "\n\n";
}

void LocalNet::renewSystemsStatus()
{
    for (int i = 0; i < computers; i++)
    {
        if (arrayOfSystems[i]->isJustInfected())
        {
            arrayOfSystems[i]->makeInfected();
            numbersOfInfected.append(i);
        }
    }
}

