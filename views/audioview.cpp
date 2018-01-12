#include "audioview.h"
#include "ui_audioview.h"


AudioView::AudioView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioView)
{
    ui->setupUi(this);
    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SLOT(slotBackPressed()));

    connect(ui->btnInserisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(bottoniUno));
    connect(ui->btnSostituisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(bottoniUno));
    connect(ui->btnOttieniOndaUno, SIGNAL(clicked(bool)), this, SLOT(bottoniUno));
    connect(ui->btnEliminaOndaUno, SIGNAL(clicked(bool)), this, SLOT(bottoniUno));

    connect(ui->btnInserisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(bottoniDue));
    connect(ui->btnSostituisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(bottoniDue));
    connect(ui->btnOttieniOndaUno, SIGNAL(clicked(bool)), this, SLOT(bottoniDue));
    connect(ui->btnEliminaOndaUno, SIGNAL(clicked(bool)), this, SLOT(bottoniDue));

    connect(ui->btnSommaOndeAudio, SIGNAL(clicked(bool)), this, SLOT(calcola));
    connect(ui->btnSottrazioneOndeAudio, SIGNAL(clicked(bool)), this, SLOT(calcola));
    connect(ui->btnDivisioneOndeAudio, SIGNAL(clicked(bool)), this, SLOT(calcola));
    connect(ui->btnMoltiplicazioneOndeAudio, SIGNAL(clicked(bool)), this, SLOT(calcola));
    connect(ui->btnUguaglianzaOndeAudio, SIGNAL(clicked(bool)), this, SLOT(calcola));
}

AudioView::~AudioView()
{
    delete ui;
}

void AudioView::slotBackPressed(){
    emit signalBack();
}

void AudioView::bottoniUno() {
    QString valOndaUnoSx = ui->lineEditValoriOndaUnoOndaSx->text();
    QString valOndaUnoDx = ui->lineEditValoriOndaUnoOndaDx->text();
    QString indOndaUno = ui->lineEditIndiceOndaUno->text();
    QString lungOndaUno = ui->lineEditLunghezzaOndaUno->text();

    int operazioneDaEseguire = -1;

    if (sender() == ui->btnInserisciOndaUno) {
        operazioneDaEseguire = Audio::operazioniDisponibili::opPush;
    } else if (sender() == ui->btnSostituisciOndaUno){
        operazioneDaEseguire = Audio::operazioniDisponibili::opSostituzione;
    } else if (sender() == ui->btnOttieniOndaUno) {
        operazioneDaEseguire = Audio::operazioniDisponibili::opGet;
    } else if (sender() == ui->btnEliminaOndaUno) {
        operazioneDaEseguire = Audio::operazioniDisponibili::opRemove;
    }

    if (operazioneDaEseguire >= 0) emit signalOpOndaUno(operazioneDaEseguire,
                                                        valOndaUnoSx,
                                                        valOndaUnoDx,
                                                        indOndaUno,
                                                        lungOndaUno);
}

void AudioView::bottoniDue() {
    QString valOndaDueSx = ui->lineEditValoriOndaDueOndaSx->text();
    QString valOndaDueDx = ui->lineEditValoriOndaDueOndaDx->text();
    QString indOndaDue = ui->lineEditIndiceOndaDue->text();
    QString lungOndaDue = ui->lineEditLunghezzaOndaDue->text();

    int operazioneDaEseguire = -1;

    if (sender() == ui->btnInserisciOndaDue) {
        operazioneDaEseguire = Audio::operazioniDisponibili::opPush;
    } else if (sender() == ui->btnSostituisciOndaDue){
        operazioneDaEseguire = Audio::operazioniDisponibili::opSostituzione;
    } else if (sender() == ui->btnOttieniOndaDue) {
        operazioneDaEseguire = Audio::operazioniDisponibili::opGet;
    } else if (sender() == ui->btnEliminaOndaDue) {
        operazioneDaEseguire = Audio::operazioniDisponibili::opRemove;
    }
    if (operazioneDaEseguire >= 0) emit signalOpOndaDue(operazioneDaEseguire,
                                                        valOndaDueSx,
                                                        valOndaDueDx,
                                                        indOndaDue,
                                                        lungOndaDue);
}
void AudioView::calcola() {
    if (sender() == ui->btnSommaOndeAudio) {
    } else if (sender() == ui->btnSottrazioneOndeAudio){
    } else if (sender() == ui->btnDivisioneOndeAudio) {
    } else if (sender() == ui->btnMoltiplicazioneOndeAudio) {
    } else if (sender() == ui->btnUguaglianzaOndeAudio){
    }
}
