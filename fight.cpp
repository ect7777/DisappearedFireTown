#include "fight.h"

Fight::Fight(int num)
{
    this->status=1;
    switch (num) {
    case 0:{
        Character *my1,*ene1;
        my1=new Character(0,"ZERO");
        this->fightList.append(my1);
        ene1=new Character(11,"Fire Dog");
        this->fightList.append(ene1);
        this->characterCount1=1;
        this->characterCount2=1;
        break;
    }
    case 1:{
        Character *p;
        p=new Character(1,"陈刚");this->fightList.append(p);
        p->paintpoint=QPoint(200,100);
        p=new Character(2,"队员A");this->fightList.append(p);
        p->paintpoint=QPoint(200,300);
        p=new Character(2,"队员B");this->fightList.append(p);
        p->paintpoint=QPoint(200,500);
        p=new Character(11,"三头犬1");this->fightList.append(p);
        p->paintpoint=QPoint(1000,100);
        p=new Character(11,"三头犬2");this->fightList.append(p);
        p->paintpoint=QPoint(1000,300);
        p=new Character(11,"三头犬3");this->fightList.append(p);
        p->paintpoint=QPoint(1000,500);
        this->characterCount1=3;
        this->characterCount2=3;
        break;
    }
    case 2:{
        Character *p;
        p=new Character(1,"陈刚");this->fightList.append(p);
        p->paintpoint=QPoint(200,100);
        p=new Character(2,"队员A");this->fightList.append(p);
        p->paintpoint=QPoint(200,300);
        p=new Character(2,"队员B");this->fightList.append(p);
        p->paintpoint=QPoint(200,500);
        p=new Character(12,"火焰巨龙");this->fightList.append(p);
        p->paintpoint=QPoint(1000,300);
        this->characterCount1=3;
        this->characterCount2=1;
        break;
    }
    case 3:{
        Character *p;
        p=new Character(3,"迟锋");this->fightList.append(p);
        p->paintpoint=QPoint(200,300);
        p=new Character(13,"迟焱");this->fightList.append(p);
        p->paintpoint=QPoint(1000,300);
        this->characterCount1=1;
        this->characterCount2=1;
        break;
    }
    case 4:{
        Character *p;
        p=new Character(4,"迟锋");this->fightList.append(p);
        p->paintpoint=QPoint(200,300);
        p=new Character(14,"熔火巨兽");this->fightList.append(p);
        p->paintpoint=QPoint(1000,300);
        this->characterCount1=1;
        this->characterCount2=1;
        break;
    }
    case 7:{
        Character *p;
        p=new Character(0,"zero");this->fightList.append(p);
        p->paintpoint=QPoint(200,100);
        p=new Character(12,"火焰巨龙");this->fightList.append(p);
        p->paintpoint=QPoint(1000,300);
        p=new Character(70,"灵火1");this->fightList.append(p);
        p->paintpoint=QPoint(1000,100);
        p=new Character(70,"灵火2");this->fightList.append(p);
        p->paintpoint=QPoint(1000,500);
        this->characterCount1=1;
        this->characterCount2=3;
        break;
    }
    case 8:{
        Character *p;
        p=new Character(0,"zero");this->fightList.append(p);
        p->paintpoint=QPoint(200,100);
        p=new Character(71,"灵魂烈焰");this->fightList.append(p);
        p->paintpoint=QPoint(1000,300);
        this->characterCount1=1;
        this->characterCount2=1;
        break;
    }
    }
}
void Fight::startFight(){//需要重写
    int minn=10000;
    nextC=0;
    int sum=fightList.size();
    for(int i=0;i<sum;i++){
        if((*fightList[i]).AT<minn){
            nextC=i;minn=(*fightList[i]).AT;
            }
        }
    this->nowC=fightList[nextC];
    if(nowC->isenemy==0)
    this->status=1;
    for(int i=0;i<fightList.size();i++){
        (*fightList[i]).AT-=minn;
    }
}
void Fight::getObject(int opt){
        //opt==1，寻找敌对目标 opt==0 寻找友方目标opt==3自己
        if(opt==3) objectList.append(nowC);
        else{
        bool identiy=this->nowC->isenemy;
        identiy^=opt;
        for(int i=0;i<this->fightList.size();i++){
            if((this->fightList[i])->isenemy==identiy){
                this->objectList.append(this->fightList[i]);//把所有目标列入objlist当中
            }
        }
        }
    this->status=2;//选定目标模式
}
void Fight::AIaction(){
    switch(nowC->ID){
    case 11://小火狗
    if(nowC->CP>=50){
        strongAtk_1();
    }
    else{
        int opt=QRandomGenerator::global()->bounded(1,4);//产生随机数
        if(opt==3){getAngry_1();}
            else {
            atk_1();
        }
    }
    break;
    //_________________________________________________
    case 12://dragon
        if(nowC->stage==1){
        if(nowC->HP<=1000) rampage_1();
        else if(nowC->CP>=30){
            int opt=QRandomGenerator::global()->bounded(1,3);//产生随机数
            if(opt==1){dragonFire_1();}
                else {
                swipe_1();
            }
        }
        else
            dragonFire_1();
        }
        else{
            if(nowC->CP>=100){
                inevitableDeath_1();
            }
            else deadlyFire_1();
        }
        break;
    case 13:
        if (nowC->CP<99)
        {
            FocusEnergy_1();
            break;
        }
        if (nowC->HP<=500)
        {
            healPulse_1();
            break;
        }
        else{int opt=QRandomGenerator::global()->bounded(1,5);
        if (opt==1) atk_1();
        else magicatk_1();}
        break;
    case 14:
        if (nowC->stage==1)
        {
            Guillotine_1();
            nowC->stage++;
        }
        else
        if (nowC->stage==2)
        {
            vampire_1();
            nowC->stage++;
        }
        else
        {
            if (nowC->CP>=200)
            {
                int opt=QRandomGenerator::global()->bounded(1,3);
                if (opt==2) Guillotinetwo_1();
                else vampire_1();
            }
            else
            if (nowC->CP>=20) {
                int opt=QRandomGenerator::global()->bounded(1,3);
                if (nowC->HP>250&&opt!=2) bloodthirsty_1();
                else vampire_1();
            }
            else if (nowC->HP>185) bloodthirsty_1();
            else staytwo_1();
        }
        break;
    case 70:
        if(nowC->CP>=100) finalFire_1();
        else{
            int opt=QRandomGenerator::global()->bounded(1,3);//产生随机数
            if(opt==1){penetrateFire_1();}
                else {
                weakenFire_1();
            }
        }
        break;
    case 71:
        if(nowC->log[0]==2){
            changeStage2_1();break;
        }
        if(nowC->stage==1){
            if(nowC->CP>=50){
                summon_1();
            }
            else{
                int opt=QRandomGenerator::global()->bounded(1,3);//产生随机数
                if(opt==1){penetrateFire_1();}
                    else {
                    weakenFire_1();
                }
            }
        }
        else{
            if(nowC->CP>=100){
                memoryFire_1();
            }
            else fastFire_1();
        }
        break;
    }
    while(remainNumber>0&&objectList.size()>0){
          int key=QRandomGenerator::global()->bounded(0,objectList.size());
          chooseList.append(objectList[key]);
          remainNumber-=1;
          objectList.remove(key);
    }
    status=3;
}
void Fight::removeDied(){
    for(int i=0;i<fightList.size();i++){
        if(fightList[i]->HP<=0){
            if(fightList[i]->isenemy) characterCount2--;
            else characterCount1--;
            fightList.remove(i);
        }
    }
}
//__________________________________________________________
void Fight::atk_1(){
    this->action=1;
    this->remainNumber=1;
    this->getObject(1);
}
void Fight::atk_2(){
    if(nowC->ID==1||nowC->ID==2){
        QSound *q=new QSound(":/sound/sound/shooting.wav");
        q->play();
    }
    else{
        QSound *q=new QSound(":/sound/sound/atk.wav");
        q->play();
    }
        passmessage="";
        Character* v=chooseList[0];
        int demage=nowC->ATK;
        demage=(int)(demage*(1.0-v->DEF/100.0));
        v->HP-=demage;
        if(v->HP<0) v->HP=0;
        passmessage+=QString("%1对%2进行了攻击，造成了%3点伤害\n").arg(nowC->name).arg(v->name).arg(demage);
        this->nowC->AT+=20;
        this->nowC->CP+=20;
        v->CP+=10;
}
void Fight::getAngry_1(){
    this->action=2;
    this->remainNumber=1;
    this->getObject(3);
}
void Fight::getAngry_2(){
    QSound *q=new QSound(":/sound/sound/dog.wav");
    q->play();
    passmessage="";
    for(int i=0;i<chooseList.size();i++){
        Character* v=chooseList[i];
        v->ATK*=2;
        passmessage+=QString("%1生气了，攻击力上升").arg(nowC->name);
    }
    this->nowC->AT+=20;
}
void Fight::strongAtk_1(){
    if(this->nowC->CP<50) return;
    this->action=8;
    this->remainNumber=1;
    this->getObject(1);
}
void Fight::strongAtk_2(){
    QSound *q=new QSound(":/sound/sound/atk.wav");
    q->play();
    passmessage="";
    Character* v=chooseList[0];
    int demage=nowC->ATK*2;
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    passmessage+=QString("%1对%2进行了强力撕咬，造成了%3点伤害\n").arg(nowC->name).arg(v->name).arg(demage);
    this->nowC->AT+=23;
    this->nowC->CP-=50;
    v->CP+=10;
}
void Fight::bandageHeal_1(){
    if(this->nowC->CP<20) return;
    this->action=7;
    this->remainNumber=1;
    this->getObject(0);//0表示友方目标
}
void Fight::bandageHeal_2(){
    QSound *q=new QSound(":/sound/sound/heal.wav");
    q->play();
    passmessage="";
    Character* v=chooseList[0];
    int heal=400;if(v->nHP-v->HP<400) heal=v->nHP-v->HP;
    v->HP+=heal;
    passmessage+=QString("%1对%2使用绷带进行了治疗，%2回复了%3点生命").arg(nowC->name).arg(v->name).arg(heal);
    this->nowC->AT+=15;
    this->nowC->CP-=20;
}
void Fight::penetrateShooting_1(){
    if(this->nowC->CP<20) return;
    this->action=3;this->remainNumber=1;
    this->getObject(1);
}
void Fight::penetrateShooting_2(){
    QSound *q=new QSound(":/sound/sound/shooting.wav");
    q->play();
    passmessage="";
    Character* v=chooseList[0];
    int demage=(int)(nowC->ATK*1.5);
    v->DEF-=10;
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    if(v->DEF<0) v->DEF=0;
    passmessage+=QString("%1对%2射出了穿心一箭，%2受到了%3点伤害，防御下降了").arg(nowC->name).arg(v->name).arg(demage);
    this->nowC->AT+=21;
    this->nowC->CP-=20;
    v->CP+=10;
}
void Fight::soberedShooting_1(){
    if(this->nowC->CP<15) return;
    this->action=4;this->remainNumber=1;
    this->getObject(1);
}
void Fight::soberedShooting_2(){
    QSound *q=new QSound(":/sound/sound/shooting.wav");
    q->play();
    passmessage="";
    Character* v=chooseList[0];
    int demage=(int)(nowC->ATK*1.1);
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    v->ATK=v->nATK;
    passmessage+=QString("%1射中了%2，%2受到了%3点伤害，%2冷静下来了").arg(nowC->name).arg(v->name).arg(demage);
    this->nowC->AT+=20;
    this->nowC->CP-=15;
    v->CP+=10;
}
void Fight::thousandShooting_1(){
    if(this->nowC->CP<15) return;
    this->action=5;this->remainNumber=characterCount2;
    this->getObject(1);//敌方全体
}
void Fight::thousandShooting_2(){
    QSound *q=new QSound(":/sound/sound/shooting.wav");
    q->play();
    passmessage=QString("%1万箭齐发 ").arg(nowC->name);
    for(int i=0;i<chooseList.size();i++){
    Character* v=chooseList[i];
    int demage=(int)(nowC->ATK);
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    passmessage+=QString("对%1造成%2伤害 ").arg(v->name).arg(demage);
    v->CP+=10;
    }
    this->nowC->AT+=15;
    this->nowC->CP-=15;
}
void Fight::deadlyShooting_1(){
    if(this->nowC->CP<100) return;
    this->action=6;this->remainNumber=1;
    this->getObject(1);
}
void Fight::deadlyShooting_2(){
    QSound *q=new QSound(":/sound/sound/shooting.wav");
    q->play();
    passmessage="";
    Character* v=chooseList[0];
    int demage=(int)(nowC->ATK*15.0);
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    passmessage+=QString("%1百步穿杨，射中了%2的要害,造成%3伤害").arg(nowC->name).arg(v->name).arg(demage);
    this->nowC->AT+=44;
    this->nowC->CP-=100;
    v->CP+=10;
}
void Fight::dragonFire_1(){
    this->action=9;this->remainNumber=1;
    this->getObject(1);
}
void Fight::dragonFire_2(){
    passmessage="";
    Character* v=chooseList[0];
    int demage=(int)(nowC->ATK);
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    v->DEF-=10;
    if(v->DEF<0) v->DEF=0;
    passmessage+=QString("%1吐出炙热的火焰，对%2造成%3伤害，并破坏了护甲").arg(nowC->name).arg(v->name).arg(demage);
    this->nowC->AT+=25;
    this->nowC->CP+=20;
    v->CP+=10;
}
void Fight::swipe_1(){
    if(nowC->CP<30) return;
    this->action=10;this->remainNumber=characterCount1;
    this->getObject(1);
}
void Fight::swipe_2(){
    passmessage=QString("%1使用龙爪横扫").arg(nowC->name);
    for(int i=0;i<chooseList.size();i++){
    Character* v=chooseList[i];
    int demage=(int)(nowC->ATK*1.2);
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    v->CP+=10;
    passmessage+=QString("对%1造成%2伤害").arg(v->name).arg(demage);
    }
    this->nowC->AT+=24;
}
void Fight::rampage_1(){
    this->action=11;this->remainNumber=1;
    getObject(3);
}
void Fight::rampage_2(){
    passmessage=QString("%1狂暴了，战斗力大幅上升").arg(nowC->name);
     Character* v=chooseList[0];
     v->HP=1250;
     v->stage=2;v->ATK+=50;v->DEF=20;
     v->CP=0;v->AT+=1;
}
void Fight::deadlyFire_1(){
    this->action=12;this->remainNumber=3;
    getObject(1);
}
void Fight::deadlyFire_2(){
    /*
    passmessage=QString("%1使用龙爪横扫").arg(nowC->name);
    for(int i=0;i<chooseList.size();i++){
    Character* v=chooseList[i];
    int demage=(int)(nowC->ATK*1.2);
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    passmessage+=QString("对%2造成%3伤害").arg(nowC->name).arg(v->name).arg(demage);
    }
    this->nowC->AT+=25;
    */
    passmessage=QString("%1吐出焚骨的烈焰").arg(nowC->name);
    for(int i=0;i<chooseList.size();i++){
    Character* v=chooseList[i];
    int demage=500;
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    passmessage+=QString("对%1造成%2伤害").arg(v->name).arg(demage);
    v->CP+=10;
    }
    this->nowC->AT+=38;
    this->nowC->CP+=25;
}
void Fight::inevitableDeath_1(){
    this->action=13;this->remainNumber=1;
    getObject(1);
}
void Fight::inevitableDeath_2(){
    passmessage=QString("%1发出古老的魔音，").arg(nowC->name);
    Character* v=chooseList[0];
    int demage=v->HP;
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    passmessage+=QString("%1听到死神的低语，受到%2伤害").arg(v->name).arg(demage);
    this->nowC->AT+=100;
    this->nowC->CP-=100;
    v->CP+=10;
}
void Fight::record_1(){
    if(nowC->CP<5) return;
    this->action=71;this->remainNumber=1;
    getObject(3);
}
void Fight::record_2(){
    passmessage=QString("%1记住了当下").arg(nowC->name);
    nowC->log[0]=nowC->HP;
    nowC->log[1]=nowC->ATK;
    nowC->log[2]=nowC->DEF;
    nowC->stage=2;
    nowC->AT+=5;nowC->CP-=5;
}
void Fight::memorize_1(){
    if(nowC->CP<10) return;
    if(nowC->stage!=2) return;
    this->action=72;this->remainNumber=1;
    getObject(1);
}
void Fight::memorize_2(){
    passmessage=QString("%1将回忆与现实重叠,HP回复，但记忆消失了").arg(nowC->name);
    Character* v=chooseList[0];
    int demage=nowC->log[0]-nowC->HP;
    nowC->nHP-=100;
    nowC->HP+=demage;if(nowC->HP>nowC->nHP) nowC->HP=nowC->nHP;
    demage+=(int)nowC->ATK*1.5;
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;if(v->HP<0) v->HP=0;
    passmessage+=QString("对%2造成%3伤害").arg(v->name).arg(demage);
    nowC->stage=1;
    nowC->AT+=12;nowC->CP-=10;v->CP+=10;
}
void Fight::bestir_1(){
    if(nowC->CP<10) return;
    this->action=73;this->remainNumber=1;
    getObject(1);
}
void Fight::bestir_2(){
    passmessage=QString("%1将回忆与现实重叠，ATK和DEF得到强化").arg(nowC->name);
    Character *v=chooseList[0];
    nowC->ATK+=20;nowC->DEF+=15;
    if(nowC->DEF>90) nowC->DEF=90;
    int demage=(int)nowC->ATK*1.2;
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;if(v->HP<0) v->HP=0;
    nowC->nHP-=50;if(nowC->HP>nowC->nHP) nowC->HP=nowC->nHP;
    passmessage+=QString("对%2造成%3伤害").arg(v->name).arg(demage);
    nowC->AT+=12;nowC->CP-=10;v->CP+=10;
}
void Fight::timedDeceleration_1(){
    if(nowC->CP<70) return;
    this->action=74;this->remainNumber=1;
    getObject(1);
}
void Fight::timedDeceleration_2(){
    passmessage=QString("%1掷出时光的流沙，");
    Character *v=chooseList[0];
    nowC->nHP-=200;if(nowC->HP>nowC->nHP) nowC->HP=nowC->nHP;
    int demage=(int)nowC->ATK*5;
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;if(v->HP<0) v->HP=0;
    v->AT+=70;v->CP+=10;
    passmessage+=QString("%2受到%3伤害，动作变得迟缓").arg(v->name).arg(demage);
    nowC->CP-=70;nowC->AT+=20;
}
void Fight::weakenFire_1(){
    this->action=75;
    this->remainNumber=1;
    this->getObject(1);
}
void Fight::weakenFire_2(){
    passmessage="";
    Character* v=chooseList[0];
    int demage=nowC->ATK*2;
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    v->ATK-=20;
    passmessage+=QString("%1用苍白色的火焰灼烧%2，造成了%3点伤害，%2力量变弱了\n").arg(nowC->name).arg(v->name).arg(demage);
    this->nowC->AT+=20;
    this->nowC->CP+=40;
    v->CP+=10;
}
void Fight::penetrateFire_1(){
    this->action=76;
    this->remainNumber=1;
    this->getObject(1);
}
void Fight::penetrateFire_2(){
    passmessage="";
    Character* v=chooseList[0];
    int demage=nowC->ATK*2;
    v->DEF-=10;
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    passmessage+=QString("%1用冷白色的火焰灼烧%2，造成了%3点伤害，%2防御变弱了\n").arg(nowC->name).arg(v->name).arg(demage);
    this->nowC->AT+=20;
    this->nowC->CP+=40;
    v->CP+=10;
}
void Fight::finalFire_1(){
    this->action=77;this->remainNumber=1;
    this->getObject(1);
}
void Fight::finalFire_2(){
    passmessage="";
    Character* v=chooseList[0];
    int demage=nowC->ATK*5;
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    nowC->HP=0;
    passmessage+=QString("%1燃烧灵魂，对%2造成了%3点伤害\n").arg(nowC->name).arg(v->name).arg(demage);
    this->nowC->AT+=1000;
    this->nowC->CP=0;
    v->CP+=10;
}
void Fight::summon_1(){
    if(nowC->CP<50) return;
    this->action=78;this->remainNumber=1;
    this->getObject(3);
}
void Fight::summon_2(){
    nowC->log[0]+=1;
    passmessage=QString("%1发出了召唤\n").arg(nowC->name);
    Character *p=new Character(70,QString("灵火%1").arg(nowC->log[0]));
    switch ( nowC->log[0]) {
    case 1:p->paintpoint=QPoint(1000,100);break;
    case 2:p->paintpoint=QPoint(1000,500);break;
    }
    fightList.append(p);
    characterCount2++;
    this->nowC->AT+=50;
    this->nowC->CP-=50;
}
void Fight::changeStage2_1(){
    this->action=79;this->remainNumber=1;
    this->getObject(3);
}
void Fight::changeStahe2_2(){
    nowC->log[0]+=1;
    passmessage=QString("%1发出了召唤\n").arg(nowC->name);
    Character *p1=new Character(70,QString("灵火3"));
    Character *p2=new Character(70,QString("灵火4"));
    p1->paintpoint=QPoint(700,200);
    p2->paintpoint=QPoint(700,400);
    fightList.append(p1);fightList.append(p2);
    characterCount2+=2;
    nowC->stage=2;
    this->nowC->AT+=50;
}
void Fight::fastFire_1(){
    this->action=80;this->remainNumber=1;
    this->getObject(1);
}
void Fight::fastFire_2(){
    passmessage="";
    Character* v=chooseList[0];
    int demage=(int)(nowC->ATK*2);
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    passmessage+=QString("%1释放了急速的火焰，对%2造成%3伤害").arg(nowC->name).arg(v->name).arg(demage);
    this->nowC->AT+=12;
    this->nowC->CP+=15;
    v->CP+=10;
}
void Fight::memoryFire_1(){
    if(nowC->CP<100) return;
    this->action=81;this->remainNumber=1;
    this->getObject(1);
}
void Fight::memoryFire_2(){
    passmessage="";
    Character* v=chooseList[0];
    int demage=(int)(nowC->ATK*5);
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    passmessage+=QString("%1用远古的记忆为火种引燃火焰，对%2造成%3伤害，并融化了护甲").arg(nowC->name).arg(v->name).arg(demage);
    v->DEF=0;
    this->nowC->AT+=30;
    this->nowC->CP-=100;
    v->CP+=10;
}
//_____________________________________zyy's
void Fight::changeATKDEF_1()
{
    if (this->nowC->CP<5) return;
    this->action=14;this->remainNumber=1;
    getObject(3);
}
void Fight::changeATKDEF_2()
{
    passmessage=QString("%1改变了作战方式").arg(nowC->name);
    int t;
    nowC->ATK/=2;
    t=nowC->DEF; nowC->DEF=nowC->ATK; nowC->ATK=t;
    nowC->ATK*=2;
    nowC->CP-=5;
    nowC->AT+=5;
}
void Fight::Endeavor_1()
{
    if (this->nowC->CP<200) return;
    this->action=15; this->remainNumber=1;
    getObject(1);
}
void Fight::Endeavor_2()
{
    Character* v=chooseList[0];
    if (v->HP<=nowC->HP) passmessage=QString("这是无效的");
            else{
                    v->HP=nowC->HP;
                    passmessage=QString("%1拼尽全力，让%2与%1生命相同").arg(nowC->name).arg(v->name);
                    nowC->CP-=200;
                    nowC->AT+=10;
                }
}
void Fight::Splash_1()
{
    if (nowC->CP<5) return;
    this->action=16;this->remainNumber=1;
    getObject(3);
}
void Fight::Splash_2()
{
    passmessage=QString("%1正在观察").arg(nowC->name);
    nowC->AT+=10;
    nowC->CP-=5;
}
void Fight::FocusEnergy_1()
{

    this->action=17;this->remainNumber=1;
    getObject(3);
}
void Fight::FocusEnergy_2()
{
    passmessage=QString("%1凝聚了力量").arg(nowC->name);
    nowC->AT+=25;
    nowC->CP=99;
}
void Fight::magicatk_1()
{
    if (nowC->CP<20) return;
    this->action=18; this->remainNumber=1;
    getObject(1);
}
void Fight::magicatk_2()
{
    passmessage="";
    Character* v=chooseList[0];
    int demage=nowC->CP;
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    passmessage+=QString("%1对%2进行了魔法攻击，造成了%3点伤害\n").arg(nowC->name).arg(v->name).arg(demage);
    this->nowC->AT+=25;
    this->nowC->CP-=20;
    v->CP+=10;
}
void Fight::healPulse_1()
{
    if (nowC->CP<99) return;
    this->action=19; this->remainNumber=1;
    getObject(3);
}
void Fight::healPulse_2()
{
    nowC->nHP-=2000;
    nowC->HP=nowC->nHP;
    passmessage=QString("%1献祭自己回满自己的血量").arg(nowC->name);
    nowC->CP=0;
    nowC->AT+=40;
}
void Fight::Guillotine_1()
{
    this->action=20; this->remainNumber=1;
    getObject(1);
}
void Fight::Guillotine_2()
{
    passmessage="";
    Character* v=chooseList[0];
    int demage=2500;
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    if(v->HP<0) v->HP=0;
    passmessage+=QString("%1对%2进行了致命一击，造成了%3点伤害\n").arg(nowC->name).arg(v->name).arg(demage);
    this->nowC->AT+=5;
    v->CP+=10;
}
void Fight::staytwo_1()
{
    this->action=21; this->remainNumber=1;
    getObject(3);
}
void Fight::staytwo_2()
{
    passmessage=QString("%1无所事事").arg(nowC->name);
    this ->nowC->AT+=20;
}
void Fight::vampire_1()
{
    if (nowC->CP<20) return;
    this->action=22; this->remainNumber=1;
    getObject(1);
}
void Fight::vampire_2()
{
    passmessage="";
    Character* v=chooseList[0];
    int demage=nowC->ATK;
    demage=(int)(demage*(1.0-v->DEF/100.0));
    v->HP-=demage;
    nowC->HP+=demage;
    if(v->HP<0) v->HP=0;
    passmessage+=QString("%1对%2进行了吸血攻击，造成了%3点伤害\n").arg(nowC->name).arg(v->name).arg(demage);
    this->nowC->AT+=20;
    this->nowC->CP-=20;
    v->CP+=10;
}
void Fight::bloodthirsty_1()
{
    this->action=23; this->remainNumber=1;
    getObject(3);
}
void Fight::bloodthirsty_2()
{
    nowC->HP-=15;
    nowC->CP+=15;
    passmessage=QString("%1献祭自己的生命，获得了能量");
    nowC->AT+=5;
}
void Fight::Guillotinetwo_1()
{
    this->action=24; this->remainNumber=1;
    getObject(1);
}
void Fight::Guillotinetwo_2()
{
    passmessage="";
    Character* v=chooseList[0];
    int demage=450;
    v->HP-=demage;
    nowC->HP+=demage;
    if(v->HP<0) v->HP=0;
    passmessage+=QString("%1对%2进行了猛烈的攻击，造成了%3点伤害\n").arg(nowC->name).arg(v->name).arg(demage);
    this->nowC->AT+=150;
    this->nowC->CP-=150;
    v->CP+=10;
}


