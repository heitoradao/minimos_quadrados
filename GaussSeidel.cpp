#include "GaussSeidel.h"





/**
 * Essa fun��o analiza os crit�rios que estabelecem condi��es suficientes para a converg�ncia do sistema, usando o crit�rio de Sassenfeld.
 * \param[in] matriz Matriz dos coeficientes.
 * \param[in] ordem A ordem da matriz.
 * \retval bool Retorna true se o sistema convergir de certeza.
 */
bool CriterioSassenfeld(double **&matriz, const int &ordem)
{
	for (int linha = 0; linha < ordem; linha++)
	{
		double soma = 0;
		for (int coluna = 0; coluna < ordem; coluna++)
		{
			if (linha != coluna)
				soma += fabs(matriz[linha][coluna]);
		}
		if (soma / fabs(matriz[linha][linha]) >= 1)
			return false;
	}
	return true;
}



/*!
 * Esta fun��o procura se tem zeros na diagonal principal e troca as linhas se existir.
 * \param[out] coeficientes A matriz que cont�m os coeficientes.
 * param[in] ordem A ordem da Matriz.
 * \param[out] independentes O vetor dos termos independentes.
 * \retval int Retorna zero se n�o tiver nenhum zero na diagonal principal e -1 em caso contr�rio.
 */
int CriterioZeros(double **&coeficientes, const int ordem, double *&independentes)
{
	int outraLinha;
	for (int i = 0; i < ordem; i++)
	{
		if (!coeficientes[i][i]) // se for falso. Em C, 0 � falso e qualquer coisa diferente � verdadeiro.
		{
			cout << "\n\nEsta matriz tem zero na diagonal principal, bem na linha " << i << ".\n"
			"Digite o numero de outra linha pra substituir com esta:\n"
			"Mas digite um numero valido!\n"
			"Os indices vao de 0 a n-1.\n"
			"Agora digite o numero da outra linha: ";
			cin >> outraLinha;
			double *aux = coeficientes[i];
			coeficientes[i] = coeficientes[outraLinha];
			coeficientes[outraLinha] = aux;
			// pronto. j� trocou as linhas, agora vai trocar o vetor de termos independentes
			double aux2 = independentes[i];
			independentes[i] = independentes[outraLinha];
			independentes[outraLinha] = aux2;
			return -1;
		}
	}
	return 0;
}


/*!
 * Esta fun��o procura o maior valor de um vetor.
 */
double Max(const double *vetor, const int &ordem)
{
	double max = vetor[0];
	for (int i = 0; i < ordem; i++)
		if (max < vetor[i])
			max = vetor[i];
	return max;
}


/*!
 * Essa fun��o retorna a variancia das incognitas.
 * \param[in] incognitas o vetor das respostas.
 * \param[in] incognitasAnterior O vetor das respostas da itera��o anterior.
 * \param[in] ordem O tamanho do vetor.
 * \retval double Retorna a vari�ncia.
 */
double Erro(double *incognitas, double *incognitasAnterior, const int &ordem)
{
	double *diferencas = new double[ordem];
	for (int i = 0; i < ordem; i++)
		diferencas[i] = fabs(incognitas[i] - incognitasAnterior[i]);
	double resultado = Max(diferencas, ordem) / Max(incognitas, ordem);
	delete diferencas; // tem que liberar a mem�ria.
	return resultado;
}



/*!
 * Copia os elementos do vetor 1 no vetor 2.
 * \param[in] vetor1 O vetor fonte.
 * \param[out] vetor2 O vetor destino.
 * \param[in] ordem o tamanho dos vetores.
 */
inline void CopiaVetor(double *vetor1, double *vetor2, const int &ordem)
{
	for (int i = 0; i < ordem; i++)
		vetor2[i] = vetor1[i];
}



/*!
 * Essa fun��o modifica o vetor de incognitas, preenchendo com os valores aproximados da sua solu��o real.
 * \param[out] coeficientes A matriz dos coeficientes.
 * \param[in] ordem A ordem da matriz.
 * \param[out] incognitas O vetor que cont�m os resultados.
 * \param
 * \retval int Retorna o n�mero de itera��es efetuadas.
 */
