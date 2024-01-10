#define BLYNK_TEMPLATE_ID "TMPL5QjjknfY"
#define BLYNK_DEVICE_NAME "Servo and Motor"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define USE_NODE_MCU_BOARD
#include <SimpleTimer.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "BlynkEdgent.h"
SimpleTimer timer;
int digitalPin = D0;

#define ONE_WIRE_BUS 2 //"D4 pin on the ndoemcu Module"
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
float temp;
#include <Servo.h>
Servo servo;

BLYNK_WRITE(V4) {
  digitalWrite(digitalPin, param.asInt());
}

BLYNK_WRITE(V0)
{
  servo.write(param.asInt());
}

void setup()
{
  Serial.begin(115200);
  DS18B20.begin();
  pinMode(digitalPin, OUTPUT);
  timer.setInterval(1000L, getSendData);
  BlynkEdgent.begin();
  
}

void loop() {
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
  BlynkEdgent.run();
}
void getSendData()
{
  DS18B20.requestTemperatures(); 
  temp = DS18B20.getTempCByIndex(0); // Celcius
  // Fahrenheit = DS18B20.toFahrenheit(temp); // Fahrenheit
  Serial.println(temp);
  //Serial.println(Fahrenheit);
  Blynk.virtualWrite(V3, temp); //virtual pin V3
  //Blynk.virtualWrite(V4, Fahrenheit); //virtual pin V4
  servo.attach(4, 500, 2350);
}
