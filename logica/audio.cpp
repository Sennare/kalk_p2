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

void Audio::pushPoint(double x, double y, int index, bool insert) {
    setVAmp(x, index, insert);
    setWAmp(y, index, insert);
}

void Audio::removePoint(const int index){
    removeWAmp(index);
    removeVAmp(index);
}

int Audio::waveLenght() const {
    return w.size();
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

QString Audio::getString(int ondaRichiesta) {
    QVector<double> aux;
    if (ondaRichiesta == Audio::ondeDisponibili::ondaSx) {
        aux=v;
    } else {
        aux=w;
    }
    QString ret("("), comma;
    QVector<double>::const_iterator end=aux.end();
    for(QVector<double>::const_iterator now = aux.begin(); now != end; ++now){
        ret.append(comma);
        ret.append(QString::number(*now));
        comma=",";
    }
    ret.append(")");
    return ret;
}

QPair<QString, QString> Audio::getBothWaves(){
    QPair<QString, QString> waves;
    waves.first = getString(ondaSx);
    waves.second = getString(ondaDx);
    return waves;
}

Audio Audio::operator+ (const Audio& x) {
    Audio* aux = new Audio();
    int maxLenght = qMax(this->waveLenght(), x.waveLenght());

    for(int i=0; i<maxLenght; ++i) {
         aux->pushPoint(this->getAmpVal(i) + x.getAmpVal(i),
                         this->getAmpVal(i, Audio::ondeDisponibili::ondaDx) + x.getAmpVal(i, Audio::ondeDisponibili::ondaDx));
    }
    return *aux;
}
Audio Audio::operator- (const Audio& x) {
    Audio* aux = new Audio();
    int maxLenght = qMax(this->waveLenght(), x.waveLenght());

    for(int i=0; i<maxLenght; ++i) {
         aux->pushPoint(this->getAmpVal(i) - x.getAmpVal(i),
                         this->getAmpVal(i, Audio::ondeDisponibili::ondaDx) - x.getAmpVal(i, Audio::ondeDisponibili::ondaDx));
    }
    return *aux;
}
Audio Audio::operator/ (const Audio& x) {
    Audio* aux = new Audio();
    int maxLenght = qMax(this->waveLenght(), x.waveLenght());

    for(int i=0; i<maxLenght; ++i) {
         aux->pushPoint(this->getAmpVal(i) / x.getAmpVal(i),
                         this->getAmpVal(i, Audio::ondeDisponibili::ondaDx) / x.getAmpVal(i, Audio::ondeDisponibili::ondaDx));
    }
    return *aux;
}
Audio Audio::operator* (const Audio& x) {
    Audio* aux = new Audio();
    int maxLenght = qMax(this->waveLenght(), x.waveLenght());

    for(int i=0; i<maxLenght; ++i) {
         aux->pushPoint(this->getAmpVal(i) * x.getAmpVal(i),
                         this->getAmpVal(i, Audio::ondeDisponibili::ondaDx) * x.getAmpVal(i, Audio::ondeDisponibili::ondaDx));
    }
    return *aux;
}
