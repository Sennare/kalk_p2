#ifndef AUDIOVIEW_H
#define AUDIOVIEW_H

#include <QWidget>

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
};

#endif // AUDIOVIEW_H
