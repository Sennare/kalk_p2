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

void ColoredWaveView::handle() {
    ui->setupUi(this);
    show();

    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SIGNAL(signalBack()));

    connect(ui->btnInserisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno));
    connect(ui->btnSostituisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno));
    connect(ui->btnOttieniOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno));
    connect(ui->btnEliminaOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno));

    connect(ui->btnInserisciOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue));
    connect(ui->btnSostituisciOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue));
    connect(ui->btnOttieniOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue));
    connect(ui->btnEliminaOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue));

    connect(ui->btnSommaOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata));
    connect(ui->btnSottrazioneOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata));
    connect(ui->btnDivisioneOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata));
    connect(ui->btnMoltiplicazioneOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata));

    *operatoreTre = *operatoreUno + *operatoreDue;
    updateOperatore(ui->widgetOndaUno, operatoreUno);
    updateOperatore(ui->widgetOndaDue, operatoreDue);
    updateOperatore(ui->widgetRisultato, operatoreTre);

    ui->widgetOndaUno->xAxis2->setVisible(true);
    ui->widgetOndaUno->xAxis2->setTickLabels(false);
    ui->widgetOndaUno->yAxis2->setVisible(true);
    ui->widgetOndaUno->yAxis2->setTickLabels(false);
}


void ColoredWaveView::slotOpOndaColorataUno(){}
void ColoredWaveView::slotOpOndaColorataDue() {}
void ColoredWaveView::slotCalcolaOndaColorata(){}
