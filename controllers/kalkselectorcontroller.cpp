#include "kalkselectorcontroller.h"

KalkSelectorController::KalkSelectorController()
{
    // Nothing to do here
}

void KalkSelectorController::handle() {
    // Something to do here
    view = new KalkSelectorView;
    view->startApp();
    view->show();
}
