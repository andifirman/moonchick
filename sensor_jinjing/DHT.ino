void sensorsuhu() {
  float kelembaban1 = dht1.readHumidity(); //menyimpan nilai Humidity pada variabel kelembaban
  float suhu1 = dht1.readTemperature(); //menyimpan nilai Temperature pada variabel suhu

  float kelembaban2 = dht2.readHumidity(); //menyimpan nilai Humidity pada variabel kelembaban
  float suhu2 = dht2.readTemperature(); //menyimpan nilai Temperature pada variabel suhu

  kelembaban = (kelembaban1 + kelembaban2) / 2;
  suhu = (suhu1 + suhu2) / 2;

  delay(500);

}
