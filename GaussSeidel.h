#ifndef H8OR_GAUSS_SEIDEL
#define H8OR_GAUSS_SEIDEL

#include <iostream>
#include <iomanip>
using namespace std;
#include <math.h>

bool CriterioSassenfeld(double **&matriz, const int &ordem);
int CriterioZeros(double **&coeficientes, const int ordem, double *&independentes);
double Max(const double *vetor, const int &ordem);
double Erro(double *incognitas, double *incognitasAnterior, const int &ordem);
inline void CopiaVetor(double *vetor1, double *vetor2, const int &ordem);
int GaussSeidel(double **coeficientes, int ordem, double *incognitas, double *independente, const int numIteracoesMaximas, const double erroPermitido);
void MostraIncognitas(double *vetorIncognitas, const int &ordem);
inline void PreencheVetorCoeficientes(double **&coeficientes, const int &ordem);
inline int DimensionaSistemaLinear();
inline void PreencheIndependentes(double *&vetorIndependente, const int &ordem);
inline void InicializaZeros(double *&vetor, const int &tamanho);

#endif // H8OR_GAUSS_SEIDEL
