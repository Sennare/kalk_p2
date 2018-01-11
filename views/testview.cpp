#include "testview.h"
#include "ui_testview.h"

#include <QMovie>

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

void TestView::slotBackPressed() {
    emit signalBack();
}
