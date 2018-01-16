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
    dynamic_cast<WaveGraph*>(ui->widget)->setLine(0.0,0.0,50.0,80.0);

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

void TestView::slotBackPressed() {
    emit signalBack();
}
