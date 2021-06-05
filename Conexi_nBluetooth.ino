
#include <Servo.h>
#include "Talkie.h"             //different words for the circuit
#include "Vocab_US_Large.h"     //give alerts 
#include "Vocab_Special.h"      //Pause between the statements
//Atributo TTS
Talkie voice;
int speech = 0;

//Atributos Feeder
Servo myservo;

int servoPin = 9;
int buttonPin = 2;
int estado = 0;

//Atributos Security
int led = 13;
int reedswitch = 5;
int buzzer = 8;
int val = 0;

void setup() {
  //App
  Serial.begin(9600);
  //Metodos feeder
  myservo.attach(servoPin);
  pinMode(buttonPin, INPUT);
  pinMode(servoPin, OUTPUT);
  digitalWrite(buttonPin, LOW);

  //Metodos Security
  pinMode(led, OUTPUT);
  pinMode(reedswitch, INPUT);
  pinMode (buzzer, OUTPUT);
  //Aqui no hay metodos del TTS porque no necesita INPUTS
}

void loop() {
  //App
  if (Serial.available() > 0)
  {
    estado = Serial.read();
    if (estado == '6' || estado == '7')
    {
      speech = estado;
    }
  }
  if (estado == '1')
  {
    this.feeder();
    //Metodos Security
    val = digitalRead(reedswitch);
    if (val == LOW) {
      this.alarma();
      this.textToSpeech();
    }
    else {
      this.apagarAlarma();
    }
  } else if (estado == '0')
  {
    this.apagarAlarma();
  } else if (estado == '2')
  {
    this.feeder();
  } else if (estado == '4')
  {
    val = digitalRead(reedswitch);
    if (val == LOW) {
      this.alarma();
      if (speech == '6')
      {
        this.textToSpeech();
      }
    }
    else {
      this.apagarAlarma();
    }
  } else if (estado == '5')
  {
    this.apagarAlarma();
  }
}

void feeder()
{
  estado = digitalRead(buttonPin);
  if (estado == HIGH) {
    myservo.write(-90);
    delay(2000);
    myservo.write(90);
    delay(1000);
  }
}

void alarma()
{
  digitalWrite(led, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
  delay(200);
}

void apagarAlarma()
{
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
}

void textToSpeech()
{
  voice.say(spPAUSE1);
  voice.say(sp2_ALERT);
  voice.say(spPAUSE2);
  voice.say(sp2_ALERT);
  delay(500);
}
