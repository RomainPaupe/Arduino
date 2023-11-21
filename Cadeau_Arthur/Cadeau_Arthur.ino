#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

#define b1 5
#define b2 6
#define b3 7
#define i1 A1
#define i2 A2
#define motor1Pin1 3
#define motor1Pin2 4
#define enablePin 9
#define address 1

LiquidCrystal_I2C LCD(0x27, 16, 2);

int etatVerrou ="";
int heure = 0;
int minutes = 0;
long min = 60000;
long h = 60*min;


void setup() {
  // put your setup code here, to run once:
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(i1, INPUT);
  pinMode(i2, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  Serial.begin(9600);

  LCD.init();
  LCD.backlight();

  etatVerrou = EEPROM.read(address);

  if(etatVerrou==1){
    OuvrirBoite();
  }

  heure = 0;
  minutes = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  ChoixTempsTrav();
  while(true){
    LCDDisplayTempsTrav();
    delay(min);
    minutes--;

    if(minutes <= 0 & heure <= 0){break;}

    if(minutes < 0){
      minutes == 59;
      heure--;
    }
  }
  OuvrirBoite();
  while(digitalRead(b3) == 0){}
  delay(200);
}

void LCDDisplayLCDBravo(){
  LCD.clear();
  LCD.setCursor(0,0);
  LCD.print("Bravo ! Tu as");
  LCD.setCursor(0,1);
  LCD.print("bien travaille");
  LCD.display();
}

void LCDDisplayTempsTrav(){
  LCD.clear();
  LCD.setCursor(0,0);
  LCD.print("Temps de travail :");
  LCD.setCursor(5,1);
  LCD.print(heure);
  LCD.print(":");
  if(minutes < 10){LCD.print("0");}
  LCD.print(minutes);
  LCD.display();
}

void LCDDisplayValidation(){
  LCD.clear();
  LCD.setCursor(0,0);
  LCD.print("Valider ");
  LCD.print(heure);
  LCD.print(":");
  LCD.print(minutes);
  if(minutes < 10){LCD.print("0");}
  LCD.print(" ?");
  LCD.setCursor(0, 1);
  LCD.print("+: OUI -: NON");
  LCD.display();
}

void ChoixTempsTrav(){
  LCDDisplayTempsTrav();
  while(digitalRead(b3) == 0){
    
    if(digitalRead(b1) == 1){
      minutes += 10;
      if(minutes == 60){
        heure++;
        minutes = 0;
      }
      LCDDisplayTempsTrav();
      delay(100);
    }

    if(digitalRead(b2) == 1){
      minutes -= 10;
      if(minutes < 0){
        heure--;
        if(heure < 0)
        {
          heure = 0;
        }
        minutes = 50;
      }
      LCDDisplayTempsTrav();
      delay(100);
    }
  }
  LCDDisplayValidation();
  delay(300);
  while(true){
    if(digitalRead(b1)==1 || digitalRead(b3)==1){
       delay(100);
      break;
    }
    if(digitalRead(b2)==1){
      delay(100);
      ChoixTempsTrav();
    }
  }
  FermerBoite();
}

void FermerBoite(){
  LCDDisplayTempsTrav();
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(enablePin, HIGH);
    while(digitalRead(i1) == 0){

  }
  ArretMoteur();
  EEPROM.write(address, 1);
}

void OuvrirBoite(){
  LCDDisplayLCDBravo();
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(enablePin, HIGH);
  while(digitalRead(i2) == 0){

  }
  ArretMoteur();
  EEPROM.write(address, 0);
}

void ArretMoteur(){
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(enablePin, HIGH);
}
