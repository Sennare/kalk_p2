#ifndef AUDIOVIEW_H
#define AUDIOVIEW_H

#include <QWidget>
#include "logica/audio.h"
#include <QVector>
#include <QPair>


namespace Ui {
class AudioView;
}

class AudioView : public QWidget
{
    Q_OBJECT

public:
    explicit AudioView(QWidget *parent = 0);
    ~AudioView();

    void updateOperatore(QVector<QVector<double>*>, int = 0);
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
