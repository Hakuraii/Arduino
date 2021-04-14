#include <Stepper.h>

int nombreDePas = 48*64;

Stepper monMoteur(nombreDePas, 9, 11, 10, 6);

int valeurActuelle;
int valeurPrecedente;

void setup() {
  monMoteur.setSpeed(9);
}

void loop() {
  valeurActuelle = analogRead(A0);
  if(valeurActuelle != valeurPrecedente and abs(valeurActuelle - valeurPrecedente) >= 1) {
    monMoteur.step(valeurActuelle-valeurPrecedente);
  }
  valeurPrecedente = valeurActuelle;
}
