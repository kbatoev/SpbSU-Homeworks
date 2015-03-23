#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calculator.h"

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
    void on_firstOperand_valueChanged(int arg1);
    void on_secondOperand_valueChanged(int arg2);
    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    void outputResults();

    Calculator *calculator;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
