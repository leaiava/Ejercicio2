/*=============================================================================
 * Author: Leandro Arrieta <leandroarrieta@gmail.com>
 * 		   Jonathan Cagua <jonathan.cagua@gmail.com >
 * Date: 2021/07/07
 *===========================================================================*/


#ifndef _SECUENCIAS_H_
#define _SECUENCIAS_H_

typedef struct{
	const gpioMap_t* ptrLed;//puntero al arreglo de leds
	uint8_t ledEncendido;//el led encendido en la secuencia
	uint8_t ultimoLed;//numero del último led del array
	bool_t sentidoSecuencia;//el sentido q va la secuencia
	const uint16_t* ptrTime;//puntero al array de times
}controlSecuencia;

bool_t SecuenciaSentidoChequear( controlSecuencia* ptrSecuencia);

bool_t SecuenciaActivar(controlSecuencia* ptrSecuencia);

bool_t SecuenciaApagar(controlSecuencia* ptrSecuencia );

bool_t SecuenciaInit(controlSecuencia* ptrSecuencia , const gpioMap_t* ptrLed , uint16_t SecuenciaSize , const uint16_t* ptrTime , uint16_t TimeSize);

bool_t SecuenciaSiguienteChequear();

bool_t SecuenciaDelayChequear( controlSecuencia* ptrSecuencia);

#endif /* _SECUENCIAS_H_ */
