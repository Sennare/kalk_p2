#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QApplication>
#include "views/view.h"


class Application : public QObject
{
    Q_OBJECT
private:
    static Application* istanza;
    QApplication qAppl;
    View* currentView;
public:
    explicit Application(int* argc, char** argv[]);
    ~Application();

    enum KalkType {
        Complessi,
        Quaternioni,
        OndeAudio,
        OndeColorate
    };

    static Application* getIstanza();
    void initialize();
    void initializeKalk(View*);
    void destroyView();
    void exitKalk();
    int exec();
signals:

public slots:
    void slotOpenKalkType(int);
    void slotBack();
};

#endif // APPLICATION_H
