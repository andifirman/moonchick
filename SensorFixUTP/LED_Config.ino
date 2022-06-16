void Sensor_Success() {
  Serial.println("Sensor_Success");
  for (int i = 0; i <= 2; i++) {
    digitalWrite(ledBlue, l_off);
    digitalWrite(ledGreen, l_on);
    digitalWrite(ledRed, l_off);
    delay(50);
    digitalWrite(ledBlue, l_off);
    digitalWrite(ledGreen, l_off);
    digitalWrite(ledRed, l_off);
    delay(50);
  }
  delay(300);
}

void Sensor_Fail() {
  Serial.println("Sensor_Fail");
  for (int i = 0; i <= 2; i++) {
    digitalWrite(ledBlue, l_off);
    digitalWrite(ledGreen, l_off);
    digitalWrite(ledRed, l_on);
    delay(50);
    digitalWrite(ledBlue, l_off);
    digitalWrite(ledGreen, l_off);
    digitalWrite(ledRed, l_off);
    delay(50);
  }
  delay(300);
}


void Firebase_Sukses() {
  Serial.println("Firebase_Sukses");
  for (int i = 0; i <= 5; i++) {
    digitalWrite(ledBlue, l_off);
    digitalWrite(ledGreen, l_on);
    digitalWrite(ledRed, l_off);
    delay(50);
    digitalWrite(ledBlue, l_off);
    digitalWrite(ledGreen, l_off);
    digitalWrite(ledRed, l_off);
    delay(50);
  }
  delay(300);
}

void Firebase_Gagal() {
  Serial.println("Firebase_Gagal");
  for (int i = 0; i <= 5; i++) {
    digitalWrite(ledBlue, l_off);
    digitalWrite(ledGreen, l_off);
    digitalWrite(ledRed, l_on);
    delay(50);
    digitalWrite(ledBlue, l_off);
    digitalWrite(ledGreen, l_off);
    digitalWrite(ledRed, l_off);
    delay(50);
  }
  delay(300);
}

void Wait_Process() {
  Serial.println("Wait_Process");
  digitalWrite(ledBlue, l_on);
  digitalWrite(ledGreen, l_off);
  digitalWrite(ledRed, l_off);
}

void Begin_Process() {
  Serial.println("Begin_Process");
  for (int i = 0; i <= 5; i++) {
    digitalWrite(ledBlue, l_on);
    digitalWrite(ledGreen, l_on);
    digitalWrite(ledRed, l_on);
    delay(300);
    digitalWrite(ledBlue, l_off);
    digitalWrite(ledGreen, l_off);
    digitalWrite(ledRed, l_off);
    delay(300);
  }

}

void Between_Process() {
  Serial.println("Between_Process");
  delay(500);
  digitalWrite(ledBlue, l_off);
  digitalWrite(ledGreen, l_off);
  digitalWrite(ledRed, l_off);
  delay(500);
  digitalWrite(ledBlue, l_on);
  digitalWrite(ledGreen, l_on);
  digitalWrite(ledRed, l_on);
  delay(500);
  digitalWrite(ledBlue, l_off);
  digitalWrite(ledGreen, l_off);
  digitalWrite(ledRed, l_off);
  delay(500);
  digitalWrite(ledBlue, l_on);
  delay(500);

}

void Sensor_reconect() {
  for (int i = 0; i <= 2; i++) {
    digitalWrite(ledBlue, l_off);
    digitalWrite(ledGreen, l_off);
    digitalWrite(ledRed, l_on);
    delay(50);
    digitalWrite(ledBlue, l_off);
    digitalWrite(ledGreen, l_off);
    digitalWrite(ledRed, l_off);
    delay(50);
  }
}
