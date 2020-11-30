#include "Character.h"
Character::Character(QString name,int inhp,int incp,int inID,QObject *parent) :QObject(parent)
{//构造函数
       m_name=name;m_hp=inhp;m_cp=incp;m_ID=inID;
}
int Character::cp(){
    return m_cp;
}
int Character::hp(){
    return m_hp;
}
void Character::setCp(int val){
    m_cp=val;
    emit cpcg(m_cp);
}
void Character::setHp(int val){
    m_hp=val;
    emit hpcg(m_hp);
}
int Character::ID(){
    return m_ID;
}

