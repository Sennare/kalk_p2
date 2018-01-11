#ifndef REAL_H
#define REAL_H

#include "QString"
#include "exce_kalk.h"

class Real
{
private:
    float rVal;

public:
    /*enum errorType {
        errorOutOfRange,
        errorDivisionByZero
    };*/

    Real(float = 0);
    virtual ~Real() = default;

    void setR(float);
    float getR() const;

    Real operator+(const Real&) const;
    Real operator-(const Real&) const;
    Real operator*(const Real&) const;
    Real operator/(const Real&) const;

    virtual QString getString(unsigned int = 2);
};

#endif // REAL_H
