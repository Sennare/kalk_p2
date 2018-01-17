#include "coloredwaveview.h"
#include "ui_coloredwaveview.h"

ColoredWaveView::ColoredWaveView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColoredWaveView)
{
    ui->setupUi(this);
    operatoreUno = new ColoredWave();
    operatoreDue = new ColoredWave();
    operatoreTre = new ColoredWave();
}

ColoredWaveView::~ColoredWaveView()
{
    delete ui;
    delete operatoreUno;
    delete operatoreDue;
    delete operatoreTre;
}

void ColoredWaveView::handle() {
    ui->setupUi(this);
    show();

    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SIGNAL(signalBack()));

    connect(ui->btnInserisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno));
    connect(ui->btnSostituisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno));
    connect(ui->btnOttieniOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno));
    connect(ui->btnEliminaOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno));
    connect(ui->horizontalSliderROndaUno,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataUno));
    connect(ui->horizontalSliderGOndaUno,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataUno));
    connect(ui->horizontalSliderBOndaUno,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataUno));


    connect(ui->btnInserisciOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue));
    connect(ui->btnSostituisciOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue));
    connect(ui->btnOttieniOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue));
    connect(ui->btnEliminaOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue));
    connect(ui->horizontalSliderROndaDue,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataDue));
    connect(ui->horizontalSliderGOndaDue,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataDue));
    connect(ui->horizontalSliderBOndaDue,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataDue));

    connect(ui->btnSommaOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata));
    connect(ui->btnSottrazioneOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata));
    connect(ui->btnDivisioneOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata));
    connect(ui->btnMoltiplicazioneOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata));

    //Assi cartesiani
    ui->widgetOndaUno->xAxis2->setVisible(true);
    ui->widgetOndaUno->xAxis2->setTickLabels(false);
    ui->widgetOndaUno->yAxis2->setVisible(true);
    ui->widgetOndaUno->yAxis2->setTickLabels(false);
    ui->widgetOndaDue->xAxis2->setVisible(true);
    ui->widgetOndaDue->xAxis2->setTickLabels(false);
    ui->widgetOndaDue->yAxis2->setVisible(true);
    ui->widgetOndaDue->yAxis2->setTickLabels(false);
    ui->widgetRisultato->xAxis2->setVisible(true);
    ui->widgetRisultato->xAxis2->setTickLabels(false);
    ui->widgetRisultato->yAxis2->setVisible(true);
    ui->widgetRisultato->yAxis2->setTickLabels(false);
}

void ColoredWaveView::updateAllOp(){
    updateOperatore(ui->widgetOndaUno, operatoreUno);
    updateOperatore(ui->widgetOndaDue, operatoreDue);
    updateOperatore(ui->widgetRisultato, operatoreTre);
}

void ColoredWaveView::updateOperatore(QCustomPlot* cPlot, ColoredWave* cWave) {
    cPlot->clearGraphs();
    cPlot->addGraph();
    cPlot->addGraph();
    cPlot->graph()->setPen(QPen(Qt::black));
    cPlot->graph()->setPen(QPen(QColor(0, 0, 0, 20)));

    for(int i=0; i<cWave->waveLenght(); ++i){
        cPlot->graph()->addData(i, cWave->getAmpVal(i));
    }
    cPlot->graph()->rescaleAxes();
    cPlot->replot();
}

void ColoredWaveView::slotOpOndaColorataUno(){
    QString valOndaUno = ui->lineEditValoriOndaUno->text();
    int indOndaUno = ui->lineEditIndiceOndaUno->text().simplified().toLower().replace( " ", "" ). toInt();
    int lungOndaUno = ui->lineEditLunghezzaOndaUno->text().simplified().toLower().replace( " ", "").toInt();

    int valROndaUno = ui->lineEditROndaUno->text().simplified().toLower().replace( " ", "").toInt();
    int valGOndaUno = ui->lineEditGOndaUno->text().simplified().toLower().replace( " ", "").toInt();
    int valBOndaUno = ui->lineEditBOndaUno->text().simplified().toLower().replace( " ", "").toInt();
    QString stringaColoreUno = ui->lineEditStringOndaUno->text();
}

void ColoredWaveView::slotOpOndaColorataDue() {}

void ColoredWaveView::slotCalcolaOndaColorata(){
    if (sender() == ui->btnSommaOndeColorate) {
        *operatoreTre = *operatoreUno + *operatoreDue;
    } else if (sender() == ui->btnSottrazioneOndeColorate){
        *operatoreTre = *operatoreUno - *operatoreDue;
    } else if (sender() == ui->btnDivisioneOndeColorate) {
        *operatoreTre = *operatoreUno / *operatoreDue;
    } else if (sender() == ui->btnMoltiplicazioneOndeColorate) {
        *operatoreTre = *operatoreUno * *operatoreDue;
    }
    updateOperatore(ui->widgetRisultato, operatoreTre);
}
