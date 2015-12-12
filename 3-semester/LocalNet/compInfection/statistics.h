#pragma once

#include <iostream>
#include <QList>
#include <QString>

class Statistics
{
public:
    Statistics();
    ~Statistics();
    void addNote(const QString &note);
    int getIterationsCount();
    void show();

private:
    QList<QString> *notes;
    int iterations;
};
