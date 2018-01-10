#ifndef AUDIO_H
#define AUDIO_H
#include <QVector>
#include <QString>
#include <QPair>
#include "wave.h"

class Audio : public Wave {
private:
    unsigned int BitRate;
    QVector<double> w;
public:
    Audio();
    ~Audio();

    enum ondeDisponibili{
        ondaSx,
        ondaDx
    };

    double getWAmp(int) const;    //ritorna l'ampiezza dell'onda nei vari punti
    void setWAmp(double, int=-1, bool=false);   //per settare altezza desiderata o con indice di default
    void removeWAmp(int);   //rimuove valori delle due onde del file audio da un determinato indice

    void pushAmpVal(double, double);  //aggiunge un valore all'onda
    void removeAmpVal(const int);  //rimuove valore che corrisponde a una determinata posizione
    int waveLenght() const;    //ritorna la lunghezza della lista dei valori

    void setAmpVal(const int, const double, const double);   //modifica un valore della lista
    double getAmpVal(const int, int=Audio::ondeDisponibili::ondaSx) const;     //ritorna il valore destro e sinistro di un determinato punto della lista
    QPair<double, double> getBothAmpVal(const int);    //

    QString getString();    //ritorna la successione di punti in formato stringa

    Audio operator+(const Audio&);
    Audio operator-(const Audio&);
    Audio operator/(const Audio&);
    Audio operator*(const Audio&);
};

#endif // AUDIO_H
