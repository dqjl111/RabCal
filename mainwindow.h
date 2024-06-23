#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lktensor.h"

enum TParamType{
    Pt = 0x01,
    Pr = 0x02,
    Ptheta = 0x04,
    Pfi = 0x08,
    PAll = Pt|Pr|Ptheta|Pfi
};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


    LkTensor tChrisIjk[4][4][4];
    LkTensor tDChrisIjkl[4][4][4][4];
    LkTensor tRijkL[4][4][4][4];
    LkTensor tRij[4][4];
    LkTensor tGij[4][4];


    quint8 chrisParamType[4][4][4];

    void initIds();
    void initChris();

    quint8 dChrisParamType(quint8 i, quint8 j, quint8 k, quint8 l);
    quint8 rijkLParamType(quint8 i, quint8 j, quint8 k, quint8 l);

    QString strRijkL[4][4][4][4];
};
#endif // MAINWINDOW_H
