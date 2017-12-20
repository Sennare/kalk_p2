#ifndef COMPLEX_H
#define COMPLEX_H

#include <QString>

class Complex
{
private:
    float real;
    float img;

public:
    Complex(float = 0, float = 0);
    //~Complex();

    QString getStr();
    float getReal();
    float getImg();
    void inverseImaginary();

    Complex operator+(const Complex&);
    Complex operator-(const Complex&);
    Complex operator*(const Complex&);
    Complex operator/(const Complex&);
};

#endif // COMPLEX_H
