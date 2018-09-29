/*
 * This code Written by Ahmed shelbaya at 29/9/2018 
 * Code Function is Atomatic Trush Bin Which open 
 * when someone get close from it 
 */
 /*
  * Component 
  * 1- Arduino UNO / Nano 
  * 2- Ultrasonic 
  * 3- Servo Motor 
  */
#include<Servo.h>   // add Servo motor libriry 
Servo servo; //Create Servo object 
int const trigPin = 13; //connect Ultrasonic Trig pin to Arduino Pin 13 
int const echoPin = 12; //Connect Ultrasonic Echo Pin to Arduino Pin 12
void setup()
{
  pinMode(trigPin, OUTPUT); //Define Trig pin as Output 
  pinMode(echoPin, INPUT); //Define Echo Pin as Input 
  servo.attach(9); //Connect Servo Pin to Arduino Pin 9 
}
void loop()
{ 
  int duration, distance;  //Create Variables to store distance ant Time 
  // Ultrasonic Opertation 
  digitalWrite(trigPin,LOW); 
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Measure the pulse input in echo pin
  duration = pulseIn(echoPin, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance = duration/58.2;
  // if distance less than 8 cm and more than 0 (0 or less means over range)
  if (distance <= 8&&distance>=0) 
  {
    servo.write(50); //Open Bin 
    delay(3000);
  } else {

    servo.write(160); //Close Bin 
  }
  // Waiting 60 ms won't hurt any one
  delay(60);
}
