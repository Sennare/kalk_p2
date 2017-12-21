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

    void setReal(float);
    float getReal() const;

    Real operator+(const Real&) const;
    Real operator-(const Real&) const;
    Real operator*(const Real&) const;
    Real operator/(const Real&) const;

    virtual QString getString(unsigned int = 2);
};

#endif // REAL_H
