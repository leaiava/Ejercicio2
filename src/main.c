/*=============================================================================
 * Author: Leandro Arrieta <leandroarrieta@gmail.com>
 * 		   Jonathan Cagua <jonathan.cagua@gmail.com >
 * Date: 2021/07/07
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "main.h"

#define SecuenciaCantidad 3

//#define Ejercicio1 //Con este define compilo para ver la secuencia de leds del ejercicio 1 o para ver el semáforo del ejercicio2

int main( void )
{

#ifdef Ejercicio1
	controlSecuencia secuencia1;
	const gpioMap_t secuenciaLeds1[] = { LEDB, LED1, LED2, LED3 };
	const uint16_t tiempoSecuencia1[] = {150 , 150 , 150 , 150 };
	uint16_t SecuenciaTamanio = (sizeof(secuenciaLeds1)/sizeof(gpioMap_t))-1;
	uint16_t TiempoTamanio = (sizeof(tiempoSecuencia1)/sizeof(uint16_t))-1;
	if( !SecuenciaInit(&secuencia1,secuenciaLeds1, SecuenciaTamanio, tiempoSecuencia1, TiempoTamanio))
		atenderError();

#else
	controlSecuencia secuencia[SecuenciaCantidad];
	int secuenciaNbr = 0;	// indice para elegir entre las 3 secuencias posible del semáforo
	const gpioMap_t secuenciaNormal[] = { LEDR,LED1,LEDG};
	const uint16_t tiempoNormal[] = {3000,500,1000};
	const gpioMap_t secuenciaDesconectado[] = { LED1,LED_OFF};
	const uint16_t tiempoDesconectado[] = {500,500};
	const gpioMap_t secuenciaAlarma[] = { LEDR,LED_OFF };
	const uint16_t tiempoAlarma[] = {1000,1000};

	if( !SecuenciaInit(&secuencia[0],secuenciaNormal, SecuenciaSize(secuenciaNormal), tiempoNormal, TiempoSize(tiempoNormal)) )
		atenderError();
	if( !SecuenciaInit(&secuencia[1],secuenciaDesconectado, SecuenciaSize(secuenciaDesconectado), tiempoDesconectado, TiempoSize(tiempoDesconectado)) )
		atenderError();
	if( !SecuenciaInit(&secuencia[2],secuenciaAlarma, SecuenciaSize(secuenciaAlarma), tiempoAlarma, TiempoSize(tiempoAlarma)) )
		atenderError();
#endif

	// ----- Setup -----------------------------------
	boardInit();

	// ----- Repeat for ever -------------------------
	while (1) {
	#ifdef Ejercicio1
			//TEC1 -> sentidoSecuencia =0 de Izq a Der
			//TEC4 -> sentidoSecuencia =1 de Der a Izq
			if( !SecuenciaSentidoChequear( &secuencia1 ))
				atenderError();
			//TEC2 -> cada led queda encendido 150 ms.
			//TEC3 -> cada led queda encendido 750 ms.
			if( !SecuenciaDelayChequear( &secuencia1 ))
				atenderError();

			if( !SecuenciaActivar( &secuencia1 ))
				atenderError();
	#else
			//TEC2 -> Selecciona entre los 3 modos de semáforo
			if(SecuenciaSiguienteChequear()){
				SecuenciaApagar(&secuencia[secuenciaNbr]);//apagamos los leds de antigua secuencia

				//espera a que se suelte el TEC2 para seguir, sino pega la vuelta muy rápido y hace muchos incrementos
				while(SecuenciaSiguienteChequear());
					secuenciaNbr++;

				if(secuenciaNbr>(SecuenciaCantidad - 1))
					secuenciaNbr=0;
			}

			if( !SecuenciaActivar( &secuencia[secuenciaNbr]) )
				atenderError();
	#endif
	}
   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}

/* Funcion atenderError
 * Funcion para atender errores no implementada
 * Se dejo un while(1) para que se quede en esta función en caso de algún error*/
void atenderError()
{
	while(1);
}
