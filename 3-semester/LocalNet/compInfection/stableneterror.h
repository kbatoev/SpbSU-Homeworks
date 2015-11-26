#pragma once

#include <QString>
#include <iostream>

class StableNetError
{
public:
    StableNetError(QString comment) : message(comment)
    {
    }
    void comment()
    {
        std::cout << message.toStdString() << "\n";
    }

private:
    QString message;
};
