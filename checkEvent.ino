void checkEvent() {
  rele1Check();
  digitalWrite(rele1Pin, !rele1Status);
  rele2Check();
  digitalWrite(rele2Pin, !rele2Status);
  rele3Check();
  digitalWrite(rele3Pin, !rele3Status);
  rele4Check();
  digitalWrite(rele4Pin, !rele4Status);
}

void rele1Check() {
  if (time.Hours >= rele1HStart && time.Hours < rele1HStop && (time.Hours - rele1HStart % rele1Period) % rele1Period == 0) {
    for (int i = 0; i < 60 / rele1Frequency; i++) {
      if (time.minutes >= (rele1Frequency * i) && (time.minutes < (rele1Frequency * i) + rele1Duration)) {
        rele1Status = true;
        return;
      }
      rele1Status = false;
    }
  }
  else {
    rele1Status = false;
  }
}

void rele2Check() {
  if (time.Hours >= rele2HStart && time.Hours < rele2HStop && (time.Hours - rele2HStart % rele2Period) % rele2Period == 0) {
    for (int i = 0; i < 60 / rele2Frequency; i++) {
      if (time.minutes >= (rele2Frequency * i) && (time.minutes < (rele2Frequency * i) + rele2Duration)) {
        rele2Status = true;
        return;
      }
      rele2Status = false;
    }
  }
  else {
    rele2Status = false;
  }
}

void rele3Check() {
  if (time.Hours >= rele3HStart && time.Hours < rele3HStop && (time.Hours - rele3HStart % rele3Period) % rele3Period == 0) {
    if ((time.minutes % rele3Frequency == 0)) {
      if (time.seconds >= 0 && time.seconds < rele3Duration) {
        rele3Status = true;
        return;
      }
      rele3Status = false;
    }
  }
  else {
    rele3Status = false;
  }
}

void rele4Check() {
  if (rele4Param == 't') {
    if (rele4Condition == '<') {
      if (temperature < rele4Value) {
        rele4Status = true;
      }
      else {
        rele4Status = false;
      }
    }
    if (rele4Condition == '>') {
      if (temperature > rele4Value) {
        rele4Status = true;
      }
      else {
        rele4Status = false;
      }
    }
  }
  if (rele4Param == 'h') {
    if (rele4Condition == '<') {
      if (humidity < rele4Value) {
        rele4Status = true;
      }
      else {
        rele4Status = false;
      }
    }
    if (rele4Condition == '>') {
      if (humidity > rele4Value) {
        rele4Status = true;
      }
      else {
        rele4Status = false;
      }
    }
  }
}

