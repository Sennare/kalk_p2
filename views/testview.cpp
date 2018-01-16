#include "testview.h"
#include "ui_testview.h"

#include <QMovie>
#include <QPainter>
#include <QStringListModel>

TestView::TestView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestView)
{
    ui->setupUi(this);
    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SLOT(slotBackPressed()));

    QMovie *movie = new QMovie(":/Resources/Resources/what.gif");
    ui->label->setMovie(movie);
    movie->start();

    WaveGraph* grafico = new WaveGraph(this);
    grafico->initialize(400,400,300,100);
    ui->widget = grafico;
    ui->widget->show();

    QStringListModel* model = new QStringListModel();
    QStringList list;
    list << "50";
    list << "-23";
    list << "54";
    list << "70";
    list << "-60";
    list << "50";
    model->setStringList(list);
    ui->listView->setModel(model);

}

TestView::~TestView()
{
    delete ui;
}

void TestView::paintEvent(QPaintEvent *)
{
  //QPainter painter(this);

  //painter.setPen(QPen(Qt::black,1));

  /* Create the line object: */
  //QLineF line(0.0, 0.0, 90.0, 90.0);

  /* Draw the line: */
  //painter.drawLine(line);
}

void TestView::slotBackPressed() {
    emit signalBack();
}
