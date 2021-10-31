#include <iostream>
#include <iomanip>
using namespace std;
#include "debug.h"
#include "mmq.h"
#include "GaussSeidel.h"

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

	double *incognitas = new double[grau + 1];
	GaussSeidel(coeficientes, grau + 1, incognitas, independentes, 5000000, 0.000000000001);

	for (int i = 0; i <= grau; i++)
		cout << "i = " << incognitas[i] << endl;
	return 0;
}
