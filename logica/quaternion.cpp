#include "quaternion.h"

Quaternion::Quaternion(QString string) {
    QStringList list = string.split(',');
    if (list.size() == 4) {
        this->setR(list[0].toInt());
        this->setI(list[1].toInt());
        this->setJ(list[2].toInt());
        this->setK(list[3].toInt());
    }else{
        // TODO : Throw error
    }
}

Quaternion::Quaternion(float rVal, float iVal, float jVal, float kVal)
{
    this->setR(rVal);
    this->setI(iVal);
    this->setJ(jVal);
    this->setK(kVal);
}

void Quaternion::setJ(float jVal) {
    this->jVal = jVal;
}

float Quaternion::getJ() const {
    return this->jVal;
}

void Quaternion::setK(float kVal) {
    this->kVal = kVal;
}

float Quaternion::getK() const {
    return this->kVal;
}

void Quaternion::inverseJ() {
    this->jVal *= -1;
}

void Quaternion::inverseK() {
    this->kVal *= -1;
}

// TODO -> Da testare in GUI
Quaternion Quaternion::conjugate() const {
    Quaternion res;
    res.setR(this->getR());
    res.setI(-this->getI());
    res.setJ(-this->getJ());
    res.setK(-this->getK());
    return res;
}

// TODO -> Da testare in GUI
float Quaternion::norm() const {
    return sqrt(exp2(this->getR()) +
                exp2(this->getI()) +
                exp2(this->getJ()) +
                exp2(this->getK()));
}


// TODO -> Da testare in GUI
Quaternion Quaternion::inverse() const {
    const Quaternion norma(exp2(this->norm()));
    Quaternion ret = *this;
    ret = ret / norma;
    return ret;
}


Quaternion Quaternion::operator+(const Quaternion& b) const {
    Quaternion ret;
    ret.setR(this->getR() + b.getR());
    ret.setI(this->getI() + b.getI());
    ret.setJ(this->getJ() + b.getJ());
    ret.setK(this->getK() + b.getK());
    return ret;
}

Quaternion Quaternion::operator-(const Quaternion& b) const {
    Quaternion ret;
    ret.setR(this->getR() - b.getR());
    ret.setI(this->getI() - b.getI());
    ret.setJ(this->getJ() - b.getJ());
    ret.setK(this->getK() - b.getK());
    return ret;
}

Quaternion Quaternion::operator*(const Quaternion& b) const {
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
    ret.setJ((this->getR() * b.getJ()) -
             (this->getI() * b.getK()) +
             (this->getJ() * b.getR()) +
             (this->getK() * b.getI()));
    // prodotti tra R<>K e I<>J
    ret.setK((this->getR() * b.getK()) +
             (this->getI() * b.getJ()) -
             (this->getJ() * b.getI()) +
             (this->getK() * b.getR()));
    return ret;
}

Quaternion Quaternion::operator/(const Quaternion& b) const {
    Quaternion ret;
    float a1 = this->getR();
    float b1 = this->getI();
    float c1 = this->getJ();
    float d1 = this->getK();
    float a2 = b.getR();
    float b2 = b.getI();
    float c2 = b.getJ();
    float d2 = b.getK();

    float denominatore = a2*a2 + b2*b2 + c2*c2 + d2*d2;
    // Parte reale -- prodotti normali
    ret.setR( ((a1*a2)+(b1*b2)+(c1*c2)+(d1*d2)) / denominatore);
    // Parte immaginaria I -- prodotti tra R<>I e J<>K
    ret.setI( ((a1*-b2)+(b1*a2)+(c1*d2)+(d1*-c2)) / denominatore);
    // Parte immaginaria J -- prodotti tra R<>J e I<>K
    ret.setJ( ((a1*-c2)+(b1*-d2)+(c1*a2)+(d1*b2)) / denominatore);
    // Parte immaginaria K -- prodotti tra R<>K e I<>J
    ret.setK( ((a1*-d2)+(b1*c2)+(c1*-b2)+(d1*a2)) / denominatore);

    return ret;
}

QString Quaternion::getString(unsigned int rPrec, unsigned int iPrec, unsigned int jPrec, unsigned int kPrec) {
    return QString::number(this->getR(), 'f', rPrec) + " + " + QString::number(this->getI(), 'f', iPrec) + "i + " + QString::number(this->getJ(), 'f', jPrec) + "j + " + QString::number(this->getK(), 'f', kPrec) + "k";

}