#ifndef PRINTVIEW_H
#define PRINTVIEW_H

#include <QWidget>
#include<QPainter>
#include<QPixmap>
class printview : public QWidget
{
    Q_OBJECT
public:
    explicit printview(QWidget *parent = nullptr);
signals:

};

#endif // PRINTVIEW_H
