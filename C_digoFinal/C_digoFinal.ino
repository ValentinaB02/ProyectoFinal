
#include <Servo.h> //Incluye la librería para el funcionamiento del microservomotor
#include "Talkie.h" //Incluye la librería Talkie que provee las palabras para el circuito
#include "Vocab_US_Large.h" //Vocabulario librería Talkie de alertas
#include "Vocab_Special.h" //Vocabulario librería Talkie de acentos
#include "Vocab_US_TI99.h" //Vocabulario librería Talkie
#include "Vocab_US_Clock.h" //Vocabulario horario librería Talkie

Talkie voice; //Creación objeto comando voz
Servo myservo; //Creación objeto microservomotor

//Inicializaciones variables y componentes con sus respectivos pines
int servoPin = 9; 
int buttonPin = 2;
int estado = 0;

int led = 13;
int reedswitch = 5;
int buzzer = 8;
int val = 0;

void setup() {
  myservo.attach(servoPin); //Declaración servomotor con su pin correspondiente
  //Declaración entradas y salidas del sistema
  pinMode(buttonPin, INPUT);
  pinMode(servoPin, OUTPUT);
  digitalWrite(buttonPin, LOW);

  pinMode(led, OUTPUT);
  pinMode(reedswitch, INPUT);
  pinMode (buzzer, OUTPUT);
}

void loop() {

  // Concidicional funcionamiento sistema de seguridad 
  val = digitalRead(reedswitch); //Lectura sensor
  if (val == LOW) { //Si el estado es bajo (no tiene tensión)
    //Intermitencia LED y buzzer para la alarma 
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    delay(200);
    //Comando de voz. Alerta sistema de seguridad
    voice.say(spPAUSE1);
    voice.say(sp2_ALERT);
    voice.say(spPAUSE2);
    voice.say(sp2_ALERT);
  }
  else {
    //La alarma está desactivada
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }

  estado = digitalRead(buttonPin); //Lectura pulsador
  if (estado == HIGH) { //Si el botón es oprimido
    //El microservomotor rota dando lugar al desplazamiento de la comida 
    myservo.write(-90);
    delay(2000);
    //El microservomotor vuelve a su posición inicial impidiendo el paso de más comida
    myservo.write(90);
    delay(1000);
  }
}
