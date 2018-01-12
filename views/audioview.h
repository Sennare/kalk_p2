#ifndef AUDIOVIEW_H
#define AUDIOVIEW_H

#include <QWidget>
#include "logica/audio.h"

namespace Ui {
class AudioView;
}

class AudioView : public QWidget
{
    Q_OBJECT

public:
    explicit AudioView(QWidget *parent = 0);
    ~AudioView();

private:
    Ui::AudioView *ui;

signals:
    void signalBack();

    void signalOpOndaUno(int, QString, QString, QString, QString);
    //void signalOpOndaUnoEseguita(Audio);

    void signalOpOndaDue(int, QString, QString, QString, QString);
    //void signalOpOndaDueEseguita(Audio);

private slots:

    void slotOpOndaUno();
    //void slotOpOndaUnoEseguita(Audio);

    void slotOpOndaDue();
    //void slotOpOndaDueEseguita(Audio);

    void slotCalcola();

};

#endif // AUDIOVIEW_H
