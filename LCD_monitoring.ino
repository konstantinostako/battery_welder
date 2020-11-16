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
#define BATT_VOLT      10   // Battery Voltage Read Pin (to change)
#define SELECT         11   // These are dummy numbers
#define LEFT           12
#define RIGHT          13
#define UP             14
#define DOWN           15

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int t_start    = 0;
int t_current  = 0;
int t_target   = 0;


void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(KICK_PEDAL, INPUT);
  pinMode(BATT_VOLT,  INPUT);
  pinMode(SELECT,     INPUT);
  pinMode(LEFT,       INPUT);
  pinMode(RIGHT,      INPUT);
  pinMode(UP,         INPUT);
  pinMode(DOWN,       INPUT);
  pinMode(RELAY,      OUTPUT);
}

void loop() 
{
  lcd.setCursor(0, 1);
  
  // Update global time
  t_current = millis();
  
  // Check for button press
  (void) checkButtons();
  // Check for foot pedal press
  (void) checkPedal();
  // Battery monitoring
  (void) batteryMonitoring();

 
  if (onPulse())
  {
    digitalWrite(RELAY, HIGH);
  }
  else
  {
    digitalWrite(RELAY, LOW);
  }
}

void checkButtons(void)
{
  if (digitalRead(LEFT))
  {
  }
  if (digitalRead(RIGHT))
  {
  }
  if (digitalRead(UP))
  {
  }
  if (digitalRead(DOWN))
  {
  }
  if (digitalRead(SELECT))
  {
  }
}

void checkPedal(void)
{
  if (digitalRead(KICK_PEDAL))
  {
    t_start = millis();
    setPulseTime(100);     // Pulse in ms 
  }
}

void batteryMonitoring(void)
{
  // Every 1-2 sec to read
  // Filtering to be implemented
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
 
