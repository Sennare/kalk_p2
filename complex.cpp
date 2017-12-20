#include "complex.h"


Complex::Complex(float realVal, float imgVal)
{
    this->real = realVal;
    this->img = imgVal;
}

QString Complex::getStr() {
    return QString::number(this->real, 'f', 2) + " + " + QString::number(this->img, 'f', 2) + "i";
}

float Complex::getReal() {   return this->real;  }

float Complex::getImg() {    return this->img;  }

void Complex::inverseImaginary() {
    this->img *= -1;
}

Complex Complex::operator+(const Complex& b) {
    Complex res;
    res.real = this->real + b.real;
    res.img= this->img + b.img;
    return res;
}
Complex Complex::operator-(const Complex& b) {
    Complex res;
    res.real = this->real - b.real;
    res.img= this->img - b.img;
    return res;
}
Complex Complex::operator*(const Complex& b) {
    Complex res;
    res.real = (this->real * b.real) - (this->img * b.img);
    res.img= (this->real * b.img) + (this->img * b.real);
    return res;
}
Complex Complex::operator/(const Complex& b) {
    Complex inverse, denominatoreComplex;
    inverse = b;
    inverse.inverseImaginary();
    denominatoreComplex = inverse * b;
    float denominatore = denominatoreComplex.getReal();
    inverse = *this * inverse;
    float realPart = inverse.getReal() / denominatore;
    float imgPart = inverse.getImg() / denominatore;
    Complex res(realPart, imgPart);
    return res;
}
