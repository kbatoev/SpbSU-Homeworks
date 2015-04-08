#include "calculatorForm.h"
#include "ui_calculatorForm.h"

CalculatorForm::CalculatorForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalculatorForm)
{
    ui->setupUi(this);
    calc = new Calculator;
    expression = "";

    signalMapper = new QSignalMapper(this);
    connectButtonWithMapper(ui->pushButton0, "0");
    connectButtonWithMapper(ui->pushButton1, "1");
    connectButtonWithMapper(ui->pushButton2, "2");
    connectButtonWithMapper(ui->pushButton3, "3");
    connectButtonWithMapper(ui->pushButton4, "4");
    connectButtonWithMapper(ui->pushButton5, "5");
    connectButtonWithMapper(ui->pushButton6, "6");
    connectButtonWithMapper(ui->pushButton7, "7");
    connectButtonWithMapper(ui->pushButton8, "8");
    connectButtonWithMapper(ui->pushButton9, "9");
    connectButtonWithMapper(ui->pointButton, ".");
    connectButtonWithMapper(ui->cancelButton, "");
    connectButtonWithMapper(ui->plusButton, "+");
    connectButtonWithMapper(ui->minusButton, "-");
    connectButtonWithMapper(ui->multiplicationButton, "*");
    connectButtonWithMapper(ui->divisionButton, "/");
    connectButtonWithMapper(ui->openedBracketButton, "(");
    connectButtonWithMapper(ui->closedBracketButton, ")");
    connectButtonWithMapper(ui->countButton, "=");

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(clicked(QString)));
}

CalculatorForm::~CalculatorForm()
{
    delete signalMapper;
    delete calc;
    delete ui;
}

bool isOperator(QString text)
{
    int i = text.size() - 1;
    return text[i] == '+' || text[i] == '-' || text[i] == '*' || text[i] == '/';
}



void CalculatorForm::clicked(const QString &text)
{
    if (text == "=")
    {
        result = calc->count(expression);
        expression = "";
        ui->lineEdit->setText(QString::number((result)));
    }
    else
    {
        if (text != "")
        {
            int i = expression.size() - 1;
            if (i >= 0 && isOperator(text) && isOperator(expression))
            {
                expression[i] = text[0];
            }
            else
            {
                expression += text;
            }
        }
        else
        {
            expression = text;
        }
        ui->lineEdit->setText(expression);
    }
}

void CalculatorForm::connectButtonWithMapper(QPushButton *button, const QString &text)
{
   connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
   signalMapper->setMapping(button, text);
}
