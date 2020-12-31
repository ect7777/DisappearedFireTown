#ifndef FIGHT_H
#define FIGHT_H

#include <QObject>
#include<QRandomGenerator>
#include "character.h"

class Fight :public QObject
{
    Q_OBJECT
public:
    Fight(int num);//num代表序号，可以知道进行的是哪场战斗
    Character getObject(int type,Character* nowC);//nowC为当前进行决策的角色
    QVector<Character*> fightList;//战斗序列
    QVector<Character*> objectList;//可选序列
    QVector<Character*> chooseList;//选定序列
    //变量定义
    int action=0;//用来表示当前角色正在进行的活动是什么
    int nextC;
    Character * nowC;//当前操作的角色，由startFight函数获取
    int status=0;//该变量用于指示该战斗正在处于什么状态下
    int characterCount1=0,characterCount2=0;
    int remainNumber=0;//该变量用来表示当前的行动还需要选定多少个对象
    QString passmessage;
    //status=0 表示选择操作对象中 status=1 表示正在准备接受操作指令 status=2 表示正在进行选择目标指令
    //_________________________________________________________________________________________________________________________
    void startFight();//用于寻找下一个操作对象
    void removeDied();
    void getObject(int opt);
    void AIaction();
    /* 以下全部为与操作相关的函数，每个都可以实现一个功能 此处应该函数繁多 特此警告*/
    void atk_1();void atk_2();
    void getAngry_1();void getAngry_2();
    void strongAtk_1();void strongAtk_2();
    void bandageHeal_1(); void bandageHeal_2();
    void penetrateShooting_1();void penetrateShooting_2();
    void soberedShooting_1();void soberedShooting_2();
    void thousandShooting_1();void thousandShooting_2();
    void deadlyShooting_1();void deadlyShooting_2();
    void dragonFire_1();void dragonFire_2();
    void swipe_1();void swipe_2();
    void rampage_1();void rampage_2();
    void deadlyFire_1();void deadlyFire_2();
    void inevitableDeath_1();void inevitableDeath_2();
    void record_1();void record_2();
    void memorize_1();void memorize_2();
    void bestir_1();void bestir_2();
    void timedDeceleration_1();void timedDeceleration_2();
    void weakenFire_1();void weakenFire_2();
    void penetrateFire_1();void penetrateFire_2();
    void finalFire_1();void finalFire_2();
    void summon_1();void summon_2();
    void changeStage2_1();void changeStahe2_2();
    void fastFire_1();void fastFire_2();
    void memoryFire_1();void memoryFire_2();
    //________________________zyy
    void changeATKDEF_1();void changeATKDEF_2();
    void Endeavor_1();void Endeavor_2();
    void Splash_1();void Splash_2();
    void FocusEnergy_1();void FocusEnergy_2();
    void magicatk_1(); void magicatk_2();
    void healPulse_1();void healPulse_2();
    void Guillotine_1();void Guillotine_2();
    void staytwo_1(); void staytwo_2();
    void vampire_1(); void vampire_2();
    void bloodthirsty_1();void bloodthirsty_2();
    void Guillotinetwo_1();void Guillotinetwo_2();
    //_________________________
};

#endif // FIGHT_H
