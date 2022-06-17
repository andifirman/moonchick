void fanControl() {
  if (level == 0) {
    fan1(0);
    fan2(0);
    delay(1000);
    fan3(0);
    fan4(0);
    delay(1000);
    fan5(0);
    fan6(0);
    delay(1000);
    fan7(0);
    fan8(0);
  }

  if (level == 1) {
    fan1(1);
    fan2(1);
    delay(1000);
    fan3(0);
    fan4(0);
    delay(1000);
    fan5(0);
    fan6(0);
    delay(1000);
    fan7(0);
    fan8(0);
  }

  if (level == 2) {
    fan1(1);
    fan2(1);
    delay(1000);
    fan3(1);
    fan4(1);
    delay(1000);
    fan5(0);
    fan6(0);
    delay(1000);
    fan7(0);
    fan8(0);
  }

  if (level == 3) {
    fan1(1);
    fan2(1);
    delay(1000);
    fan3(1);
    fan4(1);
    delay(1000);
    fan5(1);
    fan6(1);
    delay(1000);
    fan7(0);
    fan8(0);
  }
  if (level == 4) {
    fan1(1);
    fan2(1);
    delay(1000);
    fan3(1);
    fan4(1);
    delay(1000);
    fan5(1);
    fan6(1);
    delay(1000);
    fan7(1);
    fan8(1);
  }
}
