#include "testview.h"
#include "ui_testview.h"

#include <QMovie>
#include <QPainter>
#include <QStringListModel>

TestView::TestView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestView)
{
}

TestView::~TestView()
{
    delete ui;
}

void TestView::handle() {
    // Something to do here
    ui->setupUi(this);
    show();

    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SLOT(slotBackPressed()));

    QMovie *movie = new QMovie(":/Resources/Resources/what.gif");
    ui->label->setMovie(movie);
    movie->start();

    // ui->grafico TEST
    QVector<double> x(101), y(101);
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i];  // let's plot a quadratic function
    }
    ui->grafico->addGraph();
    ui->grafico->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->grafico->xAxis->setLabel("x");
    ui->grafico->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->grafico->xAxis->setRange(-1, 1);
    ui->grafico->yAxis->setRange(0, 1);
}


void TestView::slotBackPressed() {
    emit signalBack();
}
