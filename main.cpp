#include <iostream>
using namespace std;
#include "mmq.h"

int main()
{
	cout << "Bom dia professor Torres.\n";
	cout << "Informe o grau do polinomio de ajuste: ";
	int grau;
	cin >> grau;
	// informe as funções de ajuste
	ptrfuncao *funcaoAjuste = new ptrfuncao[grau];
	// preenche esse vetor
	funcaoAjuste[0] = g0;
	funcaoAjuste[1] = g1;
	funcaoAjuste[2] = g2;
	funcaoAjuste[3] = g3;
	funcaoAjuste[4] = g4;
	funcaoAjuste[5] = g5;

	// informar a tabela dos pontos
	cout << "Informe o numero de pontos: ";
	int numeroPontos;
	cin >> numeroPontos;
	SPonto *tabela = new SPonto[numeroPontos];
	for (int i = 0; i < numeroPontos; i++)
	{
		cout << "X[" << i << "] = ";
		double valor;
		cin >> valor;
		tabela[i].x = valor;
		cout << "Y[" << i << "] = ";
		cin >> valor;
		tabela[i].y = valor;
	}



	// Montar a matriz dos coeficientes
	double **coeficientes = new double*[grau];
	for (int i = 0; i < grau; i++)
		coeficientes[i] = new double[grau];



	for (int linha = 0; linha < grau; linha++)
		for (int coluna = 0; coluna < grau; coluna++)
		{
			double somatoria = 0;
			for (int i = 0; i < grau; i++)
				somatoria += gi(tabela[i].x, i) * gi(tabela[i].x, i);
			coeficientes[linha][coluna] = somatoria;
		}



	// Montar o vetor dos termos independentes
	double *independentes = new double [grau];
	for (int linha = 0; linha < grau; linha++)
	{
		double somatoria = 0;
		for (int i = 0; i < numeroPontos; i++)
			somatoria += (gi(tabela[i].x, linha) * tabela[i].y);
		independentes[linha] = somatoria;
	}
}
