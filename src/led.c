/*
 * led.c
 *
 *  Created on: Jul 7, 2021
 *      Author: lea
 */

#include "sapi.h"
#include "led.h"

/*encenderLed ahora recibe el led a encender para bajar la visibilidad y no mandar toda la estructura
bool_t encenderLed( controlSecuencia* ptrSecuencia )
{
	if (ptrSecuencia == NULL)
		return (false);
	return gpioWrite( ptrSecuencia->ptrLed[ptrSecuencia->ledEncendido], ON );
}
*/
bool_t encenderLed(gpioMap_t LedAEncender){
	gpioWrite( LedAEncender, ON );
	return( true );
}

/*
 * apagarLeds ahora recibe el array de leds a encender para bajar la visibilidad y no mandar toda la estructura
//bool_t apagarLeds(controlSecuencia* ptrSecuencia )
{
	if(ptrSecuencia == NULL)
		return(false);
	bool_t resp = true;
	for(int i = 0 ;i <= ptrSecuencia->ultimoLed; i++){
		resp &= led_apagar( ptrSecuencia->ptrLed[ i ] );	//apago led
		resp &= led_esta_apagado( ptrSecuencia->ptrLed[ i ] );	//verifico que se haya apagado
	}
	return(resp);
}
*/
bool_t apagarLeds(const gpioMap_t* ptrArrayLed ){
	if (ptrArrayLed == NULL)
			return (false);

	uint8_t ultimoLed = (sizeof(ptrArrayLed)/sizeof(gpioMap_t))-1;

	bool_t resp = true;
	for(int i = 0 ;i <= ultimoLed; i++){
		resp &= led_apagar( ptrArrayLed[ i ] );	//apago led
		resp &= led_esta_apagado( ptrArrayLed[ i ] );	//verifico que se haya apagado
	}
	return(resp);
}


