#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include <Servo.h>
Servo sg90; 
int pos = 0; 
int deger=0;
void setup() 
{
pinMode(2,OUTPUT);
pinMode(2,OUTPUT);
sg90.attach(13);
Serial.begin(9600);
lcd.begin();
}
void loop()
{
deger=analogRead(A0);
Serial.println(analogRead(A0));
if(deger>800)
{
sg90.write(90);
lcd.setCursor(0,0); // İlk satırın başlangıç noktası
lcd.print("OFF");
digitalWrite(2,1);
digitalWrite(3,0);
}
if(deger<800)
{
sg90.write(1);
lcd.setCursor(0,1); // İkinci satırın başlangıç noktası
lcd.print("ON");
digitalWrite(3,1);
digitalWrite(2,0);
delay(1500);
} 
lcd.clear();
}
