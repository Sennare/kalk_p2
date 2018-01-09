#ifndef KALKSELECTORVIEW_H
#define KALKSELECTORVIEW_H

#include <QMainWindow>
#include <QMdiArea>

// to remove
#include <QWidget>

namespace Ui {
class KalkSelectorView;
}

class KalkSelectorView : public QMainWindow
{
    Q_OBJECT
private:
    Ui::KalkSelectorView *ui;
    QMdiArea* mdi;
public:
    KalkSelectorView();
    ~KalkSelectorView();

    void startApp();
};

#endif // KALKSELECTORVIEW_H
