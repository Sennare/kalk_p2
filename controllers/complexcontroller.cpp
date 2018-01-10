#include "complexcontroller.h"

ComplexController::ComplexController()
{
    // Nothing to do here
}

ComplexController::~ComplexController() {
    // Nothing to do here
    view->close();
}

void ComplexController::handle() {
    // Something to do here
    view = new ComplexView();
    connect(view, &ComplexView::signalBack, this, &ComplexController::slotBack);
    connect(view, &ComplexView::signalCalculate, this, &ComplexController::slotCalculate);
    connect(this, SIGNAL(signalCalcComplete(Complex)), view, SLOT(slotCalcComplete(Complex)));
    view->show();
}

void ComplexController::slotBack() {
    emit signalBack();
}

void ComplexController::slotCalculate(int calcType, QString valA, QString valB) {
    Complex vA(valA), vB(valB);
    Complex vC;
    switch (calcType) {
    case Complex::possibleKalk::calcSum:
        vC = vA + vB;
        break;
    case Complex::possibleKalk::calcSub:
        vC = vA - vB;
        break;
    case Complex::possibleKalk::calcMult:
        vC = vA * vB;
        break;
    case Complex::possibleKalk::calcDiv:
        vC = vA / vB;
        break;
    case Complex::possibleKalk::calcInverse:
        vC = vA.inverse();
        break;
    case Complex::possibleKalk::calcNorm:
        vC = vA.norm();
        break;
    case Complex::possibleKalk::calcConj:
        vC = vA.conjugate();
        break;
    }
    emit signalCalcComplete(vC);
}
