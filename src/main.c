/*=============================================================================
 * Author: Leandro Arrieta <leandroarrieta@gmail.com>
 * Date: 2021/07/07
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "main.h"
#include "sapi.h"
#include "secuencias.h"

int main( void )
{
	controlSecuencia secuencia1;
	const gpioMap_t secuenciaLeds1[] = {LEDB, LED1, LED2, LED3 };
	const uint16_t tiempoSecuencia1[] = {100, 500, 1000, 3000};


	// Inicializo mi estructura1
	secuencia1.ptrLed = secuenciaLeds1;
	secuencia1.ledEncendido = (sizeof(secuenciaLeds1)/sizeof(gpioMap_t))-1;
	secuencia1.ultimoLed = (sizeof(secuenciaLeds1)/sizeof(gpioMap_t))-1;
	secuencia1.sentidoSecuencia = false;
	// ----- Setup -----------------------------------
	boardInit();

	//TEC1 -> sentidoSecuencia =0 de Izq a Der
	//TEC4 -> sentidoSecuencia =1 de Der a Izq
	//TEC2 ->
	//TEC3 ->

	// ----- Repeat for ever -------------------------
	while( true ) {

		seteo_sentidoSecuencia( &secuencia1 );

		if( !activarSecuencia( &secuencia1 , tiempoSecuencia1 ) )
			atenderError();
   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}

// No se implementa la atención del error, se deja colgado con el while(1)
void atenderError()
{
	while(1);
}
