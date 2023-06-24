#include "semaforo.c"
#include "uart.c"

// Declaracion de LEDs
const int16_t LED_VERDE = 2;
const int16_t LED_AMARILLO = 3;
const int16_t LED_ROJO = 4;

const int16_t SW1 = 10;
const int16_t SW2 = 11;


void setup(){
    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_AMARILLO, OUTPUT);
    pinMode(LED_ROJO, OUTPUT);
    pinMode(SW1, INPUT);
    pinMode(SW2, INPUT);
    Serial.begin(9600);
}

void loop(){
    const int16_t LEDS[] = {LED_VERDE, LED_AMARILLO, LED_ROJO};
    const int16_t ultimoLed = sizeof(LEDS) / sizeof(int16_t);
    while (1) {
        FuncionamientoSemaforo();
    }
}
