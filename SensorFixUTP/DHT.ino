void dht22() {
  HumA  = dht1.readHumidity();
  TempA = dht1.readTemperature();

  HumB  = dht2.readHumidity();
  TempB = dht2.readTemperature();

//  Serial.print("DHT1");Serial.print(HumA);Serial.print(";");Serial.println(TempA);
//  Serial.print("DHT2");Serial.print(HumB);Serial.print(";");Serial.println(TempB); 


  Temp  = (TempA + TempB) / 2;
  Hum   = (HumA + HumB) / 2;

}
