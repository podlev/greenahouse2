void Displays() {
  pot = analogRead(potPin);
  uint8_t temp;

  //Начальный экран
  if (displayMode == 0) {
      lcd.setCursor(0, 0);
      lcd.print(time.gettime("H:i"));
      lcd.print(" t:" + String(toFormat(temperature)));
      lcd.print( " h:" + String(toFormat(humidity)));
      lcd.setCursor(0, 1);
      lcd.print("r: " + String(rele1Status) + " " + String(rele2Status) + " " + String(rele3Status) + " " + String(rele4Status));  
  }

  //Установка времени
  if (displayMode == 1) {
    if (mode == 0) {
      hourTemp = time.Hours;
      minuteTemp = time.minutes;
      lcd.setCursor(0, 0);
      lcd.print("set time");
      lcd.setCursor(0, 1);
      lcd.print(toFormat(hourTemp) + ":" + toFormat(minuteTemp));
    }
    if (mode == 1) {
      hourTemp = constrain(map(pot, 100, 900, 0, 23), 0, 23);
      lcd.setCursor(0, 0);
      lcd.print(toFormat(hourTemp) + ":" + toFormat(minuteTemp));
    }
    if (mode == 2) {
      minuteTemp = constrain(map(pot, 100, 900, 0, 60), 0, 60);
      lcd.setCursor(0, 0);
      lcd.print(toFormat(hourTemp) + ":" + toFormat(minuteTemp));
    }
    if (mode == 3) {
      lcd.setCursor(0, 0);
      lcd.print("prs btn to sve");
      lcd.setCursor(0, 1);
      lcd.print("lng prs to cncl");
    }
    if (mode == 4) {
      time.settime(0, minuteTemp, hourTemp, 1, 1, 2019, 1); // 0  сек, 51 мин, 21 час, 27, октября, 2015 года, вторник
      displayMode++;
      mode = 0;
    }
  }

  //Установка 1 реле
  if (displayMode == 2) {
    if (mode == 0) {
      lcd.setCursor(0, 0);
      lcd.print("rele1 set");
      lcd.setCursor(0, 1);
      lcd.print(String(toFormat(rele1HStart)) + ":" + String(toFormat(rele1HStop)) + " " + String(rele1Period) + " " + String(rele1Frequency)  + " " + String(rele1Duration));
    }
    if (mode == 1) {
      releHStartTemp = constrain(map(pot, 100, 900, 0, 23), 0, 23);
      lcd.setCursor(0, 0);
      //Добавть формат
      lcd.print(String(toFormat(releHStartTemp)) + ":" + String(toFormat(rele1HStop)) + " " + String(rele1Period) + " " + String(rele1Frequency)  + " " + String(rele1Duration));
    }
    if (mode == 2) {
      releHStopTemp = constrain(map(pot, 100, 900, 0, 23), 0, 23);
      lcd.setCursor(0, 0);
      lcd.print(String(toFormat(releHStartTemp)) + ":" + String(toFormat(releHStopTemp)) + " " + String(rele1Period) + " " + String(rele1Frequency)  + " " + String(rele1Duration));
    }
    if (mode == 3) {
      relePeriodTemp = constrain(map(pot, 100, 900, 0, 10), 0, 10);
      lcd.setCursor(0, 0);
      lcd.print(String(toFormat(releHStartTemp)) + ":" + String(toFormat(releHStopTemp)) + " " + String(relePeriodTemp) + " " + String(rele1Frequency)  + " " + String(rele1Duration));

    }
    if (mode == 4) {
      releFrequencyTemp = constrain(map(pot, 100, 900, 0, 60), 0, 60);
      lcd.setCursor(0, 0);
      lcd.print(String(toFormat(releHStartTemp)) + ":" + String(toFormat(releHStopTemp)) + " " + String(relePeriodTemp) + " " + String(releFrequencyTemp)  + " " + String(rele1Duration));

    }
    if (mode == 5) {
      releDurationTemp = constrain(map(pot, 100, 900, 0, 60), 0, 60);
      lcd.setCursor(0, 0);
      lcd.print(String(toFormat(releHStartTemp)) + ":" + String(toFormat(releHStopTemp)) + " " + String(relePeriodTemp) + " " + String(releFrequencyTemp)  + " " + String(releDurationTemp));
    }
    if (mode == 6) {
      lcd.setCursor(0, 0);
      lcd.print("prs btn to sve");
      lcd.setCursor(0, 1);
      lcd.print("lng prs to cncl");
    }
    if (mode == 7) {
      rele1HStart = releHStartTemp;
      rele1HStop = releHStopTemp;
      rele1Period = relePeriodTemp;
      rele1Frequency = releFrequencyTemp;
      rele1Duration = releDurationTemp;
      EEPROM.write(0, rele1HStart);
      EEPROM.write(1, rele1HStop);
      EEPROM.write(2, rele1Period);
      EEPROM.write(3, rele1Frequency);
      EEPROM.write(4, rele1Duration);
      displayMode++;
      mode = 0;
    }
  }
  //Установка 2 реле
  if (displayMode == 3) {
    if (mode == 0) {
      lcd.setCursor(0, 0);
      lcd.print("rele2 set");
      lcd.setCursor(0, 1);
      lcd.print(String(toFormat(rele2HStart)) + ":" + String(toFormat(rele2HStop)) + " " + String(rele2Period) + " " + String(rele2Frequency)  + " " + String(rele2Duration));
    }
    if (mode == 1) {
      releHStartTemp = constrain(map(pot, 100, 900, 0, 23), 0, 23);
      lcd.setCursor(0, 0);
      //Добавть формат
      lcd.print(String(releHStartTemp) + ":" + String(rele2HStop) + " " + String(rele2Period) + " " + String(rele2Frequency)  + " " + String(rele2Duration));
    }
    if (mode == 2) {
      releHStopTemp = constrain(map(pot, 100, 900, 0, 23), 0, 23);
      lcd.setCursor(0, 0);
      lcd.print(String(releHStartTemp) + ":" + String(releHStopTemp) + " " + String(rele2Period) + " " + String(rele2Frequency)  + " " + String(rele2Duration));
    }
    if (mode == 3) {
      relePeriodTemp = constrain(map(pot, 100, 900, 0, 10), 0, 10);
      lcd.setCursor(0, 0);
      lcd.print(String(releHStartTemp) + ":" + String(releHStopTemp) + " " + String(relePeriodTemp) + " " + String(rele2Frequency)  + " " + String(rele2Duration));

    }
    if (mode == 4) {
      releFrequencyTemp = constrain(map(pot, 100, 900, 0, 60), 0, 60);
      lcd.setCursor(0, 0);
      lcd.print(String(releHStartTemp) + ":" + String(releHStopTemp) + " " + String(relePeriodTemp) + " " + String(releFrequencyTemp)  + " " + String(rele2Duration));

    }
    if (mode == 5) {
      releDurationTemp = constrain(map(pot, 100, 900, 0, 60), 0, 60);
      lcd.setCursor(0, 0);
      lcd.print(String(releHStartTemp) + ":" + String(releHStopTemp) + " " + String(relePeriodTemp) + " " + String(releFrequencyTemp)  + " " + String(releDurationTemp));
    }
    if (mode == 6) {
      lcd.setCursor(0, 0);
      lcd.print("prs btn to sve");
      lcd.setCursor(0, 1);
      lcd.print("lng prs to cncl");
    }
    if (mode == 7) {
      rele2HStart = releHStartTemp;
      rele2HStop = releHStopTemp;
      rele2Period = relePeriodTemp;
      rele2Frequency = releFrequencyTemp;
      rele2Duration = releDurationTemp;
      EEPROM.write(10, rele2HStart);
      EEPROM.write(11, rele2HStop);
      EEPROM.write(12, rele2Period);
      EEPROM.write(13, rele2Frequency);
      EEPROM.write(14, rele2Duration);
      displayMode++;
      mode = 0;
    }
  }

  //Установка 3 реле
  if (displayMode == 4) {
    if (mode == 0) {
      lcd.setCursor(0, 0);
      lcd.print("rele3 set");
      lcd.setCursor(0, 1);
      lcd.print(String(toFormat(rele3HStart)) + ":" + String(toFormat(rele3HStop)) + " " + String(rele3Period) + " " + String(rele3Frequency)  + " " + String(rele3Duration));
    }
    if (mode == 1) {
      releHStartTemp = constrain(map(pot, 100, 900, 0, 23), 0, 23);
      lcd.setCursor(0, 0);
      //Добавть формат
      lcd.print(String(releHStartTemp) + ":" + String(rele3HStop) + " " + String(rele3Period) + " " + String(rele3Frequency)  + " " + String(rele3Duration));
    }
    if (mode == 2) {
      releHStopTemp = constrain(map(pot, 100, 900, 0, 23), 0, 23);
      lcd.setCursor(0, 0);
      lcd.print(String(releHStartTemp) + ":" + String(releHStopTemp) + " " + String(rele3Period) + " " + String(rele3Frequency)  + " " + String(rele3Duration));
    }
    if (mode == 3) {
      relePeriodTemp = constrain(map(pot, 100, 900, 0, 10), 0, 10);
      lcd.setCursor(0, 0);
      lcd.print(String(releHStartTemp) + ":" + String(releHStopTemp) + " " + String(relePeriodTemp) + " " + String(rele3Frequency)  + " " + String(rele3Duration));

    }
    if (mode == 4) {
      releFrequencyTemp = constrain(map(pot, 100, 900, 0, 60), 0, 60);
      lcd.setCursor(0, 0);
      lcd.print(String(releHStartTemp) + ":" + String(releHStopTemp) + " " + String(relePeriodTemp) + " " + String(releFrequencyTemp)  + " " + String(rele3Duration));

    }
    if (mode == 5) {
      releDurationTemp = constrain(map(pot, 100, 900, 0, 60), 0, 60);
      lcd.setCursor(0, 0);
      lcd.print(String(releHStartTemp) + ":" + String(releHStopTemp) + " " + String(relePeriodTemp) + " " + String(releFrequencyTemp)  + " " + String(releDurationTemp));
    }
    if (mode == 6) {
      lcd.setCursor(0, 0);
      lcd.print("prs btn to sve");
      lcd.setCursor(0, 1);
      lcd.print("lng prs to cncl");
    }
    if (mode == 7) {
      rele3HStart = releHStartTemp;
      rele3HStop = releHStopTemp;
      rele3Period = relePeriodTemp;
      rele3Frequency = releFrequencyTemp;
      rele3Duration = releDurationTemp;
      EEPROM.write(20, rele3HStart);
      EEPROM.write(21, rele3HStop);
      EEPROM.write(22, rele3Period);
      EEPROM.write(23, rele3Frequency);
      EEPROM.write(24, rele3Duration);
      displayMode++;
      mode = 0;
    }
  }
  
  //Установка 4 реле
  if (displayMode == 5) {
    if (mode == 0) {
      lcd.setCursor(0, 0);
      lcd.print("rele4 set");
      lcd.setCursor(0, 1);
      lcd.print(String(rele4Param) + String(rele4Condition) + String(rele4Value));
    }
    if (mode == 1) {
      if (pot > 512) rele4Param = 't';
      else rele4Param = 'h';
      lcd.setCursor(0, 0);
      lcd.print(String(rele4Param) + String(rele4Condition) + String(rele4Value));
    }
    if (mode == 2) {
      if (pot > 512) rele4Condition = '>';
      else rele4Condition = '<';
      lcd.setCursor(0, 0);
      lcd.print(String(rele4Param) + String(rele4Condition) + String(rele4Value));
    }
    if (mode == 3) {
      rele4Temp = constrain(map(pot, 100, 900, 0, 40), 0, 40);
      lcd.setCursor(0, 0);
      lcd.print(String(rele4Param) + String(rele4Condition) + String(rele4Temp));
    }

    if (mode == 4) {
      lcd.setCursor(0, 0);
      lcd.print("prs btn to sve");
      lcd.setCursor(0, 1);
      lcd.print("lng prs to cncl");
    }
    if (mode == 5) {
      rele4Value = rele4Temp;
      EEPROM.write(30, rele4Value);
      EEPROM.write(31, rele4Condition);
      EEPROM.write(32, rele4Param);
      displayMode++;
      mode = 0;
    }
  }

}

