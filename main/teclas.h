#ifndef TECLAS_H
#define TECLAS_H

#include <Arduino.h>
#include <stdbool.h>
#include <time.h>>

// Estados de la MEF
typedef enum {
  UP,
  TRANSITION_TO_DOWN,
  DOWN,
  TRANSITION_TO_UP
} EstadoTecla;



void InicializarTeclas(void);
void ActualizarTeclas(tecla);

#endif
