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
    /**
     * @brief on_firstOperand_valueChanged. Slot for signal valueChanged(int) on first spinbox.
     * @param arg1 - new value
     */
    void on_firstOperand_valueChanged(int arg1);

    /**
     * @brief on_secondOperand_valueChanged. Slot for signal valueChanged(int) on second spinbox.
     * @param arg2 - new value
     */
    void on_secondOperand_valueChanged(int arg2);

    /**
     * @brief on_comboBox_currentIndexChanged. Slot for signal currentIndexChanged on comboBox.
     * @param arg1 - new operation
     */
    void on_comboBox_currentIndexChanged(const QString &arg1);

private:

    /**
     * @brief outputResults
     * Fills resultLine with result if it's valid, and if not - show Error
     */
    void outputResults();

    Calculator *calculator;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
