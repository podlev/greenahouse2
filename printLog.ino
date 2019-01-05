void printLog() {
    if (updateLog.isReady()) {
    Serial.print(time.gettime("H:i "));
    Serial.print("rele1:"); 
    Serial.print(rele1Status);
    Serial.print(" ");  
    Serial.print("rele2:"); 
    Serial.print(rele2Status);
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
    Serial.print(" t");
    Serial.print(condition);  
    Serial.print(rele4Value); 
    Serial.print(" t:"); 
    Serial.print(temperature); 
    Serial.print(" h:"); 
    Serial.print(humidity); 
    Serial.println();
    }
}

