#include "Talkie.h"             //This header file is used to provied different words for the circuit
#include "Vocab_US_Large.h"     //This header file is used to give alerts 
#include "Vocab_Special.h"      //This header file is used to take pause between the statements

Talkie voice;                   //Defining an object 

void setup()
{
                                //Empty because no need to give inputs
}

 //CIRCUIT WILL SAY :- PAPA ALERT MACHINE CONTROL IS FAILURE.EVACUATE IMMEDIATELY.

void loop()
{
  voice.say(spPAUSE1);          //Takes short pause while repaeting the alert message        
  voice.say(sp2_ALERT);
  voice.say(spPAUSE2);
  voice.say(sp2_ALERT);
}

//NOTE:-The 'void setup' will remain empty when we have to only run the loop continuously.
