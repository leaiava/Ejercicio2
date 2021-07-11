/*=============================================================================
 * Author: Leandro Arrieta <leandroarrieta@gmail.com>
 * 		   Jonathan Cagua <jonathan.cagua@gmail.com >
 * Date: 2021/07/07
 *===========================================================================*/

#include "secuencias.h"

/* Funcion SecuenciaSentidoChequear
 * Sirve para seterar el sentido de la secuencia de leds.
 * Lee las teclas 1 y 4 y actualiza la estrcutura recibida
 * TEC1 -> sentidoSecuencia =0 -> Incrementa indice en array de Leds
 * TEC4 -> sentidoSecuencia =1 -> Decrementa indice en array de Leds
 * Recibe un puntero a la estructura controlSecuencia
 * Devuelve 1 si no hubo error
 * Devuelve 0 en caso de error */
bool_t SecuenciaSentidoChequear( controlSecuencia* ptrSecuencia){
	if(ptrSecuencia == NULL) // verifico que no se haya recibido un puntero a NULL
		return(false);

	if ( leerTecla( TEC1 ) ){
		ptrSecuencia->sentidoSecuencia = false;
	}
	if ( leerTecla( TEC4 ) ){
		ptrSecuencia->sentidoSecuencia = true;
	}
	return (true);
}
/* Funcion SecuenciaDelayChequear
 * Sirve para seterar el delay de la secuencia de leds del ejercicio1.
 * Lee las teclas 2 y 3 y actualiza la estrcutura recibida
 * TEC2 -> cada led queda encendido 150 ms.
 * TEC3 -> cada led queda encendido 750 ms.
 * Recibe un puntero a la estructura controlSecuencia
 * Devuelve 1 si no hubo error
 * Devuelve 0 en caso de error */
bool_t SecuenciaDelayChequear( controlSecuencia* ptrSecuencia){
static const uint16_t tiempoSecuencia1[] = {150 , 150 , 150 , 150 };
static const uint16_t tiempoSecuencia2[] = {750 , 750 , 750 , 750 };

	if(ptrSecuencia == NULL) // verifico que no se haya recibido un puntero a NULL
		return(false);

	if ( leerTecla( TEC2 ) ){
		ptrSecuencia->ptrTime = tiempoSecuencia1;
	}
	if ( leerTecla( TEC3 ) ){
		ptrSecuencia->ptrTime = tiempoSecuencia2;
	}
	return (true);
}

/*Funcion SecuenciaSiguienteChequear
 * Sirve para chequear si se presionó la TEC2
 * Con TEC2 se cambia el modo de funcionamiento del semáforo
 * No recibe nada
 * Devuelve por valor el estado de la tecla pulsada (verdadero) o liberada (falso)
 */
bool_t SecuenciaSiguienteChequear(){

	return( leerTecla( TEC2 ) );
}

/* Funcion SecuenciaActivar
 * Selecciona el Led que se tiene que prender de acuerdo al led que estaba prendido, al sentido de la secuencia y al tiempo de destello
 * Recibe un puntero a la estructura controlSecuencia
 * Devuelve 1 si no hubo error
 * Devuelve 0 en caso de error */
bool_t SecuenciaActivar(controlSecuencia* ptrSecuencia){

	static delay_t myDelay;

	if(ptrSecuencia == NULL) // verifico que no se haya recibido un puntero a NULL
		return(false);

	if(delayRead(&myDelay)){	//Si se cumplió el delay entro a modificar la secuencia

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

		//Apago todos los leds
		if( !SecuenciaApagar(ptrSecuencia) )
			return(false);

		//Enciendo el led que corresponde
		if( !ledEncender(ptrSecuencia->ptrLed[ptrSecuencia->ledEncendido]))
			return(false);

		//seteo el delay con el tiempo de destello del led que corresponde
		delayWrite( &myDelay, ptrSecuencia->ptrTime[ptrSecuencia->ledEncendido] );
		return(true);
	}

	//Hago el siguietne chequeo porque al cambiar de secuencia debo actualizar el delay
	//sino el primer destello queda con el delay viejo
	if( myDelay.duration != ptrSecuencia->ptrTime[ptrSecuencia->ledEncendido] )
		delayWrite( &myDelay, ptrSecuencia->ptrTime[ptrSecuencia->ledEncendido] );
	return(true);
}

/* Funcion SecuenciaInit
 * Inicializa la estructura de secuencia de leds
 * Recibe puntero a estructura y todos los parámetros de la estructura
 * Devuelve 1 si no hubo error
 * Devuelve 0 en caso de error */
bool_t SecuenciaInit(controlSecuencia* ptrSecuencia , const gpioMap_t* ptrLed , uint16_t SecuenciaSize , const uint16_t* ptrTime , uint16_t TimeSize){

	//Verifico que el array con la secuencia de leds y el array con el tiempo de destello tengan el mismo tamaño
	if(SecuenciaSize != TimeSize){
		return(false);
	}
	//Inicializo la estructura
	ptrSecuencia->ptrLed = ptrLed;
	ptrSecuencia->ledEncendido = SecuenciaSize;
	ptrSecuencia->ultimoLed = SecuenciaSize;
	ptrSecuencia->sentidoSecuencia = false;
	ptrSecuencia->ptrTime = ptrTime;

	return(true);
}

/* Funcion SecuenciaApagar
 * Apaga todos los leds de la secuencia
 * Recibe puntero a la estructura
 * Devuelve 1 si no hubo error
 * Devuelve 0 en caso de error */
bool_t SecuenciaApagar(controlSecuencia* ptrSecuencia )
{
	if(ptrSecuencia == NULL) // verifico que no se haya recibido un puntero a NULL
		return(false);

	bool_t resp = true;

	for(int i = 0 ;i <= ptrSecuencia->ultimoLed; i++){
			resp &= ledApagar( ptrSecuencia->ptrLed[ i ] );	//apago led
	}
	return(resp);
}

