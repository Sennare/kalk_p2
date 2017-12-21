#ifndef COLOR_H
#define COLOR_H

#include <string>
#include <math.h>
#include <QObject>
#include <iostream>

using std::string;

class Color
{
private:
    unsigned int r, g, b;
    static char caratteriHex[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, "A", "B", "C", "D", "E", "F"};
public:
    /**
     * Costruttori per la classe Color
     * Si possono creare scrivendo il colore in caratteri esadecimali o inserendo i valori
     */
    Color();
    Color(string );
    Color(unsigned int, unsigned int, unsigned int); //0<=r,g,b<=255
    ~Color();

    /**
     * Sezione parametri decimali per la creazione colore
     */
    void setRdec(unsigned int);
    void setGdec(unsigned int);
    void setBdec(unsigned int);
    unsigned int getRdec() const;
    unsigned int getGdec() const;
    unsigned int getBdec() const;

    string ConvertRGBtoHex(const Color&) const;

    /**
     * Overloading di operatori
     */
    Color operator+(const Color&);
    Color operator-(const Color&);
    Color operator*(const Color&);
    Color operator/(const Color&);
    bool operator==(const Color &)const;
    bool operator!=(const Color &)const;


};

#endif // COLOR_H
