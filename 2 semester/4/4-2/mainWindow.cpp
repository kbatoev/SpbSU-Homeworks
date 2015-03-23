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
}

MainWindow::~MainWindow()
{
    delete ui;
    delete calculator;
}

void MainWindow::on_firstOperand_valueChanged(int arg1)
{
    calculator->changeFirstArgument(arg1);
    outputResults();
}

void MainWindow::on_secondOperand_valueChanged(int arg2)
{
    calculator->changeSecondArgument(arg2);
    outputResults();
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    calculator->changeAction(arg1);
    outputResults();
}

void MainWindow::outputResults()
{
    if (calculator->isCorrectExpression())
    {
        calculator->countExpression();
        emit ui->resultLine->setText(QString::number(calculator->getResult()));
    }
    else
    {
        QMessageBox::information(this, "Be attentive!", "No 0 division available!!!");
        emit ui->resultLine->setText("ERROR");
    }
}
