#include <iostream>
#include <iomanip>
using namespace std;
#include "debug.h"
#include "mmq.h"

int main()
{
	setprecision(16);
	cout << "Grau do polinomio de ajuste: ";
	int grau;
	cin >> grau;
	int numeroPontos;

	SPonto *tabela = PreencheTabela(&numeroPontos);
	double **coeficientes = PreencheMatrizCoeficientes(tabela, 5, grau); // Construir a matriz dos coeficientes
	double *independentes = PreencheVetorTermosIndependentes(tabela, 5, grau); // Montar o vetor dos termos independentes

	MostraMatrizCoeficientes(coeficientes, grau);
	MostraTermosIndependentes(independentes, grau);
	return 0;
}
