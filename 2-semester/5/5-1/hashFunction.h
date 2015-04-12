#pragma once

#include <QString>
#include <iostream>


enum Function
{
    sum = 0,
    polynom,
    user
};

/**
 * @brief The HashFunction class
 * Hash can be counted by different functions.
 * 2 ones are given. Others can be added by user.
 */

class HashFunction
{
public:
    HashFunction();
    ~HashFunction();

    /// shows a dialog, where you can choose new HashFunction among added ones
    void changeHashFunction();
    /// sets function, from array (addedFunctions[])
    void changeHashFunction(int index);
    /// sets last function of array (addedFunctions[])
    void setLastFunction();
    void addUsersHashFunction(int hash(const QString &, int));

    /// main field that is used for counting
    int (*hashFunction)(const QString &, int);

private:
   static int countHashPolynom(const QString &stringToCount, int module);
   static int countHashSum(const QString &stringToCount, int module);

   int (*addedFunctions[100])(const QString &, int);
   int numberOfAdded;
};
