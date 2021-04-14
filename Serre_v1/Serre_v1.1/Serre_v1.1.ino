#include <dht11.h>
dht11 DHT;
#define DHT11_PIN A0

#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int resval = 0;
int respin = A1;
int R = A5;
int G = A4;
int B = A3;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  DHT.read(A0);
  lcd.setCursor(0,0);
  String hum = "Humidite " + String(DHT.humidity) + " %";
  lcd.print(hum);
  lcd.setCursor(0,1);
  String temp = String(DHT.temperature) + " C";
  lcd.print("Temperature " + temp);
  Serial.print(hum);

  resval = analogRead(respin);

  if(resval <= 615){
    digitalWrite(R,1);
    digitalWrite(G,0);
    digitalWrite(B,0);
  }
  if(resval > 615 && resval <= 680){
    digitalWrite(R,1);
    digitalWrite(G,0);
    digitalWrite(B,1);
  }
  if(resval > 680){
    digitalWrite(R, 0);
    digitalWrite(G, 1);
    digitalWrite(B, 0);
  }
  delay(1000);
}
