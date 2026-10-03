#include <Ultrasonic.h>
#include <Servo.h>

Servo s = Servo();
Ultrasonic u = Ultrasonic(12, 13);

int ENA = 11;
int IN1 = 10;
int IN2 = 9;

int ENB = 5;
int IN3 = 7;
int IN4 = 6;

void setup() {
  // put your setup code here, to run once:
  s.attach(3);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  analogWrite(ENA, 250);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  analogWrite(ENB, 250);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int x = Serial.read();

  //FORWARD
  if(x == '1'){
    s.write(90);
    delay(300);
    int d = u.read();

    if(d > 20){
      digitalWrite(10, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
    }
  }

  //BACKWARD
  if(x == '2'){
    digitalWrite(10, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(500);
    digitalWrite(10, LOW);
    digitalWrite(8, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }

  //STOP
  if(x == '3'){
    digitalWrite(10, LOW);
    digitalWrite(8, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }

  //TURNRIGHT
  if(x == '4'){
    s.write(45);
    delay(300);
    int d = u.read();

    if(d > 20){
      digitalWrite(10, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      delay(500);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
    }
    s.write(90);
  }

  //TURNLEFT
  if(x == '5'){
    s.write(135);
    delay(300);
    int d = u.read();

    if(d > 20){
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, LOW);
      delay(500);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
    }
    s.write(90);
  }

}
