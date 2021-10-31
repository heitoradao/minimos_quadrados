#include <iostream>
#include <iomanip>
using namespace std;
#include "debug.h"
#include "mmq.h"

int main()
{
	setprecision(16);
	cout << "Bom dia professor Torres.\n";
	cout << "Informe o grau do polinomio de ajuste: ";
	int grau;
	cin >> grau;


	int numeroPontos;


	// Preenche a tabela
#ifndef H8OR_DEBUG
	cout << "Informe o numero de pontos: ";
	cin >> numeroPontos;
	// informar a tabela dos pontos
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
#else
	numeroPontos = 5;
	SPonto *tabela = new SPonto[5];
	PreencheTabelaPontos(tabela);
	for (int i = 0; i < numeroPontos; i++)
	{
		cout << "(" << tabela[i].x << ", " << tabela[i].y << ")\n";
	}
	cout << endl;
#endif


	// Montar a matriz dos coeficientes
	double **coeficientes = new double*[grau + 1];
	for (int i = 0; i <= grau; i++)
		coeficientes[i] = new double[grau + 1];


	// Preenche a matriz dos coeficientes
	for (int linha = 0; linha <= grau; linha++)
		for (int coluna = 0; coluna <= grau; coluna++)
		{
			double somatoria = 0;
			for (int i = 0; i < numeroPontos; i++)
				somatoria += gi(tabela[i].x, linha) * gi(tabela[i].x, coluna);
			coeficientes[linha][coluna] = somatoria;
		}

#ifdef H8OR_DEBUG
	MostraMatrizCoeficientes(coeficientes);
#endif


	// Montar o vetor dos termos independentes
	double *independentes = new double [grau];
	for (int linha = 0; linha < grau+1; linha++)
	{
		double somatoria = 0;
		for (int i = 0; i < numeroPontos; i++)
			somatoria += (gi(tabela[i].x, linha) * tabela[i].y);
		independentes[linha] = somatoria;
	}

#ifdef H8OR_DEBUG
	MostraTermosIndependentes(independentes);
#endif

}
