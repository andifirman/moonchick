void sendUDPAndroid() {
  String  dataKirim = "SFix;" + String(25.5) + ";" + String(75.5) + ";";

  Udp.beginPacket("192.168.1.28", localUdpPort);
  Udp.print(dataKirim);
  Udp.endPacket();
}
