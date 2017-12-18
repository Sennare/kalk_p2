#ifndef INTERO_H
#define INTERO_H

class Intero
{
private:
	int val;

public:
	Intero(int intVal = 0);
	~Intero();

    Intero operator+(const Intero&);
    Intero operator-(const Intero&);
    Intero operator*(const Intero&);
    Intero operator/(const Intero&);
};

#endif // INTERO_H
