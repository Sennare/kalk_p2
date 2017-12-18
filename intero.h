#ifndef INTERO_H
#define INTERO_H

class Intero
{
private:
	int val;

public:
	Intero(int intVal = 0);
	~Intero();

	int getVal();
    Intero operator+(const Intero&);
};

#endif // INTERO_H
