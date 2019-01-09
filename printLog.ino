void printLog() {
    if (updateLog.isReady()) {
    Serial.print(time.gettime("H:i:s "));
    Serial.print("rele1:"); 
    Serial.print(rele1Status);
    Serial.print(" ");  
    Serial.print("rele2:"); 
    Serial.print(rele2Status);
    Serial.print(" ");
     Serial.print("rele3:"); 
    Serial.print(rele3Status);
    Serial.print(" ");
    Serial.print("rele4:"); 
    Serial.print(rele4Status);
    Serial.print(" ");   
    Serial.print(toFormat(rele1HStart)); 
    Serial.print(":"); 
    Serial.print(toFormat(rele1HStop)); 
    Serial.print(" "); 
    Serial.print(rele1Period); 
    Serial.print(" "); 
    Serial.print(rele1Frequency); 
    Serial.print(" "); 
    Serial.print(rele1Duration); 
    Serial.print(" "); 
    Serial.print(toFormat(rele2HStart)); 
    Serial.print(":"); 
    Serial.print(toFormat(rele2HStop)); 
    Serial.print(" "); 
    Serial.print(rele2Period); 
    Serial.print(" "); 
    Serial.print(rele2Frequency); 
    Serial.print(" "); 
    Serial.print(rele2Duration); 
    Serial.print(" "); 
    Serial.print(toFormat(rele3HStart)); 
    Serial.print(":"); 
    Serial.print(toFormat(rele3HStop)); 
    Serial.print(" "); 
    Serial.print(rele3Period); 
    Serial.print(" "); 
    Serial.print(rele3Frequency); 
    Serial.print(" "); 
    Serial.print(rele3Duration); 
    Serial.print(" ");
    Serial.print(rele4Param);
    Serial.print(" ");
    Serial.print(rele4Condition);  
    Serial.print(rele4Value); 
    Serial.print(" t:"); 
    Serial.print(temperature); 
    Serial.print(" h:"); 
    Serial.print(humidity); 
    Serial.println();
    }
}

