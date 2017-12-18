#ifndef COLOR_H
#define COLOR_H
#include <string>
#include<math.h>
class Color
{
private:
    int r, g, b;
public:
    /**
     * Costruttori per la classe Color
     * Si possono creare scrivendo il colore in caratteri esadecimali o inserendo i valori
     */
    Color();
    Color(string c);
    Color(int r, int g, int b); //0<=r,g,b<=255

    /**
     * Sezione parametri esadecimali per la creazione colore
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
    void setRdec(int);
    void setGdec(int);
    void setBdec(int);
    int getRdec() const;
    int getGdec() const;
    int getBdec() const;

    /**
     * Overloading di operatori
     */
    Color operator+(const Color&);
    Color operator-(const Color&);
    Color operator*(const Color&);
    Color operator/(const Color&);


};

#endif // COLOR_H
