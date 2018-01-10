#include "application.h"
#include "controllers/kalkselectorcontroller.h"
#include "controllers/complexcontroller.h"

Application* Application::istanza = 0;

Application::Application(int* argc, char** argv[]) :
    qAppl(*argc, *argv)
{
    istanza = this;
}

Application::~Application() {
    if (istanza == this) {
        istanza = 0;
    }
}

Application *Application::getIstanza() {
    return istanza;
}

void Application::initialize() {
    // do something   0_0
    currentController = new KalkSelectorController();

    currentController->handle();

    KalkSelectorController* aux = dynamic_cast<KalkSelectorController*>(currentController);
    connect(aux, SIGNAL(signalOpenKalk(int)), this, SLOT(slotOpenKalkType(int)));
}

void Application::initializeKalk(Controller* subC) {
    destroyController();
    currentController = subC;
    subC->handle();
}

void Application::destroyController() {
    delete currentController;
}

void Application::exitKalk() {
    destroyController();
    initialize();
}

int Application::exec() {
    // Leave app ????
    return qAppl.exec();
}

void Application::slotOpenKalkType(int tipo) {
    switch (tipo) {
    case Application::KalkType::Complessi:
        ComplexController* aux = new ComplexController();
        connect(aux, &ComplexController::signalBack, this, &Application::slotBack);
        initializeKalk(aux);
        break;
    }
}

void Application::slotBack() {
    exitKalk();
}
