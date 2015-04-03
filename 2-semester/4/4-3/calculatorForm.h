#ifndef CALCULATORFORM_H
#define CALCULATORFORM_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QSignalMapper>
#include "calculator.h"

namespace Ui {
class CalculatorForm;
}

/**
 * @brief The CalculatorForm class
 * Real form Calculator that works with right input
 */

class CalculatorForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalculatorForm(QWidget *parent = 0);
    ~CalculatorForm();

private slots:
    void clicked(const QString &text);

private:

    /**
     * @brief connectButtonWithMapper
     * @param button - button to be connected
     * @param text - set text that this button will emit
     */
    void connectButtonWithMapper(QPushButton *button, QString text);

    Ui::CalculatorForm *ui;
    QSignalMapper *signalMapper;

    /**
     * @brief calc - object of class Calculator
     */
    Calculator *calc;
    QString expression;
    double result;
};

#endif // CALCULATORFORM_H
