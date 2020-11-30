#include "dft.h"
#include "ui_dft.h"
#include<QMetaProperty>

DFT::DFT(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DFT)
{
    ui->setupUi(this);
    c1=new Character("xiaoming",100,0,1);
    connect(c1,SIGNAL(hpcg(int)),this,SLOT(onAtk()));
    c2=new Character("xiaoc",110,0,3);
    connect(c2,SIGNAL(hpcg(int)),this,SLOT(onAtk()));
    //初始化文本框的值
    ui->lineEdit->setText(QString::number(c1->hp()));
    ui->lineEdit_2->setText(QString::number(c1->cp()));
    ui->lineEdit_3->setText(QString::number(c2->hp()));
    ui->lineEdit_4->setText(QString::number(c2->cp()));
}
DFT::~DFT()
{
    delete ui;
}
void DFT::atk(Character* u){
    //u的hp-10
    int temp=u->hp()-10;//temp为临时变量
    u->setHp(temp);
}
void DFT::update(Character*u,int ID){
    switch(ID)
    {
    case 1:ui->lineEdit->setText(QString::number(u->hp()));break;
    case 3:ui->lineEdit_3->setText(QString::number(u->hp()));break;
    }
}

void DFT::heroAtk()
{//hero攻击
    //atk(c2);
}

void DFT::enemyAtk()
{//enemy攻击
    //atk(c1);
}

void DFT::onAtk()
{//u是当前进行操作的对象
    Character* u=qobject_cast<Character *>(sender());
    update(u,u->ID());
}
void DFT::on_pushButton_2_clicked()
{//hero攻击
    atk(c2);
}

void DFT::on_pushButton_3_clicked()
{//enemy攻击
    atk(c1);
}
