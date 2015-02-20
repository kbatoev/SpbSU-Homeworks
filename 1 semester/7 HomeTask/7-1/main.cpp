#include <iostream>

using namespace std;

void findWrittenVariant(bool *used, int *studentsConnection, int *variant, int currentStudent)
{
    used[currentStudent] = true;
    int nextStudent = studentsConnection[currentStudent];
    if (nextStudent)
    {
        if (!used[nextStudent])
            findWrittenVariant(used, studentsConnection, variant, nextStudent);
        variant[currentStudent] = variant[nextStudent];
    }
}

int main()
{
    cout << "Enter a number of Students and a number of pairs: " << endl;
    int numberOfStudents = 0;
    int numberOfPairs = 0;
    cin >> numberOfStudents >> numberOfPairs;
    numberOfStudents++;

    bool *used = new bool[numberOfStudents];
    int *studentsConnection = new int[numberOfStudents];
    int *variant = new int[numberOfStudents];
    for (int i = 0; i < numberOfStudents; i++)
    {
        used[i] = false;
        studentsConnection[i] = 0;
        if (i <= 3)
            variant[i] = i;
        else
            variant[i] = 0;
    }

    cout << "Enter pairs: " << endl;
    for (int i = 0; i < numberOfPairs; i++)
    {
        int first = 0;
        int second = 0;
        cin >> first >> second;
        studentsConnection[first] = second;
    }

    for (int i = 1; i < numberOfStudents; i++)
        if (!used[i])
            findWrittenVariant(used, studentsConnection, variant, i);

    for (int i = 1; i < numberOfStudents; i++)
        if (variant[i])
            cout << "The student number " << i << " has variant " << variant[i] << endl;
        else
            cout << "The student number " << i << " hasn't done work" << endl;

    delete[] used;
    delete[] studentsConnection;
    delete[] variant;

    return 0;
}

