#ifndef REAL_H
#define REAL_H

#include "QString"
#include "exce_kalk.h"

class Real
{
private:
    float rVal;

public:
    Real(float = 0);
    virtual ~Real() = default;

    void setR(float);
    float getR() const;

    virtual void string(QString);

    virtual Real operator+(const Real&) const;
    virtual Real operator-(const Real&) const;
    virtual Real operator*(const Real&) const;
    virtual Real operator/(const Real&) const;

    virtual QString getString(unsigned int = 2);
};

#endif // REAL_H
