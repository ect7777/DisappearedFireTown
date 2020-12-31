#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include<QPushButton>
#include<QString>
#include<QPixmap>
#include<QSize>

class mybutton : public QPushButton
{
    Q_OBJECT
public:
    explicit mybutton(QString);

signals:

};

#endif // MYBUTTON_H
