#ifndef REAL_H
#define REAL_H

#include "QString"

class Real
{
private:
    float realVal;

public:
    Real(float = 0);
    //~Real();

    Real operator+(const Real&);
    Real operator-(const Real&);
    Real operator*(const Real&);
    Real operator/(const Real&);

    virtual QString getString(unsigned int = 2);
};

#endif // REAL_H
