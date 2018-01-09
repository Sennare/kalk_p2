#include "complex.h"

Complex::Complex(QString string) {
    QStringList list = string.split(',');
    if (list.size() == 2) {
        this->setR(list[0].toInt());
        this->setI(list[1].toInt());
    }else{
        // TODO : Throw error
    }
}

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

Complex Complex::conjugate() const {
    Complex res = *this;
    res.inverseI();
    return res;
}

float Complex::norm() const {
    return sqrt(exp2(this->getR()) + exp2(this->getI()));
}

Complex Complex::inverse() const {
    const Complex norma(exp2(this->norm()));
    Complex ret = *this;
    ret = ret / norma;
    return ret;
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
