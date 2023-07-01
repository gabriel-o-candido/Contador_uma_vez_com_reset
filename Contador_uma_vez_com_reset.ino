
#include <LiquidCrystal.h>
LiquidCrystal lcd (7,6,5,4,3,2);
bool sensor;
int cont=0;
bool flag=0;
bool botao;

void setup() {

pinMode (8,INPUT);
pinMode (9,INPUT_PULLUP);
lcd.begin (16,2);

}

void loop() {

sensor = digitalRead (8);
botao = digitalRead (9);
lcd.setCursor (3,0);
lcd.print ("Contador");
if ((sensor==1)&&(flag==0))
 {
  flag=1;
 }
if ((sensor==0)&&(flag==1))
 {
  cont++;
  flag=0;
 }
lcd.setCursor (7,1);
lcd.print (cont);
if (botao==0)
 {
  lcd.clear();
  lcd.setCursor (1,0);
  lcd.print("Resetando...");
  delay (2000);
  lcd.clear ();
  cont =0;
  
 }
delay (300);
}
