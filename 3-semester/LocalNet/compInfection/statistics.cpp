#include "statistics.h"

Statistics::Statistics()
{
    notes = new QList<QString>();
    iterations = 0;
}

Statistics::~Statistics()
{
    delete notes;
}

void Statistics::addNote(const QString &note)
{
    notes->append(note);
    iterations++;
}

int Statistics::getIterationsCount()
{
    return iterations;
}

void Statistics::show()
{
    for (int i = 0; i < notes->size(); ++i)
    {
        std::cout << notes->at(i).toStdString() << "\n";
    }
}

