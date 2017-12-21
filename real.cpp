#include "real.h"

Real::Real(float initVal) {
    this->realVal = initVal;
}

Real Real::operator+(const Real& b) {
    Real res;
    res.realVal = this->realVal + b.realVal;
    return res;
}
Real Real::operator-(const Real& b) {
    Real res;
    res.realVal = this->realVal - b.realVal;
    return res;
}
Real Real::operator*(const Real& b) {
    Real res;
    res.realVal = this->realVal * b.realVal;
    return res;
}
Real Real::operator/(const Real& b) {
    Real res;
    res.realVal = this->realVal / b.realVal;
    return res;
}

QString Real::getString(unsigned int precision) {
    return QString::number(this->realVal, 'f', precision);
}
