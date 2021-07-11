# Ejercicio2
## Autores ✒️

_Este firmware tiene dos integrantes:_

* **L.Arrieta** - (https://github.com/leaiava)
* **J.Cagua** - (https://github.com/jonathancagua)

### Pre-requisitos 📋
- [Firmware V3](https://github.com/epernia/firmware_v3).
- [Utilización básica de firmware_v3](https://github.com/epernia/firmware_v3/blob/master/documentation/firmware/usage/usage-es.md).

## Opcion de compilacion
En main.c con 
 
    #define ejercicio1
Se comila para que ejecute la secuencia de leds del práctica 1. Sin el define ejecuta la secuencia de leds del semáforo de la práctica 2

## PdM - Práctica 2

### Resumen
Modularizar en funciones, archivos y capas, un proyecto de controlador de leds. Implementar un programa que controle la lógica de funcionamiento de una secuencia arbitraria de LEDs de la EDU-CIAA-NXP.
### Condiciones de funcionamiento
Dependencias externas:
sAPI.h
Usar delay no bloqueantes
## Objetivo:

### 1. Modularizar el ejercicio 1 de la práctica 1 en los siguientes módulos de software:
- main.c, main.h
- secuencias.c secuencias.h
- led.c, led.h
- teclas.c teclas.h

  Asignar las funciones solicitadas en la práctica 1 al módulo que corresponda y aplicar los conceptos de público y privado para funciones, variables y constantes de cada módulo.

### 2. Modificar la función activarSecuencia para que admita un segundo parámetro que indique el tiempo de destello de cada led de la secuencia individualmente, por ejemplo:

    void activarSecuencia(gpioMap_t * psecuencia, uint8_t * tiempoDestello);

El modo de uso sería el siguiente:

    gpioMap_t secuencia1[] = {LED1, LED_OFF, LED2, LED3};

    uint8_t tiempoSecuencia1[] = {1000, 500, 2000, 3000}; /* tiempos en ms para LED1, LED2 y LED3, respectivamente*/

    activarSecuencia( secuencia1, tiempoSecuencia1 ); // la función debe ahora implementar el encendido y apagado de cada led con su tiempo propio.


### 3. [Optativo] Implementar una aplicación de semáforo como secuencias de leds:

El semáforo debe tener los siguientes modos de operación:
- Normal: secuencia de leds: rojo 3 s, amarillo 500 mS, verde 1s, rojo nuevamente....
- Desconectado: led amarillo intermitente cada 500 mS.
- Alarma: rojo intermitente cada 1 s

Con la tecla 2 de la EDU-CIAA-NXP se debe poder cambiar el modo de operación del semáforo a normal. Cada vez que se pulse, se debe cambiar en el siguiente orden:

Normal, desconectado, alarma, normal, etc...