int GaussSeidel(double **coeficientes, int ordem, double *incognitas, double *independente,
const int numIteracoesMaximas = 10, const double erroPermitido = 0.0001)
{
	int iteracao = 0;
	double *incognitasIteracaoAnterior = new double[ordem];

	//for(iteracao = 0; iteracao < numIteracoesMaximas && VerificaErro(incognitas, incognitasIteracaoAnterior, ordem, erroPermitido); iteracao++)
	do
	{
		CopiaVetor(incognitas, incognitasIteracaoAnterior, ordem);
    	for (int linha = 0; linha < ordem; linha++)
    	{
    		incognitas[linha] = independente[linha];
    		for (int coluna = 0; coluna < ordem; coluna++)
    			if (linha != coluna)
					incognitas[linha] -= (coeficientes[linha][coluna] * incognitas[coluna]);
    		incognitas[linha] /= coeficientes[linha][linha];
    	}
    	iteracao++;
	} while (iteracao < numIteracoesMaximas && Erro(incognitas, incognitasIteracaoAnterior, ordem) >= erroPermitido);
	delete incognitasIteracaoAnterior; // liberar mem�ria
	return iteracao;
}



/*!
 * Esta fun��o mostra na tela o conte�do do vetor das incognitas.
 * \param[out] vetorIncognitas Esse vetor armazena as incognitas, ou seja, os resultados finais.
 * \param[in] ordem O tamanho do vetor.
 */
void MostraIncognitas(double *vetorIncognitas, const int &ordem)
{
	for (int i = 0; i < ordem; i++)
		cout << "X("<<i<<") = " << vetorIncognitas[i] << endl;
}



/*!
 * Esta fun��o preenche a matriz dos coeficientes com dados fornecidos pelo usu�rio.
 * \param[out] coeficientes Essa � a matriz que armazena os coeficientes.
 * \param[in] ordem A ordem da matriz.
 */
inline void PreencheVetorCoeficientes(double **&coeficientes, const int &ordem)
{
	cout << "\n\nDigite os termos independentes.\nVoce pode digitar um por um ou digitar todos eles "
	"separados por espacos:\nex:\n"
	"coeficientes[0][0] = 1 2 33.5\n\n";
	for (int linha = 0; linha < ordem; linha++)
		for (int coluna = 0; coluna < ordem; coluna++)
		{
			cout << "coeficientes[" << linha << "][" << coluna << "] = ";
			cin >> coeficientes[linha][coluna];
		}
}



/*!
 * Esta fun��o define o tamanho das matrizes e dos vetores, de acordo com dados fornecidos pelo usu�rio.
 * \retval int Retorna o tamanho (ordem) da matriz dos coeficientes, que tamb�m ser� o tamanho dos vetores.
 */
inline int DimensionaSistemaLinear()
{
	cout << "Bom dia professor Torres.\nEntre com a ordem da matriz dos coeficientes: ";
	int num;
	cin >> num;
	return num;
}



/*!
 * Esta fun��o preenche o vetor dos termos independentes com dados fornecidos pelo usu�rio.
 * \param[out] vetorIndependente O vetor que cont�m os termos independentes, ou seja, as constantes.
 * \param[in] ordem O tamanho do vetor.
 */
inline void PreencheIndependentes(double *&vetorIndependente, const int &ordem)
{
	cout << "\n\nDigite agora os termos independentes.\n\n";
	for (int i = 0; i < ordem; i++)
	{
		cout << "independente[" << i << "] = ";
		cin >> vetorIndependente[i];
	}
}



/*!
 * Essa fun��o inicializa um vetor com zeros.
 * \param[out] vetor     O vetor que � pra ser inicializado.
 * \param[in]  tamanho   O tamanho do vetor.
 */
inline void InicializaZeros(double *&vetor, const int &tamanho)
{
	for (int i = 0; i < tamanho; i++)
		vetor[i] = 0;
}
