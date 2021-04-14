#include <IRremote.h>

const char PIN_RECEIVER = 9;

IRrecv IRreceptor(PIN_RECEIVER);

decode_results messageRecu;

int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 7;
int G = 8;
char buzzer = 12;

void setup() {

  Serial.begin(9600);
  IRreceptor.enableIRIn();
  IRreceptor.blink13(true);

  pinMode(PIN_RECEIVER, INPUT);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);

}

void loop() {
  if (IRreceptor.decode(&messageRecu)) {
    Serial.println(messageRecu.value, HEX);
      if(messageRecu.value == 0xFF30CF) {
      affichageNb(1);
      }
      if(messageRecu.value == 0xFF18E7) {
      affichageNb(2);
      }
      if(messageRecu.value == 0xFF7A85) {
      affichageNb(3);
      }
      if(messageRecu.value == 0xFF10EF) {
      affichageNb(4);
      }
      if(messageRecu.value == 0xFF38C7) {
      affichageNb(5);
      }
      if(messageRecu.value == 0xFF5AA5) {
      affichageNb(6);
      }
      if(messageRecu.value == 0xFF42BD) {
      affichageNb(7);
      }
      if(messageRecu.value == 0xFF4AB5) {
      affichageNb(8);
      }
      if(messageRecu.value == 0xFF52AD) {
      affichageNb(9);
      }
    delay(500);
    IRreceptor.resume();
  }
  delay(1);
}

void affichageNb(int NbAff) {
  if (NbAff == 1) {
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
  }
  else if (NbAff == 2) {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
  }
  else if (NbAff == 3) {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
  }
  else if (NbAff == 4) {
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  }
  else if (NbAff == 5) {
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  }
  else if (NbAff == 6) {
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  }
  else if (NbAff == 7) {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
  }
  else if (NbAff == 8) {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  }
  else if (NbAff == 9) {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  }
}
