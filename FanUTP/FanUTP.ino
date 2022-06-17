//=====================================================================LIBRARY==
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#define WIFI_SSID "TP-Link AP"
#define WIFI_PASSWORD "4l4yb3td4h"

#define fan1p D0
#define fan2p D1
#define fan3p D2
#define fan4p D3
#define fan5p D4
#define fan6p D5
#define fan7p D6
#define fan8p D7

IPAddress ip(192, 168, 43, 27);
IPAddress dns(192, 168, 43, 1);
IPAddress gateway(192, 168, 43, 1);
IPAddress subnet(255, 255, 255, 0);

//============UDP Setting ==================
WiFiUDP Udp;
unsigned int localUdpPort = 8888;
char incomingPacket[255];  // buffer for incoming packets

String levelBlowerUDP;

byte level = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(fan1p, OUTPUT);
  pinMode(fan2p, OUTPUT);
  pinMode(fan3p, OUTPUT);
  pinMode(fan4p, OUTPUT);
  pinMode(fan5p, OUTPUT);
  pinMode(fan6p, OUTPUT);
  pinMode(fan7p, OUTPUT);
  pinMode(fan8p, OUTPUT);

  digitalWrite(fan1p, LOW);
  digitalWrite(fan2p, LOW);
  digitalWrite(fan3p, LOW);
  digitalWrite(fan4p, LOW);
  digitalWrite(fan5p, LOW);
  digitalWrite(fan6p, LOW);
  digitalWrite(fan7p, LOW);
  digitalWrite(fan8p, LOW);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  WiFi.config(ip, dns, gateway, subnet);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Udp.begin(localUdpPort);

  Serial.println("بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم");
}

void loop() {
  // put your main code here, to run repeatedly:

  if (WiFi.status() != WL_CONNECTED) {
    reconnectWifi();
  }

  terimaData();
}
