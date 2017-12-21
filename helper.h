#ifndef HELPER_H
#define HELPER_H

#include "QString"
#include "QList"
#include <math.h>

class Helper
{
public:
    Helper();

    QList<QString> hexList;

    QString decToHex (int, int = 1);
};

#endif // HELPER_H
