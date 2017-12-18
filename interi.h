#ifndef INTERO_H
#define INTERO_H

#include <QMainWindow>

class Intero
{
	Q_OBJECT

private:
	int val;

public:
	Intero(int intVal = 0);
	~Intero();

	int getVal();
	Intero operator+(const Intero& toAdd);
};

#endif // INTERO_H
