#ifndef COLOR_H
#define COLOR_H

#include <string>
#include <math.h>
#include "QString"
#include <iostream>

#include "helper.h"

using std::string;

class Color
{
private:
    unsigned int r, g, b;

public:
    /**
     * Costruttori per la classe Color
     * Si possono creare scrivendo il colore in caratteri esadecimali o inserendo i valori
     */
    Color();
    Color(QString );
    Color(unsigned int, unsigned int, unsigned int); //0<=r,g,b<=255
    Color(const Color&);
    Color(const Color*);
    ~Color() = default;

    /**
     * Sezione parametri decimali per la creazione colore
     */
    void setRdec(unsigned int);
    void setGdec(unsigned int);
    void setBdec(unsigned int);
    unsigned int getRdec() const;
    unsigned int getGdec() const;
    unsigned int getBdec() const;

    static QString ConvertRGBtoHex(const Color*);
    QString GetColore() const;

    Color operator+(const Color& x) const;
    Color operator-(const Color& x) const;
    Color operator*(const Color& x) const;
    Color operator/(const Color& x) const;
};
#endif // COLOR_H
