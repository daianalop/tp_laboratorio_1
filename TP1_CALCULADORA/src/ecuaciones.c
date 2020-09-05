/*
 * ecuaciones.c
 *
 *  Created on: 5 sep. 2020
 *      Author: Daiana
 */

#include <stdio.h>
#include <stdlib.h>
#include "ecuaciones.h"

int sumar(int num1, int num2)
{
	int resultado;
	resultado = num1 + num2;

	return resultado;
}

int restar(int num1, int num2)
{
	int resultado;
	resultado = num1 - num2;

	return resultado;
}

int multiplicar(int num1, int num2)
{
	int resultado;
	resultado = num1 * num2;

	return resultado;
}

float dividir(int num1, int num2)
{
	float resultado;
	if(num2 != 0)
	{
		resultado = (float) num1/num2;
	}


	return resultado;
}

long int factorial(int num1)
{
	long int resultado;

	resultado = -1;

	if(num1 == 1 || num1 == 0)
	{
		resultado = 1;
	}
	else if(num1>1)
	{
		resultado = num1 * factorial((num1 - 1));
	}

	return resultado;
}

