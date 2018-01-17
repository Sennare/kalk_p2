#include "application.h"
#include "views/kalkselectorview.h"
#include "views/audioview.h"
#include "views/testview.h"
#include "views/coloredwaveview.h"
#include "views/complexview.h"
#include "views/quaternionview.h"

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
    currentView = new KalkSelectorView();

    currentView->handle();

    KalkSelectorView* aux = dynamic_cast<KalkSelectorView*>(currentView);
    connect(aux, SIGNAL(signalOpenKalk(int)), this, SLOT(slotOpenKalkType(int)));
}

void Application::initializeKalk(View* subC) {
    destroyView();
    currentView = subC;
    subC->handle();
}

void Application::destroyView() {
    delete currentView;
}

void Application::exitKalk() {
    destroyView();
    initialize();
}

int Application::exec() {
    // Leave app ????
    return qAppl.exec();
}

void Application::slotOpenKalkType(int tipo) {
    switch (tipo) {
    case Application::KalkType::Complessi:
        {ComplexView* aux = new ComplexView();
        connect(aux, &ComplexView::signalBack, this, &Application::slotBack);
        initializeKalk(aux);}
        break;
    case Application::KalkType::Quaternioni:
        {QuaternionView* aux = new QuaternionView();
        connect(aux, &QuaternionView::signalBack, this, &Application::slotBack);
        initializeKalk(aux);}
        break;
    case Application::KalkType::OndeAudio:{
        AudioView* aux = new AudioView();
        connect(aux, &AudioView::signalBack, this, &Application::slotBack);
        initializeKalk(aux);}
        break;
    case Application::KalkType::OndeColorate:{
        ColoredWaveView* aux = new ColoredWaveView();
        connect(aux, &ColoredWaveView::signalBack, this, &Application::slotBack);
        initializeKalk(aux);}
    }

}

void Application::slotBack() {
    exitKalk();
}
