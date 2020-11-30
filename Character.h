#ifndef CHARACTER_H
#define CHARACTER_H

#include<QObject>
class Character :public QObject
{
    Q_OBJECT

    Q_PROPERTY(int hp MEMBER m_hp)
    Q_PROPERTY(Qstring name MEMBER m_name)
    Q_PROPERTY(int cp MEMBER m_cp)
private:
    int m_hp;
    QString  m_name;
    int m_cp;
public:
    explicit Character(QString inname,int inhp,int incp,QObject *parent = nullptr);
    int hp();
    void setHp(int val);
    int cp();
    void setCp(int val);
signals:
    void hpcg(int val);
    void cpcg(int val);
//public slots:
};

#endif // CHARACTER_H
