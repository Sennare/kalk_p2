#include "color.h"


/**
 * Costruttori per la classe colore
 * -costruttore per interi: imposta il colore predefinito di default
 * -costruttore per stringhe
 * -costruttori a 3 parametri per interi
 */
Color::Color(): r(255), g(255), b(255) {}
Color::Color(QString c) {

}
Color::Color(unsigned int red, unsigned int green, unsigned int blue): r(red), g(green), b(blue) {
    if(r>255) r=255;
    if(g>255) g=255;
    if(b>255) b=255;
}
Color::Color(const Color& x) {
    r=x.r;
    g=x.g;
    b=x.b;
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

QString ConvertRGBtoHex(const Color* RGB) {
    Helper aux;
    QString result="#";
    result.append(aux.decToHex(RGB->getRdec()));
    result.append(aux.decToHex(RGB->getGdec()));
    result.append(aux.decToHex(RGB->getBdec()));
    return result;
}

QString Color::GetColore() const{
    QString color;
    color.append(getRdec());
    color.append(getGdec());
    color.append(getBdec());
    return color;
}

Color* operator+ (const Color& x, const Color& y){
    return new Color ((x.getRdec()+y.getRdec())%255, (x.getGdec()+y.getGdec())%255, (x.getBdec()+y.getBdec())%255);
}
Color* operator- (const Color& x, const Color& y){
    return new Color ((x.getRdec()-y.getRdec())%255, (x.getGdec()-y.getGdec())%255, (x.getBdec()-y.getBdec())%255);
}
Color* operator* (const Color& x, const Color& y){
    return new Color ((x.getRdec()*y.getRdec())%255, (x.getGdec()*y.getGdec())%255, (x.getBdec()*y.getBdec())%255);
}
Color* operator/ (const Color& x, const Color& y){
    return new Color ((x.getRdec()/y.getRdec())%255, (x.getGdec()/y.getGdec())%255, (x.getBdec()/y.getBdec())%255);
}
