#include <dht11.h>
dht11 DHT;
#define DHT11_PIN 4

void setup() {
  Serial.begin(9600);

}

void loop() {
  DHT.read(DHT11_PIN);
  Serial.print("Humidité : ");
  String hum = String(DHT.humidity) + "%";
  Serial.print(hum);
  Serial.println();
  Serial.print("Température : ");
  String temp = String(DHT.temperature) + "°C";
  Serial.print(temp);
  Serial.println();
  delay(1000);

}
