#include "coloredwaveview.h"
#include "ui_coloredwaveview.h"

ColoredWaveView::ColoredWaveView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColoredWaveView)
{
    ui->setupUi(this);
}

ColoredWaveView::~ColoredWaveView()
{
    delete ui;
}
