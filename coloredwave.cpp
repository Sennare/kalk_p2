#include "coloredwave.h"

ColoredWave::ColoredWave() {}

Color ColoredWave::getColor(int index) const {
    Color ret;
    if(index < colori.size()) {
        ret=*colori[index];
    } return ret;
}


void ColoredWave::setColor(Color color, int index, bool insert) {
    Color* aux = new Color(color);
    if(index < 0) {
        colori.push_back(aux);
    } else if (insert < waveLenght()){
        if(insert){
            colori.insert(index, aux);
        } else {
            colori.replace(index, aux);
        }
    }
}

void ColoredWave::pushPoint(double val, Color color, int index, bool insert) {
    this->setVAmp(val, index, insert);
    this->setColor(color, index, insert);
}

void ColoredWave::removePoint(const int index) {
    if (index < colori.size()) {
        colori.remove(index);
        v.remove(index);
    }
}

int ColoredWave::waveLenght() const{
    return colori.size();
}

double ColoredWave::getAmpVal(const int index) const {
    return getVAmp(index);
}

Color ColoredWave::getAmpColor(const int index) const {
    return getColor(index);
}

QString ColoredWave::getString(){
    QString ret("("), comma;
    QVector<Color*>::const_iterator end=colori.end();
    for(QVector<Color*>::const_iterator now = colori.begin(); now != end; ++now){
        ret.append(comma);
        ret.append(Color::ConvertRGBtoHex(*now));
        comma=",";
    }
    ret.append(")");
    return ret;
}
