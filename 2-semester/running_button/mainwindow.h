#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QTextEdit>

#include <ctime>
#include <stdlib.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    bool eventFilter(QObject *object, QEvent *event);
    void fail();

private:
    void drawWindow();
    void makePointArray();
    bool areFarPoints(QPoint first, QPoint second);

    Ui::MainWindow *ui;
    QPoint *array;
    int currentPosition;
    int numberOfPositions;
};

