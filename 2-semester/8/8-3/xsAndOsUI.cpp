#include "xsAndOsUIi.h"
#include "ui_xsandosui.h"

XsAndOsUI::XsAndOsUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::XsAndOsUI)
{
    ui->setupUi(this);
    ui->lineEdit->setText("Xs - move");

    signalMapper = new QSignalMapper(this);
    move = XOGame::xs;
    fieldSize = 5;
    game = new XOGame(fieldSize);

    field = new QPushButton*[fieldSize];
    for (int i = 0; i < fieldSize; i++)
        field[i] = new QPushButton[fieldSize];

    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
        {
            connect(&field[i][j], SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(&field[i][j], fieldSize * i + j);
            ui->gridLayout->addWidget(&field[i][j], i, j);
        }
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(play(int)));
}

XsAndOsUI::~XsAndOsUI()
{
    delete signalMapper;
    for (int i = 0; i < fieldSize; i++)
        delete[] field[i];
    delete[] field;
    delete ui;
}

void XsAndOsUI::play(int id)
{
    int i = id / fieldSize;
    int j = id % fieldSize;
    game->makeMove(move, i, j);

    if (!move)
    {
        field[i][j].setText("O");
        ui->lineEdit->setText("Xs - move");
        move = XOGame::xs;
    }
    else
    {
        field[i][j].setText("X");
        ui->lineEdit->setText("Os - move");
        move = XOGame::os;
    }

    field[i][j].setEnabled(false);


    XOGame::Move resultOfGame = game->checkPosition();
    if (resultOfGame != XOGame::none)
    {
        if (resultOfGame == XOGame::xs)
            ui->lineEdit->setText("Xs - winner!!!");
        else
            ui->lineEdit->setText("Os - winner!!!");
        for (int i = 0; i < fieldSize; i++)
            for (int j = 0; j < fieldSize; j++)
                field[i][j].setEnabled(false);
    }
}

