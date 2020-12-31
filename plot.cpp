#include "plot.h"
#include "ui_plot.h"

plot::plot(int opt,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::plot)
{
    ui->setupUi(this);
    this->setWindowTitle("DisappearedFireTown");
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    whichPolt=opt;
    showNumber=0;
    player=new QMediaPlayer(this);
    player->setMedia(QUrl("qrc:/sound/silver.wav"));
    player->setVolume(40);
    player->play();
    readFile();
}

plot::~plot()
{
    delete ui;
}
void plot::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QFont font;
    QPixmap dialogbackground(":/image/image/dialog.png");
    QPixmap * pix=new QPixmap(":/image/image/backlog.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),*pix);
    painter.drawPixmap(50,560,dialogbackground);
    font.setPointSize(18);
    font.setFamily("Microsoft YaHei");
    painter.setFont(font);
    painter.drawText(100,640,text[showNumber]);
}
void plot::mousePressEvent(QMouseEvent *){
    showNumber++;
    if (showNumber>=text.size()){
    emit plotend(2,whichPolt,0);
    }
    update();
}
void plot::readFile(){
    QString filename=QString(":/text/plots/plot%1").arg(whichPolt);
    QFile *fp=new QFile(filename);
    fp->open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream rd(fp);
    rd.setCodec("utf-8");
    rd.setAutoDetectUnicode(true);
    while(!rd.atEnd()){
        text.append(rd.readLine());
    }
}
void plot::keyPressEvent(QKeyEvent * event){
    showNumber++;
    if (showNumber>=text.size()){
    emit plotend(2,whichPolt,0);
    }
    update();
}
