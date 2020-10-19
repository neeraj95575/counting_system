#include <LiquidCrystal.h>

const int rs = 10, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int led = 13;
int led1 = 12;
int ir = 9;
int ir1 = 8;
int count =0;
int count1 =0;
int state;
int LastState=HIGH;
int state1;
int LastState1=HIGH;

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Person In=");
  lcd.setCursor(0,1);
  lcd.print("Person Out=");
  pinMode(13,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(9,INPUT);
  pinMode(12,OUTPUT);
  pinMode(8,INPUT);
  
  Serial.begin(9600);
}

void loop()
{
 int state = digitalRead(8);
 int state1 = digitalRead(9);
 
  if (state==HIGH && LastState==HIGH)
  {
    LastState=LOW;
    Serial.println( " DEC count=");
    lcd.setCursor(11,1);
    lcd.print(count-1);
    Serial.print(count--);
    //digitalWrite(6,HIGH);
 
  }
  else if (state==LOW)
  {
    LastState=HIGH;
    //digitalWrite(6,LOW);
  }
  
     if (state1==HIGH && LastState1==HIGH)
  {
    LastState1=LOW;
    Serial.println( " INC count=");
    lcd.setCursor(11, 0);
    lcd.print(count1+1);
    Serial.println(count1++);
    //digitalWrite(7,HIGH);
 
  }
  else if (state1==LOW)
  {
    LastState1=HIGH;
    //digitalWrite(7,LOW);

  if(count==-count1)
  {
   digitalWrite(13,LOW);
  }
  else
  {
   digitalWrite(13,HIGH);
  }

 }
}
