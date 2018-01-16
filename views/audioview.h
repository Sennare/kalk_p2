#ifndef AUDIOVIEW_H
#define AUDIOVIEW_H

#include <QWidget>
#include "views/view.h"
#include "logica/audio.h"
#include <QVector>
#include <QPair>


namespace Ui {
class AudioView;
}

class AudioView : public QWidget, public View
{
    Q_OBJECT

public:
    explicit AudioView(QWidget *parent = 0);
    ~AudioView();

    void handle() override;
    void updateOperatore(QVector<QVector<double>*>, int = 0);

private:
    Ui::AudioView *ui;

signals:
    void signalBack();

private slots:

    void slotOpOndaUno();
    //void slotOpOndaUnoEseguita(Audio);

    void slotOpOndaDue();
    //void slotOpOndaDueEseguita(Audio);

    void slotCalcola();

};

#endif // AUDIOVIEW_H
