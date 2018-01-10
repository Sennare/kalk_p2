#include "complex.h"

Complex::Complex(QString string) {
    string = string.simplified();
    // Controllo il formato "2,2"
    QStringList list = string.split(',');
    if (list.size() == 2) {
        this->setR(list[0].toDouble());
        this->setI(list[1].toDouble());
    }else{
        // Controllo il formato "2 + 2i"
        list = string.split("+");
        if (list.size() == 2 && list[1].indexOf("i") != -1 ) {
            this->setR(list[0].toDouble());
            list[1] = list[1].replace("i", "");
            this->setI(list[1].toDouble());
        }
        throw Complex::errorType::errorStringNotValid;
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
    float ret;
    if (exp2(this->getR()) + exp2(this->getI()) < 0)
        throw Complex::errorType::errorRootNegative;
    else
        ret = sqrt(exp2(this->getR()) + exp2(this->getI()));
    return ret;
}

Complex Complex::inverse() const {
    const Complex norma(exp2(this->norm()));
    Complex ret = *this;
    if (norma.getI() < 0)
        throw Complex::errorType::errorNormaNegative;
    else
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
    float rPart;
    float iPart;
    if (denominatore < 0)
        throw Complex::errorType::errorDivisionByZero;
    else {
        inverse = *this * inverse;
        rPart = inverse.getR() / denominatore;
        iPart = inverse.getI() / denominatore;
    }
    Complex res(rPart, iPart);
    return res;
}

QString Complex::getString(unsigned int rPrec, unsigned int iPrec) {
    return QString::number(this->getR(), 'f', rPrec) + " + " + QString::number(this->getI(), 'f', iPrec) + "i";
}
