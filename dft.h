#ifndef DFT_H
#define DFT_H

#include <QMainWindow>
#include<QString>
#include"Character.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DFT; }
QT_END_NAMESPACE

class DFT : public QMainWindow
{
    Q_OBJECT

public:
    DFT(QWidget *parent = nullptr);
    ~DFT();
    void update(Character*u,int ID);//更新角色u的HP
public:
    Character *c1,*c2;

private:
    Ui::DFT *ui;
signals:
private slots:
    void atk(Character* u);//进行攻击
   // void heal(Character* u);治疗代码暂时不实现
    void heroAtk();
    void enemyAtk();
    void onAtk();//onAtk接受hpcg发出的信号
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};
#endif // DFT_H
