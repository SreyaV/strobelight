#define <uspeech.h>
#define led 13
#include <stdio.h>

signal voice(A0);
//char prev;
boolean prev=false;
boolean start=false;

int sum = 0;
void setup(){
  voice.f_enabled = true;
  //Calibrate these values.
  voice.minVolume = 70;
  voice.fconstant = 400;
  voice.econstant = 1;
  voice.aconstant = 2;
  voice.vconstant = 3;
  voice.shconstant = 4;
  voice.calibrate();
  Serial.begin(9600);
  pinMode(led, OUTPUT); 
}
void loop(){
    char p = voice.getPhoneme();
    Serial.write(p);
    if(p!=' '){
      if(p=='o'){
          start = true;
      }
      else if(p=='s'){
          start = false;
      }
    }
    else{
      if(start && !prev){
        digitalWrite(led, HIGH);
      }
      else if (!start && prev){
        digitalWrite(led, LOW);
      }
    }
    prev = start;
}
