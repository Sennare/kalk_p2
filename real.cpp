#include "real.h"

Real::Real(float initVal) {
    this->setReal(initVal);
}

void Real::setReal(float valToSet) {
    this->realVal = valToSet;
}

float Real::getReal() const {
    return this->realVal;
}

Real Real::operator+(const Real& b) const {
    Real res;
    res.realVal = this->realVal + b.realVal;
    return res;
}
Real Real::operator-(const Real& b) const {
    Real res;
    res.realVal = this->realVal - b.realVal;
    return res;
}
Real Real::operator*(const Real& b) const {
    Real res;
    res.realVal = this->realVal * b.realVal;
    return res;
}
Real Real::operator/(const Real& b) const {
    Real res;
    res.realVal = this->realVal / b.realVal;
    return res;
}

QString Real::getString(unsigned int precision) {
    return QString::number(this->realVal, 'f', precision);
}
