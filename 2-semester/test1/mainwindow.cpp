#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setLayout(ui->gridLayout);
    count = 0;

    ui->gridLayout->addWidget(ui->spinBox, 0, 0);
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(generateField(int)));


    //play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateField(int n)
{
    size = n;
    if (n && n % 2 == 0)
    {
        ui->gridLayout->removeWidget(ui->spinBox);
        ui->spinBox->setVisible(false);
        field = new QPushButton*[n];
        for (int i = 0; i < n; i++)
            field[i] = new QPushButton[n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                ui->gridLayout->addWidget(&field[i][j], i, j);
                //field[i][j].setEnabled(false);
            }

        values = new int[n * n];
        int zeroAmount = 0;
        int oneAmount = 0;

        srand(time(0));
        for (int i = 0; i < n * n; i++)
            {

                values[i] = rand() % 2;
                if (values[i])
                    oneAmount++;
                else
                    zeroAmount++;

            }
        if (oneAmount % 2)
            values[n * n - 1] = (values[n * n - 1] + 1) % 2;



        signalMapper = new QSignalMapper;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                connect(&field[i][j], SIGNAL(clicked()), signalMapper, SLOT(map()));
                signalMapper->setMapping(&field[i][j], QString::number(i * n + j));
            }
        connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(clicked(QString)));
    }
}

void MainWindow::clicked(QString sIndex)
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
    }
}
