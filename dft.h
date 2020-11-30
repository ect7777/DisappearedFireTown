#ifndef DFT_H
#define DFT_H

#include <QMainWindow>
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
private:
    Character *a,*b;

private:
    Ui::DFT *ui;
};
#endif // DFT_H
