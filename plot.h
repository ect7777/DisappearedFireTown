#ifndef PLOT_H
#define PLOT_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QRect>
#include <QMouseEvent>
#include <QPalette>
#include<QVector>
#include<QString>
#include<QFont>
#include<QFile>
#include<QTextStream>
#include<QKeyEvent>
#include <QMediaPlayer>
namespace Ui {
class plot;
}

class plot : public QWidget
{
    Q_OBJECT

public:
    explicit plot(int opt,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    int whichPolt;
    int showNumber;
    QMediaPlayer *player;
    QVector<QString> text;
    void readFile();
    void splitPlot();
    ~plot();
signals:
    void plotend(int whichwindow,int key,bool none);
private:
    Ui::plot *ui;
};

#endif // PLOT_H
