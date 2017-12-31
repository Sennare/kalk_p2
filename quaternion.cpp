#include "quaternion.h"

Quaternion::Quaternion(float rVal, float iVal, float jVal, float kVal)
{
    this->setR(rVal);
    this->setI(iVal);
    this->setJ(jVal);
    this->setK(kVal);
}

Quaternion::setJ(float jVal) {
    this->jVal = jVal;
}

Quaternion::getJ() {
    return this->jVal;
}

Quaternion::setK(float kVal) {
    this->kVal = kVal;
}

Quaternion::getK() {
    return this->kVal;
}

Quaternion::inverseJ() {
    this->jVal *= -1;
}

Quaternion::inverseK() {
    this->kVal *= -1;
}

Quaternion::operator+(const Quaternion& b) {
    Quaternion ret;
    ret.setR(this->getR() + b.getR());
    ret.setI(this->getI() + b.getI());
    ret.setJ(this->getJ() + b.getJ());
    ret.setK(this->getK() + b.getK());
    return ret;
}

Quaternion::operator-(const Quaternion& b) {
    Quaternion ret;
    ret.setR(this->getR() - b.getR());
    ret.setI(this->getI() - b.getI());
    ret.setJ(this->getJ() - b.getJ());
    ret.setK(this->getK() - b.getK());
    return ret;
}

Quaternion::operator*(const Quaternion& b) {
    Quaternion ret;
    // prodotti normali
    ret.setR((this->getR() * b.getR()) -
             (this->getI() * b.getI()) -
             (this->getJ() * b.getJ()) -
             (this->getK() * b.getK()));
    // prodotti tra R<>I e J<>K
    ret.setI((this->getR() * b.getI()) +
             (this->getI() * b.getR()) +
             (this->getJ() * b.getK()) -
             (this->getK() * b.getJ()));
    // prodotti tra R<>J e I<>K
    ret.setR((this->getR() * b.getJ()) -
             (this->getI() * b.getK()) +
             (this->getJ() * b.getR()) +
             (this->getK() * b.getI()));
    // prodotti tra R<>K e I<>J
    ret.setR((this->getR() * b.getK()) +
             (this->getI() * b.getJ()) -
             (this->getJ() * b.getI()) +
             (this->getK() * b.getR()));
    return ret;
}
