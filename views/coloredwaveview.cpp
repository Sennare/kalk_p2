#include "coloredwaveview.h"
#include "ui_coloredwaveview.h"
#include <QDebug>

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
    //ui->setupUi(this);
    show();

    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SIGNAL(signalBack()));

    connect(ui->btnInserisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno()));
    connect(ui->btnSostituisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno()));
    connect(ui->btnOttieniOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno()));
    connect(ui->btnEliminaOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataUno()));
    connect(ui->horizontalSliderROndaUno,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataUno()));
    connect(ui->horizontalSliderGOndaUno,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataUno()));
    connect(ui->horizontalSliderBOndaUno,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataUno()));


    connect(ui->btnInserisciOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue()));
    connect(ui->btnSostituisciOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue()));
    connect(ui->btnOttieniOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue()));
    connect(ui->btnEliminaOndaDue, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaColorataDue()));
    connect(ui->horizontalSliderROndaDue,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataDue()));
    connect(ui->horizontalSliderGOndaDue,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataDue()));
    connect(ui->horizontalSliderBOndaDue,SIGNAL(valueChanged(int)),this, SLOT(slotOpOndaColorataDue()));

    connect(ui->btnSommaOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata()));
    connect(ui->btnSottrazioneOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata()));
    connect(ui->btnDivisioneOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata()));
    connect(ui->btnMoltiplicazioneOndeColorate, SIGNAL(clicked(bool)), this, SLOT(slotCalcolaOndaColorata()));

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
    updateOperatore(ui->widgetOndaUno, ui->listWidgetColoriOndaUno, operatoreUno);
    updateOperatore(ui->widgetOndaDue, ui->listWidgetColoriOndaDue, operatoreDue);
    updateOperatore(ui->widgetRisultato, ui->listWidgetColoriOndaTre, operatoreTre);
}

void ColoredWaveView::updateOperatore(QCustomPlot* cPlot, QListWidget* listW, ColoredWave* cWave) {
    cPlot->clearGraphs();
    cPlot->addGraph();
    cPlot->graph(0)->setPen(QPen(Qt::black));
    cPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    listW->clear();
    for(int i=0; i<cWave->waveLenght(); ++i){
        cPlot->graph(0)->addData(i, cWave->getAmpVal(i));

        Color colore = cWave->getColor(i);
        QColor coloreSfondo(colore.getRdec(), colore.getGdec(), colore.getBdec());
        QBrush brushSfondo(coloreSfondo);
        QColor coloreText(255-colore.getRdec(), 255-colore.getGdec(), 255-colore.getBdec());
        QBrush brushText(coloreText);
        QListWidgetItem *item = new QListWidgetItem();
        item->setBackground(brushSfondo);
        item->setForeground(brushText);
        item->setText(QString::number(i));
        listW->addItem(item);
    }
    cPlot->graph(0)->rescaleAxes(true);
    cPlot->replot();
}

void ColoredWaveView::slotOpOndaColorataUno(){
    double ampOndaUno = ui->lineEditValoriOndaUno->text().simplified().toLower().replace(" ", "").toDouble();
    int indOndaUno = ui->lineEditIndiceOndaUno->text().simplified().toLower().replace( " ", "" ). toInt();

    int valROndaUno = ui->lineEditROndaUno->text().simplified().toLower().replace( " ", "").toInt();
    int valGOndaUno = ui->lineEditGOndaUno->text().simplified().toLower().replace( " ", "").toInt();
    int valBOndaUno = ui->lineEditBOndaUno->text().simplified().toLower().replace( " ", "").toInt();
    Color colore(valROndaUno, valGOndaUno, valBOndaUno);

    if (sender() == ui->btnInserisciOndaUno){
        int indTarget = (indOndaUno<0 ? -1 : indOndaUno);
        operatoreUno->pushPoint(ampOndaUno, colore, indTarget, true);
        updateAllOp();
    } else if(sender() == ui->btnSostituisciOndaUno) {
        if (indOndaUno < 0) indOndaUno = 0;
        int indTarget = (indOndaUno<0 ? 0 : indOndaUno);
        operatoreUno->pushPoint(ampOndaUno, colore, indTarget, false);
        updateAllOp();
    } else if (sender() == ui->btnOttieniOndaUno) {
        ui->lineEditValoriOndaUno->setText((QString::number(operatoreUno->getAmpVal(indOndaUno))));
    } else if (sender() == ui->btnEliminaOndaUno) {
        operatoreUno->removePoint(indOndaUno);
        updateAllOp();
    }
}

void ColoredWaveView::slotOpOndaColorataDue() {
    double ampOndaDue = ui->lineEditValoriOndaDue->text().simplified().toLower().replace( " ", "").toDouble();
    int indOndaDue = ui->lineEditIndiceOndaDue->text().simplified().toLower().replace( " ", "" ). toInt();

    int valROndaDue = ui->lineEditROndaDue->text().simplified().toLower().replace( " ", "").toInt();
    int valGOndaDue = ui->lineEditGOndaDue->text().simplified().toLower().replace( " ", "").toInt();
    int valBOndaDue = ui->lineEditBOndaDue->text().simplified().toLower().replace( " ", "").toInt();
    Color colore(valROndaDue, valGOndaDue, valBOndaDue);

    if (sender() == ui->btnInserisciOndaDue){
        int indTarget = (indOndaDue<0 ? -1 : indOndaDue);
        operatoreDue->pushPoint(ampOndaDue, colore, indTarget, true);
        updateAllOp();
    } else if(sender() == ui->btnSostituisciOndaDue) {
        if (indOndaDue < 0) indOndaDue = 0;
        int indTarget = (indOndaDue<0 ? 0 : indOndaDue);
        operatoreDue->pushPoint(ampOndaDue, colore, indTarget, false);
        updateAllOp();
    } else if (sender() == ui->btnOttieniOndaDue) {
        ui->lineEditValoriOndaDue->setText((QString::number(operatoreDue->getAmpVal(indOndaDue))));
    } else if (sender() == ui->btnEliminaOndaDue) {
        operatoreDue->removePoint(indOndaDue);
        updateAllOp();
    }

}

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
    updateOperatore(ui->widgetRisultato, ui->listWidgetColoriOndaTre, operatoreTre);
}
