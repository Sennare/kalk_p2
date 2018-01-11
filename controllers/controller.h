#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QWidget>

class Controller : public QObject
{
public:
    virtual ~Controller() = default;
    Controller() = default;
    Controller(const Controller&) = delete;
    Controller& operator=(const Controller&) = delete;

    virtual void handle() =0;
};

#endif // CONTROLLER_H
