#include "mybutton.h"

mybutton::mybutton(QString pix) : QPushButton(0)
{
    QPixmap* pixmap=new QPixmap(pix);
    this->setFixedSize(pixmap->width(),pixmap->height());
    //this->setFixedSize(240,90);
    this->setStyleSheet("QPushbutton{border:0px}");
    this->setIcon(*pixmap);
    this->setIconSize(QSize(pixmap->width(),pixmap->height()));
}
