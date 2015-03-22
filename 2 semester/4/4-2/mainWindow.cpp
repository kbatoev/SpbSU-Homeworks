#include "mainWindow.h"
#include "ui_mainWindow.h"
#include <QMessageBox>

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->resultLine->setText("0");
    connect(ui->firstOperand, SIGNAL(valueChanged(int)), this, SLOT(countExpression()));
    connect(ui->secondOperand, SIGNAL(valueChanged(int)), this, SLOT(countExpression()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(countExpression()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::countExpression()
{
    int firstOperand = ui->firstOperand->value();
    int secondOperand = ui->secondOperand->value();
    Operations operation = transformOperation(ui->comboBox->currentText());

    int expressionResult = 0;
    switch (operation)
    {
    case plus: expressionResult = firstOperand + secondOperand;
        break;

    case minus: expressionResult = firstOperand - secondOperand;
        break;

    case multiplication: expressionResult = firstOperand * secondOperand;
        break;

    case division:
        if (secondOperand)
            expressionResult = firstOperand / secondOperand;
        else
            QMessageBox::information(this, "Be Attentive", "No 0 division available!!!");

        break;
    default:
        break;
    }

    QString resultString = QString::number(expressionResult);
    emit ui->resultLine->setText(resultString);
}

Calculator::Operations Calculator::transformOperation(QString operation)
{
    if (operation == "+")
        return plus;
    if (operation == "-")
        return minus;
    if (operation == "*")
        return multiplication;
    if (operation == "/")
        return division;
}

