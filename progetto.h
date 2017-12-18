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
    void slotButtonClicked();
};

#endif // PROGETTO_H
