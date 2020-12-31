#ifndef DFT_H
#define DFT_H

#include <QMainWindow>
#include "mybutton.h"
#include "fightwindow.h"
#include "plot.h"
#include "view.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DFT; }
QT_END_NAMESPACE

class DFT : public QMainWindow
{
    Q_OBJECT

public:
    DFT(QWidget *parent = nullptr);
    ~DFT();
    void paintEvent(QPaintEvent*);
    Fightwindow *FW;
    plot *pW;
    QMediaPlayer *player;
    QFile *save_load;
public slots:
    void firststart();
    void changeToFight(int key);
    void changeToMenu(int whatWindow,int opt,bool isWin);
    void changeToPlot(int key);
    void continueGame();
    void savenow(bool isPlot,int key);
private slots:
    void on_pushButton_clicked();

private:
    Ui::DFT *ui;
};
#endif // DFT_H
