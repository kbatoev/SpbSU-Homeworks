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
    void show();

private:
    QList<QString> *notes;
};
