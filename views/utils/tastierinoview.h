#ifndef TASTIERINOVIEW_H
#define TASTIERINOVIEW_H

#include <QWidget>

namespace Ui {
class tastierinoView;
}

class tastierinoView : public QWidget
{
    Q_OBJECT

public:
    explicit tastierinoView(QWidget *parent = 0);
    ~tastierinoView();

private:
    Ui::tastierinoView *ui;

private slots:
    void slotKeyPressed();
};

#endif // TASTIERINOVIEW_H
