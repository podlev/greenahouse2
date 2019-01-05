void checkEvent() {
  rele1Check();
  digitalWrite(rele1Pin, !rele1Status);
  rele2Check();
  digitalWrite(rele2Pin, !rele2Status);
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

