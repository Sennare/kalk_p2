#include "quaternioncontroller.h"

#include <QMessageBox>

QuaternionController::QuaternionController()
{
    // Nothing to do here
}

QuaternionController::~QuaternionController() {
    // Nothing to do here
    view->close();
}

void QuaternionController::handle() {
    // Something to do here
    view = new QuaternionView();
    connect(view, &QuaternionView::signalBack, this, &QuaternionController::slotBack);
    connect(view, &QuaternionView::signalCalculate, this, &QuaternionController::slotCalculate);
    connect(this, SIGNAL(signalCalcComplete(Quaternion)), view, SLOT(slotCalcComplete(Quaternion)));
    view->show();
}

void QuaternionController::slotBack() {
    emit signalBack();
}

void QuaternionController::slotCalculate(int calcType, QString valA, QString valB) {
    try{
        Quaternion vA(valA), vB(valB);
        Quaternion vC;
        switch (calcType) {
        case Quaternion::possibleKalk::calcSum:
                vC = vA + vB;
            break;
        case Quaternion::possibleKalk::calcSub:
            vC = vA - vB;
            break;
        case Quaternion::possibleKalk::calcMult:
            vC = vA * vB;
            break;
        case Quaternion::possibleKalk::calcDiv:
            vC = vA / vB;
            break;
        case Quaternion::possibleKalk::calcInverse:
            vC = vA.inverse();
            break;
        case Quaternion::possibleKalk::calcNorm:
            vC = vA.norm();
            break;
        case Quaternion::possibleKalk::calcConj:
            vC = vA.conjugate();
            break;
        }
        emit signalCalcComplete(vC);
    }catch(exce_kalk err){
        // Something to do here
        QMessageBox::information(view, tr("Error"), err.what());
        //view->errorManager(err.what());
    }
}
