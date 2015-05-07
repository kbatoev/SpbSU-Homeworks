#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>

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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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

#endif // MAINWINDOW_H
