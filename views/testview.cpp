#include "testview.h"
#include "ui_testview.h"

#include <QMovie>
#include <QPainter>

TestView::TestView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestView)
{
    ui->setupUi(this);
    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SLOT(slotBackPressed()));

    QMovie *movie = new QMovie(":/Resources/Resources/what.gif");
    ui->label->setMovie(movie);
    movie->start();

}

TestView::~TestView()
{
    delete ui;
}

void TestView::paintEvent(QPaintEvent *)
{
  QPainter painter(this);

  painter.setPen(QPen(Qt::black,1));

  /* Create the line object: */
  QLineF line(0.0, 0.0, 90.0, 90.0);

  /* Draw the line: */
  painter.drawLine(line);
}

void TestView::slotBackPressed() {
    emit signalBack();
}
