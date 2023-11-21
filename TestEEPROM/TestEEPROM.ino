#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>


LiquidCrystal_I2C LCD(0x27, 16, 2);

#define address 1
#define presenceSensor A0

int value;

void setup() {
  Serial.begin(9600);

  LCD.init();
  LCD.backlight();
  
  pinMode(presenceSensor, INPUT);
  
  value = EEPROM.read(address);
  LCDDisplay();
  }
  

void loop() {
   CheckPresence();
   if(Serial.read() == '0')
   {
     value = 0;
     EEPROM.write(address, value);
     LCDDisplay();
   }
}

void CheckPresence(){
  if(analogRead(presenceSensor) < 40){
    value++;
    Serial.println("Objet détecter");
    Serial.println(analogRead(presenceSensor));
    EEPROM.write(address, value);
    TextRand();
    LCDDisplay();
  }
}

void LCDDisplay(){
  LCD.clear();
  LCD.setCursor(1,0);
  LCD.print("TISPOUNE A BU ");
  LCD.setCursor(3,1);
  LCD.print(value);
  LCD.print(" BIERES");
  LCD.display();
}

void TextRand(){
  int nb = random(3);
  String tab[3] = {"SAL ALCOOLIQUE", "BRAVO CHAMPION", "BON APP BG"};
  String text = tab[nb];
  int cursorStart = ((16 - text.length())/2) - 1;
  LCD.clear();
  LCD.setCursor(cursorStart,0);
  LCD.print(text);
  LCD.setCursor(1,1);
  LCD.print("PLUS UNE BIERE");
  LCD.display();
  delay(3000);
}
