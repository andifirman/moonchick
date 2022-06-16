void timbangan() {
  if ((Serial3.available() > 0)) {
    dataT = Serial3.read();
    if (dataT == '\n') {
      beresT = true;
      Serial3.end();
    } else {
      valueT +=  dataT;
    }
  }

  if ((beresT == true) && (beresR == true)) {
    int baca = valueT.length();
    int pengurangan = baca - 4;
    String beratString = valueT.substring(8, pengurangan);
    int berat = beratString.toInt();
    sensorsuhu();
    mq137();
    spekKandang(valueR);

    kirimdata = "P" + String(idGrid) + ";" + String(berat) + ";" + String(amonia) + ";" + String(kelembaban) + ";" + String(suhu);

    ledSend();
    Serial1.print(kirimdata + "\n");
    Serial.println(kirimdata);

    valueT = "";
    valueR = "";
    coba = "";

    beresT = false;
    beresR = false;
    siap   = true;
  }


}
