#ifndef COLOREDWAVEVIEW_H
#define COLOREDWAVEVIEW_H

#include <QWidget>

namespace Ui {
class ColoredWaveView;
}

class ColoredWaveView : public QWidget
{
    Q_OBJECT

public:
    explicit ColoredWaveView(QWidget *parent = 0);
    ~ColoredWaveView();

private:
    Ui::ColoredWaveView *ui;
};

#endif // COLOREDWAVEVIEW_H
