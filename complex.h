#ifndef COMPLEX_H
#define COMPLEX_H

#include <QString>
#include <real.h>

class Complex : public Real
{
private:
    float imgVal;

public:
    Complex(float = 0, float = 0);
    //~Complex();

    void setImg(float);
    float getImg() const;
    void inverseImaginary();

    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator*(const Complex&) const;
    Complex operator/(const Complex&) const;

    QString getString(unsigned int = 2, unsigned int = 2);
};

#endif // COMPLEX_H
