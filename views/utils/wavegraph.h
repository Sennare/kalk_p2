#ifndef WAVEGRAPH_H
#define WAVEGRAPH_H

#include <QWidget>
#include <QPainter>

class WaveGraph : public QWidget
{
    Q_OBJECT
public:
    explicit WaveGraph(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // WAVEGRAPH_H
