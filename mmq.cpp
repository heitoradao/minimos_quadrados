#include "mmq.h"

double gi(double x, int i)
{
	double resultado = 1;
	for (int j = 0; j < i; j++)
		resultado *= x;
	return resultado;
}

double**PreencheMatrizCoeficientes(SPonto *tabelaPontos, int numeroPontos, int grauPolinomio)
{
	// Aloca memória para a matriz.
	double **matriz = new double*[grauPolinomio + 1];
	for (int linha = 0; linha <= grauPolinomio; linha++)
	{
		matriz[linha] = new double[grauPolinomio + 1];
		for (int coluna = 0; coluna <= grauPolinomio; coluna++)
		{
			matriz[linha][coluna] = 0;
			for (int i = 0; i < numeroPontos; i++)
				matriz[linha][coluna] += gi(tabelaPontos[i].x, linha) * gi(tabelaPontos[i].x, coluna);
		}
	}
}
