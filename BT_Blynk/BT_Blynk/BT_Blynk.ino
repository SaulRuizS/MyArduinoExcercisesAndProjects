
#define BLYNK_PRINT Serial

#include <SoftwareSerial.h>
SoftwareSerial SwSerial(0, 1); // RX, TX

#include <BlynkSimpleSerialBLE.h>

char auth[] = "GhDkjMF5u4oiloNozQHAOZZJgcbXyqwl";

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);
}

void setup() 
{
  Serial.begin(9600);
  SwSerial.begin(9600);
  Blynk.begin(SwSerial, auth);
  Serial.println("Waiting for connections...");
}

void loop() 
{ 
  Blynk.run();
}
