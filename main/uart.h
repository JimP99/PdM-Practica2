#ifndef _UART_H_
#define _UART_H_

#include <Arduino.h>

enum estados{verde, amarillo, rojo, desconectado, alarma};

void EstadoSemaforo(enum estados actual);

#endif