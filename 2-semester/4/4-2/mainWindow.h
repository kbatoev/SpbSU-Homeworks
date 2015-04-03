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
     * @brief firstValueChanged.
     * Slot for signal valueChanged(int) on first spinBox.
     */
    void firstValueChanged(int value1);

    /**
     * @brief secondValueChanged.
     * Slot for signal valueChanged(int) on second spinBox.
     */
    void secondValueChanged(int value2);

    /**
     * @brief operationChanged.
     * Slot for signal currentIndexChanged on comboBox.
     */
    void operationChanged(const QString &arg1);

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
