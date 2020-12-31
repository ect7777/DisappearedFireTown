#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include<QPainter>
#include<QPixmap>
#include<QPalette>
#include<QRect>
#include<QString>
namespace Ui {
class View;
}

class View : public QWidget
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    QString  message;
    void fontSet(QFont&);
    ~View();

private:
    Ui::View *ui;
};

#endif // VIEW_H
