#ifndef AUDIOCONTROLLER_H
#define AUDIOCONTROLLER_H

#include<QObject>
#include"controllers/controller.h"
#include"views/audioview.h"
#include "logica/audio.h"

class AudioController : public Controller
{
    Q_OBJECT
private:
    AudioView* view;
public:
    AudioController();
    ~AudioController();

    Audio* operatoreSx;
    Audio* operatoreDx;
    Audio* operatoreRis;

    void handle() override;

private slots:
    void slotBack();

    //void slotOpOndaUno(int, QString, QString, QString, QString);

    //void slotOpOndaDue(int, QString, QString, QString, QString);
signals:
    void signalBack();

    //signalOpOndaUnoEseguita(Audio);

    //signalOpOndaDueEseguita(Audio);
};

#endif // AUDIOCONTROLLER_H
