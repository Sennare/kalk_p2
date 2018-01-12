#include "wavegraph.h"

WaveGraph::WaveGraph(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background-color: red");
}

void WaveGraph::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black,1));

    /* Create the line object: */
    QLineF line(0.0, 0.0, 90.0, 50.0);
    QLineF line2(90.0, 50.0, 50.0, 10.0);

    /* Draw the line: */
    painter.drawLine(line);
    painter.drawLine(line2);
}

void WaveGraph::initialize(int width, int height, int x, int y) {
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::gray);
    pal.setColor(QPalette::Base, Qt::red);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setFixedSize(width, height);
    if (x >= 0 && y >= 0) {
        QPoint pos(x, y);
        this->move(pos);
    }
}
void WaveGraph::setLine(QVector<double> x, QVector<double> y, int index) {

}
void WaveGraph::removeLine(int index) {

}
