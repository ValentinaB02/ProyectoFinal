#include <Servo.h>

Servo myservo;

int servoPin = 9;
int buttonPin = 2;
int estado = 0;

void setup() {
  myservo.attach(servoPin);
  pinMode(buttonPin, INPUT);
  pinMode(servoPin, OUTPUT);
  digitalWrite(buttonPin, LOW);
}

void loop() {
  estado = digitalRead(buttonPin);
  if(estado == HIGH) {
  myservo.write(-90);
  delay(2000);
  myservo.write(90);
  delay(1000);
  }
}
