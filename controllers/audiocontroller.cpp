#include "audiocontroller.h"


AudioController::AudioController(){}

AudioController::~AudioController() {
    view->close();
}

void AudioController::handle() {
    view = new AudioView();
    connect(view, &AudioView::signalBack, this, &AudioController::slotBack);
    //connect(view, &AudioView::signalOpOndaUno, this, &AudioController::slotOpOndaUno);
    //connect(view, &AudioView::signalOpOndaDue, this, &AudioController::slotOpOndaDue);
    //connect(this, SIGNAL(signalOpnoOndaUnoEseguita(Audio)), view, SLOT(slotOpnoOndaUnoEseguita(Audio)));
    //connect(this, SIGNAL(signalOpnoOndaDueEseguita(Audio)), view, SLOT(slotOpnoOndaUnoEseguita(Audio)));
    view->show();
}

void AudioController::slotBack() {
    emit signalBack();
}

//void slotOpOndaUno()
