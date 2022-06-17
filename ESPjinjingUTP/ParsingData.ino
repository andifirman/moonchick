void getData() {
  if (Serial.available() > 0) {
    ledGetData();
    byte idGrid = Serial.read();

    bacaSerial = Serial.readStringUntil('\n');
    Serial.println(bacaSerial);

    //    if (idGrid != 10) {
    //      //      Serial.println(generetIDRFID(idGrid));
    //      id      = generetIDRFID(idGrid);
    //      berat   = random(1500, 1800);
    //      amonia  = random(15, 25);
    //      hum     = random(65, 75);
    //      temp    = random(27, 29);
    //
    //      spekKandang(id);
    //    if ((idGrid != 0)) {
    //      //sendDataKandang();
    //      //sendDataGrafik();
    sendUDP();
    //    }

    //    }

    //    bacaSerial = Serial.readStringUntil('\n');
    //    Serial.println(bacaSerial);
    //
    //    //    Convert from String Object to String.
    //    char buf[255];
    //    char *p = buf;
    //    char *str;
    //    char *data[5];
    //    int i;
    //
    //    bacaSerial.toCharArray(buf, sizeof(buf));
    //    while ((str = strtok_r(p, ";", &p)) != NULL) // delimiter is the semicolon
    //    {
    //      data[i] = str;
    //      i++;
    //    }
    //
    //    id      = data[0];
    //    berat   = data[1];
    //    amonia  = data[2];
    //    hum     = data[3];
    //    temp    = data[4];
    //
    //    if ((berat != "") && (amonia != "") && (hum != "") && (temp != "") ) {
    //      Serial.println(id);
    //      Serial.println(berat);
    //      Serial.println(amonia);
    //      Serial.println(hum);
    //      Serial.println(temp);
    //      spekKandang(id);
    //      if ((idGrid != 0) && (idKandang != 0) && (namaKandang != "") && (posisi != 0) ) {
    //        sendDataKandang();
    ////        sendDataGrafik();
    //      }
    //    }
  }
}
