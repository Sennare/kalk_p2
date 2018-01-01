#ifndef PROGETTO_H
#define PROGETTO_H

#include <QMainWindow>

namespace Ui {
class Progetto;
}

class Progetto : public QMainWindow
{
    Q_OBJECT

public:
    explicit Progetto(QWidget *parent = 0);
    ~Progetto();

private:
    Ui::Progetto *ui;

private slots:
    void slotRealSum();
    void slotRealSottr();
    void slotRealMult();
    void slotRealDiv();
    void slotComplexSum();
    void slotComplexSottr();
    void slotComplexPer();
    void slotComplexDiv();
    void slotQuaternionSum();
    void slotQuaternionSottr();
    void slotQuaternionPer();
    void slotQuaternionDiv();
};

#endif // PROGETTO_H
