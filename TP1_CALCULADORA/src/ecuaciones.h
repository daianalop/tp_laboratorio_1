/*
 * ecuaciones.h
 *
 *  Created on: 5 sep. 2020
 *      Author: Daiana
 */

#ifndef ECUACIONES_H_
#define ECUACIONES_H_

/**
 * @brief suma dos numeros ingresados por el usuario
 * @param num1 es el primer numero ingresado
 * @param num2 es el segundo numero ingresado
 * @return me retorna el resultado de la suma de ambos numeros ingresados
 */
int sumar(int num1, int num2);

/**
 * @brief  resta dos numeros ingresados por el usuario
 * @param num1 es el primer numero ingresado
 * @param num2 es el segundo numero ingresado
 * @return me retorna el resultado de la resta de ambos numeros ingresados
 */
int restar(int num1, int num2);

/**
 * @brief multiplica dos numeros ingresados por el usuario
 * @param num1 es el primero numero ingresado
 * @param num2 es el segundo resultado ingresado
 * @return me retorna el resultado de la multiplicacion entre ambos numeros
 */
int multiplicar(int num1, int num2);

/**
 * @brief divide dos numeros ingresados por el usuario
 * @param num1 es el primer numero ingresado
 * @param num2 es el segundo numero ingresado
 * @return me retorna el resultado de la division entre ambos numeros
 */
float dividir(int num1, int num2);

/**
 * @brief agarra un numero entero positivo y lo multiplica por todos los numeros que lo separan del 1
 * @param num1 es el numero que se ingresa para sacar su factorial
 * @return me retorna el resultado del factorial
 */
long int factorial(int num1);

#endif /* ECUACIONES_H_ */
