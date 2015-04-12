#pragma once

#include <QString>
#include <iostream>

enum Function
{
    sum = 0,
    polynom,
    user
};

class HashFunction
{
public:
    HashFunction();
    ~HashFunction();

    void changeHashFunction();
    void changeHashFunction(int index);
    void setLastFunction();
    void addUsersHashFunction(int hash(const QString &, int));

    int (*hashFunction)(const QString &, int);

private:
   static int countHashPolynom(const QString &stringToCount, int module);
   static int countHashSum(const QString &stringToCount, int module);

   int (*addedFunctions[100])(const QString &, int);
   int numberOfAdded;
};
