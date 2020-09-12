/*
 * ecuaciones.c
 *
 *  Created on: 5 sep. 2020
 *      Author: Daiana
 */

#include <stdio.h>
#include <stdlib.h>
#include "ecuaciones.h"

float sumar(float num1, float num2)
{
	float resultado;
	resultado = num1 + num2;

	return resultado;
}

float restar(float num1, float num2)
{
	float resultado;
	resultado = num1 - num2;

	return resultado;
}

float multiplicar(float num1, float num2)
{
	float resultado;
	resultado = num1 * num2;

	return resultado;
}

float dividir(float num1, float num2)
{
	float resultado;
	if(num2 != 0)
	{
		resultado = (float) num1/num2;
	}


	return resultado;
}

unsigned long int factorial(float num1)
{
	unsigned long int resultado;

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

int validarNumeroNat(float num1)
{
	int entero;
	int valorDeRetorno;

	entero = (int) num1;
	valorDeRetorno = 1;
	if(entero - num1 || num1 < 0 )
	{
		valorDeRetorno = 0;
	}

	return valorDeRetorno;
}
