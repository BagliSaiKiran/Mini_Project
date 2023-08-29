#include <Servo.h>
byte com = 0;

Servo myServo;
//define leds
int YellowLED = 2;
int GreenLED = 2;
int RedLED = 2;

void setup() {
  
Serial.begin(9600);
myServo.attach(9);//define servo pin
myServo.write(0);
pinMode(YellowLED,OUTPUT);
pinMode(GreenLED,OUTPUT);
pinMode(RedLED,OUTPUT);

Serial.write(0xAA);

Serial.write(0x37);

delay(1000);

Serial.write(0xAA);

Serial.write(0x21);
}

void loop() {

  while(Serial.available()) {

  com = Serial.read();

  switch(com) {

      case 0x11:   //command 1 is for Green LED 
      digitalWrite(YellowLED, HIGH);
      

      break;

      case 0x12:  //command 2 is for Red LED
      digitalWrite(GreenLED, HIGH);
      

      break;

      case 0x13:  //command 3 is for Yellow LED
      digitalWrite(RedLED, HIGH);

      

      break;

      case 0x14:  //command 4 is for Servo motor
      myServo.write(180);
      
      

      break;

      case 0x15:  //command 5 is for Servo Motor
      myServo.write(0);
      
      

      break;

            }
      }
}
