#include "audioview.h"
#include "ui_audioview.h"

AudioView::AudioView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioView)
{
    ui->setupUi(this);
}

AudioView::~AudioView()
{
    delete ui;
}
