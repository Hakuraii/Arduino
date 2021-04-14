#include <Servo.h>

Servo monServo;

char PWN_Servo = 9;
char AN_POT = 0;

int positionDuServo = 0;

void setup() {
  // put your setup code here, to run once:
  monServo.attach(9);
  monServo.write(positionDuServo);

}

void loop() {
  positionDuServo = analogRead(AN_POT); 
  positionDuServo = map(positionDuServo, 0, 1023, 0, 180);
  monServo.write(positionDuServo);
  delay(15);
}
