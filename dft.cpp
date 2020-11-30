#include "dft.h"
#include "ui_dft.h"
#include<QMetaProperty>

DFT::DFT(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DFT)
{
    ui->setupUi(this);
    Character* a=new Character("Zoom",100,0);
    Character* b=new Character("Mike",20,0);
}
DFT::~DFT()
{
    delete ui;
}

