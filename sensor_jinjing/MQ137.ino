void mq137() {
  amonia = analogRead(MQPIN);

  VRL = amonia * (5.0 / 1023.0); //Measure the voltage drop and convert to 0-5V
  Rs = ((5.0 * RL) / VRL) - RL; //Use formula to get Rs value
  ratio = Rs / Ro; // find ratio Rs/Ro

  float ppm = pow(10, ((log10(ratio)-b)/m)); //use formula to calculate ppm

  amonia = ppm;
}
