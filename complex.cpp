#include "complex.h"


Complex::Complex(float realVal, float imgVal)
{
    this->setReal(realVal);
    this->setImg(imgVal);
}

void Complex::setImg(float newImg)  {
    this->imgVal = newImg;
}

float Complex::getImg() const {
    return this->imgVal;
}

void Complex::inverseImaginary() {
    this->imgVal *= -1;
}

Complex Complex::operator+(const Complex& b) const {
    Complex res;
    float aa = this->getReal() + b.getReal();
    res.setReal(this->getReal() + b.getReal());
    res.setImg(this->getImg() + b.getImg());
    return res;
}
Complex Complex::operator-(const Complex& b) const {
    Complex res;
    res.setReal(this->getReal() - b.getReal());
    res.setImg(this->getImg() - b.getImg());
    return res;
}
Complex Complex::operator*(const Complex& b) const {
    Complex res;
    res.setReal((this->getReal() * b.getReal()) -
                  (this->getImg() * b.getImg()));
    res.setImg((this->getReal() * b.getImg()) +
                 (this->getImg() * b.getReal()));
    return res;
}
Complex Complex::operator/(const Complex& b) const {
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

QString Complex::getString(unsigned int realPrec, unsigned int imgPrec) {
    return QString::number(this->getReal(), 'f', realPrec) + " + " + QString::number(this->getImg(), 'f', imgPrec) + "i";
}
