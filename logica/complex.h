#ifndef COMPLEX_H
#define COMPLEX_H

#include <QString>
#include <QStringList>
#include <cmath>
#include "real.h"

class Complex : public Real
{
private:
    float iVal;

public:
    enum possibleKalk {
        calcSum,
        calcSub,
        calcMult,
        calcDiv,
        calcConj,
        calcNorm,
        calcInverse
    };

    Complex(QString);
    Complex(float = 0, float = 0);
    ~Complex() = default;

    void setI(float);
    float getI() const;
    void inverseI();

    Complex conjugate() const;
    float norm() const;
    Complex inverse() const;

    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator*(const Complex&) const;
    Complex operator/(const Complex&) const;

    QString getString(unsigned int = 2, unsigned int = 2);
};

#endif // COMPLEX_H
