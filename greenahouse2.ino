//greenhouse2

#define potPin A0
#define btnPin 5
#define rele1Pin 8
#define rele2Pin 9
#define rele3Pin 10
#define rele4Pin 11
#define CLKPin 2
#define DATPin 3
#define RSTPin 4
#define I2CAdress 0x3F

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <iarduino_RTC.h>
#include "GyverButton.h"
#include "GyverTimer.h"
#include <TroykaDHT.h>
#include <EEPROM.h>

iarduino_RTC time(RTC_DS1302, RSTPin, CLKPin, DATPin);
LiquidCrystal_I2C lcd(I2CAdress, 16, 2);
GButton button(btnPin);
GTimer_ms updateLog(60000);
GTimer_ms DHTTimer(2000);

DHT dht(12, DHT11);

uint16_t pot = 0;

uint8_t temperature = 0;
uint8_t humidity = 0;

uint8_t hourTemp;
uint8_t minuteTemp;
uint8_t secondTemp;

uint8_t rele1HStart = 0;
uint8_t rele1HStop = 23;
uint8_t rele1Period = 1;
uint8_t rele1Frequency = 30;
uint8_t rele1Duration = 5;

uint8_t rele2HStart = 6;
uint8_t rele2HStop = 20;
uint8_t rele2Period = 1;
uint8_t rele2Frequency = 60;
uint8_t rele2Duration = 60;

uint8_t rele4Value = 30;
uint8_t rele4Temp = 30;
char condition = '>';

uint8_t releHStartTemp = 0;
uint8_t releHStopTemp = 0;
uint8_t relePeriodTemp = 0;
uint8_t releFrequencyTemp = 0;
uint8_t releDurationTemp = 0;

bool rele1Status = false;
bool rele2Status = false;
bool rele3Status = false;
bool rele4Status = false;


uint8_t mode = 0;
uint8_t displayMode = 0;

void setup()
{

  pinMode(potPin, INPUT);
  //pinMode(btnPin, INPUT_PULLUP);
  pinMode(rele1Pin, OUTPUT);
  pinMode(rele2Pin, OUTPUT);

  lcd.init(); //Инициализация LCD
  lcd.backlight(); //Включение подстветки LCD
  Serial.begin(9600);
  time.begin();
  dht.begin();
  settingsLoad();
}



void loop()
{
  button.tick();
  time.gettime();
  Displays();
  checkEvent();
  printLog();
  DHTUpdate();
  
  if (button.isClick()) {
    mode++;
    lcd.clear();
    }
  if (button.isHolded()) {
    displayMode++; 
    mode = 0;
    lcd.clear();
    }
  displayMode = displayMode % 5;
}
