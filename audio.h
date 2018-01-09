#ifndef AUDIO_H
#define AUDIO_H
#include <QVector>
#include <QString>
#include "wave.h"

class Audio : public Wave {
private:
    unsigned int BitRate;
    QVector<double> w;
public:
    Audio();
    ~Audio();

    double getWAmp(int);    //ritorna l'ampiezza dell'onda nei vari punti
    void setWAmp(double, int=-1, bool=false);   //per settare altezza desiderata o con indice di default

    void pushAmpVal(double, double);  //aggiunge un valore all'onda
    void removeAmpVal(const int);  //rimuove valore che corrisponde a una determinata posizione
    unsigned int waveLenght() const;    //ritorna la lunghezza della lista dei valori

    void setAmpVal(const int, const double, const double);   //modifica un valore della lista
    virtual double getAmpVal(const int) const;     //ritorna il valore desro e sinistro di un determinato punto della lista

    QString getString();    //ritorna la successione di punti in formato stringa

    Audio operator+(const Audio&);
    Audio operator-(const Audio&);
    Audio operator/(const Audio&);
    Audio operator*(const Audio&);
};

#endif // AUDIO_H
