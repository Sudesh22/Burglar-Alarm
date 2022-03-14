#include <LiquidCrystal.h>

int analogPin= 0;
int raw= 0;
int Vin= 5;
int LED = 13;
float Vout= 0;
float R1= 1000;
float R2= 0;
float buffer= 0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
lcd.begin(16, 2);
Serial.begin(9600);
pinMode(LED,OUTPUT);
  lcd.setCursor(1,0);
  lcd.print("Burglar Alarm!");
  lcd.setCursor(3,1);
  lcd.print("By SUDESH");
  delay(3000);
}

void loop()
{
raw= analogRead(analogPin);
if(raw) 
{
buffer= raw * Vin;
Vout= (buffer)/1024.0;
buffer= (Vin/Vout) -1;
R2= R1 * buffer;
delay(250);

if(R2 >=100000){
  digitalWrite(LED,HIGH);
  delay(50);
  digitalWrite(LED,LOW);
  delay(50);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Burglar Alarm!");
  lcd.setCursor(1,1);
  lcd.print("Theif Detected");
}else{
  digitalWrite(LED,LOW);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Burglar Alarm!");
  lcd.setCursor(2,1);
  lcd.print("Home is Safe");

  }
}
}
