#include <LiquidCrystal.h> 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12,11,10,9,8,7,6,5,4,3,2);  
int valY, valX;
    
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);      // set up the LCD's number of columns and rows:
  
}
void loop()
{
  valY = analogRead(0);
  valX = analogRead(1);

  posJS();
  Serial.print(valY);
  Serial.print(", ");
  Serial.println(valX);
}

void posJS()
{
  if (valY <= 480)
  {
    right();
  }
  else if(valY >= 500)
  {
    left();
  }
  else if(valX <= 490)
  {
    down();
  }
  else if(valX >= 510)
  {
    up();
  }
  else if((valY < 500 && valY > 480) || (valX < 510 && valX > 490))
  {
    center();
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Error");  
  }
}

void right()
{
  lcd.setCursor(0,0);   // set the cursor to column 0, line 0
  lcd.print("Right           "); //// Print a message to the LCD.
  delay(5);
}

void left()
{
  lcd.setCursor(0,0);   // set the cursor to column 0, line 0
  lcd.print("Left            "); //// Print a message to the LCD.
  delay(5);
}

void up()
{
  lcd.setCursor(0,0);   // set the cursor to column 0, line 0
  lcd.print("Up           "); //// Print a message to the LCD.
  delay(5);
}

void down()
{
  lcd.setCursor(0,0);   // set the cursor to column 0, line 0
  lcd.print("Down           "); //// Print a message to the LCD.
  delay(5);
}

void center()
{
  lcd.setCursor(0,0);   // set the cursor to column 0, line 0
  lcd.print("Center          "); //// Print a message to the LCD.
  delay(5);
}
