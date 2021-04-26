#include <MPU6050_tockn.h>  //Libreria MPU6050_tockn
#include <Wire.h>
#include <hcsr04.h> //Libreria Bifrost.Arduino.Sensor.HCSR04

//Pines de conexion para Trigger.
#define PinTrigger1 2
#define PinTrigger2 7
#define PinTrigger3 9
#define PinTrigger4 12

//Pines de conexion para Echo.
#define PinEcho1 4
#define PinEcho2 8
#define PinEcho3 10
#define PinEcho4 13

//Rango de distancia de trabajo de los sensores ultrasonicos.
#define DistanciaMin 20
#define DistanciaMax 4000

#define PinVoltaje A1 //Pin de lectura de voltaje.
#define PinCorriente A0 //Pin de lectura de corriente.
#define VoltajeMaxBateria 4.0 //Voltaje de bateria totalmente cargada.
#define LecturaVoltMax 842.0  //Lectura del voltaje.

HCSR04 ultrasonico1(PinTrigger1, PinEcho1, DistanciaMin, DistanciaMax), ultrasonico2(PinTrigger2, PinEcho2, DistanciaMin, DistanciaMax), ultrasonico3(PinTrigger3, PinEcho3, DistanciaMin, DistanciaMax), ultrasonico4(PinTrigger4, PinEcho4, DistanciaMin, DistanciaMax);

MPU6050 mpu6050(Wire);

float A, V, voltaje, corriente, dist1, dist2, dist3, dist4;

void setup() 
{
  Serial.begin(115200);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() 
{
 getBateria();
 getAngulos();
 getDistancia();
 Serial.print ( (String) voltaje + "B" + mpu6050.getAngleX() + "X" + mpu6050.getAngleY() + "Y" + mpu6050.getAngleZ() + "Z" + dist1 + "D1S" + dist2 + "D2S" + dist3 + "D3S" + dist4 + "D4S" + "\n");
 delay(100);
}

void getAngulos()
{
  mpu6050.update();
}

void getDistancia()
{
  if(ultrasonico1.distanceInMillimeters() > DistanciaMin && ultrasonico1.distanceInMillimeters() < DistanciaMax)
    dist1 = ultrasonico1.distanceInMillimeters();
    
  if(ultrasonico2.distanceInMillimeters() > DistanciaMin && ultrasonico2.distanceInMillimeters() < DistanciaMax)
    dist2 = ultrasonico2.distanceInMillimeters();

  if(ultrasonico3.distanceInMillimeters() > DistanciaMin && ultrasonico3.distanceInMillimeters() < DistanciaMax)
    dist3 = ultrasonico3.distanceInMillimeters();

  if(ultrasonico4.distanceInMillimeters() > DistanciaMin && ultrasonico4.distanceInMillimeters() < DistanciaMax)
    dist4 = ultrasonico4.distanceInMillimeters();
}

void getBateria()
{
  int lectura_voltaje = analogRead(PinVoltaje);
  int lectura_corriente = analogRead(PinCorriente);

  if(lectura_voltaje < LecturaVoltMax && lectura_voltaje > 0.0)
  {
    voltaje = lectura_voltaje * (VoltajeMaxBateria / LecturaVoltMax);
  }
  else
  {
    voltaje = 0;
  }
}
