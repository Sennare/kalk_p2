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
    void signalOpOndaDue(int, QString, QString, QString, QString);
private slots:
    void bottoniUno();
    void bottoniDue();
    void calcola();

};

#endif // AUDIOVIEW_H
