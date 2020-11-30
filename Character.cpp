#include "Character.h"
Character::Character(QString name,int inhp,int incp,QObject *parent) :QObject(parent)
{//构造函数
       m_name=name;m_hp=inhp;m_cp=incp;
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

