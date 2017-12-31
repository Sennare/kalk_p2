#ifndef QUATERNION_H
#define QUATERNION_H

#include <complex.h>

class Quaternion : public Complex
{
private:
    float jVal;
    float kVal;

public:
    Quaternion(float = 0, float = 0, float = 0, float = 0);
    //~Quaternion();

    void setJ(float);
    float getJ() const;
    void setK(float);
    float getK() const;
    void inverseJ();
    void inverseK();

    Quaternion operator+(const Quaternion&) const;
    Quaternion operator-(const Quaternion&) const;
    Quaternion operator*(const Quaternion&) const;
    Quaternion operator/(const Quaternion&) const;

    QString getString(unsigned int = 2, unsigned int = 2, unsigned int = 2, unsigned int = 2);
};

#endif // QUATERNION_H
