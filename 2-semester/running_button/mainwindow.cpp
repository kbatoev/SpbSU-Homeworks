#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentPosition(0)
{
    ui->setupUi(this);

    drawWindow();

    connect(ui->runningButton, SIGNAL(clicked()), this, SLOT(fail()));
    ui->runningButton->installEventFilter(this);
    ui->runningButton->setMouseTracking(true);

    makePointArray();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete[] array;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (object == ui->runningButton)
    {
        if (event->type() == QEvent::MouseMove)
        {
            ui->runningButton->move(array[currentPosition++]);
            currentPosition %= numberOfPositions;
        }
    }
    return false;
}

void MainWindow::fail()
{
    ui->runningButton->setEnabled(false);
    ui->lineEdit->setText("Незачет :(");
    ui->lineEdit->setVisible(true);
}

void MainWindow::drawWindow()
{
    QPoint leftUp(0, 0);
    QPoint rightDown(100, 100);
    QRect rectangle(leftUp, rightDown);
    ui->runningButton->setGeometry(rectangle);
    QSize size(500, 500);
    ui->centralWidget->setFixedSize(size);
    ui->runningButton->setText("running");
    ui->lineEdit->setVisible(false);
}

void MainWindow::makePointArray()
{
    srand(time(0));
    numberOfPositions = 100;
    array = new QPoint[numberOfPositions];
    for (int i = 0; i < numberOfPositions; i++)
    {
        array[i].setX(rand() % 400);
        array[i].setY(rand() % 400);
        if (i && !areFarPoints(array[i], array[i-1]) ||
                i == numberOfPositions - 1 && !areFarPoints(array[0], array[i]))
            i--;
    }
    ui->runningButton->move(array[currentPosition++]);
}

bool MainWindow::areFarPoints(QPoint first, QPoint second)
{
    return (first.x() - second.x()) * (first.x() - second.x())
            + (first.y() - second.y()) * (first.y() - second.y()) > 10000;
}

