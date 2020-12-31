#include "fightwindow.h"
#include "ui_fightwindow.h"

Fightwindow::Fightwindow(int opt,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fightwindow)
{
    ui->setupUi(this);
    this->setFixedSize(1440,900);
    this->setWindowTitle("DisappearedFireTown");
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    whichFight=opt;
    view=new View(this);
    {
    buttons.append(ui->choose0);
    buttons.append(ui->choose1);
    buttons.append(ui->choose2);
    buttons.append(ui->choose3);
    buttons.append(ui->choose4);
    }
    nowfight=new Fight(whichFight);//0为测试Fight事件
    isfightend=0;
    player=new QMediaPlayer(this);
    player->setMedia(QUrl("qrc:/sound/sound/rainstreet.wav"));
    player->setVolume(40);
    player->play();
    nowfight->startFight();
    getConnet();
    showTheStatus();
    showSkills();
}

Fightwindow::~Fightwindow()
{
    delete ui;
}

void Fightwindow::keyPressEvent(QKeyEvent *event){
        switch(event->key()){
        case Qt::Key_0:emit keyMessage(0);break;
        case Qt::Key_1:emit keyMessage(1);break;
        case Qt::Key_2:emit keyMessage(2);break;
        case Qt::Key_3:emit keyMessage(3);break;
        case Qt::Key_4:emit keyMessage(4);break;
        case Qt::Key_5:emit keyMessage(5);break;
        case Qt::Key_6:emit keyMessage(6);break;
        case Qt::Key_7:emit keyMessage(7);break;
        case Qt::Key_8:emit keyMessage(8);break;
        case Qt::Key_9:emit keyMessage(9);break;
    }
}
void Fightwindow::doAction(int key){//接受键盘按键的信号的槽函数
    if(this->nowfight->status!=1) return;
    Fight* nf=this->nowfight;
    if(key>nf->nowC->skills.size()-1) return;
    bool fail=0;
switch (nf->nowC->skills[key]) {
case 1:
    nf->atk_1();break;
case 2:
    nf->getAngry_1();break;
case 3:
    if(nf->nowC->CP<20) fail=1;
    nf->penetrateShooting_1();break;
case 4:
    if(nf->nowC->CP<15) fail=1;
    nf->soberedShooting_1();break;
case 5:
    if(nf->nowC->CP<15) fail=1;
    nf->thousandShooting_1();break;
case 6:
    if(nf->nowC->CP<100) fail=1;
    nf->deadlyShooting_1();break;
case 7:
    if(nf->nowC->CP<20) fail=1;
    nf->bandageHeal_1();break;
case 14:
    if (nf->nowC->CP<5) fail=1;
    nf->changeATKDEF_1();break;
case 15:
    if (nf->nowC->CP<200) fail=1;
    nf->Endeavor_1();break;
case 16:
    if (nf->nowC->CP<10) fail=1;
    nf->Splash_1(); break;
case 17:
    nf->FocusEnergy_1();break;
case 18:
    if (nf->nowC->CP<20) fail=1;
    nf->magicatk_1(); break;
case 19:
    if (nf->nowC->CP<99) fail=1;
    nf->healPulse_1(); break;
case 20:
    nf->Guillotine_1(); break;
case 21:
    nf->staytwo_1();break;
case 71:
    if(nf->nowC->CP<5) fail=1;
    nf->record_1();break;
case 72:
    if(nf->nowC->CP<10||nf->nowC->stage!=2) fail=1;
    nf->memorize_1();break;
case 73:
    if(nf->nowC->CP<10) fail=1;
    nf->bestir_1();break;
case 74:
    if(nf->nowC->CP<70) fail=1;
    nf->timedDeceleration_1();break;
}
    if(!fail){
    showOption();
    changeToStatus2();
    }
}
void Fightwindow::finishAction(){
    Fight* nf=this->nowfight;
    if(this->nowfight->status!=3) return;
    buttonsClr();
    switch (this->nowfight->action) {
    case 1:
        this->nowfight->atk_2();
        break;
    case 2:
        nf->getAngry_2();break;
    case 3:
        nf->penetrateShooting_2();break;
    case 4:
        nf->soberedShooting_2();break;
    case 5:
        nf->thousandShooting_2();break;
    case 6:
        nf->deadlyShooting_2();break;
    case 7:
        nf->bandageHeal_2();break;
    case 8:
        nf->strongAtk_2();break;
    case 9:
        nf->dragonFire_2();break;
    case 10:
        nf->swipe_2();break;
    case 11:
        nf->rampage_2();break;
    case 12:
        nf->deadlyFire_2();break;
    case 13:
        nf->inevitableDeath_2();break;
    case 14:
        nf->changeATKDEF_2();break;
    case 15:
        nf->Endeavor_2();break;
    case 16:
        nf->Splash_2();break;
    case 17:
        nf->FocusEnergy_2();break;
    case 18:
        nf->magicatk_2();break;
    case 19:
        nf->healPulse_2();break;
    case 20:
        nf->Guillotine_2(); break;
    case 21:
        nf->staytwo_2();break;
    case 22:
        nf->vampire_2();break;
    case 23:
        nf->bloodthirsty_2();break;
    case 24:
        nf->Guillotinetwo_2(); break;
    case 71:
        nf->record_2();break;
    case 72:
        nf->memorize_2();break;
    case 73:
        nf->bestir_2();break;
    case 74:
        nf->timedDeceleration_2();break;
    case 75:
        nf->weakenFire_2();break;
    case 76:
        nf->penetrateFire_2();break;
    case 77:
        nf->finalFire_2();break;
    case 78:
        nf->summon_2();break;
    case 79:
        nf->changeStahe2_2();break;
    case 80:
        nf->fastFire_2();break;
    case 81:
        nf->memoryFire_2();break;
    }
    showResults();
    showTheStatus();
    nf->removeDied();
    repaint();
    if(nf->characterCount1<=0) {Failed();return;}
    if(nf->characterCount2<=0) {Win();return;}
    nf->chooseList.clear();
    nf->objectList.clear();
    repaint();
    nf->startFight();
    repaint();
    changeToStatus1();
    if(nf->nowC->isenemy==0){
    showSkills();
    }
    else{//当是敌人时执行AI
        nf->AIaction();
        finishAction();
        nf->removeDied();
        Sleep(1000);
    }
}
void Fightwindow::chooseObject(int key){
    Fight* nf=this->nowfight;
    if(nf->status!=2) return;
    if(key>nf->objectList.size()-1) return;
    if(nf->objectList.size()==0){
        qDebug()<<"there are'nt enough objects";
        nf->status=3;
        finishAction();
        return;
    }
    nf->chooseList.append(nf->objectList[key]);
    nf->remainNumber-=1;
    nf->objectList.remove(key);
    if(nf->remainNumber==0){
            qDebug()<<"chooes ended";
            nf->status=3;
            finishAction();
            return;
    }
}
void Fightwindow::getConnet(){
    connect(this,SIGNAL(keyMessage(int)),this,SLOT(doAction(int)));
}
void Fightwindow::changeToStatus1(){
    disconnect(this,SIGNAL(keyMessage(int)),this,SLOT(chooseObject(int)));
    connect(this,SIGNAL(keyMessage(int)),this,SLOT(doAction(int)));
}
void Fightwindow::changeToStatus2(){
    disconnect(this,SIGNAL(keyMessage(int)),this,SLOT(doAction(int)));
    connect(this,SIGNAL(keyMessage(int)),this,SLOT(chooseObject(int)));
}
void Fightwindow::showTheStatus(){
    Fight* nf=this->nowfight;
    QString myDescription=QString("%1\nHP:%2\nCP:%3\n").arg(nf->fightList[0]->name)
            .arg(nf->fightList[0]->HP).arg(nf->fightList[0]->CP);
    QString yourDescription=QString("%1\nHP:%2\nCP:%3\n").arg(nf->fightList[1]->name)
            .arg(nf->fightList[1]->HP).arg(nf->fightList[1]->CP);
    //ui->mystatus->setText(myDescription);
    //ui->yourstatus->setText(yourDescription);
}
void Fightwindow::showOption(){
    buttonsClr();
    Fight* nf=this->nowfight;
    qDebug()<<"showOption\n";
    QString options="选择你技能的施放对象\n";
    for (int i=0; i<nf->objectList.size();i++ ) {
        //options+=QString("[%1]%2\n").arg(i).arg(nf->objectList[i]->name);
        buttons[i]->setText(QString("[%1]%2\n").arg(i).arg(nf->objectList[i]->name));
    }
   // ui->othermessage_2->setText(options);
}
void Fightwindow::showSkills(){
    buttonsClr();
    Fight* nf=this->nowfight;
    QString options=QString("%1正在行动\n").arg(nf->nowC->name);
    view->message=options;view->update();
    options+=nf->nowC->skillsOption();
    Character * nowCharacter=nf->nowC;
    for(int i=0;i<nowCharacter->skills.size();i++){
        buttons[i]->setText(QString("[%1]%2\n").arg(i).arg(nowCharacter->getSkillName(nowCharacter->skills[i])));
    }
    //ui->othermessage_2->setText(options);
}
void Fightwindow::showResults(){
     Fight* nf=this->nowfight;
    //ui->othermessage_2->setText(nf->passmessage);
    view->message=nf->passmessage;view->repaint();
    qDebug()<<nf->nowC->name<<"hasshow";
    Sleep(1000);
}
void Fightwindow::Sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void Fightwindow::Win(){
    isfightend=1;
    //ui->othermessage_2->setText("You Win!");
    view->message="You Win!";view->update();
    Sleep(5000);
    emit fightend(1,whichFight,1);

}
void Fightwindow::Failed(){
    isfightend=1;
    //ui->othermessage_2->setText("You Failed!");
    view->message="You Failed";view->update();
    Sleep(5000);
    emit fightend(1,whichFight,0);
}
void Fightwindow::paintEvent(QPaintEvent *){
    QPainter painter (this);
    QPixmap fighttBackground(":/image/image/fightbackgr.png");
    painter.drawPixmap(0,0,fighttBackground);
    if(isfightend) return;
    Fight* nf=this->nowfight;
    QPen fontpen;fontpen.setColor(Qt::white);
    fontpen.setWidth(2);
    QFont nameFont;QFont statusFont;
    QBrush HPred,HPgreen;
    QPen ATpen;ATpen.setColor(Qt::white);
    ATpen.setWidth(2);
    HPred.setColor(Qt::red);HPgreen.setColor(Qt::green);
    HPred.setStyle(Qt::SolidPattern);HPgreen.setStyle(Qt::SolidPattern);
    nameFont.setFamily("Microsoft YaHei");
    nameFont.setPointSize(14);
    statusFont.setFamily("Microsoft YaHei");
    //______________________________________
    QBrush nowRectbrush;
    statusFont.setPointSize(12);
    QPen nowRectpen;
    nowRectpen.setColor(Qt::blue);
    nowRectpen.setWidth(3);
    for (int i=0;i<nf->fightList.size();i++) {
        Character *paintCharacter=nf->fightList[i];
        //画人物图片
        QPoint picturepoint=paintCharacter->paintpoint;
        painter.drawPixmap(picturepoint,paintCharacter->picture);
        QPoint namePoint(picturepoint.x()-150,picturepoint.y()+50);
        painter.setFont(nameFont);painter.setPen(fontpen);
        //画名字 HP CP 等
        painter.drawText(namePoint,paintCharacter->name);//名字
        QPoint startPoint(picturepoint.x(),picturepoint.y()+110);
        QPoint endPoint(picturepoint.x()+100,picturepoint.y()+115);
        QRect HPback(startPoint,endPoint);painter.setBrush(HPred);
        painter.drawRect(QRect(startPoint,endPoint));
        endPoint.setX(endPoint.x()-100+100*paintCharacter->HP/(double)paintCharacter->nHP);
        painter.setBrush(HPgreen);
        painter.drawRect(QRect(startPoint,endPoint));
        QPoint statusPoint(picturepoint.x()+110,picturepoint.y()+120);
        painter.setFont(statusFont);
        painter.drawText(statusPoint,QString("HP:%1").arg(paintCharacter->HP));
        statusPoint.setY(statusPoint.y()-20);
        painter.drawText(statusPoint,QString("CP:%1").arg(paintCharacter->CP));
        statusPoint.setY(statusPoint.y()-20);
        painter.drawText(statusPoint,QString("AT:%1").arg(paintCharacter->AT));
        statusPoint.setY(statusPoint.y()-20);
        painter.drawText(statusPoint,QString("DEF:%1").arg(paintCharacter->DEF));
        statusPoint.setY(statusPoint.y()-20);
        painter.drawText(statusPoint,QString("ATK:%1").arg(paintCharacter->ATK));
    }
    //画当前角色框
    painter.setBrush(nowRectbrush);painter.setPen(nowRectpen);
    Character *v=this->nowfight->nowC;
    QPoint stP=v->paintpoint;
    QPoint edP(stP.x()+100,stP.y()+100);
    QRect acting(stP,edP);
    painter.drawRect(acting);
    //画AT行动顺序
    QVector<QRect> ATRects;
    QVector<Character *> ATshow(nf->fightList);
    painter.setPen(ATpen);
    for(int i=0;i<nf->fightList.size();i++){
        for(int j=ATshow.size()-1;j>i;j--){
            if(ATshow[j]->AT<ATshow[j-1]->AT){
                Character * temp=ATshow[j];
                ATshow[j]=ATshow[j-1];
                ATshow[j-1]=temp;
            }
        }
    }
    QPixmap arrow(":/image/image/arrow.png");
    int count=ATshow.size()<=3?ATshow.size():3;
    for(int i=0;i<count;i++){
        ATRects.append(QRect(600,200+i*150,70,70));
        painter.drawRect(ATRects[i]);
        painter.drawPixmap(ATRects[i],ATshow[i]->picture,QRect(0,0,100,100));
        painter.drawText(670,225+i*150,ATshow[i]->name);
        painter.drawText(670,255+i*150,QString("AT:%1").arg(ATshow[i]->AT));
        if(i<count-1)
        painter.drawPixmap(600,275+i*150,70,70,arrow);
    }
}
void Fightwindow::mousePressEvent(QMouseEvent* event){
    if(event->y()>=700&&event->y()<=800){
        for(int i=0;i<5;i++){
            if(event->x()>=i*200&&event->x()<(i+1)*200)
                emit keyMessage(i);
        }
    }
}
void Fightwindow::buttonsClr(){
    for(int i=0;i<buttons.size();i++){
        buttons[i]->setText("");
    }
}
void Fightwindow::on_choose0_clicked()
{
    emit keyMessage(0);
}

void Fightwindow::on_choose1_clicked()
{
    emit keyMessage(1);
}

void Fightwindow::on_choose2_clicked()
{
    emit keyMessage(2);
}

void Fightwindow::on_choose3_clicked()
{
    emit keyMessage(3);
}

void Fightwindow::on_choose4_clicked()
{
    emit keyMessage(4);
}
