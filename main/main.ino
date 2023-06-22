//#include <Arduino.h>
#include "semaforo.c"

void setup()
{
	pinMode(3, OUTPUT);
}

void loop()
{
    int valor = apagarLeds();
	digitalWrite(valor, HIGH);
    delay(5000);
    digitalWrite(valor, LOW);
    delay(1000);
    encenderLed();
}
