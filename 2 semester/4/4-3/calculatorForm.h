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

class CalculatorForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalculatorForm(QWidget *parent = 0);
    ~CalculatorForm();

private slots:
    void clicked(const QString &text);

private:

    void connectButtonWithMapper(QPushButton *button, QString text);

    Ui::CalculatorForm *ui;
    QSignalMapper *signalMapper;
    Calculator *calc;
    QString expression;
    double result;
};

#endif // CALCULATORFORM_H
