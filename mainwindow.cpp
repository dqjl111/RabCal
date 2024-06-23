#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initIds();
    initChris();

//    for(uint i=0; i<4; ++i){
//        for(uint j=0; j<4; ++j){
//            for(uint k=0; k<4; ++k){
//                for(uint l=0; l<4; ++l){
//                    quint8 paramType = rijkLParamType(i, j, k, l);
//                    if(paramType != 0){
//                        std::cout<< QString("{R_{%0%1%2}}^{%3} = ").arg(i).arg(j).arg(k).arg(l).toStdString()
//                                 << strRijkL[i][j][k][l].toStdString()
//                                 << std::endl;
//                    }
//                }
//            }
//        }
//    }

    for(uint i=0; i<4; ++i){
        for(uint j=0; j<4; ++j){
            QStringList adds;
            for(uint k=0; k<4; ++k){
                quint8 paramType = rijkLParamType(i, k, j, k);
                if(paramType != 0){
                    adds.append(QString("{R_{%0%1%2}}^{%3}").arg(i).arg(k).arg(j).arg(k));
                }
            }


            if(!adds.isEmpty()){
                std::cout << QString("R_{%0%1} = ").arg(i).arg(j).toStdString()
                          << adds.join(" + ").toStdString()
                          << std::endl;
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initIds()
{
    for(uint i=0; i<4; ++i){
        for(uint j=0; j<4; ++j){
            for(uint k=0; k<4; ++k){
                tChrisIjk[i][j][k].ids.resize(3);
                tChrisIjk[i][j][k].ids[0].isUp = true;
                tChrisIjk[i][j][k].ids[1].isUp = false;
                tChrisIjk[i][j][k].ids[2].isUp = false;

                tChrisIjk[i][j][k].ids[0].id = i;
                tChrisIjk[i][j][k].ids[1].id = j;
                tChrisIjk[i][j][k].ids[2].id = k;

                chrisParamType[i][j][k] = 0;
            }
        }
    }

    for(uint i=0; i<4; ++i){
        for(uint j=0; j<4; ++j){
            for(uint k=0; k<4; ++k){
                for(uint l=0; l<4; ++l){
                    tRijkL[i][j][k][l].ids.resize(4);

                    tRijkL[i][j][k][l].ids[0].isUp = false;
                    tRijkL[i][j][k][l].ids[1].isUp = false;
                    tRijkL[i][j][k][l].ids[2].isUp = false;
                    tRijkL[i][j][k][l].ids[3].isUp = true;


                    tRijkL[i][j][k][l].ids[0].id = i;
                    tRijkL[i][j][k][l].ids[1].id = j;
                    tRijkL[i][j][k][l].ids[2].id = k;
                    tRijkL[i][j][k][l].ids[3].id = l;

                    tDChrisIjkl[i][j][k][l].ids.resize(4);

                    tDChrisIjkl[i][j][k][l].ids[0].isUp = true;
                    tDChrisIjkl[i][j][k][l].ids[1].isUp = false;
                    tDChrisIjkl[i][j][k][l].ids[2].isUp = false;
                    tDChrisIjkl[i][j][k][l].ids[3].isUp = false;

                    tDChrisIjkl[i][j][k][l].ids[0].id = i;
                    tDChrisIjkl[i][j][k][l].ids[1].id = j;
                    tDChrisIjkl[i][j][k][l].ids[2].id = k;
                    tDChrisIjkl[i][j][k][l].ids[3].id = l;
                }
            }
        }
    }

    for(uint i=0; i<4; ++i){
        for(uint j=0; j<4; ++j){
            tRij[i][j].ids.resize(2);

            tRij[i][j].ids[0].isUp = false;
            tRij[i][j].ids[1].isUp = false;

            tRij[i][j].ids[0].id = i;
            tRij[i][j].ids[1].id = j;

            tGij[i][j].ids.resize(2);

            tGij[i][j].ids[0].isUp = false;
            tGij[i][j].ids[1].isUp = false;

            tGij[i][j].ids[0].id = i;
            tGij[i][j].ids[1].id = j;
        }
    }
}

void MainWindow::initChris()
{
    chrisParamType[0][0][0] = PAll;
    chrisParamType[0][1][1] = PAll;
    chrisParamType[1][0][1] = PAll;
    chrisParamType[1][1][0] = PAll;

    chrisParamType[0][0][2] = PAll;
    chrisParamType[0][2][0] = PAll;
    chrisParamType[1][1][2] = PAll;
    chrisParamType[1][2][1] = PAll;
    chrisParamType[2][0][0] = PAll;
    chrisParamType[2][1][1] = PAll;

    chrisParamType[0][0][3] = PAll;
    chrisParamType[0][3][0] = PAll;
    chrisParamType[1][1][3] = PAll;
    chrisParamType[1][3][1] = PAll;
    chrisParamType[3][0][0] = PAll;
    chrisParamType[3][1][1] = PAll;

    chrisParamType[0][0][1] = PAll;
    chrisParamType[0][1][0] = PAll;
    chrisParamType[1][0][0] = PAll;
    chrisParamType[1][1][1] = PAll;
    chrisParamType[1][2][2] = PAll;
    chrisParamType[1][3][3] = PAll;

    chrisParamType[2][1][2] = Pr;
    chrisParamType[2][2][1] = Pr;
    chrisParamType[2][3][3] = Ptheta;

    chrisParamType[3][1][3] = Pr;
    chrisParamType[3][3][1] = Pr;

    chrisParamType[3][2][3] = Ptheta;
    chrisParamType[3][3][2] = Ptheta;
}

quint8 MainWindow::dChrisParamType(quint8 i, quint8 j, quint8 k, quint8 l)
{
    quint8 ret = 0;
    switch(l){
    case 0:{
        if(chrisParamType[i][j][k] & Pt){
            ret =  chrisParamType[i][j][k];
        }
        break;
    }
    case 1:{
        if(chrisParamType[i][j][k] & Pr){
            ret =  chrisParamType[i][j][k];
        }
        break;
    }
    case 2:{
        if(chrisParamType[i][j][k] & Ptheta){
            ret =  chrisParamType[i][j][k];
        }
        break;
    }
    case 3:{
        if(chrisParamType[i][j][k] & Pfi){
            ret =  chrisParamType[i][j][k];
        }
        break;
    }
    default:{
        break;
    }
    }
    return ret;
}

quint8 MainWindow::rijkLParamType(quint8 i, quint8 j, quint8 k, quint8 l)
{
    strRijkL[i][j][k][l] = "";

    quint8 ret = 0;
    quint8 dChirsType = 0;
    if(i != j){
        quint8 dChris1Type = dChrisParamType(l, i, k, j);
        quint8 dChris2Type = dChrisParamType(l, j, k, i);

        dChirsType = dChris1Type | dChris2Type;

        if(dChris1Type){
            strRijkL[i][j][k][l].append(QString("\\Gamma^{%0}_{%1%2,%3}").arg(l).arg(i).arg(k).arg(j));
        }

        if(dChris2Type){
            strRijkL[i][j][k][l].append(QString("-\\Gamma^{%0}_{%1%2,%3}").arg(l).arg(j).arg(k).arg(i));
        }
    }


    quint8 chrisType = 0;
    if(i != j){
        quint8 chirsType[4];

        quint8 chrisTypeTemp = 0;
        for(uint lamda=0; lamda<4; ++lamda){
            chirsType[lamda] = 0;

            bool isZeroI = false;
            if(lamda == l){
                if((k == i) && (i==lamda) && (k==j) && (lamda == j)){
                    isZeroI = true;
                }

                if(k == lamda){
                    isZeroI = true;
                }
            }

            if(!isZeroI)
            {
                quint8 chrisType1  = 0;
                quint8 chrisType11 = chrisParamType[lamda][k][i];
                quint8 chrisType12 = chrisParamType[l][j][lamda];
                if(chrisType11 == 0 || chrisType12 == 0){
                    chrisType1 = 0;
                }else{
                    chrisType1 = chrisType11 | chrisType12;
                }


                quint8 chrisType2  = 0;
                quint8 chrisType21 = chrisParamType[lamda][k][j];
                quint8 chrisType22 = chrisParamType[l][i][lamda];

                if(chrisType21 == 0 || chrisType22 == 0){
                    chrisType2 = 0;
                }else{
                    chrisType2 = chrisType21 | chrisType22;
                }

                chirsType[lamda] = chrisType1 | chrisType2;
            }

            chrisTypeTemp |= chirsType[lamda];
        }

        if(chrisTypeTemp == 0){
            chrisType = 0;
        }else{
            quint8 chrisAddIndex[4][6];
            quint8 chrisMinusIndex[4][6];
            bool isMinusCanceled[4];
            bool isAddCanceled[4];

            for(uint lamda=0; lamda<4; ++lamda){
                chrisAddIndex[lamda][0] = lamda;
                chrisAddIndex[lamda][1] = k;
                chrisAddIndex[lamda][2] = i;
                chrisAddIndex[lamda][3] = l;
                chrisAddIndex[lamda][4] = j;
                chrisAddIndex[lamda][5] = lamda;

                chrisMinusIndex[lamda][0] = lamda;
                chrisMinusIndex[lamda][1] = k;
                chrisMinusIndex[lamda][2] = j;
                chrisMinusIndex[lamda][3] = l;
                chrisMinusIndex[lamda][4] = i;
                chrisMinusIndex[lamda][5] = lamda;

                if(chirsType[lamda] == 0){
                    isMinusCanceled[lamda] = true;
                    isAddCanceled[lamda] = true;
                }else{
                    isMinusCanceled[lamda] = false;
                    isAddCanceled[lamda] = false;
                }
            }

            for(uint ii=0; ii<4; ++ii){
                if(isAddCanceled[ii] == false){
                    for(uint jj=0; jj<4; ++jj){
                        if(ii != jj){
                            if(isMinusCanceled[jj] == false){
                                bool isCancled = false;
                                if(chrisAddIndex[ii][0] == chrisAddIndex[jj][0]){

                                    if((chrisAddIndex[ii][1] == chrisMinusIndex[jj][1])
                                            && (chrisAddIndex[ii][2] == chrisMinusIndex[jj][2])
                                            && (chrisAddIndex[ii][4] == chrisMinusIndex[jj][4])
                                            && (chrisAddIndex[ii][5] == chrisMinusIndex[jj][5])){
                                        isCancled = true;
                                    }

                                    if(!isCancled){
                                        if((chrisAddIndex[ii][1] == chrisMinusIndex[jj][2])
                                                && (chrisAddIndex[ii][2] == chrisMinusIndex[jj][1])
                                                && (chrisAddIndex[ii][4] == chrisMinusIndex[jj][4])
                                                && (chrisAddIndex[ii][5] == chrisMinusIndex[jj][5])){
                                            isCancled = true;
                                        }
                                    }

                                    if(!isCancled){
                                        if((chrisAddIndex[ii][1] == chrisMinusIndex[jj][1])
                                                && (chrisAddIndex[ii][2] == chrisMinusIndex[jj][2])
                                                && (chrisAddIndex[ii][4] == chrisMinusIndex[jj][5])
                                                && (chrisAddIndex[ii][5] == chrisMinusIndex[jj][4])){
                                            isCancled = true;
                                        }
                                    }

                                    if(!isCancled){
                                        if((chrisAddIndex[ii][1] == chrisMinusIndex[jj][2])
                                                && (chrisAddIndex[ii][2] == chrisMinusIndex[jj][1])
                                                && (chrisAddIndex[ii][4] == chrisMinusIndex[jj][5])
                                                && (chrisAddIndex[ii][5] == chrisMinusIndex[jj][4])){
                                            isCancled = true;
                                        }
                                    }
                                }

                                if(!isCancled){
                                    if((chrisAddIndex[ii][0] == chrisAddIndex[jj][3])
                                            && (chrisAddIndex[ii][3] == chrisAddIndex[jj][0])){

                                        if((chrisAddIndex[ii][1] == chrisMinusIndex[jj][4])
                                                && (chrisAddIndex[ii][2] == chrisMinusIndex[jj][5])
                                                && (chrisAddIndex[ii][4] == chrisMinusIndex[jj][1])
                                                && (chrisAddIndex[ii][5] == chrisMinusIndex[jj][2])){
                                            isCancled = true;
                                        }

                                        if(!isCancled){
                                            if((chrisAddIndex[ii][1] == chrisMinusIndex[jj][5])
                                                    && (chrisAddIndex[ii][2] == chrisMinusIndex[jj][4])
                                                    && (chrisAddIndex[ii][4] == chrisMinusIndex[jj][1])
                                                    && (chrisAddIndex[ii][5] == chrisMinusIndex[jj][2])){
                                                isCancled = true;
                                            }
                                        }

                                        if(!isCancled){
                                            if((chrisAddIndex[ii][1] == chrisMinusIndex[jj][4])
                                                    && (chrisAddIndex[ii][2] == chrisMinusIndex[jj][5])
                                                    && (chrisAddIndex[ii][4] == chrisMinusIndex[jj][2])
                                                    && (chrisAddIndex[ii][5] == chrisMinusIndex[jj][1])){
                                                isCancled = true;
                                            }
                                        }

                                        if(!isCancled){
                                            if((chrisAddIndex[ii][1] == chrisMinusIndex[jj][5])
                                                    && (chrisAddIndex[ii][2] == chrisMinusIndex[jj][4])
                                                    && (chrisAddIndex[ii][4] == chrisMinusIndex[jj][2])
                                                    && (chrisAddIndex[ii][5] == chrisMinusIndex[jj][1])){
                                                isCancled = true;
                                            }
                                        }
                                    }
                                }

                                if(isCancled){
                                    isAddCanceled[ii] = true;
                                    isMinusCanceled[jj] = true;
                                }
                            }
                        }
                    }
                }
            }

            for(uint ii=0; ii<4; ++ii){
                quint8 chrisType1  = 0;
                if(isAddCanceled[ii] == false){
                    quint8 chrisType11 = chrisParamType[ii][k][i];
                    quint8 chrisType12 = chrisParamType[l][j][ii];

                    if(chrisType11 == 0 || chrisType12 == 0){
                        chrisType1 = 0;
                    }else{
                        chrisType1 = chrisType11 | chrisType12;
                    }

                    if(chrisType1){
                        if(!strRijkL[i][j][k][l].isEmpty()){
                            strRijkL[i][j][k][l].append("+");
                        }
                        strRijkL[i][j][k][l].append(QString("\\Gamma^{%0}_{%1%2}\\Gamma^{%3}_{%4%5}").arg(ii).arg(k).arg(i).arg(l).arg(j).arg(ii));
                    }
                }

                quint8 chrisType2  = 0;
                if(isMinusCanceled[ii] == false){
                    quint8 chrisType21 = chrisParamType[ii][k][j];
                    quint8 chrisType22 = chrisParamType[l][i][ii];

                    if(chrisType21 == 0 || chrisType22 == 0){
                        chrisType2 = 0;
                    }else{
                        chrisType2 = chrisType21 | chrisType22;
                    }

                    if(chrisType2){
                        strRijkL[i][j][k][l].append(QString("-\\Gamma^{%0}_{%1%2}\\Gamma^{%3}_{%4%5}").arg(ii).arg(k).arg(j).arg(l).arg(i).arg(ii));
                    }
                }

                chrisType |= chrisType1 | chrisType2;
            }
        }
    }

    ret = dChirsType | chrisType;
    return  ret;
}

