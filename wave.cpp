#include "wave.h"

Wave::Wave(){}

void Wave::pushAmpVal(const double x) {
    v.push_back(x);
}

void Wave::removeAmpVal(const unsigned int x){
    //TODO: eccezione da aggiungere
    if(x<=v.size()) v.remove(x);
}

unsigned int Wave::waveLenght() const{
    return v.size();
}

void Wave::setAmpVal(const unsigned int x, const double y){
    if (x<=v.size()){
        v.replace(x, y);
    }
    //TODO: eccezione da aggiungere
}

double Wave::getAmpVal(const unsigned int x) const{
    if(x<=v.size())
        return v.at(x);
}

QString Wave::getString() {
    QString ret("("), comma;
    QVector<double>::const_iterator end=v.end();
    for(QVector<double>::const_iterator now = v.begin(); now != end; ++now){
        ret.append(QString::number(*now));
        ret.append(comma);
        comma=",";
    }
    ret.append(")");
    return ret;
}
