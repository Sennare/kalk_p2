#include "wavegraph.h"

WaveGraph::WaveGraph(QWidget *parent) : QWidget(parent)
{

}

void WaveGraph::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black,1));

    /* Create the line object: */
    QLineF line(0.0, 0.0, 90.0, 90.0);
    QLineF line2(90.0, 90.0, 110.0, 50.0);

    /* Draw the line: */
    painter.drawLine(line);
    painter.drawLine(line2);
}
