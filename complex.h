#ifndef COMPLEX_H
#define COMPLEX_H


class Complex
{
private:
    float real;
    float img;

public:
    Complex(float realVal = 0, float imgVal = 0);
    ~Complex();

    Complex operator+(const Complex&);
    Complex operator-(const Complex&);
    Complex operator*(const Complex&);
    Complex operator/(const Complex&);
};

#endif // COMPLEX_H
