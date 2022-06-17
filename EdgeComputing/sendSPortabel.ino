void sendSPortabel() {
  String RFIDA    = DBPortabel + idGrid + "/a_berat";
  String RFIDB    = DBPortabel + idGrid + "/b_amonia";
  String RFIDC    = DBPortabel + idGrid + "/c_huma";
  String RFIDD    = DBPortabel + idGrid + "/d_temp";

  String G_idGrid = DBPortabel + idGrid + "/idGrid";

  String tanggal  = DBPortabel + idGrid + "/tanggal";
  String waktu    = DBPortabel + idGrid + "/waktu";


  Firebase.setFloat(G_idGrid, idGrid.toFloat());
  while (Firebase.failed()) {
    ledFailSend();
    Serial.println(Firebase.error());
    Firebase.setFloat(G_idGrid, idGrid.toFloat());
  }
  ledSuccessSend();

  Firebase.setString(RFIDA, berat);
  while (Firebase.failed()) {
    ledFailSend();
    Serial.println(Firebase.error());
    Firebase.setString(RFIDA, berat);
  }
  ledSuccessSend();

  Firebase.setString(RFIDB, amonia);
  while (Firebase.failed()) {
    ledFailSend();
    Serial.println(Firebase.error());
    Firebase.setString(RFIDB, amonia);
  }
  ledSuccessSend();

  Firebase.setString(RFIDC, hum);
  while (Firebase.failed()) {
    ledFailSend();
    Serial.println(Firebase.error());
    Firebase.setString(RFIDC, hum);
  }
  ledSuccessSend();

  Firebase.setString(RFIDD, temp);
  while (Firebase.failed()) {
    ledFailSend();
    Serial.println(Firebase.error());
    Firebase.setString(RFIDD, temp);
  }
  ledSuccessSend();

  Firebase.setString(tanggal, getDate());
  while (Firebase.failed()) {
    ledFailSend();
    Serial.println(Firebase.error());
    Firebase.setString(tanggal, getDate());
  }
  ledSuccessSend();

  Firebase.setString(waktu, getTime());
  while (Firebase.failed()) {
    ledFailSend();
    Serial.println(Firebase.error());
    Firebase.setString(waktu, getTime());
  }
  ledSuccessSend();
}
