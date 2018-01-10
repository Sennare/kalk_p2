#include "testview.h"
#include "ui_testview.h"

TestView::TestView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestView)
{
    ui->setupUi(this);
}

TestView::~TestView()
{
    delete ui;
}
