#include "wave.h"

Wave::Wave(){}

Wave::Wave(QString x) {
    QStringList aux = x.split(",");
    for(int i=0; i < aux.size(); ++i) {
        this->pushAmpVal(aux[i].toDouble());
    }
}

double Wave::getVAmp(int i) {
    return v[i];
}

void Wave::setVAmp(double x, int i, bool insert){
    if (i<0) {
        v.push_back(x);
    }
    else{
        if(insert) {
            v.insert(i, x);
        }
        else{
            v.replace(i, x);
        }
    }
}

void Wave::pushAmpVal(double x) {
    v.push_back(x);
}

void Wave::removeAmpVal(const int x){
    //TODO: eccezione da aggiungere
    if(x<v.size()) v.remove(x);
}

unsigned int Wave::waveLenght() const{
    return v.size();
}

void Wave::setAmpVal(const int x, const double y){
    if (x<v.size()){
        v.replace(x, y);
    }
    //TODO: eccezione da aggiungere
}

double Wave::getAmpVal(const int x) const{
    if(x<v.size())
        return v.at(x);
    else return 0;
}

QString Wave::getString() {
    QString ret("("), comma;
    QVector<double>::const_iterator end=v.end();
    for(QVector<double>::const_iterator now = v.begin(); now != end; ++now){
        ret.append(comma);
        ret.append(QString::number(*now));
        comma=",";
    }
    ret.append(")");
    return ret;
}
Wave Wave::operator+ (const Wave& x) {
   Wave* aux = new Wave();
   int maxLenght = qMax(this->waveLenght(), x.waveLenght());
   int i=0;
   for( ; i<maxLenght; ++i) {
        aux->pushAmpVal(this->getAmpVal(i) + x.getAmpVal(i));
   }
   return *aux;
}

Wave Wave::operator- (const Wave& x) {
   Wave* aux = new Wave();
   int maxLenght = qMax(this->waveLenght(), x.waveLenght());

   for(int i=0; i<maxLenght; ++i) {
       aux->pushAmpVal(this->getAmpVal(i) - x.getAmpVal(i));
   }
   return *aux;
}

Wave Wave::operator/ (const Wave& x) {
   Wave* aux = new Wave();
   int maxLenght = qMax(this->waveLenght(), x.waveLenght());

   for(int i=0; i<maxLenght; ++i) {
        aux->pushAmpVal(this->getAmpVal(i) / x.getAmpVal(i));
   }
   // TODO: eccezzione div x 0
   return *aux;
}

Wave Wave::operator* (const Wave& x) {
   Wave* aux = new Wave();
   int maxLenght = qMax(this->waveLenght(), x.waveLenght());

   for(int i=0; i<maxLenght; ++i) {
       aux->pushAmpVal(this->getAmpVal(i) * x.getAmpVal(i));
   }
    return *aux;
}
