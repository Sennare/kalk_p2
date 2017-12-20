#ifndef COLOR_H
#define COLOR_H
#include <string>
#include<math.h>
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
    Color(string c);
    Color(unsigned int, unsigned int, unsigned int); //0<=r,g,b<=255

    /**
     * Sezione parametri esadecimali per la modifica colore
     */
    void setRhex(string);
    void setGhex(string);
    void setBhex(string);
    string getRhex() const;
    string getGhex() const;
    string getBhex() const;

    /**
     * Sezione parametri decimali per la creazione colore
     */
    void setRdec(unsigned int);
    void setGdec(unsigned int);
    void setBdec(unsigned int);
    unsigned int getRdec() const;
    unsigned int getGdec() const;
    unsigned int getBdec() const;

    /**
     * Overloading di operatori
     */
    Color operator+(const Color&);
    Color operator-(const Color&);
    Color operator*(const Color&);
    Color operator/(const Color&);
    bool operator==(const Colore &)const;
    bool operator!=(const Colore &)const;


};

#endif // COLOR_H
