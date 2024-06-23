#ifndef LKTENSOR_H
#define LKTENSOR_H

#include <QtCore>

struct LkTensorId{
    quint8 isUp:1;
    quint8 id:7;
};

class LkTensor
{
public:
    LkTensor();

    std::vector<LkTensorId> ids;
    QCborValue express;

};

#endif // LKTENSOR_H
