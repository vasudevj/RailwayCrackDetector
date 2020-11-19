/* Railway Crack Detector
 * Author - Vasudev Jayachandran Nair
 * 
 */


#include <AFMotor.h>

const int trigPin = A5;
const int echoPin = A4;
const int led1 = A3;
const int led2 = A2;
const int buzz = A1;
long duration;
int distance;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzz, OUTPUT);
  
  motor1.setSpeed(100);
  motor1.run(RELEASE);
  
  motor2.setSpeed(100);
  motor2.run(RELEASE);
  
  motor3.setSpeed(100);
  motor3.run(RELEASE);
  
  motor4.setSpeed(100);
  motor4.run(RELEASE);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  static int flag=0, i, n=500;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;

  if(distance<11 && distance>5 && flag==0)
  {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  else
  {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    flag=1;
    for(i=0;i<=n;i++)
    {
      if(i==0 || i==1 || i==2)
      {
        digitalWrite(buzz, HIGH);
      }
      else
      {
        digitalWrite(buzz, LOW);
      }
        digitalWrite(led1, HIGH);
        delay(500);
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        delay(500);
        digitalWrite(led2, LOW);
      }    
  }
}
