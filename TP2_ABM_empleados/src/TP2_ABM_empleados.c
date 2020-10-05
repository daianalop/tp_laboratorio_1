/*
 ============================================================================
 Name        : TP2_ABM_empleados.c
 Author      : Daiana Andrea Lopez
 Version     : 1
 Division    : 1G
 Copyright   : Your copyright notice
 Description : ABM para una empresa con una nomina de 1000 empleados
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

#define LEN 1000


int main(void)
{
	char confirm = 's';
	eEmployee list[LEN];
	eEmployee newEmployee;
	int id;
	int nextID = 3000;
	char validarRespuesta = 'n';
	int opcionInformar;
	int flagFirstEntrance = 0;


	if(initEmployees(list, LEN)== 0)
	{
		printf("Lista inicializada con exito\n");
	}
	else
	{
		printf("Problemas al inicializar personas\n");
	}


	do
	{

	switch(menu()){
			case 'a': // Alta
				system("cls");
				printf("()()()()() Ingreso de Empleados ()()()()()\n");
				printf("Ingrese el Nombre del Empleado: ");
				fflush(stdin);
				gets(newEmployee.name);

				printf("Ingrese el Apellido del Empleado: ");
				fflush(stdin);
				gets(newEmployee.lastName);

				printf("Ingrese Salario del Empleado: ");
				scanf("%f", &newEmployee.salary);

				menuSector();
				printf("Ingrese el Sector del Empleado: ");
				scanf("%d", &newEmployee.sector);

				if(addEmployee(list, LEN, nextID, newEmployee.name, newEmployee.lastName, newEmployee.salary, newEmployee.sector) == 0)
				{
					nextID++;
					printf("Alta Realizada Con exito!\n\n");
					printEmployees(list, LEN);
					flagFirstEntrance = 1;
				}
				else
				{
					printf("Error al Realizar el Alta.\n");
				}
				break;
			case 'm': // Modificacion
				if(flagFirstEntrance)
				{
					modifyEmployeeInformation(list, LEN);
					printf("\n");
					printEmployees(list, LEN);
				}
				else
				{
					printf("Debe ingresar uno o mas empleados para acceder a esta opcion\n");
				}
				break;
			case 'b': // Baja
				system("cls");
				if(flagFirstEntrance)
				{
					printEmployees(list, LEN);
					system("cls");
					printf("***Baja de persona***\n\n");
					printEmployees(list, LEN);
					printf("Ingrese el legajo: ");
					scanf("%d", &id);
					removeEmployee(list, LEN, id);
					printEmployees(list, LEN);
					printf("Felicitaciones! Ha despedido a una persona, envie su curriculum a 10 empresas o la suya quebrara en un mes.\n");
				}
				else
				{
					printf("Debe ingresar uno o mas empleados para acceder a esta opcion\n");
				}
				break;
			case 'i': // Sort
				system("cls");
				if(flagFirstEntrance)
				{
					printf("()()()()() Menu de opciones ()()()()()\n");
					printf("Que queres ver?\n"
							"1) Ordenamiento  de la lista[Apellido - Sector]\n"
							"2) Salarios totales y promedios, y cuantos empleados superan el salario promedio\n");
					scanf("%d", &opcionInformar);
					if(opcionInformar == 1)
					{
						sortEmployees(list, LEN, opcionInformar);
					}
					else if(opcionInformar == 2)
					{
						totalAndAverageSalary(list, LEN);
					}
				}
				else
				{
					printf("Debe ingresar uno o mas empleados para acceder a esta opcion\n");
				}
				break;

			case 'c': // Get Out
				printf("Esta seguro que desea salir (s/n)?");
				fflush(stdin);
				scanf("%c",&validarRespuesta);
				if(validarRespuesta != 'n')
				{
					confirm = 'n';
				}
				else
				{
					flagFirstEntrance = 0;
				}
				break;
			default: // Error
				printf("Esa opcion no existe ni aca ni en China\n");
				break;

			}
			system("pause");
			system("cls");

	}while(confirm == 's');


	return EXIT_SUCCESS;
}
