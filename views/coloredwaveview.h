#ifndef COLOREDWAVEVIEW_H
#define COLOREDWAVEVIEW_H

#include <QWidget>
#include "views/view.h"
#include "logica/coloredwave.h"
#include "views/utils/qcustomplot.h"
namespace Ui {
class ColoredWaveView;
}

class ColoredWaveView : public QWidget, public View
{
    Q_OBJECT

public:
    explicit ColoredWaveView(QWidget *parent = 0);
    ~ColoredWaveView();

    void handle() override;

    void updateAllOp();

   // void updateOperatore(QCustomPlot*, ColoredWave*);

private:
    Ui::ColoredWaveView *ui;

    ColoredWave* operatoreUno;

    ColoredWave* operatoreDue;

    ColoredWave* operatoreTre;

signals:
    void signalBack();

private slots:

    void slotOpOndaColorataUno();

    void slotOpOndaColorataDue();

    void slotCalcolaOndaColorata();
};

#endif // COLOREDWAVEVIEW_H
