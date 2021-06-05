
#include <Servo.h>
//#include "Talkie.h"             //This header file is used to provied different words for the circuit
//#include "Vocab_US_Large.h"     //This header file is used to give alerts 
//#include "Vocab_Special.h"

//Talkie voice;
Servo myservo;

int servoPin = 9;
int buttonPin = 2;
int estado = 0;

int led = 13;
int reedswitch = 5;
int buzzer = 8;
int val = 0;

void setup() {
  myservo.attach(servoPin);
  pinMode(buttonPin, INPUT);
  pinMode(servoPin, OUTPUT);
  digitalWrite(buttonPin, LOW);

  pinMode(led, OUTPUT);
  pinMode(reedswitch, INPUT);
  pinMode (buzzer, OUTPUT);
}

void loop() {
  estado = digitalRead(buttonPin);
  if (estado == HIGH) {
    myservo.write(-90);
    delay(2000);
    myservo.write(90);
    delay(1000);
  }

  val = digitalRead(reedswitch);
  if (val == LOW) {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    delay(200);
//    voice.say(spPAUSE1);          //Takes short pause while repaeting the alert message
//    voice.say(sp2_ALERT);
//    voice.say(spPAUSE2);
//    voice.say(sp2_ALERT);
  }
  else {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }
}
