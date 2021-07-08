/*
 * tecla.c
 *
 *  Created on: Jul 7, 2021
 *      Author: lea
 */
#include "sapi.h"
#include "tecla.h"

bool_t leerTecla (gpioMap_t teclax){
	//verifico que sea una tecla válida
	if ( !( (teclax== TEC1) || (teclax== TEC2) || (teclax== TEC3) || (teclax== TEC4) ) )
			return 0;
	return !gpioRead( teclax );
}

/*
 * Esta función ya no se usa ya que el tiempo que destella cada led se fija en un array
bool_t seteo_delay(delay_t* ptrDelay){

	if ( leerTecla( TEC2 ) ){
		delayWrite( ptrDelay, 150 );
	}
	if ( leerTecla( TEC3 ) ){
		delayWrite( ptrDelay, 750 );
	}
	return (delayRead(ptrDelay));
}
*/


