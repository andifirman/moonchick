void reOnAnemometer() {

  //MEnjaga agar anemometer selalu nyala
  digitalWrite(onFan, HIGH);
  delay(500);
  digitalWrite(onFan, LOW);
  delay(500);
  digitalWrite(onFan, HIGH);
  delay(500);
  digitalWrite(onFan, LOW);
}
