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
signals:
    void signalBack();
};

#endif // AUDIOCONTROLLER_H
