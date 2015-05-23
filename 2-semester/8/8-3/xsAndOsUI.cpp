#include "xsAndOsUIi.h"
#include "ui_xsandosui.h"

XsAndOsUI::XsAndOsUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::XsAndOsUI)
{
    ui->setupUi(this);

    statusLine = new QLineEdit;
    ui->centralWidget->setLayout(ui->gridLayout);

    delete ui->lineEdit;

    fieldSize = 3;

    ui->gridLayout->addWidget(statusLine, 0, 0, 1, fieldSize);
    statusLine->setText("Xs - move");

    signalMapper = new QSignalMapper(this);
    move = XOGame::xs;

    game = new XOGame(fieldSize);

    field = new QPushButton*[fieldSize];
    for (int i = 0; i < fieldSize; i++)
        field[i] = new QPushButton[fieldSize];

    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
        {
            connect(&field[i][j], SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(&field[i][j], fieldSize * i + j);
            ui->gridLayout->addWidget(&field[i][j], i + 1, j);
        }
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(play(int)));

}

XsAndOsUI::~XsAndOsUI()
{
    delete statusLine;
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
        statusLine->setText("Xs - move");
        move = XOGame::xs;
    }
    else
    {
        field[i][j].setText("X");
        statusLine->setText("Os - move");
        move = XOGame::os;
    }

    field[i][j].setEnabled(false);


    XOGame::Move resultOfGame = game->checkPosition();
    if (resultOfGame != XOGame::none)
    {
        if (resultOfGame == XOGame::xs)
            statusLine->setText("Xs - winner!!!");
        else
        if (resultOfGame == XOGame::os)
            statusLine->setText("Os - winner!!!");
        else
            statusLine->setText("Draw!!!");


        for (int i = 0; i < fieldSize; i++)
            for (int j = 0; j < fieldSize; j++)
                field[i][j].setEnabled(false);
    }
}

