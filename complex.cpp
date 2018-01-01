#include "complex.h"


Complex::Complex(float rVal, float iVal)
{
    this->setR(rVal);
    this->setI(iVal);
}

void Complex::setI(float iVal)  {
    this->iVal = iVal;
}

float Complex::getI() const {
    return this->iVal;
}

void Complex::inverseI() {
    this->iVal *= -1;
}

Complex Complex::operator+(const Complex& b) const {
    Complex res;
    res.setR(this->getR() + b.getR());
    res.setI(this->getI() + b.getI());
    return res;
}
Complex Complex::operator-(const Complex& b) const {
    Complex res;
    res.setR(this->getR() - b.getR());
    res.setI(this->getI() - b.getI());
    return res;
}
Complex Complex::operator*(const Complex& b) const {
    Complex res;
    res.setR((this->getR() * b.getR()) -
                  (this->getI() * b.getI()));
    res.setI((this->getR() * b.getI()) +
                 (this->getI() * b.getR()));
    return res;
}
Complex Complex::operator/(const Complex& b) const {
    Complex inverse, denominatoreComplex;
    inverse = b;
    inverse.inverseI();
    denominatoreComplex = inverse * b;
    float denominatore = denominatoreComplex.getR();
    inverse = *this * inverse;
    float rPart = inverse.getR() / denominatore;
    float iPart = inverse.getI() / denominatore;
    Complex res(rPart, iPart);
    return res;
}

QString Complex::getString(unsigned int rPrec, unsigned int iPrec) {
    return QString::number(this->getR(), 'f', rPrec) + " + " + QString::number(this->getI(), 'f', iPrec) + "i";
}
