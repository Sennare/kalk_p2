#ifndef TASTIERINOVIEW_H
#define TASTIERINOVIEW_H

#include <QWidget>
#include <QString>

namespace Ui {
class TastierinoView;
}

class TastierinoView : public QWidget
{
    Q_OBJECT

public:
    explicit TastierinoView(QWidget *parent = 0);
    ~TastierinoView();

private:
    Ui::TastierinoView *ui;

private slots:
    void slotKeyPressed();

signals:
    void signalKeyPressed(QString);
};

#endif // TASTIERINOVIEW_H
