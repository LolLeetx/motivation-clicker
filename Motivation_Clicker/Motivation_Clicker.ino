const int buttonPin = 8;
int counter = 0;
String words[] = {"wow very nice!","geng lo you","awsome!", "damn son","hiong leh you","nice one dude"};
int i = 0;
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.init();
  lcd.clear();
  lcd.backlight();      // Make sure backlight is on

  lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
  lcd.print("Clicks:");
  lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
  lcd.print(counter);
}
void loop() {
  int buttonState;
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    counter++;
    lcd.clear();
    lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
    lcd.print("Clicks:");

    lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
    lcd.print(counter);
    delay(150);

  if(counter%10 == 0){
    if( i <= 5 ){  
      Serial.println(i);
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print(words[i]);
      i++;
    }
    
   else{
    i = 0;
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print(words[i]);
    i++;
    }
    
   }
  }
}
