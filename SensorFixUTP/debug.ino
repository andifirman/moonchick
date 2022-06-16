void debug() {
  Serial.print("Data Suhu       = ");
  Serial.println(Temp);

  Serial.print("Data Kelembaban = ");
  Serial.println(Hum);

  Serial.print("Data Kec. Angin = ");
  Serial.println(WindSpeed);

  Serial.print("Data Kirim      = ");
  Serial.println(dataKirim);

  Serial.println("");
  
}
