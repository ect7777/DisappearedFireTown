#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QDebug>
#include <QTime>
#include<QPainter>
#include<QPixmap>
#include<QPalette>
#include<QRect>
#include<QPoint>
#include <QSound>
#include <QMediaPlayer>
class Character:public QObject
{
    Q_OBJECT
public:
    explicit Character(int setID,QString inname);//构造函数
    int HP,CP,ATK,DEF,AT,ID;
    int nHP,nATK,nDEF;//所有不带n的变量都为当前的状态，带n的都为初始状态
    bool isenemy;
    QString name;
    QVector<int> skills;
    QPixmap picture;
    int stage;//用来表示BOSS在第几阶段
    QPoint paintpoint;//绘制的起始点是哪里
    int dot=0;
    int log[3];
    QString getSkillName(int);
    QString skillsOption();
};
#endif // CHARACTER_H
