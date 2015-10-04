#include "localnet.h"
#include "msystem.h"
#include "lsystem.h"
#include "wsystem.h"

LocalNet::LocalNet(int computers, int **matrix, int *os) : computers(computers)
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
        OS current = OS(os[i]);
        switch (current)
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
    for (int i = 1; i < computers; i++) // only first computer is infected in the beginning
        numbersOfUninfected.append(i);
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

void LocalNet::startExperiment()
{
    arrayOfSystems[0]->tryToInfectYorself(1000); // made first computer infected
    int uninfectedComputers = computers - 1;

    int iteration = 0;
    while (uninfectedComputers)
    {
        showStatistics(iteration++);
        for (int i = 0; i < numbersOfUninfected.size(); i++)
        {
            int number = numbersOfUninfected.at(i);
            ISystem *system = arrayOfSystems[number];

            int j = 0;
            while (!system->getStatus() && j < computers)
            {
                if (map[number][j] && arrayOfSystems[j]->getStatus())
                {
                    system->tryToInfectYorself(arrayOfSystems[j]->getInfectionAbility());
                    if (system->getStatus())
                        uninfectedComputers--;

                }
                j++;
            }
        }
    }
    showStatistics(iteration++);
}

void LocalNet::showStatistics(int iteration)
{
    std::cout << "Iteration " << iteration << ":\n";
    for (int i = 0; i < computers; i++)
        std::cout << i + 1 << ": " << "os: " << arrayOfSystems[i]->getName().toStdString()
                  << " " << arrayOfSystems[i]->getQStringStatus().toStdString() << "\n";
    std::cout << "\n\n";
}

