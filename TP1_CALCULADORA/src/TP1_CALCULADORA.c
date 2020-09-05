/*
 ============================================================================
 Name        : TP1_CALCULADORA.c
 Author      : Daiana Andrea Lopez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ecuaciones.h"

int menuPrincipal(int flag1, int flag2, int num1, int num2)
{
	int opcion;
	if(!flag1 && !flag2)
	{
		printf("    Menu Principal\n");
	   printf("    [1] Ingresar 1er operando (A=x)\n");
	   printf("    [2] Ingresar 2do operando (B=y)\n");
	   printf("    [3] Calcular todas las operaciones\n");
	   printf("		a) Calcular la suma (A+B)\n");
	   printf("		b) Calcular la resta (A-B)\n");
	   printf("		c) Calcular la division (A/B)\n");
	   printf("		d) Calcular la multiplicacion (A*B)\n");
	   printf("		e) Calcular el factorial (A!)\n");
	   printf("    [4] Informar resultados\n");
	   printf("    [5] Salir\n"
			  "    Opcion: ");

	}
	else if(flag1 && !flag2)
	{
		printf("    Menu Principal\n");
	   printf("    [1] Ingresar 1er operando (A=%d)\n", num1);
	   printf("    [2] Ingresar 2do operando (B=y)\n");
	   printf("    [3] Calcular todas las operaciones\n");
	   printf("		a) Calcular la suma (%d+B)\n", num1);
	   printf("		b) Calcular la resta (%d-B)\n", num1);
	   printf("		c) Calcular la division (%d/B)\n", num1);
	   printf("		d) Calcular la multiplicacion (%d*B)\n", num1);
	   printf("		e) Calcular el factorial (%d!)\n", num1);
	   printf("     f)Calcular el factorial B\n");
	   printf("    [4] Informar resultados\n");
	   printf("    [5] Salir\n"
			  "    Opcion: ");
	}
	else if (flag2)
	{
		printf("    Menu Principal\n");
	   printf("    [1] Ingresar 1er operando (A=%d)\n", num1);
	   printf("    [2] Ingresar 2do operando (B=%d)\n", num2);
	   printf("    [3] Calcular todas las operaciones\n");
	   printf("		a) Calcular la suma (%d+%d)\n", num1, num2);
	   printf("		b) Calcular la resta (%d-%d)\n", num1, num2);
	   printf("		c) Calcular la division (%d/%d)\n", num1, num2);
	   printf("		d) Calcular la multiplicacion (%d*%d)\n", num1, num2);
	   printf("		e) Calcular el factorial (%d!)\n", num1);
	   printf("     f)Calcular el factorial %d\n", num2);
	   printf("    [4] Informar resultados\n");
	   printf("    [5] Salir\n"
			  "    Opcion: ");
	}

	scanf("%d", &opcion);

	return opcion;
}

int cargaNumero()
{
	int numero;
	printf("    Ingrese numero: ");
	scanf("%d", &numero);

	return numero;
}

int main(void) {

	int numero1;
	int numero2;

	int resultadoSuma;
	int resultadoResta;
	int resultadoMulti;
	long int factorial1;
	long int factorial2;
	float resultadoDiv;
	char respuesta;
	char validarSalida;
	int flagPrimerNumero;
	int flagSegundoNumero;
	int flagResultados;

	respuesta = 's';
	validarSalida = 'n';

	flagPrimerNumero = 0;
	flagSegundoNumero = 0;
	flagResultados = 0;

	//Este es el menu principal de la calculadora
	do{
		switch(menuPrincipal(flagPrimerNumero, flagSegundoNumero, numero1, numero2))
		{
			case 1://primer ingreso
				numero1 = cargaNumero();
				flagPrimerNumero = 1;
				break;
			case 2://segundo ingreso
				if(flagPrimerNumero)
				{
					numero2 = cargaNumero();
					flagSegundoNumero = 1;
				}
				break;
			case 3://calcular los resultados
				if(flagPrimerNumero && flagSegundoNumero)
				{
				resultadoSuma = sumar(numero1, numero2);
				resultadoResta = restar(numero1, numero2);
				resultadoMulti = multiplicar(numero1, numero2);
				resultadoDiv = dividir(numero1, numero2);
				factorial1 = factorial(numero1);
				factorial2 =factorial(numero2);
				printf("Ya se realizaron las operaciones\n");
				flagResultados = 1;
				}
				else
				{
					printf("Te falta ingresar al menos un numero\n");
				}
				break;
			case 4://Mostrar resultados
				if(flagResultados)
				{
					printf("El resultado de A+B es: %d\n ", resultadoSuma);
					printf("El resultado de A-B es: %d\n", resultadoResta);
					if(numero2 != 0)
					{
						printf("El resultado de A/B es: %.2f\n ", resultadoDiv);
					}
					else
					{
						printf("No se puede dividir por cero");
					}
					printf("El resultado de A*B es: %d\n", resultadoMulti);
					if(numero1 >= 0)
					{
						printf("El factorial de A es: %li\n ", factorial1);
					}
					else
					{
						printf("No se puede calcular el factorial de un numero negativo\n");
					}

					if(numero2 >= 0)
					{
						printf("y El factorial de B es: %li\n", factorial2);
					}
					else
					{
						printf("No se puede calcular el factorial de un numero negativo\n");
					}
				}
				else
				{
					printf("No hay resultados validos que mostrar\n");
				}
				break;
			case 5:
				printf("Esta seguro que desea salir (s/n)?");
				fflush(stdin);
				scanf("%c",&validarSalida);
				if(validarSalida != 'n')
				{
					respuesta = 'n';
				}
				else
				{
					flagPrimerNumero = 0;
					flagSegundoNumero = 0;
					flagResultados = 0;
				}
				break;
			default:
				printf("    Opcion Incorrecta!\n");
				break;

		}
		system("pause");
		system("cls");
	}while(respuesta == 's');



	return EXIT_SUCCESS;
}
