#ifndef WAVE_H
#define WAVE_H

#include <QVector>
#include <QString>

class Wave
{
protected:
    QVector<double> v;

public:
    Wave();
    virtual ~Wave() = default;

    virtual void pushAmpVal(const double);
    virtual void removeAmpVal(const unsigned int);
    virtual unsigned int waveLenght() const;

    virtual void setAmpVal(const unsigned int, const double);
    virtual double getAmpVal(const unsigned int) const;

    virtual QString getString() ;

    Wave operator+(const Wave&);
    Wave operator-(const Wave&);
    Wave operator/(const Wave&);
    Wave operator*(const Wave&);
};

#endif // WAVE_H
