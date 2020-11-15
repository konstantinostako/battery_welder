/*

  Features to be added:
  Button press debounce
  Mapping of all buttons to modes
  Pulse mode (completed?)
  Burst mode?
  LCD handling

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// define pins:
#define RELAY          9
#define KICK_PEDAL     6

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int t_start    = 0;
int t_current  = 0;
int t_target   = 0;


void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(9, OUTPUT);
  pinMode(6, INPUT);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() 
{
  lcd.setCursor(0, 1);
  
  t_current = millis();
  if (digitalRead(KICK_PEDAL)) // Needs debounce 
  {
    t_start = millis();
    setPulseTime(100);     // Pulse in ms 
  }
  
  if (onPulse())
  {
    digitalWrite(RELAY, HIGH);
  }
  else
  {
    digitalWrite(RELAY, LOW);
  }
}

void setPulseTime(int time_in_ms)
{
  t_target = time_in_ms;
}

bool onPulse()
{
  if (t_current - t_start < t_target)
  {
    return true;
  }
  else
  {
    return false;
  }
}
 
