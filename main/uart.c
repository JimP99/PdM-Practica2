#include "uart.h"

void EstadoSemaforo(enum estados actual){
    static enum estados pasado;

    if (pasado != actual){
        Serial.print("Cambio en semaforo: Estado Actual: ");
        Serial.println(actual);
    }
    pasado = actual;
}