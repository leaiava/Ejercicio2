/*=============================================================================
 * Author: Leandro Arrieta <leandroarrieta@gmail.com>
 * 		   Jonathan Cagua <jonathan.cagua@gmail.com >
 * Date: 2021/07/07
 *===========================================================================*/

#include "sapi.h"
#include "tecla.h"

/* Funcion leerTecla
 * Sirve para leer el estado de una tecla.
 * Recibe tecla a leer
 * Devuelve por valor el estado de la tecla pulsada (verdadero) o liberada (falso)*/
bool_t leerTecla (gpioMap_t teclax){
	if ( !( (teclax== TEC1) || (teclax== TEC2) || (teclax== TEC3) || (teclax== TEC4) ) ) //verifico que sea una tecla válida
			return 0;
	return !gpioRead( teclax );
}
