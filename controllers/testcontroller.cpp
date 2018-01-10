#include "testcontroller.h"

TestController::TestController()
{
    // Nothing to do here
}

TestController::~TestController() {
    // Nothing to do here
    view->close();
}

void TestController::handle() {
    // Something to do here
    view = new TestView();
    connect(view, &TestView::signalBack, this, &TestController::slotBack);
    view->show();
}

void TestController::slotBack() {
    emit signalBack();
}
