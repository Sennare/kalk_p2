#include "audio.h"

Audio::Audio(){}

double Audio::getWAmp(int i) {
    return w[i];
}

void Audio::setWAmp(double x, int i, bool insert) {
    if(i<0) {
        w.push_back(x);
    } else {
        if(insert) {
            w.insert(i, x);
        } else {
            w.replace(i, x);
        }
    }
}

void Audio::pushAmpVal(double x, double y) {
    this->setVAmp(x);
    this->setWAmp(y);
}

void Audio::removeAmpVal(const int i){
    if(i<w.size()){
        w.remove(i);
        v.remove(i);
    }
}

unsigned int Audio::waveLenght() const {
    return w.size();
}

void Audio::setAmpVal(const int i, const double x, const double y) {
    if (i<w.size()) {
        w.replace(i, x);
        v.replace(i, y);
    }
    //TODO: eccezione da aggiungere
}

double Audio::getAmpVal(const int x) const{
    if (x<w.size())
        return w.at(x), v.at(x);
    else return 0;
}

QString Audio::getString() {

}
