#include "mainWindow.h"
#include "ui_mainWindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    calculator = new Calculator;
    ui->resultLine->setText("0");

    connect(ui->firstOperand, SIGNAL(valueChanged(int)), this, SLOT(firstValueChanged(int)));
    connect(ui->secondOperand, SIGNAL(valueChanged(int)), this, SLOT(secondValueChanged(int)));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(operationChanged(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete calculator;
}

void MainWindow::firstValueChanged(int value1)
{
    calculator->changeFirstArgument(value1);
    outputResults();
}

void MainWindow::secondValueChanged(int value2)
{
    calculator->changeSecondArgument(value2);
    outputResults();
}

void MainWindow::operationChanged(const QString &arg1)
{
    calculator->changeAction(arg1);
    outputResults();
}

void MainWindow::outputResults()
{
    if (calculator->isCorrectExpression())
    {
        calculator->countExpression();
        ui->resultLine->setText(QString::number(calculator->getResult()));
    }
    else
    {
        QMessageBox::information(this, "Be attentive!", "No 0 division available!!!");
        ui->resultLine->setText("ERROR");
    }
}
