#include "localnet.h"

LocalNet::LocalNet(int computers, int **matrix, int *os, INumberGenerator *generator)
{
    this->computers = computers;
    infected = false;
    statistics = new Statistics();

    makeMap(matrix);
    if (!generator)
        generator = new RandomNumberGenerator();

    arrayOfSystems = new ISystem*[computers];
    for (int i = 0; i < computers; i++)
    {
        OS currentSystem = (OS)os[i];
        switch (currentSystem)
        {
        case MOS:
            arrayOfSystems[i] = new MSystem(generator);
            break;
        case LOS:
            arrayOfSystems[i] = new LSystem(generator);
            break;
        case WOS:
            arrayOfSystems[i] = new WSystem(generator);
            break;
        }
    }
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
    arrayOfSystems[firstComputer]->makeInfected(); // made first computer infected
    numbersOfInfected.append(firstComputer);

    int iteration = 1;
    while (numbersOfInfected.size() < computers)
    {
        for (int i = 0; i < numbersOfInfected.size(); i++)
        {
            int number = numbersOfInfected.at(i);
            int j = 0;
            while (j < computers)
            {
                if (map[number][j] && arrayOfSystems[j]->isHealthy())
                    arrayOfSystems[j]->wasAttacked();
                j++;
            }
        }
        addStatistics(iteration);
        renewStatusOfSystems();
        iteration++;
        if (iteration == maxIterations)
            throw StableNetError("Too many iterations!!!");
    }
    addStatistics(iteration);
    infected = true;
}

void LocalNet::showStatistics()
{
    statistics->show();
}

int LocalNet::getIterationsCount()
{
    return statistics->getIterationsCount();
}

bool LocalNet::isInfected()
{
    return infected;
}

void LocalNet::addStatistics(int iteration)
{
    QString data = QString("Iteration ");
    data += QString::number(iteration);
    data += ":\n";
    for (int i = 0; i < computers; ++i)
    {
        data += QString::number(i + 1) + QString(" os: ") + arrayOfSystems[i]->getName() +
                QString(" ") + arrayOfSystems[i]->getQStringStatus() + "\n";
    }
    statistics->addNote(data);
}

void LocalNet::renewStatusOfSystems()
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

void LocalNet::makeMap(int **matrix)
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
}

