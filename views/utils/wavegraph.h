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

    void initialize(int, int, int = -1, int = -1);
    void setLine(QVector<double>, QVector<double>, int = 0);
    void removeLine(int = 0);
signals:

public slots:
};

#endif // WAVEGRAPH_H
