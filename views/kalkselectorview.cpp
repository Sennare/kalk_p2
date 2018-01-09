#include "kalkselectorview.h"
#include "ui_kalkselectorview.h"

KalkSelectorView::KalkSelectorView() :
    ui(new Ui::KalkSelectorView)
{
    ui->setupUi(this);
    // Nothing to do here
    mdi = new QMdiArea;
    setCentralWidget(mdi);
}

KalkSelectorView::~KalkSelectorView() {
    delete mdi;
}

void KalkSelectorView::startApp() {
    // boooh
}
