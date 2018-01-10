#include "complexcontroller.h"
#include <QDebug>

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
    switch (calcType) {
    case Complex::possibleKalk::calcSum:
        Complex vA(valA), vB(valB);
        Complex vC = vA + vB;
        emit signalCalcComplete(vC);
        qDebug() << vA.getString();
        qDebug() << vB.getString();
        qDebug() << vC.getString();
        break;
    }
}
