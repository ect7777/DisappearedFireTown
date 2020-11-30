#ifndef CHARACTER_H
#define CHARACTER_H

#include<QObject>
class Character :public QObject
{
    Q_OBJECT

    Q_PROPERTY(int hp MEMBER m_hp)
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int cp MEMBER m_cp)
    Q_PROPERTY(int ID MEMBER m_ID)
private:
    int m_ID;
    int m_hp;
    QString  m_name;
    int m_cp;
public:
    explicit Character(QString inname,int inhp,int incp,int inID,QObject *parent = nullptr);
    //构造函数
    //使用下列函数获取和更改hp、cp值
    //因为m_hp m_cp为私有元素，不能直接访问（为了安全）
    int hp();//返回hp值
    void setHp(int val);//更改hp值
    int cp();//返回cp值
    void setCp(int val);//更改cp值
    int ID();//返回ID
signals:
    void hpcg(int val);//hp改变时的信号
    void cpcg(int val);//同上理解
public slots:
};

#endif // CHARACTER_H
