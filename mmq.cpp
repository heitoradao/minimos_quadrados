#include "mmq.h"

double g0(double x)
{
	return 1;
}

double g1(double x)
{
	return x;
}

double g2(double x)
{
	return x * x;
}

double g3(double x)
{
	return x * x * x;
}

double g4(double x)
{
	return x * x * x;
}

double g5(double x)
{
	return x * x * x;
}

double gi(double x, int i)
{
	double resultado = 1;
	for (int j = 0; j < i; j++)
		resultado *= x;
}
