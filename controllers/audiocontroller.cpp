#include "audiocontroller.h"
#include "qmath.h"

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

    operatoreSx = new Audio();
    QVector<QVector<double>*> ondaSX;
    ondaSX.push_back(new QVector<double>);
    ondaSX.push_back(new QVector<double>);
    // Generiamo un'onda di test
    for (int i=0; i<100; ++i) {
        operatoreSx->pushPoint(qCos(i/10.0),qSin(i/10.0));
        ondaSX[0]->push_back(operatoreSx->getAmpVal(i));
        ondaSX[1]->push_back(operatoreSx->getAmpVal(i, Audio::ondeDisponibili::ondaDx));
    }
    view->updateOperatore(ondaSX,1);

}

void AudioController::slotBack() {
    emit signalBack();
}

//void slotOpOndaUno()
