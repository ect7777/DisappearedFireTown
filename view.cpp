#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
}

View::~View()
{
    delete ui;
}
void View::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QRect *rect=new QRect(0,0,1440,90);
    QPixmap background(":/image/image/view.png");
    painter.drawPixmap(*rect,background,*rect);
    //________________________________________________
   QFont font;
   fontSet(font);
   QPen pen(Qt::white);
   painter.setFont(font);
   painter.setPen(pen);
   painter.drawText(50,40,message);
}
void View::fontSet(QFont& font){
    font.setFamily("Microsoft YaHei");
    font.setPointSize(20);
    font.setBold(1);
}
