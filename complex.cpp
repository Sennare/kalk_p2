#include "complex.h"

Complex::Complex(float realVal, float imgVal)
{
    this->real = realVal;
    this->img = imgVal;
}



Complex Complex::operator+(const Complex& b) {
    Complex res;
    res.real = this->real + b.real;
    res.img= this->img + b.img;
    return res;
}
Complex Complex::operator-(const Complex& b) {
    Complex res;
    res.real = this->real - b.real;
    res.img= this->img - b.img;
    return res;
}
Complex Complex::operator*(const Complex& b) {
    Complex res;
    res.real = (this->real * b.real) + (this->img * b.img);
    res.img= (this->real * b.img) + (this->img * b.real);
    return res;
}
Complex Complex::operator/(const Complex& b) {
    Complex res;
    /*
     * TODO
    */
    return res;
}
