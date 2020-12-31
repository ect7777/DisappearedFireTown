#include "dft.h"
#include "ui_dft.h"

DFT::DFT(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DFT)
{
    ui->setupUi(this);
    this->setFixedSize(1440,900);
    this->setWindowTitle("DisappearedFireTown");
    mybutton *but1=new mybutton(":/image/image/start.png");
    mybutton *but2=new mybutton(":/image/image/CONTINUE.png");
    mybutton *but3=new mybutton(":/image/image/EXIT.png");
    but1->setParent(this);
    but1->move(800,200);
    but2->setParent(this);
    but2->move(800,400);
    but3->setParent(this);
    but3->move(800,600);
    connect(but1,SIGNAL(clicked()),this,SLOT(firststart()));
    connect(but2,SIGNAL(clicked()),this,SLOT(continueGame()));
    connect(but3,SIGNAL(clicked()),this,SLOT(close()));
    player=new QMediaPlayer(this);
    player->setMedia(QUrl("qrc:/sound/sound/my heart.wav"));
    player->setVolume(40);
    player->play();
}
DFT::~DFT()
{
    delete ui;
}
void DFT::paintEvent(QPaintEvent *){
    QPixmap * pix=new QPixmap(":/image/image/DFTbackgr.png");//此处改为背景图片
    QPixmap *title=new QPixmap(":/image/image/Disappeared_Firetown.png");
    QPainter *painter=new QPainter(this);
    painter->drawPixmap(0,0,this->width(),this->height(),*pix);
    painter->drawPixmap(100,100,600,400,*title);
    painter->end();
}
void DFT::changeToFight(int key){
    FW=new Fightwindow(key);
    player->stop();
    this->hide();FW->show();
    connect(FW,SIGNAL(fightend(int,int,bool)),this,SLOT(changeToMenu(int,int,bool)));
}
void DFT::changeToMenu(int whatWindow,int key,bool isWin=0) {
    if(whatWindow==1)//表示是战斗窗口结束
        {
        FW->player->stop();
        FW->close();
        this->show();
        if(isWin==0)
        {//战斗失败
            changeToFight(key);return;//重新战斗
        }
        else
            {
            switch(key){
            case 1:savenow(1,3);changeToPlot(3);break;
            case 2:savenow(1,4);changeToPlot(4);break;
            case 3:savenow(1,7);changeToPlot(7);break;
            case 4:savenow(1,8);changeToPlot(8);break;
            case 8:savenow(1,10);changeToPlot(10);break;
            }
        }
        }
    else if(whatWindow==2)
    {//如果是剧情窗口
        pW->player->stop();
        pW->close();
        this->show();
        switch(key){
        case 1:savenow(1,2);changeToPlot(2);break;
        case 2:savenow(0,1);changeToFight(1);break;
        case 3:savenow(0,2);changeToFight(2);break;
        case 4:savenow(1,5);changeToPlot(5);break;
        case 5:savenow(1,6);changeToPlot(6);break;
        case 6:savenow(0,3);changeToFight(3);break;
        case 7:savenow(0,4);changeToFight(4);break;
        case 8:savenow(1,9);changeToPlot(9);break;
        case 9:savenow(0,8);changeToFight(8);break;
        case 10:player->play();break;
        }
    }
}
void DFT::changeToPlot(int key){
    pW=new plot(key);
    player->stop();
    this->hide();pW->show();
    connect(pW,SIGNAL(plotend(int,int,bool)),this,SLOT(changeToMenu(int,int,bool)));
}

//关于剧情与战斗转换的关系
/* 剧情1-》剧情2-》战斗1-》剧情3-》战斗2-》剧情4*/
void DFT::firststart(){
    save_load=new QFile("savedata");
    save_load->open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream rd(save_load);
    rd.operator<<("p1");
    save_load->close();
    changeToPlot(1);
}
void DFT::on_pushButton_clicked()
{
}
void DFT::continueGame(){
    save_load=new QFile("savedata");
    if(!save_load->open(QIODevice::ReadOnly|QIODevice::Text))
        return;
    QTextStream rd(save_load);
    QString message=rd.readAll();
    if(message[0]=='p'){
        changeToPlot(message[1].digitValue());
    }
    else{
        changeToFight(message[1].digitValue());
    }
}
void DFT::savenow(bool isPlot,int key){
    save_load=new QFile("savedata");
    save_load->open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream rd(save_load);
    if(isPlot)
    rd.operator<<(QString("p%1").arg(key));
    else
    rd.operator<<(QString("f%1").arg(key));
    save_load->close();
}

