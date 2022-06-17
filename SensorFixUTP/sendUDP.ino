void sendUDP() {
  dataKirim = "T;" + String(Temp) + ";" + String(Hum) + ";" + String(WindSpeed);

  debug();

  Udp.beginPacket("192.168.43.24", localUdpPort);
  Udp.print(dataKirim);
  Udp.endPacket();
}
