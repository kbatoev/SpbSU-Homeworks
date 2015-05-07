#pragma once

#include <QMainWindow>
#include <QSpinBox>

#include <QLineEdit>
#include <QSignalMapper>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <iostream>

#include <cstdlib>
#include <ctime>

namespace Ui {
class MainWindow;
}

class FindPair : public QMainWindow
{
    Q_OBJECT

public:
    explicit FindPair(QWidget *parent = 0);
    ~FindPair();

private slots:
    void generateField(int n);
    void clicked(QString sIndex);

private:

    bool isFirst;
    int iFirst;
    int jFirst;
    QPushButton **field;
    Ui::MainWindow *ui;
    QSignalMapper *signalMapper;
    int size;
    int count;
    int *values;
};
