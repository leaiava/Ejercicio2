/*
 * led.h
 *
 *  Created on: Jul 7, 2021
 *      Author: lea
 */

#ifndef _LED_H_
#define _LED_H_

#define led_apagar(ledx)	gpioWrite( ledx, OFF )
#define led_esta_apagado(teclax)	!gpioRead( teclax )

/*=====[Prototypes (declarations) of public functions]=======================*/

/* Funcion encenderLed
 * Sirve para encender un led en particular
 * Recibe un puntero a la estructura controlSecuencia
 * Devuelve 1 si pudo encender el led
 * Devuelve 0 en caso de error */
//bool_t encenderLed( controlSecuencia* ptrSecuencia );
bool_t encenderLed(gpioMap_t LedAEncender);

/* Funcion apagarLeds
 * Sirve para apagar todos los leds juntos
 * Recibe un puntero a la estructura controlSecuencia
 * Devuelve 1 si pudo apagar todos los leds
 * Devuelve 0 en caso de error */
//bool_t apagarLeds(controlSecuencia* ptrSecuencia );
bool_t apagarLeds(const gpioMap_t* ptrArrayLed );

#endif /* EJERCICIOSLEA_EJERCICIO2_INC_LED_H_ */

