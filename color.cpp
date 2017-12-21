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
    if(r>255) r=255;
    if(g>255) g=255;
    if(b>255) b=255;
}

/**
 * Per le modifiche dei colori attraverso interi:
 *      primi tre metodi per inserire i valori interi di un colore
 *      gli alri parametri sono per ritornare i valori inseriti
 */
void Color::setRdec(unsigned int red) {
    r=red;
}
void Color::setGdec(unsigned int green){
    g=green;
}
void Color::setBdec(unsigned int blue){
    b=blue;
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

string ConvertRGBtoHex(const Color& x) const {
    std::string HEX = "#";
    return HEX+caratteriHex[(x.getRdec()/16)%16]+caratteriHex[x.getRdec()%16]+caratteriHex[(x.getGdec()/16)%16]+caratteriHex[x.getGdec()%16]+caratteriHex[(x.getBdec()/16)%16]+caratteriHex[x.getBdec()%16];
}
