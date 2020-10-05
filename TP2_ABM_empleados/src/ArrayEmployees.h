/*
 * ArrayEmployees.h
 *
 *  Created on: 4 oct. 2020
 *      Author: Daiana
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}eEmployee;

/**
 * @brief Muestra el menu de opciones
 * @return retorna la opcion elegida
 */
char menu();

/**
 * @brief menu para elegir los sectores
 */
void menuSector();


/**
 * @brief indica que todas las posiciones del array estan vacias para incializar la carga de datos
 * @param list va a la estructura y llama a lo que hay dentro
 * @param len largo del array
 * @return retorna -1 si hay algun error y 0 si esta todo bien
 */
int initEmployees(eEmployee list[], int len);

/**
 * @brief me muestra a acada uno de los empleados por separado con sus respectivos datos
 * @param employee va a la data del empleado
 */
void showEmployee(eEmployee employee);

/**
 * @brief Muestra a todos los empleados en una lista
 * @param list va a la estructura y llama a lo que hay dentro
 * @param len largo del array
 * @return
 */
int printEmployees(eEmployee list[], int len);

/**
 * @brief buesca algun indice libre
 * @param list va a la estructura y llama a lo que hay dentro
 * @param len largo del array
 * @return retorna el indice si es que lo encuentra sino me retorna -1 como error
 */
int findFreePlace(eEmployee list[], int len );

/**
 * @brief busca a un empleado por ID
 * @param list va a la estructura y llama a lo que hay dentro
 * @param len largo del array
 * @param id ID en  busqueda
 * @return me retorna el indice de la posicion en el array o me devuelve -1 si no hay empleado con el ID o hubo algun tipo de error
 */
int findEmployeeById(eEmployee list[], int len, int id);

/**
 * @brief cargar un empleado al sistema
 * @param list
 * @param len
 * @param id
 * @param name
 * @param lastName
 * @param salary
 * @param sector
 * @return retorna 0 si se subio bien y -1 si no se subio bien o mal
 */
int addEmployee(eEmployee list[], int len, int id,  char name[],char lastName[],float salary,int sector);


/**
 * @brief es para modificar la informacion del enpleado elegido
 * @param vec
 * @param len
 * @return me retorna el indice del dato del empleado a modifircar o modificado
 */
int modifyEmployeeInformation(eEmployee vec[], int len);

/**
 * @brief para dar de baja a un empleado por id
 * @param list
 * @param len
 * @param id
 * @return me retorna si hubo si el usuario quiso modificar o no
 */
int removeEmployee(eEmployee list[], int len, int id);

/**
 * @brief me ordena la lista por apellidos y sectores swapeando
 * @param list
 * @param len
 * @param order
 * @return me retorna si no hubo errores el el swapeo
 */
int sortEmployees(eEmployee list[], int len, int order);

/**
 * @brief me dice el total de sueldos en la nomina de empleados, el promedio y la cantidad de personas que superan el sueldo promedio
 * @param list
 * @param len
 */
void totalAndAverageSalary(eEmployee list[], int len);



#endif /* ARRAYEMPLOYEES_H_ */
