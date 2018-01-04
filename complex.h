#ifndef COMPLEX_H
#define COMPLEX_H

#include <QString>
#include <QStringList>
#include <real.h>
#include <cmath>

class Complex : public Real
{
private:
    float iVal;

public:
    Complex(QString);
    Complex(float = 0, float = 0);
    //~Complex();

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
