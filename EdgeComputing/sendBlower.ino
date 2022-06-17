void sendBlower() {
  float maxTemp;

  // Set Maksimal Temp
  if (harike < 3) {
    maxTemp = 32;
  }
  else if (harike < 6) {
    maxTemp = 30;
  }
  else if (harike < 9) {
    maxTemp = 28;
  }
  else if (harike <= 12) {
    maxTemp = 27;
  }
  else {
    maxTemp = 26;
  }

  // Set Level Blower

  if (sFixTemp.toFloat() > (maxTemp + blowerLev4.toFloat())) {
    levelBlower = "4";
  }
  else if (sFixTemp.toFloat() > (maxTemp + blowerLev3.toFloat())) {
    levelBlower = "3";
  }
  else if (sFixTemp.toFloat() > (maxTemp + blowerLev2.toFloat())) {
    levelBlower = "2";
  }
  else if (sFixTemp.toFloat() > (maxTemp + blowerLev1.toFloat())) {
    levelBlower = "1";
  }
  else {
    levelBlower = "0";
  }

  if (levelBlower != levelBlowerLama) {
    String  dataKirim = "B;" + String(levelBlower);
    levelBlowerLama = levelBlower;

    Serial.println("");
    Serial.print("Kirim Data Blower    : "); Serial.println(dataKirim);
    Serial.println("");

    Udp.beginPacket("192.168.43.27", localUdpPort);
    Udp.print(dataKirim);
    Udp.endPacket();
  }

}
