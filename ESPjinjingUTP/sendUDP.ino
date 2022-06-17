void sendUDP() {
  dataKirim = "P;" + bacaSerial;

  debug();

  Udp.beginPacket("192.168.43.24", localUdpPort);
  Udp.print(dataKirim);
  Udp.endPacket();
}
