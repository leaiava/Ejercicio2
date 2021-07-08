/*
 * tecla.h
 *
 *  Created on: Jul 7, 2021
 *      Author: lea
 */

#ifndef _TECLA_H_
#define _TECLA_H_

/*=====[Prototypes (declarations) of public functions]=======================*/
/* Funcion leerTecla
 * Sirve para leer el estado de una tecla.
 * Recibe un puntero a la estructura controlSecuencia
 * Devuelve por valor el estado de la tecla pulsada (verdadero) o liberada (falso)*/
bool_t leerTecla (gpioMap_t tecla);

/* Funcion seteo_delay
 * Funcion para setear el delay y verificar si se cumplió el tiempo. Es un delay no bloqueante
 * TEC2 -> cada led queda encendido 150 ms.
 * TEC3 -> cada led queda encendido 750 ms.
 * Recibe un puntero a la variable tipo delay_t
 * Devuelve 1 si se cumplió el delay
 * Devuelve 0 en caso contrario */
//bool_t seteo_delay(delay_t* ptrDelay);

#endif /* EJERCICIOSLEA_EJERCICIO2_INC_TECLA_H_ */

