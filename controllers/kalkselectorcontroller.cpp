#include "kalkselectorcontroller.h"

KalkSelectorController::KalkSelectorController()
{
    // Nothing to do here
}

KalkSelectorController::~KalkSelectorController() {
    // do nothing
    view->close();
}

void KalkSelectorController::handle() {
    // Something to do here
    view = new KalkSelectorView();
    view->show();

    connect(view, &KalkSelectorView::signalOpenKalk, this, &KalkSelectorController::slotOpenKalk);
}

void KalkSelectorController::slotOpenKalk(int x) {
    emit signalOpenKalk(x);
}
