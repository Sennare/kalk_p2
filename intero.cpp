#include "intero.h"

Intero::Intero(int intVal) {
	val = intVal;
}

int Intero::getVal() {
    return this->val;
}

Intero Intero::operator+(const Intero& toAdd) {
    Intero res;
    res.val = this->val + toAdd.val;
    return res;
}
