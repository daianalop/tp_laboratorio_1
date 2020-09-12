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
float sumar(float num1, float num2);

/**
 * @brief  resta dos numeros ingresados por el usuario
 * @param num1 es el primer numero ingresado
 * @param num2 es el segundo numero ingresado
 * @return me retorna el resultado de la resta de ambos numeros ingresados
 */
float restar(float num1, float num2);

/**
 * @brief multiplica dos numeros ingresados por el usuario
 * @param num1 es el primero numero ingresado
 * @param num2 es el segundo resultado ingresado
 * @return me retorna el resultado de la multiplicacion entre ambos numeros
 */
float multiplicar(float num1, float num2);

/**
 * @brief divide dos numeros ingresados por el usuario
 * @param num1 es el primer numero ingresado
 * @param num2 es el segundo numero ingresado
 * @return me retorna el resultado de la division entre ambos numeros
 */
float dividir(float num1, float num2);

/**
 * @brief agarra un numero entero positivo y lo multiplica por todos los numeros que lo separan del 1
 * @param num1 es el numero que se ingresa para sacar su factorial
 * @return me retorna el resultado del factorial
 */
unsigned long int factorial(float num1);

/**
 * @brief Lo hice para validar si es un numero natural para que se pueda calcular el factorial ya que solo admite numeros enteros
 * @param num1 es el numero ingresado
 * @return me retorna si es o no es un numero natural
 */
int validarNumeroNat(float num1);

#endif /* ECUACIONES_H_ */
