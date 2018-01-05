#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QApplication>

class Application : public QObject
{
    Q_OBJECT
private:
    static Application* istanza;
    QApplication qAppl;
public:
    explicit Application(int* argc, char** argv[]);
    ~Application();

    static Application* getIstanza();
    void initialize();
    int exec();
signals:

public slots:
};

#endif // APPLICATION_H
