#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private slots:
    void countExpression();

private:

    enum Operations
    {
        plus = 1,
        minus,
        multiplication,
        division
    };

    Ui::MainWindow *ui;
    Operations transformOperation(QString operation);
};

#endif // MAINWINDOW_H
