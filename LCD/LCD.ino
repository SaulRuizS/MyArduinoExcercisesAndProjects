#include <LiquidCrystal.h> 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12,11,10,9,8,7,6,5,4,3,2);  

    
void setup()
{
  lcd.begin(16,2);      // set up the LCD's number of columns and rows:
  //lcd.setCursor(0,0);   // set the cursor to column 0, line 0
  //lcd.print("A B C D E F G H"); //// Print a message to the LCD.
  //lcd.setCursor(0,2);   // set the cursor to column 0, line 2
  //lcd.print("I J K L M N O P");  //Print a message to the LCD.
}
void loop()
{
  fxFall();
}

void fxFall()
{
  int vel = 300;
  int vel2 = 15;
  lcd.setCursor(0,0);   // set the cursor to column 0, line 0
  lcd.print("A B C D E F G H"); //// Print a message to the LCD.
  delay(vel);
  lcd.setCursor(0,0);
  lcd.print("               ");
  delay(vel2);
  lcd.setCursor(0,2);   // set the cursor to column 0, line 2
  lcd.print("A B C D E F G H");  //Print a message to the LCD.
  delay(vel);
  lcd.setCursor(0,2);
  lcd.print("               ");
  delay(vel);
}
