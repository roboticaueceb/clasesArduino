/*
  Configuracion HC06

  El siguiente sketch se debe cargar en un Arduino UNO, Nano o MEGA
  para poder configurar un dispositivo Bluetooth HC06 via codigos AT. 
  Al final del codigo aparecen los comandos a utilizar. El codigo
  utiliza la libreria SoftwareSerial.h para poder comunicarse con RX/TX
  sin usar los pines 0 y 1 del Arduino.

  Autor: Profesor Ramses Antolines
  Fecha de modificación: 22 de julio de 2024 
  Motivo: Ejemplos Unidad Educativa Colegio Eduardo Blanco

  El archivo es completamente modificable
 
  Diagrama de conexion Arduino - HC06:
  5V --- VCC
  12 --- TX
  11 --- RX
  GND --- GND

*/


#include <SoftwareSerial.h>   //Se incluye la libreria 
SoftwareSerial BT(12,11);    // RX Arduino -> 12, TX Arduino -> 11
 
void setup()
{
  BT.begin(9600);       // Se inicia el puerto serial BT
  Serial.begin(9600);   // Se inicia el monitor serial default
}
 
void loop()
{
  if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Serial.write(BT.read());
  }
 
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     BT.write(Serial.read());
  }
}

/*
  Comandos AT para HC-06:
  AT: se recibe OK
  AT+NAMEnombre: se guarda "nombre" como el nombre del dispositivo y se recibe setName.
  AT+PINxxxx: se guarda "xxxx" como el pin del dispositivo y se recibe setPIN.

*/