#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(7, 2);   // RX | TX Data communication between HC-05 and Atmel. Note BT pass"1234" speed 9600 by defoult

Servo servo1;  // create servo object to control a servo
int enablePin = 4;  // enable pin for the motor driver
int in1Pin = 8;  // input pin for the motor driver
int in2Pin = 9;  // input pin for the motor driver

void setup() {

  
  BTSerial.begin(9600);
  servo1.attach(12);  // attaches the servo on pin  to the servo object
  pinMode(enablePin, OUTPUT);  // set the enable pin as an output
  pinMode(in1Pin, OUTPUT);  // set the input 1 pin as an output
  pinMode(in2Pin, OUTPUT);  // set the input 2 pin as an output
  //Serial.begin(9600);  // start serial communication at 9600 baud rate
  
  
}

void loop() {
  
  // Keep reading from HC-05 and send to Arduino Serial Monitor
 // if (BTSerial.available()){
  //  Serial.write(BTSerial.read());
 // }
  // Keep reading from Arduino Serial Monitor and send to HC-05
 // if (Serial.available()){
 //   BTSerial.write(Serial.read());
  //}
  int input = BTSerial.read();  // read the input from the serial port

  if (input == 'L') {  // if the input is 'L', move servo left
    servo1.write(60);
    //delay(500);
    //servo1.write(105);
   // delay(10);  
  }
  else if (input == 'R') {  // if the input is 'R', move servo right
    servo1.write(130);
   // delay(500);
    //servo1.write(105);
   // delay(10);  
  }
  
  else if (input == 'F') {  // if the input is 'F', turn on motor 1 in forward direction at full speed
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
    analogWrite(enablePin, 255);  // set the duty cycle to 255 (maximum speed)
   // delay(10);    
  }
  else if (input == 'B') {  // if the input is 'B', turn on motor 1 in reverse direction at full speed
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
    analogWrite(enablePin, 255);  // set the duty cycle to 255 (maximum speed)
    //delay(10);  
  }
  else if (input == 'S') {  // if the input is 'S', turn off motor 1
  //delay(1000); 
    servo1.write(105); //set as 0 direction (ballanced)
    //delay(10);   
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
    analogWrite(enablePin, 0);  // set the duty cycle to 0 (minimum speed)
  }
  else if (input == 'G') {
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
    analogWrite(enablePin, 255);  // set the duty cycle to 255 (maximum speed)
    servo1.write(60);
  }
  else if (input == 'I') {
    digitalWrite(in1Pin, HIGH); 
    digitalWrite(in2Pin, LOW);
    analogWrite(enablePin, 255);  // set the duty cycle to 255 (maximum speed)
    servo1.write(130);    
  }
else if (input == 'H') {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
    analogWrite(enablePin, 255);  // set the duty cycle to 255 (maximum speed)
    servo1.write(60);
  }
  else if (input == 'J') {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
    analogWrite(enablePin, 255);  // set the duty cycle to 255 (maximum speed)
    servo1.write(130);
  }
}
