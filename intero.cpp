#include "intero.h"

Intero::Intero(int intVal) {
	val = intVal;
}

Intero Intero::operator+(const Intero& toAdd) {
    Intero res;
    res.val = this->val + toAdd.val;
    return res;
}
Intero Intero::operator-(const Intero& toAdd) {
    Intero res;
    res.val = this->val - toAdd.val;
    return res;
}
Intero Intero::operator*(const Intero& toAdd) {
    Intero res;
    res.val = this->val * toAdd.val;
    return res;
}
Intero Intero::operator/(const Intero& toAdd) {
    Intero res;
    res.val = this->val / toAdd.val;
    return res;
}
