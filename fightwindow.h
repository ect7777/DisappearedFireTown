#ifndef FIGHTWINDOW_H
#define FIGHTWINDOW_H
#include "fight.h"
#include "printview.h"
#include "view.h"
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPushButton>
namespace Ui {
class Fightwindow;
}

class Fightwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Fightwindow(int opt,QWidget *parent = nullptr);
    ~Fightwindow();
    Fight* nowfight;
    View * view;
    QMediaPlayer *player;
    bool isfightend;
    int whichFight;
    QVector<QPushButton *>buttons;
    void getConnet();//这个函数用来执行所有的connect操作
    void showTheStatus();
    void showOption();
    void showSkills();
    void showResults();
    void changeToStatus1();
    void changeToStatus2();
    void Sleep(int);
    void Failed();void Win();
    void paintEvent(QPaintEvent *);
    void buttonsClr();
private:
    Ui::Fightwindow *ui;
protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
signals:
    void keyMessage(int key);
    void fightend(int type,int key,bool isWin);
public slots:
    void doAction(int key);//状态1时进行
    void chooseObject(int key);//状态2时进行
    void finishAction();//状态3时进行
private slots:
    void on_choose0_clicked();
    void on_choose1_clicked();
    void on_choose2_clicked();
    void on_choose3_clicked();
    void on_choose4_clicked();
};

#endif // FIGHTWINDOW_H
