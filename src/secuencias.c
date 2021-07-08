/*
 * secuencias.c
 *
 *  Created on: Jul 7, 2021
 *      Author: lea
 */
#include "sapi.h"
#include "secuencias.h"
#include "led.h"
#include "tecla.h"


void seteo_sentidoSecuencia( controlSecuencia* ptrSecuencia){

	if ( leerTecla( TEC1 ) ){
		ptrSecuencia->sentidoSecuencia = false;
	}
	if ( leerTecla( TEC4 ) ){
		ptrSecuencia->sentidoSecuencia = true;
	}
}

bool_t activarSecuencia(controlSecuencia* ptrSecuencia, const uint16_t* tiempoDestello)
{
	static delay_t myDelay;

	if(ptrSecuencia == NULL)
		return(false);

	if(delayRead(&myDelay)){

		//Ajusto el led que se tiene que encender de acuerdo al led que estaba prendido y al sentido de la secuencia
		if(ptrSecuencia->sentidoSecuencia){
			if (ptrSecuencia->ledEncendido <= 0)
				ptrSecuencia->ledEncendido = ptrSecuencia->ultimoLed;
			else
				ptrSecuencia->ledEncendido--;
		}
		else{
			if (ptrSecuencia->ledEncendido >= ptrSecuencia->ultimoLed)
				ptrSecuencia->ledEncendido = 0;
			else
				ptrSecuencia->ledEncendido++;
		}


		//if( !apagarLeds(ptrSecuencia) ) //Envío solo el array de leds para bajar la visibilidad y no mandar la estructura
		if( !apagarLeds(ptrSecuencia->ptrLed) )
			return(false);

		//if( !encenderLed(ptrSecuencia)) //Envío solo el led a encender para bajar visibilidad y no mandar la estructura
		if( !encenderLed(ptrSecuencia->ptrLed[ptrSecuencia->ledEncendido]))
			return(false);

		delayWrite( &myDelay, tiempoDestello[ptrSecuencia->ledEncendido] );
	}


	return(true);
}


