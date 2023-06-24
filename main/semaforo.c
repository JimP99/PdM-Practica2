#include "semaforo.h"
#include "uart.h"


enum estados iniSemaforo();

enum estados actSemaforo(enum estados cambio, float mult);

void apagar();

void encender(int led);

bool titilar(int led, int tiempo, bool estado);

float definirTiempo(float tiempo);

bool espera(unsigned long duracion);

int FuncionamientoSemaforo(){
	enum estados eActual;
	eActual = iniSemaforo();
	float valores=1;
	bool ff = 0;
	while (1){
		/*if(!digitalRead(10)){
			break;
		}*/
		valores = definirTiempo(valores);
		switch (eActual){
		case verde:
			encender(2);
			break;
		case amarillo:
			encender(3);
			break;
		case rojo:
			encender(4);
			break;
		case desconectado:
			ff = titilar(3,500*valores, ff);
			break;
		case alarma:
			ff = titilar(4,valores*1000,ff);
			break;		
		default:
			break;
		}
		eActual = actSemaforo(eActual,valores);
		EstadoSemaforo(eActual);
	}
	
	return 3;
}

enum estados iniSemaforo(){
	return verde;
};

enum estados actSemaforo(enum estados cambio, float mult){
	
	switch (cambio){
	case verde:
		if (espera(3000*mult)){
			apagar();
			cambio = amarillo;
		}
		if(!digitalRead(10)){
			apagar();
			cambio = desconectado;
		}
		break;
	case amarillo:
		if (espera(500*mult)){
			apagar();
			cambio = rojo;
		}
		if(!digitalRead(10)){
			apagar();
			cambio = desconectado;
		}
		break;
	case rojo:
		if (espera(2000*mult)){
			apagar();
			cambio = verde;
		}
		if(!digitalRead(10)){
			apagar();
			cambio = desconectado;
		}
		break;
	case desconectado:
		if(!digitalRead(10)){
			apagar();
			cambio = alarma;
		}
		break;
	case alarma:
		if(!digitalRead(10)){
			apagar();
			cambio = rojo;
		}
		break;
	default:
		cambio = verde;
		break;
	}

	return cambio;
};

void apagar(){
	digitalWrite(2,LOW);
	digitalWrite(3,LOW);
	digitalWrite(4,LOW);
}

void encender(int led){
	digitalWrite(led,HIGH);
}

bool titilar(int led, int tiempo, bool estado){
	if(espera(tiempo)){
		estado = !estado;
		digitalWrite(led,estado);
	}
	return estado;
}


float definirTiempo(float tiempo){
	if(!digitalRead(11)){
		if (tiempo == 0.5){
			return 1;
		} else if (tiempo == 1){
			return 2;
		} else {
			return 0.5;
		}
	}
	return tiempo;
}

bool espera(unsigned long duracion){
  static long tiempo1 = 0;
  unsigned long tiempo2 = 0;
  tiempo2 = millis();
  if(tiempo2 > (duracion + tiempo1)){
    tiempo1 = millis();
    return HIGH;
  }
  return LOW; 
}
