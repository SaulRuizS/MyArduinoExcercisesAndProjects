#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "nrHVZsIUosu754SO0Um8Nz1Z5f46S8Ql";

char ssid[] = "HOME-BBDD";
char pass[] = "A6B3EA3D44C0D632";

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();

  Serial.print("El valor del Slider es: ");
  Serial.println(pinValue);
}

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
