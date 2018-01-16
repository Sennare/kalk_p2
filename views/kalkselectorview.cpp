#include "kalkselectorview.h"
#include "ui_kalkselectorview.h"

KalkSelectorView::KalkSelectorView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KalkSelectorView)
{
}

KalkSelectorView::~KalkSelectorView()
{
    delete ui;
}

void KalkSelectorView::handle() {
    // Something to do here
    ui->setupUi(this);
    show();
    connect(ui->openComplex, SIGNAL(clicked(bool)), this, SLOT(slotOpenComplex()));
    connect(ui->openAudio, SIGNAL(clicked(bool)), this, SLOT(slotOpenAudio()));
}


void KalkSelectorView::slotOpenComplex() {
    emit signalOpenKalk(Application::KalkType::Complessi);
}
void KalkSelectorView::slotOpenAudio() {
    emit signalOpenKalk(Application::KalkType::OndeAudio);
}
