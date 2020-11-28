#ifndef DFT_H
#define DFT_H

#include <QMainWindow>

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
    Ui::DFT *ui;
};
#endif // DFT_H
