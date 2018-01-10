#include "testview.h"
#include "ui_testview.h"

TestView::TestView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestView)
{
    ui->setupUi(this);
    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SLOT(slotBackPressed()));
}

TestView::~TestView()
{
    delete ui;
}

void TestView::slotBackPressed() {
    emit signalBack();
}
