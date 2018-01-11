#include "kalkselectorview.h"
#include "ui_kalkselectorview.h"

KalkSelectorView::KalkSelectorView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KalkSelectorView)
{
    ui->setupUi(this);

    connect(ui->openComplex, SIGNAL(clicked(bool)), this, SLOT(slotOpenComplex()));
    connect(ui->openQuaternion, SIGNAL(clicked(bool)), this, SLOT(slotOpenQuaternion()));
}

KalkSelectorView::~KalkSelectorView()
{
    delete ui;
}

void KalkSelectorView::slotOpenComplex() {
    emit signalOpenKalk(Application::KalkType::Complessi);
}


void KalkSelectorView::slotOpenQuaternion() {
    emit signalOpenKalk(Application::KalkType::Quaternioni);
}
