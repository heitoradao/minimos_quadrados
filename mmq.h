#ifndef MMQ_H
#define MMQ_H

#include <iostream>
using std::cout;
using std::cin;

struct SPonto
{
    double x;
    double y;
};

typedef double(*ptrfuncao)(double);

double gi(double x, int i);

SPonto *PreencheTabela(int *numeroPontos);
double **PreencheMatrizCoeficientes(SPonto *tabelaPontos, int numeroPontos, int grauPolinomio);
double *PreencheVetorTermosIndependentes(SPonto *tabelaPontos, int numeroPontos, int grauPolinomio);

#endif // MMQ_H
