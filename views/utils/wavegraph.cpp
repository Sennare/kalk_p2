#include "wavegraph.h"

WaveGraph::WaveGraph(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background-color: red");

}

void WaveGraph::paintEvent(QPaintEvent *) {
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
    painter.setPen(QPen(Qt::black,1));

    painter.setPen(QPen(Qt::black,1));
    // Create the line object:
    QLineF line(0.0,0.0,80.0,40.0);
    // Draw the line:
    painter.drawLine(line);
}

void WaveGraph::initialize(int width, int height, int x, int y) {
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::gray);
    //pal.setColor(QPalette::Base, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
    setFixedSize(width, height);
    if (x >= 0 && y >= 0) {
        QPoint pos(x, y);
        this->move(pos);
    }


}
void WaveGraph::setLine(double x1, double y1, double x2, double y2, int index) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black,1));
    // Create the line object:
    QLineF line(x1, y1, x2, y2);
    // Draw the line:
    painter.drawLine(line);
}
