#ifndef MMQ_H
#define MMQ_H

struct SPonto
{
	double x;
	double y;
};

typedef double(*ptrfuncao)(double);

double g0(double x);
double g1(double x);
double g2(double x);
double g3(double x);
double g4(double x);
double g5(double x);
double gi(double x, int i);

#endif // MMQ_H
