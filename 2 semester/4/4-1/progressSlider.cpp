#include "progressSlider.h"
#include "ui_progressSlider.h"

ProgressSlider::ProgressSlider(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProgressSlider)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
}

ProgressSlider::~ProgressSlider()
{
    delete ui;
}
