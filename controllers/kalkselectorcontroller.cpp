#include "kalkselectorcontroller.h"

KalkSelectorController::KalkSelectorController()
{
    // Nothing to do here
}

KalkSelectorController::~KalkSelectorController() {
    // do nothing
}

void KalkSelectorController::handle() {
    // Something to do here
    view = new KalkSelectorView();
    //view->startApp();
    view->show();
}
