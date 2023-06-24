#include "teclas.h"
#include <stdbool.h>
#include <time.h>>
// Variables globales para almacenar el estado de las teclas
EstadoTecla tecla1;
EstadoTecla tecla2;


EstadoTecla currentState = UP;  // Estado inicial de la FSM
int buttonPressed = 0;     // Estado del botón actual
int buttonStable = 0;      // Flag para estabilidad del boton


void delayNonBlocking(unsigned int milliseconds) {
    unsigned int microseconds = milliseconds * 1000;
    usleep(microseconds);
}


//Funciones de transicion de DOWN y UP
void transitionToDown() {
    delayNonBlocking(40);
}

void transitionToUp() {
    delayNonBlocking(40);

}



void InicializarTeclas(void) {
  // Inicializar las variables de estado de las teclas
  tecla1 = UP;
  tecla2 = UP;
}

void ActualizarTeclas(void) {
    buttonStable = 0;

    switch (tecla1)
    {
    case UP:
        if (buttonPressed=1)
        {
            tecla1 = TRANSITION_TO_DOWN;
        }
        
        break;

    case TRANSITION_TO_DOWN:
        if (buttonPressed=0)
        {
            tecla1 = UP;
        } else {
            transitionToDown();
            tecla1 = DOWN;

        }
        break;

    case DOWN:
        if (buttonPressed=1)
        {
            tecla1 = TRANSITION_TO_UP;

        }
        break;
    case TRANSITION_TO_UP:
        if (buttonPressed=0)
        {
            tecla1 = DOWN;
        }
        else {
            transitionToUp();
            tecla1 = UP;
            buttonStable = 1;
        }
        
        
    
    default:
        break;
    }

}



