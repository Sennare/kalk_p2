#ifndef COLOREDWAVEVIEW_H
#define COLOREDWAVEVIEW_H

#include <QWidget>
#include "views/view.h"
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
private:
    Ui::ColoredWaveView *ui;

signals:
    void signalBack();
};

#endif // COLOREDWAVEVIEW_H
