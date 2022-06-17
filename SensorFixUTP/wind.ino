void wind() {
  value = 0;

  for (int i = 0; i < 50; i++) {
    angin = float(analogRead(A0));
    if (value < angin) {
      value = angin;
    }
    delay(10);
  }
  if (value >= 150) {
    value = ((value - 150) / 100) / 1.575;
    WindSpeed = value;
    delay(50);
  }
}
