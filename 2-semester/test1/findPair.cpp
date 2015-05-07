#include "findPair.h"
#include "ui_mainwindow.h"

FindPair::FindPair(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setLayout(ui->gridLayout);
    count = 0;
    isFirst = true;

    ui->gridLayout->addWidget(ui->spinBox, 0, 0);
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(generateField(int)));

}

FindPair::~FindPair()
{
    delete ui;
    delete signalMapper;
    delete[] values;
    for (int i = 0; i < size; i++)
        delete[] field;
    delete[] field;
}

void FindPair::generateField(int n)
{
    size = n;
    if (!((size + 2) % 2))
    {
        ui->gridLayout->removeWidget(ui->spinBox);
        ui->spinBox->setVisible(false);
        field = new QPushButton*[size];
        for (int i = 0; i < size; i++)
            field[i] = new QPushButton[size];

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
            {
                ui->gridLayout->addWidget(&field[i][j], i, j);
            }

        values = new int[size * size];
        int zeroAmount = 0;
        int oneAmount = 0;

        srand(time(0));
        for (int i = 0; i < size * size; i++)
            {
                values[i] = rand() % 2;
                if (values[i])
                    oneAmount++;
                else
                    zeroAmount++;
            }
        if (oneAmount % 2)
            values[size * size - 1] = (values[size * size - 1] + 1) % 2;

        signalMapper = new QSignalMapper;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
            {
                connect(&field[i][j], SIGNAL(clicked()), signalMapper, SLOT(map()));
                signalMapper->setMapping(&field[i][j], QString::number(i * size + j));
            }
        connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(clicked(QString)));
    }
}

void FindPair::clicked(QString sIndex)
{
    int index = sIndex.toInt();
    int i = index / size;
    int j = index % size;
    QString value = QString::number(values[index]);
    field[i][j].setText(value);
    if (isFirst)
    {
        this->iFirst = i;
        this->jFirst = j;
        this->isFirst = false;
    }
    else
    {
        int firstValue = values[iFirst * size + jFirst];
        int secondValue = values[i * size + j];
        if (firstValue == secondValue)
        {
            field[i][j].setEnabled(false);
            field[iFirst][jFirst].setEnabled(false);
            count += 2;
            if (count == size)
            {
                return;
            }
        }
        else
        {
            field[i][j].setText("");
            field[iFirst][jFirst].setText("");
        }
        isFirst = true;
    }
}
