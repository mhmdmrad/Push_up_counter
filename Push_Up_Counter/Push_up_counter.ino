#include <TM1637Display.h>
//HC-SR04
//Youtube link: https://youtu.be/u9JauTRP_cc
#define echoPin  2
#define trigPin  3
#define resetPin 4

// 4-digital display pins
#define CLK 8
#define DIO 9
TM1637Display display(CLK, DIO);

float duration; //micro second
float cm;
long numDisplay=100;
boolean trigUp = false;
boolean trigDown = false;
float counterPushUp=0;
int buzzer=7;// Passive buzzer pin

void setup() {

  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(resetPin,INPUT_PULLUP);
  display.setBrightness(4);
  display.clear();
  delay(500);
  display.showNumberDecEx(numDisplay, false, true, 4, 0);
  
}
 

void loop() {
  
  //reset by switch
  if(digitalRead(resetPin)==0){
    trigUp=false;
    trigDown=false;
    counterPushUp=0;
  }
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(100);
  // receive, convert time (us) to cm
  duration = pulseIn(echoPin,HIGH);
  cm = duration * 0.034/2.;
  if (cm>15 && cm<=30){
    trigUp = true;
  } 
  else if (cm < 10){
    trigDown = true;
  } 
 else if(cm >30) {
  }
 
  if (trigUp==true && trigDown==true){
    counterPushUp=counterPushUp+0.5;
    trigUp=false;
    delay(500);
    tone(7,800,40);//buzzer pin 7 frequency 800 duration 500
    trigDown=false;
  }

  display.showNumberDecEx(counterPushUp, false, true, 4, 0);
}
