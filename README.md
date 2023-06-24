# PdM-Practica2
Implementación de un semáforo y sistema antirrebotes mediante máquina de estados y retardos no bloqueantes.

## Circuito
Para el desarrollo de la práctica se utilizó un Arduino Leonardo. En los pines 2, 3 y 4 se conectan los leds verde amarillo y rojo respectivamente.
En los pines 10 y 11 se conectan pulsadores que se encuentran en modo pull-up.

## Código
El proyecto consta de un archivo principal: ```main.ino```.
Como módulos se usarán los archivos: 
- ```uart.c```
- ```uart.h```
- ```semaforo.c```
- ```semaforo.h```
-```teclas.c```
- ```teclas.h```

En el archivo ```semaforo.c``` se encuentra el funcionamiento de los diferentes modos y en el archivo ```uart.c``` se encuentra el código que muestra en el serial cuando existe un cambio de la máquina de estados del semáforo. Finalmente, dentro del archivo ```teclas.c``` se realiza la implementacion antirebote mediante software para los pulsadores.