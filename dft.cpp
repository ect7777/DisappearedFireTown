#include "dft.h"
#include "ui_dft.h"

DFT::DFT(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DFT)
{
    ui->setupUi(this);
}

DFT::~DFT()
{
    delete ui;
}

