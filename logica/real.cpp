#include "real.h"

Real::Real(double initVal) {
    this->setR(initVal);
}

void Real::setR(double valToSet) {
    this->rVal = valToSet;
}

double Real::getR() const {
    return this->rVal;
}

void Real::string(QString str) {
    str = str.simplified();
    setR(str.toDouble());
}

Real& Real::operator+(const Real& b) const {
    Real* res = new Real();
    res->rVal = this->rVal + b.rVal;
    return *res;
}
Real& Real::operator-(const Real& b) const {
    Real* res = new Real();
    res->rVal = this->rVal - b.rVal;
    return *res;
}
Real& Real::operator*(const Real& b) const {
    Real* res = new Real();
    res->rVal = this->rVal * b.rVal;
    return *res;
}
Real& Real::operator/(const Real& b) const {
    Real* res = new Real();
    if (b.rVal == 0)
        throw exce_kalk("Errore divisione per 0");
    res->rVal = this->rVal / b.rVal;
    return *res;
}

QString Real::getString(unsigned int precision) {
    return QString::number(this->rVal, 'f', precision);
}
