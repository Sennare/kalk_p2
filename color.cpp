#include "color.h"


/**
 * Costruttori per la classe colore
 * -costruttore per interi: imposta il colore predefinito di default
 * -costruttore per stringhe
 * -costruttori a 3 parametri per interi
 */
Color::Color(): r(255), g(255), b(255) {}
Color::Color(string c) {

}
Color::Color(unsigned int red, unsigned int green, unsigned int blue): r(red), g(green), b(blue) {
    if(r<0) r=0;
    if(r>255) r=255;
    if(g<0) g=0;
    if(g>255) g=255;
    if(b<0) b=0;
    if(b>255) b=255;
    int c = b + g*256 + r*65536;
    colore = c;
}



/**
 * Per le modifiche dei colori attraverso stringa:
 *      primi tre metodi per inserire i valori esadecimali di un colore
 *      gli alri parametri sono per ritornare i valori inseriti
 */
void Color::setRhex(string r) {

}

void Color::setGhex(string g) {

}

void Color::setBhex(string b) {

}
string Color::getRhex() const{}
string Color::getGhex() const{}
string Color::getBhex() const{}

/**
 * Per le modifiche dei colori attraverso interi:
 *      primi tre metodi per inserire i valori interi di un colore
 *      gli alri parametri sono per ritornare i valori inseriti
 */
void Color::setRdec(unsigned int r) {
    if(r>=0 && r<=255){
        r=red;
    }
}
void Color::setGdec(unsigned int g){
    if(g>=0 && g<=255){
        g=green;
    }
}
void Color::setBdec(unsigned int b){
    if(b>=0 && b<=255){
        b=blue;
    }
}
unsigned int Color::getRdec() const{
    return r;
}
unsigned int Color::getGdec() const{
    return g;
}
unsigned int Color::getBdec() const{
    return b;
}
