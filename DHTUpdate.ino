void DHTUpdate()
{
  if (DHTTimer.isReady()) {
    // считывание данных с датчика
    dht.read();
    // проверяем состояние данных
    switch (dht.getState()) {
      // всё OK
      case DHT_OK:
        // выводим показания влажности и температуры
        //Serial.print("Temperature = ");
        //Serial.print(dht.getTemperatureC());
        temperature = dht.getTemperatureC();
        //Serial.println(" C \t");
        //Serial.print("Temperature = ");
        //Serial.print(dht.getTemperatureK());
        //Serial.println(" K \t");
        //Serial.print("Temperature = ");
        //Serial.print(dht.getTemperatureF());
        //Serial.println(" F \t");
        //Serial.print("Humidity = ");
        //Serial.print(dht.getHumidity());
        humidity = dht.getHumidity();
        //Serial.println(" %");
        break;
      // ошибка контрольной суммы
      case DHT_ERROR_CHECKSUM:
        Serial.println("Checksum error");
        break;
      // превышение времени ожидания
      case DHT_ERROR_TIMEOUT:
        Serial.println("Time out error");
        break;
      // данных нет, датчик не реагирует или отсутствует
      case DHT_ERROR_NO_REPLY:
        Serial.println("Sensor not connected");
        break;
    }
  }}
