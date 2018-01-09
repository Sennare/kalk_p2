#ifndef WAVE_H
#define WAVE_H

#include <QVector>
#include <QString>
#include <iostream>
#include<QDebug>
#include<QString>
#include<QStringList>

class Wave
{
protected:
    QVector<double> v;

public:
    Wave();
    Wave(QString);

    double getVAmp(int);
    void setVAmp(double, int=-1, bool = false);

    virtual ~Wave() = default;

    virtual void pushAmpVal(double);  //aggiunge un valore all'onda
    virtual void removeAmpVal(const int);  //rimuove valore che corrisponde a una determinata posizione
    virtual unsigned int waveLenght() const;    //ritorna la lunghezza della lista dei valori

    virtual void setAmpVal(const int, const double);   //modifica un valore della lista
    virtual double getAmpVal(const int) const;     //ritorna il valore di un determinato punto della lista

    virtual QString getString();    //ritorna la successione di punti in formato stringa

    Wave operator+(const Wave&);
    Wave operator-(const Wave&);
    Wave operator/(const Wave&);
    Wave operator*(const Wave&);
};

#endif // WAVE_H
