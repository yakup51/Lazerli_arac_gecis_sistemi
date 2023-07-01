#include <LiquidCrystal_I2C.h> // I2C LCD kütüphanesini dahil ettik
LiquidCrystal_I2C lcd(0x27,16,2); // LCD nesnesi oluşturduk
#include <Servo.h> // Servo kütüphanesini dahil ettik
Servo sg90; // Servo nesnesi oluşturduk
int pos = 0; // Servo pozisyonu için değişken tanımladık
int deger=0; // Analog okuma için değişken tanımladık
int kırmızı=2;//digital pin 2yi kırmızı olarak tanımladık.
int yesil=3;//digital pin 3ü yesil olarak tanımladık.
void setup() 
{
pinMode(kırmızı,OUTPUT); // kırmızı ledi çıkış olarak ayarladık
pinMode(yesil,OUTPUT); // yesil ledi çıkış olarak ayarladık
sg90.attach(13); // Servoyu 13. pine bağladık
Serial.begin(9600); // Seri haberleşmeyi başlattık
lcd.begin(); // LCD'yi başlattık
}
void loop()
{
deger=analogRead(A0); // A0 pininden analog değer oku
Serial.println(analogRead(A0)); // Okunan değeri seri monitöre yaz
if(deger>800) // Eğer değer 800'den büyükse
{
sg90.write(90); // Servoyu 90 dereceye döndürdük
lcd.setCursor(0,0); // LCD'nin ilk satırının başına gittik.
lcd.print("OFF"); // Kapı kapalı olduğu için OFF yazdık
digitalWrite(kırmızı,HIGH); // kırmızı ledimiz aktif halde
digitalWrite(yesil,LOW); // yeşil ledimiz inaktif halde
}
if(deger<800) // Eğer değer 800'den küçükse
{
sg90.write(1); // Servoyu 1 dereceye döndürdük.
lcd.setCursor(0,1); // LCD'nin ikinci satırının başına gittik
lcd.print("ON"); // Kapı kapalı olduğu için ON yazdık
digitalWrite(3,HIGH); // yeşil ledimiz aktif halde
digitalWrite(2,LOW); // kırmızı ledimiz inaktif halde
delay(1500); // 1500 ms(1.5sn) bekledik
} 
lcd.clear(); // LCD'yi temizleyerek yazıların karmaşasını önledik
}
