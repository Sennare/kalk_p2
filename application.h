#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QApplication>
#include "controllers/controller.h"


class Application : public QObject
{
    Q_OBJECT
private:
    static Application* istanza;
    QApplication qAppl;
    Controller* currentController;
    Controller* currentSubController;
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
    void initializeKalk(Controller*);
    void destroyController();
    void exitKalk();
    int exec();
signals:

public slots:
    void slotOpenKalkType(int);
    void slotBack();
};

#endif // APPLICATION_H
