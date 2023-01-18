// sandeep project of bidirctional counter with 2 ir sensor and led
long int count = 0;
int out = 4;
int ir1pin = 2;
int ir2pin = 3;
int s1;
int s2;

//intializing led and variables above
#include <LiquidCrystal.h>
int rsPin = 6;
int enPin = 7;
int d4Pin = 8;
int d5Pin = 9;
int d6Pin = 10;
int d7Pin = 11;

LiquidCrystal myLCD(rsPin,enPin,d4Pin,d5Pin,d6Pin,d7Pin);




void setup() {


 // ir input 
pinMode(ir1pin,INPUT);
pinMode(ir2pin,INPUT);
pinMode(out,OUTPUT);

//lcd and serial moniter initializtion 
Serial.begin(9600);
myLCD.begin(16,2);
myLCD.clear();
myLCD.setCursor(0,0);
myLCD.print("Bidirectional counter");
delay(1000);
myLCD.setCursor(0,1);
myLCD.print("Power consumption");
delay(1000);

}



void loop() {
  // put your main code here, to run repeatedly:


s1 = digitalRead(ir1pin);
s2 = digitalRead(ir2pin);

while(s1==1 && s2==1){
  s1 = digitalRead(ir1pin);
  s2 = digitalRead(ir2pin);
  if(count == 0){
    myLCD.clear();
    myLCD.setCursor(0,0);
    myLCD.print("NO STUDENTS");
    myLCD.setCursor(0,1);
    myLCD.print("NO LIGHT");
    digitalWrite(out,LOW);
  }
  if(count >= 1){
    digitalWrite(out,HIGH);
  }
}

if(s1==0){
  while(s2==1){
    s2 = digitalRead(ir2pin);
  }
  count++;
  Serial.print("count=");
  Serial.println(count);
  myLCD.clear();
  myLCD.setCursor(0,0);
  myLCD.print("count =");
  myLCD.setCursor(8,0);
  myLCD.print(count);
  goto sandy;
}



if(s2==0){
  while(s1==1){
    s1 = digitalRead(ir1pin);
  }
  count--;
  Serial.print("count=");
  Serial.println(count);
  myLCD.clear();
  myLCD.setCursor(0,0);
  myLCD.print("count =");
  myLCD.setCursor(8,0);
  myLCD.print(count);
  goto sandy;
}

sandy:
  delay(500);
  s1 = digitalRead(ir1pin);
  s2 = digitalRead(ir2pin);

}
