#include "application.h"

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
}

int Application::exec() {
    // Leave app ????
    return qAppl.exec();
}
