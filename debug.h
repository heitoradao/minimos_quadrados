#ifndef H8OR_DEBUG
#define H8OR_DEBUG 1

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "mmq.h"

#define NUMERO_PONTOS 5
#define GRAU 1

void debug_PreencheTabelaPontos(SPonto *tabela)
{
    tabela[0].x = 0;
    tabela[0].y = 0;
    tabela[1].x = 1;
    tabela[1].y = 1;
    tabela[2].x = 2;
    tabela[2].y = 1;
    tabela[3].x = 3;
    tabela[3].y = 4;
    tabela[4].x = 4;
    tabela[4].y = 4;
}

void MostraMatrizCoeficientes(double **coeficientes, int grauPolinomio)
{
    for (int linha = 0; linha <= grauPolinomio; linha++) {
        for (int coluna = 0; coluna <= grauPolinomio; coluna++) {
            cout << coeficientes[linha][coluna] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void MostraTermosIndependentes(double *independentes, int grauPolinomio)
{
    for (int linha = 0; linha <= grauPolinomio; linha++) {
        cout << independentes[linha] << endl;
    }
    cout << endl;
}

#endif // H8OR_DEBUG
