#include "audioview.h"
#include "ui_audioview.h"


AudioView::AudioView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioView)
{
    ui->setupUi(this);
    connect(ui->btnBack, SIGNAL(clicked(bool)), this, SIGNAL(signalBack()));

    connect(ui->btnInserisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaUno));
    connect(ui->btnSostituisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaUno));
    connect(ui->btnOttieniOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaUno));
    connect(ui->btnEliminaOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaUno));

    connect(ui->btnInserisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaDue));
    connect(ui->btnSostituisciOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaDue));
    connect(ui->btnOttieniOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaDue));
    connect(ui->btnEliminaOndaUno, SIGNAL(clicked(bool)), this, SLOT(slotOpOndaDue));

    connect(ui->btnSommaOndeAudio, SIGNAL(clicked(bool)), this, SLOT(slotCalcola));
    connect(ui->btnSottrazioneOndeAudio, SIGNAL(clicked(bool)), this, SLOT(slotCalcola));
    connect(ui->btnDivisioneOndeAudio, SIGNAL(clicked(bool)), this, SLOT(slotCalcola));
    connect(ui->btnMoltiplicazioneOndeAudio, SIGNAL(clicked(bool)), this, SLOT(slotCalcola));
    connect(ui->btnUguaglianzaOndeAudio, SIGNAL(clicked(bool)), this, SLOT(slotCalcola));
}

AudioView::~AudioView()
{
    delete ui;
}

void AudioView::slotOpOndaUno() {
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

/*void AudioView::slotOpOndaUnoEseguita(Audio risultato) {
    ui->lineEditRis->setText(risultato.getString());
}*/

void AudioView::slotOpOndaDue() {
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

/*void AudioView::slotOpOndaDueEseguita(Audio risultato) {
    ui->lineEditRis->setText(risultato.getString());
}*/

void AudioView::slotCalcola() {
    if (sender() == ui->btnSommaOndeAudio) {
    } else if (sender() == ui->btnSottrazioneOndeAudio){
    } else if (sender() == ui->btnDivisioneOndeAudio) {
    } else if (sender() == ui->btnMoltiplicazioneOndeAudio) {
    } else if (sender() == ui->btnUguaglianzaOndeAudio){
    }
}
