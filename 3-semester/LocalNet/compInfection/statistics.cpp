#include "statistics.h"

Statistics::Statistics()
{
    notes = new QList<QString>();
}

Statistics::~Statistics()
{
    delete notes;
}

void Statistics::addNote(const QString &note)
{
    notes->append(note);
}

void Statistics::show()
{
    for (int i = 0; i < notes->size(); ++i)
    {
        std::cout << notes->at(i).toStdString() << "\n";
    }
}

