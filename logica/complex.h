#ifndef COMPLEX_H
#define COMPLEX_H

#include <QString>
#include <QStringList>
#include <cmath>
#include "real.h"
#include "exce_kalk.h"

class Complex : public Real
{
private:
    float iVal;

public:
    Complex(QString);
    Complex(float = 0, float = 0);
    ~Complex() = default;

    void setI(float);
    float getI() const;
    void inverseI();

    Complex conjugate() const;
    float norm() const;
    Complex inverse() const;

    void string(QString);

    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator*(const Complex&) const;
    Complex operator/(const Complex&) const;

    QString getString(unsigned int = 2) override;
};

#endif // COMPLEX_H
