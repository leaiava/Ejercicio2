/*
 * secuencias.h
 *
 *  Created on: Jul 7, 2021
 *      Author: lea
 */

#ifndef _SECUENCIAS_H_
#define _SECUENCIAS_H_


typedef struct{
	const gpioMap_t* ptrLed;//puntero al arreglo de leds
	uint8_t ledEncendido;//el led encendido en la secuencia
	uint8_t ultimoLed;//numero del último led del array
	bool_t sentidoSecuencia;//el sentido q va la secuencia
}controlSecuencia;

/* Funcion seteo_sentidoSecuencia
 * Sirve para apagar seterar el sentido de la secuencia de leds. Lee las teclas 1 y 4
 * TEC1 -> sentidoSecuencia =0 LEDA -> LED1 -> LED2 -> LED3 -> LEDA …
 * TEC4 -> sentidoSecuencia =1 LED3 -> LED2 -> LED1 -> LEDA -> LED3 …
 * Recibe un puntero a la estructura controlSecuencia
 * No devuelve nada*/
void seteo_sentidoSecuencia( controlSecuencia* ptrSecuencia);

/* Funcion activarSecuencia
 * Funcion que selecciona el Led que se tiene que prender de acuerdo al led que estaba prendido y al sentido de la secuencia
 * Recibe un puntero a la estructura controlSecuencia
 * Devuelve 1 si no hubo error
 * Devuelve 0 en caso de error */
bool_t activarSecuencia(controlSecuencia* ptrSecuencia, const uint16_t* tiempoDestello);

#endif /* EJERCICIOSLEA_EJERCICIO2_INC_SECUENCIAS_H_ */
