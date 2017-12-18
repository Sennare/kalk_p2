#include "color.h"

Color::Color()
{
    colore=0;
}
Color::Color(string c) {

}
Color::Color(int r, int g, int b) {
    if(r<0) r=0;
    if(r>255) r=255;
    if(g<0) g=0;
    if(g>255) g=255;
    if(b<0) b=0;
    if(b>255) b=255;
    int c = b + g*256 + r*65536;
    colore = c;
}

void Color::setRhex(string r) {

}

void Color::setGhex(string g) {

}

void Color::setBhex(string b) {

}
