#ifndef KALKSELECTORVIEW_H
#define KALKSELECTORVIEW_H

#include <QMainWindow>

namespace Ui {
class KalkSelectorView;
}

class KalkSelectorView : public QMainWindow
{
    Q_OBJECT

public:
    explicit KalkSelectorView(QWidget *parent = 0);
    ~KalkSelectorView();

private:
    Ui::KalkSelectorView *ui;
};

#endif // KALKSELECTORVIEW_H
