void settingsLoad() {
 rele1HStart = EEPROM.read(0);
 rele1HStop = EEPROM.read(1);
 rele1Period = EEPROM.read(2);
 rele1Frequency = EEPROM.read(3);
 rele1Duration = EEPROM.read(4);

 rele2HStart = EEPROM.read(10);
 rele2HStop = EEPROM.read(11);
 rele2Period = EEPROM.read(12);
 rele2Frequency = EEPROM.read(13);
 rele2Duration = EEPROM.read(14);

 rele3HStart = EEPROM.read(20);
 rele3HStop = EEPROM.read(21);
 rele3Period = EEPROM.read(22);
 rele3Frequency = EEPROM.read(23);
 rele3Duration = EEPROM.read(24); 

 rele4Value = EEPROM.read(30);
 rele4Condition = EEPROM.read(31);
 rele4Param = EEPROM.read(32); 
}

