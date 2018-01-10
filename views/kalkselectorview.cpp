#include "kalkselectorview.h"
#include "ui_kalkselectorview.h"

KalkSelectorView::KalkSelectorView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KalkSelectorView)
{
    ui->setupUi(this);
}

KalkSelectorView::~KalkSelectorView()
{
    delete ui;
}

void KalkSelectorView::slotOpenComplex() {
    emit signalOpenKalk(Application::KalkType::Complessi);
}
