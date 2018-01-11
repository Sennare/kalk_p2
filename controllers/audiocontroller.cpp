#include "audiocontroller.h"


AudioController::AudioController(){}

AudioController::~AudioController() {
    view->close();
}

void AudioController::handle() {
    view = new AudioView();
    connect(view, &AudioView::signalBack, this, &AudioController::slotBack);
    view->show();
}

void AudioController::slotBack() {
    emit signalBack();
}
