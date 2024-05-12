#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Keypad.h>
#define rows 4
#define cols 4
#define led 7
 unsigned long lastUpdateTime = 0; 
unsigned long updateInterval =100; 
 unsigned long currentTime = 0;
int countdown = 15; // Initial countdown value
int pass_l = 5; /*password lenght*/
int c = 0;
byte i=0;
String pass = "12102";
String Data;
char arr[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte row_pin[4] = {2, 3, 4 ,5 }; /*8bit from memory*/
byte col_pin[4] = {6, 7, 8 , 9}; /*8bit from memory*/
Keypad customKeypad = Keypad(makeKeymap(arr), row_pin, col_pin, rows, cols);
void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
 
}
int Attempts(){
 if(i==1){
  delay(1000);
  lcd.clear();
  lcd.print("Only two attempts left... ");
  } 
  else if(i==2){
    delay(1000);
  lcd.clear();
  lcd.print("Only one attempt left... ");
  } 
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  char key = customKeypad.getKey();
  if (key) { /*if(key==قيمه)*/
    Data += key;
    lcd.setCursor(c, 1);
    lcd.print(Data[c]);
    delay(100);
    lcd.setCursor(c, 1);
    lcd.print('*');
    c++;
    } 
      if (c == pass_l){
    lcd.clear();
  if (Data == pass) {
    lcd.setCursor(0, 0);
    lcd.print("correct");
    i=0; 
    delay(1000);
    lcd.clear();
    }
   else{
      lcd.setCursor(0, 0);
      lcd.println("In Correct ");
      i++;
      Attempts();
      if(i==3){
        lcd.clear();
        lcd.print("You have no attempts ");
        delay(1000);
        timer();
        }
      delay(1000);
      lcd.clear();
 }
  c = 0;
  Data = "";
      }
}
