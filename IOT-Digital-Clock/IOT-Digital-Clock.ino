/*
   This is developed by SAMEER TUTEJA and if required to modify it, please contact beforehand.
   https://github.com/sam-tj

   This is tested for NODEMCU 1.0
   For any suggestions please contact me using GITHUB.
*/

/*
  For getting other values from DateTime Structure

  tm_sec int seconds after the minute  0-60
  tm_min  int minutes after the hour  0-59
  tm_hour int hours since midnight  0-23
  tm_mday int day of the month  1-31
  tm_mon  int months since January  0-11
  tm_year int years since 1900
  tm_wday int days since Sunday 0-6
  tm_yday int days since January 1  0-365
  tm_isdst  int Daylight Saving Time flag

*/

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

const char *ssid     = "YOUR SSID";
const char *password = "YOUR PASSWORD";

unsigned int timezoneSign = +1; //sign +1 -1
int timezoneHR = 5; // FOR ASIA TIMEZONE
int timezoneMIN = 30;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

String weekDays[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
String months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};


void setup() {
  Serial.begin(115200);
  Wire.begin(D5, D6);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi Connect :)");
  lcd.setCursor(0, 1);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
    lcd.print ( "." );
  }
  unsigned int timezone = (((timezoneHR * 60) + timezoneMIN) * 60) * timezoneSign;
  timeClient.begin();
  timeClient.setTimeOffset(timezone); //
  timeClient.update();

  lcd.clear();
}

int i = 0;
unsigned long previousMillis = 0;
const long interval = 1000;

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    Serial.println("");

    timeClient.update();
    unsigned long epochTime = timeClient.getEpochTime();
    struct  tm *ptm = gmtime ((time_t *)&epochTime);

    {
      lcd.setCursor(3, 0);

      int currentHour = ptm->tm_hour;
      int currentMinute = ptm->tm_min;
      int currentSecond = ptm->tm_sec;

      Serial.print(currentHour);
      Serial.print(":");
      Serial.print(currentMinute);
      Serial.print(":");
      Serial.print(currentSecond);

      if (currentHour >= 12) {
        if (currentHour == 12)
        {
          lcd.print(currentHour);
        }
        else if (currentHour > 12 && currentHour < 22) {
          lcd.print("0");
          lcd.print(currentHour - 12);
        }

        else {
          lcd.print(currentHour - 12);
        }

        if (currentMinute < 10) {
          lcd.print(":0");
          lcd.print(currentMinute);
        }
        else {
          lcd.print(":");
          lcd.print(currentMinute);
        }

        if (currentSecond < 10) {
          lcd.print(":0");
          lcd.print(currentSecond);
        }
        else {
          lcd.print(":");
          lcd.print(currentSecond);
        }
        lcd.print(" PM ");
      }
      else {
        if (currentHour < 10) {
          if (currentHour == 0) {
            lcd.print("12");
          }
          else {
            lcd.print("0");
            lcd.print(currentHour);
          }
        }
        else {
          lcd.print(currentHour);
        }
        if (currentMinute < 10) {
          lcd.print(":0");
          lcd.print(currentMinute);
        }
        else {
          lcd.print(":");
          lcd.print(currentMinute);
        }

        if (currentSecond < 10) {
          lcd.print(":0");
          lcd.print(currentSecond);
        }
        else {
          lcd.print(":");
          lcd.print(currentSecond);
        }
        lcd.print(" AM ");
      }
    }

    {
      lcd.setCursor(0, 1);

      String weekDay = weekDays[ptm->tm_wday];
      String currentMonth = months[ptm->tm_mon];
      int currentYear = ptm->tm_year + 1900;
      int currentDay = ptm->tm_mday;

      lcd.print(weekDay);
      lcd.print(". ");
      lcd.print(currentMonth);
      lcd.print(" ");
      lcd.print(currentDay);
      lcd.print(" ");
      lcd.print(currentYear);
    }

  }
}


