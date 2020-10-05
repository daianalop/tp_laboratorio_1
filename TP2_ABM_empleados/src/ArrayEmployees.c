/*
 * ArrayEmployees.c
 *
 *  Created on: 4 oct. 2020
 *      Author: Daiana
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayEmployees.h"



char menu(){

	system("color 0C");
	char opcion;

	printf("()()()()()Menu()()()()()\n");
	printf("[A] Dar de Alta Empleado.\n");
	printf("[M] Modificar Informacion de un Empleado.\n");
	printf("[B] Dar de Baja a un Empleado.\n");
	printf("[I] Informes.\n");
	printf("[C] Cerrar programa.\n");
	printf("Escoja una opcion para operar: \n");
	fflush(stdin);
	scanf("%c", &opcion);
	opcion = tolower(opcion);

	return opcion;
}

void menuSector(){
	printf("[1] Sistemas.\n"
		   "[2] Administracion.\n"
		   "[3] RRHH.\n"
		   "[4] Finanzas.\n"
		   "[5] Limpieza.\n"
		   "[6] Seguridad.\n");
}



int initEmployees(eEmployee list[], int len)
{
	int error = -1;

		if(list != NULL && len > 0)
		{
			for(int i = 0; i < len; i++ )
			{
				list[i].isEmpty = 1;
			}

			error = 0;
		}

 return error;
}

void showEmployee(eEmployee employee){
   printf("\n    %d    %10s   %10s   %.2f       %d\n", employee.id, employee.name, employee.lastName, employee.salary, employee.sector);
}

int printEmployees(eEmployee list[], int len){

	int flag = 0;
	int error = 1;


	if(list != NULL && len > 0)
	{
		printf("\n()()()()()()()()()()() Lista de Empleados ()()()()()()()()()()() \n");
		printf("     Id        Nombre        Apellido     Salario    Sector\n");


		for (int i = 0;i<len;i++)
		{
			if (list[i].isEmpty==0)
			{
				showEmployee(list[i]);
				flag = 1;
			}

		}

		if(flag == 0)
		{
			printf("No hay personas en la lista para mostrar aun\n");
		}
	}

	return error;
}

int findFreePlace(eEmployee list[], int len )
{

	int indice = -1;

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int findEmployeeById(eEmployee list[], int len, int id)
{
	int retorno = -1;

	for(int i = 0; i < len; i++)
	{
		if(list[i].id == id && list[i].isEmpty == 0)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}

int addEmployee(eEmployee list[], int len, int id,  char name[],char lastName[],float salary,int sector)
{
	int isUploaded = -1;
	int indice;
	eEmployee newEmployee;

		if(list != NULL && len > 0 && id > 0)
		{
			indice = findFreePlace(list, len);

			if(indice == -1)
			{
				printf("El sistema esta completo y no se puede agregar a mas empleados\n");
			}
			else
			{
							newEmployee.id = id;
							newEmployee.isEmpty = 0;

							strcpy(newEmployee.name, name);
							strcpy(newEmployee.lastName, lastName);
							newEmployee.salary = salary;
							newEmployee.sector = sector;
							list[indice] = newEmployee;

							isUploaded = 0;


			}
		}

		return isUploaded;

}

int modifyEmployeeInformation(eEmployee vec[], int len)
{
	int id;
	int indice;
	int modifyOption;
	char confirm;
	char confirmModify;
	eEmployee auxEmployeeChange;

	system("cls");
	printf("\n****Modificar Informacion de Empleado****\n");
	printEmployees(vec, len);


	printf("\nPor favor ingrese el ID del empleado que desea modificar\n");
	scanf("%d", &id);

	indice = findEmployeeById(vec, len, id);

	if(indice == -1)
	{
		printf("No existe un empleado con el ID: %d\n", id);

	}
	else
	{
		printf("El empleado con el ID  %d es : \n", id);
		printf("     ID        Nombre        Apellido     Salario     Sector\n");
		printf("\n_-_-_-_-_-_-_-_-_-__-_-_-_-_-_-_-_-_-__-_-_-_-_-_-_-_-_-__-_-_-_-_");
		showEmployee(vec[indice]);
		printf("\n_-_-_-_-_-_-_-_-_-__-_-_-_-_-_-_-_-_-__-_-_-_-_-_-_-_-_-__-_-_-_-_");
		printf("\n Que información desea modificar del empleado?\n");
		printf("1- Nombre\n"
				"2- Apellido\n"
				"3- Salario\n"
				"4- Sector\n"
				"5- Volver al Menu\n");
		scanf("%d", &modifyOption);

		do{
			switch(modifyOption)
			{
			case 1:
				printf("Modificar nombre?(s/n): ");
				fflush(stdin);
				scanf("%c", &confirmModify);
				if(confirmModify == 's')
				{
					printf("Ingrese nuevo nombre: ");
					fflush(stdin);
					gets(auxEmployeeChange.name);
					strcpy(vec[indice].name,auxEmployeeChange.name);
					printf("\nNombre modificado con exito.\n");
				}
				else
				{
					printf("\n Modificacion Cancelada.\n");
					confirm = 'n';
				}
				break;
			case 2:
				printf("Modificar Apellido? (s/n): ");
				fflush(stdin);
				scanf("%c", &confirmModify);
				if(confirmModify == 's')
				{
					printf("Ingrese nuevo apellido: ");
					fflush(stdin);
					gets(auxEmployeeChange.lastName);
					strcpy(vec[indice].lastName, auxEmployeeChange.lastName);
					printf("\nApellido modificado con exito.\n");
				}
				else
				{
					printf("\nModificacion Cancelada\n");
					confirm = 'n';
				}
				break;
			case 3:
				printf("Modificar Salario? (s/n): ");
				fflush(stdin);
				scanf("%c", &confirmModify);
				if(confirmModify == 's')
				{
					printf("\n Ingrese nuevo salario: ");
					scanf("%f", &auxEmployeeChange.salary);
					vec[indice].salary = auxEmployeeChange.salary;
					printf("\n Salario modificado con exito\n");

				}
				else
				{
					printf("\nModificacion cancelada.\n");
					confirm = 'n';
				}
				break;
			case 4:
				printf("Modificar Sector? (s/n): ");
				fflush(stdin);
				scanf("%c", &confirmModify);
				if(confirmModify == 's')
				{
					menuSector();
					printf("\nIngrese nuevo sector: ");
					scanf("%d", &auxEmployeeChange.sector);
					vec[indice].sector = auxEmployeeChange.sector;
					printf("\nSector modificado con exito.\n");
				}
				else
				{
					printf("\nModificacion Cancelada");
					confirm = 'n';
				}
				break;
			default:
				confirm = 'n';
				break;
			}
			system("pause");

		}while(confirm == 's');

	}

	return indice;
}

int removeEmployee(eEmployee *list, int len, int id)
{

	int error = 1;
	//eEmployee idEmployee;
	int indice;
	char confirmRemove;

	if(list != NULL && len > 0)
	{



		indice = findEmployeeById(list, len, id);

		if(indice == -1)
		{
			printf("\nNo existe una persona con ese legajo\n");
			system("pause");
		}
		else
		{
			showEmployee(list[indice]);
			printf("Confirma borrado?: ");
			fflush(stdin);
			scanf("%c", &confirmRemove);

			if(confirmRemove == 's')
			{
				list[indice].isEmpty = 1;
				error = 0;
			}
			else
			{
				error = 2;
			}
		}
	}

	return error;
}

int sortEmployees(eEmployee list[], int len, int order)
{
	eEmployee employee;
	int sort_order = order;
	int noError = -1;

	 if(sort_order == 0)
	 {
		 for(int i=0; i<len-1; i++)//Descendente
		 {
			 for(int j=i+1; j<len; j++){
				 if(strcmp(list[j].lastName,list[i].lastName)<0)
				 {
					 employee = list[i];
					 list[i] = list[j];
					 list[j] = employee;
				 }
				else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[i].sector>list[j].sector)
				{
					employee = list[i];
					list[i] = list[j];
					list[j] = employee;
				}
			}
		}
		noError = 1;
	 }

	printEmployees(list,len);

 return noError;
}

void totalAndAverageSalary(eEmployee list[], int len)
{
	float totalSalary = 0;
	int totalEmployee = 0;
	float averageSalary = 0;
	float biggerSalary = 0;
	//int cantidadSueldos = 0;

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == 0)
		{
			totalSalary += list[i].salary;
			totalEmployee++;
			//cantidadSueldos++;
		}
	}

	if(totalEmployee != 0)
	{
		averageSalary = (float) totalSalary/totalEmployee;

		for(int i = 0; i < len; i++)
		{
			if (list[i].salary > averageSalary && list[i].isEmpty == 0)
			{
				biggerSalary++;
			}
		}
	}


	//printf("cantidad empleados: %d\n", totalEmployee);
	//printf("cantidad sueldos sumados: %d\n", cantidadSueldos);
	printf("\nEl salario total de la nomina es de $ %.2f\n",totalSalary);
	printf("El promedio total de salario es $ %.2f\n",averageSalary);
	printf("La cantidad de empleados con sueldo que pasan el promedio son: %.2f\n", biggerSalary);


}














