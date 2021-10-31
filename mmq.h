#ifndef MMQ_H
#define MMQ_H

struct SPonto
{
	double x;
	double y;
};

typedef double(*ptrfuncao)(double);

double gi(double x, int i);

double**PreencheMatrizCoeficientes(SPonto *tabelaPontos, int numeroPontos, int grauPolinomio);

#endif // MMQ_H
