#include "real.h"

Real::Real(float initVal) {
    this->setR(initVal);
}

void Real::setR(float valToSet) {
    this->rVal = valToSet;
}

float Real::getR() const {
    return this->rVal;
}

void Real::string(QString str) {
    str = str.simplified();
    setR(str.toFloat());
}

Real Real::operator+(const Real& b) const {
    Real res;
    res.rVal = this->rVal + b.rVal;
    return res;
}
Real Real::operator-(const Real& b) const {
    Real res;
    res.rVal = this->rVal - b.rVal;
    return res;
}
Real Real::operator*(const Real& b) const {
    Real res;
    res.rVal = this->rVal * b.rVal;
    return res;
}
Real Real::operator/(const Real& b) const {
    Real res;
    if (b.rVal == 0)
        throw exce_kalk("Errore divisione per 0");
    res.rVal = this->rVal / b.rVal;
    return res;
}

QString Real::getString(unsigned int precision) {
    return QString::number(this->rVal, 'f', precision);
}
