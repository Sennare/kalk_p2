#ifndef REAL_H
#define REAL_H

#include "QString"

class Real
{
private:
    float rVal;

public:
    Real(float = 0);
    //~Real();

    void setR(float);
    float getR() const;

    Real operator+(const Real&) const;
    Real operator-(const Real&) const;
    Real operator*(const Real&) const;
    Real operator/(const Real&) const;

    virtual QString getString(unsigned int = 2);
};

#endif // REAL_H
