#include "intero.h"
#include "ui_intero.h"

Intero::Intero(int intVal) {
	val = intVal;
}

Intero::getVal() {
	return this.val;
}

Intero::operator+(const Intero& toAdd) {
	this.val += toAdd.getVal();
}