void sendSPortabelGrafik() {
  String formatAwal = DBGrafik + getDateGrafik() + "/RFID/" + idGrid;

  String g_amonia     = formatAwal + "/b_amonia";
  String g_berat      = formatAwal + "/a_berat";
  String g_kelembapan = formatAwal + "/c_huma";
  String g_suhu       = formatAwal + "/d_temp";
  String g_idGrid     = formatAwal + "/idGrid";

  Firebase.setString(g_amonia, amonia);
  while (Firebase.failed()) {
    ledFailSend();
    Serial.println(Firebase.error());
    Firebase.setString(g_amonia, amonia);
  }
  ledSuccessSend();

  Firebase.setString(g_berat, berat);
  while (Firebase.failed()) {
    ledFailSend();
    Serial.println(Firebase.error());
    Firebase.setString(g_berat, berat);
  }
  ledSuccessSend();

  Firebase.setString(g_kelembapan, hum);
  while (Firebase.failed()) {
    ledFailSend();
    Serial.println(Firebase.error());
    Firebase.setString(g_kelembapan, hum);
  }
  ledSuccessSend();

  Firebase.setString(g_suhu, temp);
  while (Firebase.failed()) {
    ledFailSend();
    Serial.println(Firebase.error());
    Firebase.setString(g_suhu, temp);
  }
  ledSuccessSend();

  Firebase.setInt(g_idGrid, idGrid.toInt());
  while (Firebase.failed()) {
    ledFailSend();
    Serial.println(Firebase.error());
    Firebase.setInt(g_idGrid, idGrid.toInt());
  }
  ledSuccessSend();
}
