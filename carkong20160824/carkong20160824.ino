#include<Servo.h>
Servo servoLeft;
Servo servoRight;
byte wLeftOld;
byte wRightOld;
byte counter;
void setup() {
  // put your setup code here, to run once:
  servoLeft.attach(13);
  servoRight.attach(12);
  pinMode(7,INPUT);
  pinMode(5,INPUT);
  wLeftOld = 0;
  wRightOld = 1;
  counter = 0;
  Serial.begin(9600);
  
  
  
}

void loop() {
  byte wLeft = digitalRead(5);
  byte wRight = digitalRead(7);
  goStraight(20);
  if (wLeft != wRight){
    if(wLeft !=wLeftOld&&wRight != wRightOld){
      counter++;
      wLeftOld = wLeft;
      wRightOld = wRight;
      if(counter == 4){
        wLeft = 0;
        wRight = 0;
        counter =0;
      }
    }
    else{
      counter = 0;
    }
  }
//  if((wLeft == 0)&&(wRight == 0)){
//    goBack(1000);
//    turnLeft(830);
//    goStraight(3000);
//    turnLeft(830);
//  }
//  else if(wLeft == 0){
//    goBack(1000);
//    turnRight(400);
//  }
//  else 
  if(wRight == 0&&wLeft == 1){
  goBack(1000);
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  delay(830);
  goStraight(1000);
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  delay(830);
  goStraight(3000);
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  delay(830);
  goStraight(1500);
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  delay(830);
  goStraight(3500);
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  delay(830);
  goStraight(4000);
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  delay(830);
  } 
  delay(50);
 
}



void goStraight(int time){
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(time);
}

void goBack(int time){
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  delay(time);
}

void turnLeft(int time){
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  delay(time);
}

void turnRight(int time){
  servoLeft.writeMicroseconds(1700);
  servoLeft.writeMicroseconds(1700);
  delay(time);
 
}

void Stop(){
  servoLeft.detach();
  servoRight.detach();
}

