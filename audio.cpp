#include "audio.h"

Audio::Audio(){}

double Audio::getWAmp(int index) const {
    if(index < w.size()) {
        return w[index];
    }else return 0;
}

void Audio::setWAmp(double x, int index, bool insert) {
    if(index<0) {
        w.push_back(x);
    } else if (index<waveLenght()){
        if(insert) {
            w.insert(index, x);
        } else {
            w.replace(index, x);
        }
    }
}
void Audio::removeWAmp(int index) {
    if (index < w.size())
        w.remove(index);
}

void Audio::pushAmpVal(double x, double y) {
    this->setVAmp(x);
    this->setWAmp(y);
}

void Audio::removeAmpVal(const int index){
    removeWAmp(index);
    removeVAmp(index);
}

int Audio::waveLenght() const {
    return w.size();
}

void Audio::setAmpVal(const int index, const double wval, const double vval) {
    setWAmp(wval,index);
    setVAmp(vval,index);
    //TODO: eccezione da aggiungere
}

double Audio::getAmpVal(const int index, int ondaRichiesta) const{
    if(ondaRichiesta==Audio::ondeDisponibili::ondaSx) {
        return getVAmp(index);
    }else{
        return getWAmp(index);
    }
}

QPair<double,double> Audio::getBothAmpVal(const int index) {
    QPair<double, double> values;
    values.first = getVAmp(index);
    values.second = getWAmp(index);
    return values;
}

QString Audio::getString() {

}
