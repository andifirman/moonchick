void RFID() {
  if (Serial2.available()) {
    ledGetRFID();
    dataR = Serial2.read();
    if ((int) dataR == 3 || (int) dataR == 2 || (int) dataR == 13 || (int) dataR == 10) { //enter
      if ((int) dataR == 3) {
        ledStanby();
        beresR = true;
        siap = false;
        Serial2.end();
      }
    } else {
      if ((int)dataR >= 0 && (int)dataR <= 127) {
        valueR += dataR;
      }
      
    }

  }
}
